#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class ResourceManager {
public:
    static ResourceManager& get(); // Singleton доступ

    // Загрузка
    void loadFont(const std::string& id, const std::string& path);
    void loadTexture(const std::string& id, const std::string& path);
    void loadSound(const std::string& id, const std::string& path);

    // Получение
    const sf::Font& getFont(const std::string& id) const;
    const sf::Texture& getTexture(const std::string& id) const;
    const sf::SoundBuffer& getSound(const std::string& id) const;
private:
    ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    std::map<std::string, sf::Font> mFonts;
    std::map<std::string, sf::Texture> mTextures;
    std::map<std::string, sf::SoundBuffer> mSounds;
};
