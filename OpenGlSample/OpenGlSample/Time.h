#pragma once
#include <Windows.h>

class Time
{
public:
	static Time* instance()
	{
		static Time instance;
		return &instance;
	}


	bool IsFixedRendering();



private:
	int frame;
	int count;
	double perFrame;
	LARGE_INTEGER frameinfo;
	LARGE_INTEGER prevFrameCounter;
	LARGE_INTEGER FrameCounter;
	Time();

	
};