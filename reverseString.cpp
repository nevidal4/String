#include "ReverseString.h"
#include <iostream>
#include <fstream>
using namespace std;
ReverseString::ReverseString() {
}
ReverseString::ReverseString(const ReverseString& s) : String(s) {
}
ReverseString::ReverseString(const char* s) : String(s) {
}
ReverseString& ReverseString::operator=(const ReverseString& s) {
	(String&)*this = s;
	return *this;
}
ReverseString ReverseString::operator~() {
	ReverseString s(*this);
	char temp;
	for (int i = 0,j = length - 1; i < length / 2; ++i, --j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	s[length] = '\0';
	return s;
}