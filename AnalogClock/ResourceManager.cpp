#include "ResourceManager.h"
#include <stdexcept>


ResourceManager& ResourceManager::get() {
    static ResourceManager instance;
    return instance;
}

void ResourceManager::loadFont(const std::string& id, const std::string& path) {
    sf::Font font;
    if (!font.openFromFile(path))
        throw std::runtime_error("Failed to load font: " + path);
    mFonts[id] = std::move(font);
}

void ResourceManager::loadTexture(const std::string& id, const std::string& path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path))
        throw std::runtime_error("Failed to load texture: " + path);
    mTextures[id] = std::move(texture);
}

void ResourceManager::loadSound(const std::string& id, const std::string& path) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(path))
        throw std::runtime_error("Failed to load sound: " + path);
    mSounds[id] = std::move(buffer);
}

const sf::Font& ResourceManager::getFont(const std::string& id) const {
    auto it = mFonts.find(id);
    if (it == mFonts.end())
        throw std::runtime_error("Font not found: " + id);
    return it->second;
}

const sf::Texture& ResourceManager::getTexture(const std::string& id) const {
    auto it = mTextures.find(id);
    if (it == mTextures.end())
        throw std::runtime_error("Texture not found: " + id);
    return it->second;
}

const sf::SoundBuffer& ResourceManager::getSound(const std::string& id) const {
    auto it = mSounds.find(id);
    if (it == mSounds.end())
        throw std::runtime_error("Sound not found: " + id);
    return it->second;
}
