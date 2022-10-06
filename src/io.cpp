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
		int Stop = 1;
		int p = 0;
		int error = 0;
		int count_tags=1;
		
		while (p < text.size() && Stop){
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
						if(pila.empty()){
							myText <<"faltan tags para cerrar"<<endl;
							Stop = 0;
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
								myText <<"Se esperaba"<<" </"+tag+">"<<endl;
								error++;
								break;
							}
							if (tag == clo_tag) {
								myText<< "tag <"<<tag<<"> ok"<<endl;
								Stop=0;
							}
							pila.pop();
						}
					}
				}
			}
			p++;
		}
	
		if (pila.size()!=0){
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

