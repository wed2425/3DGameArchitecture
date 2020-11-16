#include "Time.h"
#include <iostream>
Time::Time()
{
	frame = 60;
	count = 0;

	QueryPerformanceFrequency(&frameinfo);
	QueryPerformanceCounter(&prevFrameCounter);

	perFrame = frameinfo.QuadPart / 60;

}

bool Time::IsFixedRendering()
{
	QueryPerformanceCounter(&FrameCounter);
	double timeDistance = FrameCounter.QuadPart - prevFrameCounter.QuadPart;

	if (timeDistance > perFrame)
	{
		prevFrameCounter = FrameCounter;

		count++;
		if (frame == count)
		{
			//std::cout << "1ae" << std::endl;
			count = 0;
		}
		return true;
	}
	//std::cout << "Dis   " << timeDistance << "   FPS   " << 1 / (timeDistance / (double)frameinfo.QuadPart) << std::endl;
	
	return false;
}
