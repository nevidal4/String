#include "CaseString.h"
#include <iostream>
#include <fstream>
using namespace std;
extern ofstream csis;
CaseString::CaseString() {
	upper = new char[length + 1];
	*upper = '\0';
	lower = new char[length + 1];
	*lower = '\0';
}
CaseString::CaseString(const CaseString& s) : String(s) {
	upper = new char[length + 1];
	for (int i = 0; i < length; ++i)
		upper[i] = toupper(buf[i]);
	upper[length] = '\0';
	lower = new char[length + 1];
	for (int i = 0; i < length; ++i)
		lower[i] = tolower(buf[i]);
	lower[length] = '\0';
}
CaseString::CaseString(const char* s) : String(s) {
	upper = new char[length + 1];
	for (int i = 0; i < length; ++i)
		upper[i] = toupper(buf[i]);
	upper[length] = '\0';
	lower = new char[length + 1];
	for (int i = 0; i < length; ++i)
		lower[i] = tolower(buf[i]);
	lower[length] = '\0';
}
CaseString::~CaseString() {
	delete[] upper;
	delete[] lower;
}
void CaseString::print() {
	this->String::print();
	cout << "\"" << upper << "\"" << endl;
	cout << "\"" << lower << "\"" << endl;
	csis << "\"" << upper << "\"" << endl;
	csis << "\"" << lower << "\"" << endl;
}
CaseString& CaseString::operator=(const CaseString& s) {
	(String&)*this = s;
	delete[]upper;
	upper = new char[s.length + 1];
	*upper = '\0';
	strcpy(upper, s.upper);
	delete[]lower;
	lower = new char[s.length + 1];
	*lower = '\0';
	strcpy(lower, s.lower);
	return *this;
}