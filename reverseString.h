#ifndef REVERSESTRING_H
#define REVERSESTRING_H
#include "string.h"
#include <iostream>
using namespace std;
class ReverseString : public String {
public:
	ReverseString();
	ReverseString(const ReverseString& s);
	ReverseString(const char* s);
	ReverseString& operator=(const ReverseString& s);
	ReverseString operator~();
};
#endif