#include "io/io.hpp"
#include <fstream>
#include <iostream>
#include <stack> //LIFO (Last In, First Out)
using namespace std;

namespace io {
	void readTextFile(const string &filename){
		ifstream f_in(filename);
		char symbol = '\0';
		if (f_in.is_open()){
			while (f_in.get(symbol)){
				cout<<symbol;
			}
			cout<<endl;
		}
		else{
			cout<< "Error al leer " << filename << endl;
		}
		f_in.close();

	}
	
	string removeSpace(const string& filename){
		ifstream f_in(filename);
		string no_space;
		if (f_in.is_open()){
			string token;
			while(f_in >> token){
				no_space += token;
			}
		}
		return no_space;
	}
	
	void verifyHTML(const string &text, string name){
		ofstream myText;
		myText.open(name+".log", ios::app);
		stack <string> pila;
		int error = 0;
		int count_tags= 0;
		int stop = 1;

		for (size_t i = 0; i < text.size(); i++){
		const auto* character = &text.at(i);
			if(*character == '<'){
				string op_tag;
				string clo_tag;

				if (*(character + 1) != '/'){
					i++;
					character++;

					while(*character != '>'){
						op_tag += *character;
						i++;
						character++;
					}
					pila.push(op_tag);
					count_tags++;
					}
				else{
					string tag = pila.top();
					if (*(character + 1) == '/'){
						i++;
						character+=2;
						while(*character != '>'){
							clo_tag += *character;
							i++;
							character++;
						}
					}
					if (tag != clo_tag){
						myText<<"En la línea "<<count_tags<<endl;
						myText <<"Se esperaba"<<" </"+tag+"> en lugar de un </"+clo_tag+"> "<<endl;
						error++;
						stop = 0;
						break;
						}
					if (tag == clo_tag) {
						myText<< "tag <"<<tag<<"> ok"<<endl;
						pila.pop();
					}
				}
			}
		}
		
		if (!pila.empty() && stop == 1){
			myText<<"En la linea "<<count_tags<<endl;
			myText<<"<"+pila.top()+">"<<" no tiene un closing tag"<<endl;
			error++;
		}
		
		if (error==0){
		myText<<error<<" errores"<<endl;
		}
		myText.close();
	}
}


