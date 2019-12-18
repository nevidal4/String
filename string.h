#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String {
protected:
	int length;
	char*buf;
public:
	String();
	String(int i);
	String(const char* s);
	String(char c);
	String(const String& s);
	String(char c, int num);
	~String();
	int getLength();
	void print();
	String substr(int i1, int i2);
	String& operator=(const String& s);
	String& operator=(const char* s);
	char& operator[](int num) const;
	String operator+() const;
	String operator-() const;
	String& operator++();
	String& operator--();
	String operator++(int);
	String operator--(int);
	String& operator+=(const String& s);
	String& operator+=(const char c);
	friend ostream& operator<<(ostream& os, const String& s);
	friend String operator+(const String& s1, const String& s2);
	friend String operator+(const String& s1, const char* s2);
	friend String operator+(const char* s1, const String& s2);
	friend String operator+(const String& s1, const char c);
	friend String operator+(const char c, const String& s2);
	friend char*operator+(const String& s, int num);
	friend char*operator+(int num, const String& s);
	friend int operator==(const String& s1, const String& s2);
	friend int operator!=(const String& s1, const String& s2);
	friend int operator<(const String& s1, const String& s2);
	friend int operator<=(const String& s1, const String& s2);
	friend int operator>(const String& s1, const String& s2);
	friend int operator>=(const String& s1, const String& s2);
	int main(void);
};
#endif
