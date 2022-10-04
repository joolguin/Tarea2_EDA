#include "io/io.hpp"
using namespace std;

int main(int nargs, char** vargs){
	string filename("../data/ej1.html");
	//io::readTextFile(filename);
	string const text = io::removeSpace(filename);
	io::getOpenTags(text);
	io::getClosingTags(text);
	return 0;
}
