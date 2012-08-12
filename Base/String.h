/****************************************************
 *  String.h
 *
 *  Created by tempbuffer on 8/12/12.
 *  Copyright 2012 tempbuffer. All rights reserved.
 *
 *  A String that combine ansi and unicode
 ****************************************************/

#ifndef _BASE_STRING_H_
#define _BASE_STRING_H_

#include "Type.h"
#include "Exception.h"
#include "StringConv.h"

#include <vector>

namespace Base
{
	class String;
	typedef std::vector<String> Strings;
	
	class String
	{
		base_wstring mContent;
	public:
		typedef int32 IndexVar;
		static const IndexVar npos;

		String() {}
		String(const char *s, bool isUtf8 = false) {
			mContent = isUtf8?utf82ws(s):s2ws(s);}
		String(const wchar *s):mContent(s) {}
		String(const base_string &s, bool isUtf8 = false) {
			mContent = isUtf8?utf82ws(s):s2ws(s);
		}
		String(const base_wstring &ws):mContent(ws) {}
		String(char c) {
			base_string s; 
			s += c;
			mContent = s2ws(s);
		}
		String(wchar c) {
			mContent += c;
		}
		String(int32 value) {*this=itos(value);}
		String(double value, size_t precise = 6) {*this=rtos(value,precise);}
		String(bool value) {mContent=value?L"true":L"false";}
		~String() {}

		String substr(IndexVar index, IndexVar len) const{
			if(index<0||len<=0||index+len>size())
				return L"";
			return mContent.substr(index,len);
		}
		IndexVar find(const String &sub, IndexVar off = 0) const{
			return mContent.find(sub.mContent,off);
		}
		IndexVar rfind(const String &sub, IndexVar off = 0) const{
			return mContent.rfind(sub.mContent,off);
		}
		String lower() const;
		String upper() const;
		String reverse() const;
		Strings split(Strings tokens=Strings()) const;
		String strip(Strings tokens=Strings()) const;

		size_t size() const{return mContent.size();}
		void resize(size_t size, wchar newChar) {mContent.resize(size,newChar);}
		wchar getWChar(IndexVar index) const{return mContent[index];}
		char getChar(IndexVar index) const{
			return static_cast<char>(getWChar(index)&0xff);
		}

		//operator
		wchar operator[](IndexVar index) {return getWChar(index);}
		IndexVar operator()(const String& sub, IndexVar off = 0, bool isReverse = false) {
			if(isReverse)
				return rfind(sub,off);
			else
				return find(sub,off);
		}
		char operator()(IndexVar index) {return getChar(index);}
		String operator()(IndexVar l, IndexVar r) {
			return mContent.substr(l,r<0?size()-l:r-l);
		}
		String& operator+=(const String& other) {
			mContent+=other.mContent; 
			return*this;
		}
		String& operator*=(uint32 size) {
			base_wstring origin = mContent;
			for(uint32 i = 0; i < size; i++)
				mContent += origin;
		}
		friend String operator+(const String &a, const String &b) {return a.mContent+b.mContent;}
		friend bool operator<(const String &a, const String &b) {return a.mContent<b.mContent;}
		friend bool operator>(const String &a, const String &b) {return a.mContent>b.mContent;}
		friend bool operator<=(const String &a, const String &b) {return a.mContent<=b.mContent;}
		friend bool operator>=(const String &a, const String &b) {return a.mContent>=b.mContent;}
		friend bool operator==(const String &a, const String &b) {return a.mContent==b.mContent;}
		friend String operator*(const String &a, uint32 b) {
			String ret = a;
			ret *= b;
			return ret;
		}

		//utility funcs
		bool isInt() const;
		bool isReal() const;
		bool isNumber() const {return isReal()|isInt();}
		int32 asInt() const {return stoi(*this);}
		double asReal() const {return stor(*this);}
		base_string asAnsi() const{return ws2s(mContent);}
		base_string asUTF8() const{return ws2utf8(mContent);}
		base_wstring asUnicode() const{return mContent;}
		const char* c_str() const{static base_string tmp; tmp = ws2s(mContent); return tmp.c_str();}
		const wchar* c_wstr() const{return mContent.c_str();}
		static String itos(int value);
		static int stoi(const String &s);
		static String rtos(double value, size_t precise = 6);
		static double stor(const String &s);
		static String format(const char* fmt, ...);
	};
}

#endif