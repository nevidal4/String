#ifndef CASESTRING_H
#define CASESTRING_H
#include <iostream>
#include "string.h"
using namespace std;
class CaseString : public String {
private:
	char* upper;
	char* lower;
public:
	CaseString();
	CaseString(const CaseString& s);
	CaseString(const char* s);
	~CaseString();
	CaseString& operator=(const CaseString& s);
	void print();
};
#endif