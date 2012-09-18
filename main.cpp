#include <iostream>
#include <vector>
#include "Base/Base.h"
using namespace std;

Base::String haha(int haha, int hehe) {
	for(int i = 0; i < 100; i++)
		cout << haha*hehe << endl;
	return "hehe";
}

int main(void)
{
	Base::Thread<Base::String(int,int)> test = haha;
	Base::Thread<Base::String(int,int)> test2 = haha;
	test(1,2);
	test2(5,10);
	while(test||test2);
	return 0;
}