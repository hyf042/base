/****************************************************
 *  Common.h
 *
 *  Created by tempbuffer on 7/31/12.
 *  Copyright 2012 tempbuffer. All rights reserved.
 *
 *  A common header to include
 ****************************************************/

#ifndef _BASE_COMMON_
#define _BASE_COMMON_

#include "Type.h"
#include "Exception.h"

#include <cstdarg>
#include <cstdio>
#include <cassert>

namespace Base
{
	//safe delete ptr
	template<typename T>
	void DeletePtr(const T* ptr){
		if(ptr) {
			delete ptr;
			ptr = 0;
		}
	}

	//safe delete stl pair
	template<typename T1, typename T2>
	void DeleteSTLPairPtr(const std::pair<T1, T2>& ptr) {
		if(ptr.second) {
			delete ptr.second;
			ptr.second = 0;
		}
	}

	static base_string FormatString(const char* format, ...)
	{
		va_list arg;
		char buffer[1024] = {0};

		va_start(arg, format);
		vsprintf(buffer, format, arg);
		va_end(arg);

		return base_string(buffer);
	}

	#define base_assert assert
}

#endif