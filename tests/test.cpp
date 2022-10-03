#include "io/io.hpp"
using namespace std;

int main(int nargs, char** vargs){
	string filename("../data/ej1.html");
	//io::readTextFile(filename);
	io::getTags(filename);
	return 0;
}
