#include <iostream>
#include "Base/Logger.h"
#include "Base/Timer.h"
#include "Base/Thread/Queue.h"
#include "Base/String.h"
using namespace std;

// Global Logger

//typedef Base::Singleton<Base::Logger> LOGGER;

int main(void)
{
	Base::String s1="123",s2=L"321";
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	s1 += L"123", s2 += "123";
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	Base::Logger::instance().log(L"haha");
	//LOGGER::instance().log("haha");
	return 0;
}