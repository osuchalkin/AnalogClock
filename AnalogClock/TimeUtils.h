#pragma once

struct TimeData { float h, m, s; };

class TimeUtils
{
public:
	static TimeData getCurrentTime();
};

