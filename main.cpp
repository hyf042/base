#include <iostream>
#include <vector>
#include "Base/Base.h"
using namespace std;

using namespace Base::Math;

int main(void)
{
	Vector3 p = Vector3(1,0,0);
	p = p*Matrix::Rotate(pi*0.25f,Vector3(0,0,1));
	cout << p.x << ' ' << p.y << ' ' << p.z << endl;
	return 0;
}