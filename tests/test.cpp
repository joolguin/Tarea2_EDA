#include "io/io.hpp"
using namespace std;



int main(int nargs, char** vargs){
	string name;
	cout<<"ingrese el nombre del HTML"<<endl;
	cin>>name;
	string filename("../data/"+name+".html");
	//io::readTextFile(filename);
	cout<<endl;
	string const text = io::removeSpace(filename);
	io::verifyHTML(text, name);
	

	return 0;
}
