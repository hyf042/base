#include <iostream>
#include <vector>
#include "Base/Base.h"
using namespace std;
using namespace Base;

using namespace Base::Math;

int main(void)
{
	string a = "hyf hahahahaha yeah";
	Raw data = a;
	uint8 list[] = {89,95,22,0,103,227,146,36,15,208,92,45,13,3,196,11,26,159,28,10,35,239,4,12,60,192,191,111,48,215,39,99,30,176,156,0,6,212,247,120,32,120,92,21};
	data = list;
	//for(int i = 0; i < data.size(); i++)
	//	cout << data[i] << endl;
	//cout << "--------------------------------------------" << endl;
	//data = Codec::RFA::instance().encode(data);
	//for(int i = 0; i < data.size(); i++)
	//	cout << uint32(data[i]) << ",";
	//cout << endl;
	//cout << "--------------------------------------------" << endl;
	data = Codec::RFA::instance().decode(data);
	for(int i = 0; i < data.size(); i++)
		cout << data[i] << endl;
	return 0;
}