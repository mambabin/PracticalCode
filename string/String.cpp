#include "String.h"
#include "string.h"
#include "iostream"
#include "algorithm"
using namespace std;

String::String()
:str_(new char[1])
{
	*str_ = '\0';
}

String::String(const char *s)
:str_(new char[strlen(s) + 1])
{
	::strcpy(str_, s);
}

String::String(const String &s)
:str_(new char[s.size() + 1])
{
	::strcpy(str_, s.str_);
}

String::~String()
{
	delete[] str_;
}

String& String::operator=(const String &s)
{
	if(this != &s)
	{
		delete[] str_;
		str_ = new char[s.size() + 1];
		::strcpy(str_, s.str_);
	}

	return *this;
}

String& String::operator=(const char *s)
{
	if(str_ != s)
	{
		delete[] str_;
		str_ = new char[strlen(s) + 1];
		::strcpy(str_, s);
	}

	return *this;
}

void String::debug() const
{
	cout << str_ << endl;
}

String& String::operator+=(const String &s)
{
	char *st = new char[size() + s.size() + 1];
	::strcpy(st, str_);
	::strcat(st, s.str_);

	delete[] str_;
	str_ = st;

	return *this;
}

String& String::operator+=(const char *s)
{
	char *st = new char[size() + strlen(s) + 1];
	::strcpy(st, str_);
	::strcat(st, s);

	delete[] str_;
	str_ = st;

	return *this;
}

String operator+(const String &s1, const String &s2)
{
	String st(s1);
	st += s2;

	return st;
}

String operator+(const String &s1, const char *s2)
{
    return s1 + String(s2);
}

String operator+(const char *s1, const String &s2)
{
    return String(s1) + s2;
}


bool operator<  (const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) < 0;
}

bool operator<= (const String &s1, const String &s2)
{
    //s1 <= s2 -> !(s1 > s2)
    return !(s1 > s2);
}

bool operator>  (const String &s1, const String &s2)
{
    //s1 > s2 -> s2 < s1;
    return s2 < s1;
}

bool operator>= (const String &s1, const String &s2)
{
    return !(s1 < s2);
}

bool operator== (const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) == 0;
}

bool operator!= (const String &s1, const String &s2)
{
    return !(s1 == s2);
}

char& String::operator[](size_t index)
{
	return str_[index];
}
char String::operator[](size_t index) const
{
	return str_[index];
}

void String::swap(String &other)
{
	std::swap(str_, other.str_);
}
