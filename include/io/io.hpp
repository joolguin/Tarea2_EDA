#ifndef IO_IO_HPP
#define IO_IO_HPP
#include <iostream>
#include <stack>
using namespace std;

namespace io {
	void readTextFile(const string &filename);
	string removeSpace(const string &filename);
	void getClosingTags(const string &text);
	void getOpenTags(const string &text);

	
}

#endif
