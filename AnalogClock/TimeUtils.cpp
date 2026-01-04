#include "TimeUtils.h"

#include <chrono>

TimeData TimeUtils::getCurrentTime()
{
	// 1. Получаем текущее системное время
	auto now = std::chrono::system_clock::now();

	// 2. Преобразуем в локальное время (нужен C++20)
	auto zt = std::chrono::zoned_time{ std::chrono::current_zone(), now };
	auto local_time = zt.get_local_time();

	// 3. Получаем "время дня" (разбиваем на ч/м/с/мс)
	auto dp = std::chrono::floor<std::chrono::days>(local_time);
	std::chrono::hh_mm_ss time_of_day{ local_time - dp };

	return TimeData{
		static_cast<float>(time_of_day.hours().count()),
		static_cast<float>(time_of_day.minutes().count()),
		static_cast<float>(time_of_day.seconds().count())
	};
}