#include <iostream>
#include "Base/Logger.h"
#include "Base/Timer.h"
using namespace std;

// Global Logger

//typedef Base::Singleton<Base::Logger> LOGGER;

int main(void)
{
	Base::TimeUtil::mSleep(1000);
	BASE_LOGGER.log("haha");
	Base::TimeUtil::mSleep(1000);
	BASE_LOGGER.log("hehe");
	//LOGGER::instance().log("haha");
	return 0;
}