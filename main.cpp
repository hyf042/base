#include <iostream>
#include <vector>
#include "Base/Logger.h"
#include "Base/Io/Path.h"
using namespace std;

using namespace Base;

int main(void)
{
	Path::SetCurrentPath("D:/");
	Path tmp = Path::CombinePath("haha\\","/nihao/hehe");
	cout << Path::CheckHasEntension(Path::GetFullPath(tmp)) << endl;
	return 0;
}