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

	void getClosingTags(const string &text){
		
		stack<string> closing_tags;

		for (size_t i = 0; i < text.size(); i++){
			const auto* character = &text.at(i);
			
			if(*character == '<'){
				string cur_tag;

				if (*(character + 1) == '/'){
					//i++;
					character++;
					while(*character != '>'){
						cur_tag += *character;
						i++;
						character++;
						}
					closing_tags.push(cur_tag);
				}
			}
		}
		while(!closing_tags.empty()){
			cout<<closing_tags.top()<<endl;
			closing_tags.pop();}
	}

	void getOpenTags(const string &text){
		stack<string> opening_tags;
		for (size_t i = 0; i < text.size(); i++){
			const auto* character = &text.at(i);
			
			if(*character == '<'){
				string cur_tag;

				if (*(character + 1) != '/'){
					i++;
					character++;

					while(*character != '>'){
						cur_tag += *character;
						i++;
						character++;
					}
					opening_tags.push(cur_tag);
				}
			}
		}
		while(!opening_tags.empty()){
			cout<<opening_tags.top()<<endl;
			opening_tags.pop();
		}
		cout<<endl;

	}
}
