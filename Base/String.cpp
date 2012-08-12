/****************************************************
 *  String.cpp
 *
 *  Created by tempbuffer on 8/12/12.
 *  Copyright 2012 tempbuffer. All rights reserved.
 *
 *  A String that combine ansi and unicode
 ****************************************************/

#include "String.h"

#include <cmath>

namespace Base
{
	const String::IndexVar String::npos = std::string::npos;

	String String::lower() const
	{
		base_wstring ret;
		for(size_t index = 0; index < mContent.size(); index++)
			if(mContent[index]>=L'A'&&mContent[index]<='z')
				ret += mContent[index]+(L'a'-L'A');
			else
				ret += mContent[index];
		return ret;
	}
	String String::upper() const
	{
		base_wstring ret;
		for(size_t index = 0; index < mContent.size(); index++)
			if(mContent[index]>=L'a'&&mContent[index]<='z')
				ret += mContent[index]+(L'A'-L'a');
			else
				ret += mContent[index];
		return ret;
	}
	String String::reverse() const
	{
		base_wstring ret;
		for(size_t index = 0; index < mContent.size(); index++)
			ret.push_back(mContent[size()-index-1]);
		return ret;
	}
	Strings String::split(Strings tokens) const
	{
		if(tokens.empty())
			tokens.push_back(L" ");

		Strings ans;
		base_wstring nowS;
		IndexVar index = 0;
		while(index<mContent.size())
		{
			bool flag = false;
			for(Strings::iterator ptr = tokens.begin(); ptr != tokens.end(); ptr++)
				if(find(*ptr,index)==index)
				{
					flag = true;
					ans.push_back(nowS);
					nowS = L"";
					break;
				}
			if(!flag)
				nowS += mContent[index];
			index++;
		}
		ans.push_back(nowS);

		return ans;
	}
	String String::strip(Strings tokens) const
	{
		if(tokens.empty())
			tokens.push_back(L" ");

		IndexVar left = 0, right = mContent.size();
		while(left<mContent.size())
		{
			bool flag = false;
			for(Strings::iterator ptr = tokens.begin(); ptr != tokens.end(); ptr++)
				if(find(*ptr,left)==left)
				{
					flag = true;
					break;
				}
			if(!flag)
				break;
			left++;
		}
		while(right>=0)
		{
			bool flag = false;
			for(Strings::iterator ptr = tokens.begin(); ptr != tokens.end(); ptr++)
				if(rfind(*ptr,size()-right)==size()-right)
				{
					flag = true;
					break;
				}
			if(!flag)
				break;
			right--;
		}
		return substr(left,right-left);
	}

	//utility funcs
	bool String::isInt() const
	{
		IndexVar index = (mContent[0]==L'-')?1:0;
		while(index<mContent.size())
		{
			if(mContent[index]<L'0'||mContent[index]>L'9')
				return false;
			index++;
		}
		return true;
	}
	bool String::isReal() const
	{
		IndexVar index = (mContent[0]==L'-')?1:0;
		bool hasDot = false;
		while(index<mContent.size())
		{
			if(mContent[index]==L'.')
			{
				if(!hasDot)
					hasDot = true;
				else
					return false;
			}
			else if(mContent[index]<L'0'||mContent[index]>L'9')
				return false;
			index++;
		}

		return true;
	}
	String String::itos(int value)
	{
		bool minus = false;
		base_wstring s;
		if(value<0)
			minus = true, value = -value;
		if(value==0) s += L'0';
		while(value)
		{
			s += L'0'+value%10;
			value /= 10;
		}

		return (minus?L"-":L"")+String(s).reverse();
	}
	int String::stoi(const String &s)
	{
		if(!s.isInt())
			BASE_THROW_EXCEPTION(s.asAnsi()+"is not an interger");
		String absValue = s;
		bool minus = false;
		int32 value = 0;

		if(s.mContent[0]==L'-')
			minus = true, absValue = s.substr(1,s.size()-1);
		for(IndexVar index = 0; index < absValue.size(); index++)
			value = value*10+absValue[index]-L'0';

		return (minus?-1:1)*value;
	}
	String String::rtos(double value, size_t precise)
	{
		String ans = itos(int32(value));
		value -= floor(value);
		wchar tmp;

		if(precise>0)
			ans += L'.';

		for(size_t i = 0; i < precise; i++)
		{
			value *= 10;
			tmp = static_cast<wchar>(floor(value));
			ans += static_cast<wchar>(L'0'+tmp);
			value -= tmp;
		}

		return ans;
	}
	double String::stor(const String &s)
	{
		if(!s.isReal())
			BASE_THROW_EXCEPTION(s.asAnsi()+"is not an real");
		bool minus = false;
		double value = 0, tmp = 1;
		size_t index = 0;

		if(s.mContent[0]==L'-') minus = true, index++;
		
		while(s.mContent[index]!=L'.'&&index<s.mContent.size())
			value = value*10+s.mContent[index++]-L'0';
		index++;
		while(index<s.mContent.size())
			tmp *= 0.1, value += (s.mContent[index++]-L'0')*tmp;

		return (minus?-1:1)*value;
	}
	String String::format(const char* fmt, ...)
	{
		va_list arg;
		char buffer[1024] = {0};

		va_start(arg, fmt);
		vsprintf(buffer, fmt, arg);
		va_end(arg);

		return String(buffer);
	}
}