﻿#include <iostream>
#include <vector>
#include "Base/Base.h"
using namespace std;

using namespace Base;

struct A
{
public:
	void haha(int index)
	{
		cout << index << endl;
	}
};

void haha2(int index) {
	cout << index*2 << endl;
}

class haha3
{
public:
	void operator()(int index) {
		cout << index*3 << endl;
	}
};

int main(void)
{
	A a;
	Base::function::Function<void(int)> tmp = Base::function::MakeFunction(&A::haha,&a);
	tmp(5);
	tmp = haha2;
	tmp(5);
	tmp = haha3();
	tmp(5);
	return 0;
}