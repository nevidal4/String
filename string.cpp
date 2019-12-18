#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;
extern ofstream csis;
String::String() {
	length = 0;
	buf = new char[length + 1];
	*buf = '\0';
}
String::String(int i) {
	length = i;
	buf = new char[i + 1];
	*buf = '\0';
}
String::String(const char*s) {
	length = strlen(s);
	buf = new char[length + 1];
	strcpy(buf, s);
	buf[length] = '\0';
}
String::String(char c) {
	length = 1;
	buf = new char[length + 1];
	*buf = c;
	buf[1] = '\0';
}
String::String(const String& s) {
	length = s.length;
	buf = new char[length + 1];
	strcpy(buf, s.buf);
}
String::String(char c, int num) {
	length = num;
	buf = new char[length + 1];
	for (int i = 0; i <= num; ++i)
		buf[i] = c;
	buf[length] = '\0';
}
String::~String() {
	delete[]buf;
}
int String::getLength() {
	return length;
}
void String::print() {
	cout << "\"" << buf << "\"" << " size: " << length << endl;
	csis << "\"" << buf << "\"" << " size: " << length << endl;
}
String String::substr(int i1, int i2) {
	if (i1 < 0) {
		cout << "Error substr low index" << endl;
		csis << "Error substr low index" << endl;
		return *this;
	}
	else if (length < i2) {
		cout << "Error substr high index" << endl;
		csis << "Error substr high index" << endl;
		return *this;
	}
	if (i2 < i1) {
		int temp = i1;
		i1 = i2;
		i2 = temp;
	}
	String s(i2 - i1 + 1);
	String split(*this);
	split[i2 + 1] = '\0';
	strcat(s.buf,&split.buf[i1]);
	return s;

}
String& String::operator=(const String& s) {
	String ss(s);
	delete[]buf;
	length = ss.length;
	buf = new char[ss.length + 1];
	*buf = '\0';
	strcpy(buf, ss.buf);
	return *this;
}
String& String::operator=(const char*s) {
	String ss(s);
	*this = ss;
	return *this;
}
String String::operator+() const {
	String s(*this);
	for (int i = 0; i < s.length; ++i) {
		if (isalpha(s[i]) && islower(s[i]))
			s[i] -= 32;
	}
	return s;
}
String String::operator-() const {
	String s(*this);
	for (int i = 0; i < s.length; ++i) {
		if (isalpha(s[i]) && isupper(s[i]))
			s[i] += 32;
	}
	return s;
}
char& String::operator[](int num)const {
	if (length < num) {
		cout << "Error operator [] upper bound" << endl;
		csis << "Error operator [] upper bound" << endl;
		return buf[length];
	}
	else if (num < 0) {
		cout << "Error operator [] lower bound" << endl;
		csis << "Error operator [] lower bound" << endl;
		return buf[0];
	}
	else
		return buf[num];
}
String& String::operator+=(const String& s) {
	*this = *this + s;
	return *this;
}
String& String::operator+=(const char c) {
	*this = *this + String(c);
	return *this;
}
String operator+(const String& s1, const String& s2) {
	String s3(s1.length + s2.length);
	strcat(s3.buf, s1.buf);
	strcat(s3.buf, s2.buf);
	return s3;
}
String operator+(const String& s1, const char* s2) {
	String ss2(s2);
	String s3(s1 + ss2);
	return s3;
}
String operator+(const char* s1, const String& s2) {
	String ss1(s1);
	String s3(ss1 + s2);
	return s3;
}
String operator+(char c, const String& s2) {
	String s1(c);
	String s3(s1 + s2);
	return s3;
}
String operator+(const String& s1, char c) {
	String s2(c);
	String s3(s1 + s2);
	return s3;
}
ostream& operator<<(ostream& os, const String& s) {
	os << "\"" << s.buf << "\"";
	return os;
}
String& String::operator++() {
	for (int i = 0; i < length; ++i)
		++buf[i];
	return *this;
}
String& String::operator--() {
	for (int i = 0; i < length; ++i)
		--buf[i];
	return *this;
}
String String::operator++(int) {
	String temp(*this);
	for (int i = 0; i < length; ++i)
		++buf[i];
	return temp;
}
String String::operator--(int) {
	String temp(*this);
	for (int i = 0; i < length; ++i)
		--buf[i];
	return temp;
}
char* operator+(const String& s, int num) {
	return &s[num];
}
char* operator+(int num, const String& s) {
	return &s[num];
}
int operator==(const String& s1, const String& s2) {
	if (s1.length != s2.length)
		return 0;
	for (int i = 0; i < s1.length; ++i) {
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}
int operator!=(const String& s1, const String& s2) {
	if (s1 == s2)
		return 0;
	return 1;
}
int operator<(const String& s1, const String& s2) {
	char c1, c2;
	for (int i = 0; i < s1.length && i < s2.length; ++i) {
		c1 = toupper(s1[i]);
		c2 = toupper(s2[i]);
		if (c1 < c2)
			return 0;
		else if (c1 > c2)
			return 1;
	}
	if (s1.length < s2.length)
		return 0;
	return 1;
}
int operator>(const String& s1, const String& s2) {
	if (s1 == s2)
		return 0;
	else if (s1 < s2)
		return 0;
	return 1;
}
int operator<=(const String& s1, const String& s2) {
	if (s1 > s2)
		return 0;
	return 1;
}
int operator>=(const String& s1, const String& s2) {
	if (s1 < s2)
		return 0;
	return 1;
}