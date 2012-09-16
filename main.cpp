#include <iostream>
#include <vector>
#include "Base/Logger.h"
#include "Base/Io/Path.h"
#include "Base/sys/Sys.h"
using namespace std;

using namespace Base;

int main(void)
{
	Path path("Base/");
	std::vector<Base::Path> files = path.enumFolder(true);
	for(int i = 0; i < files.size(); i++)
		cout << files[i].str() << endl;
	
	return 0;
}