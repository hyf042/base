#include <iostream>
#include <vector>
#include "Base/Base.h"
using namespace std;
using namespace Base;

using namespace Base::Math;

void haha(int a, int b)
{
	cout << "haha: " << a+b << endl;
}

int main(void)
{
	Base::Function<void(int,int)> tmp = haha;
	tmp(1,2);
	return 0;
}