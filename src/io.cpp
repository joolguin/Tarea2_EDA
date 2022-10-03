#include "io/io.hpp"
#include <fstream>
#include <iostream>
#include <unordered_set>
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
	
	void getTags(const string& filename){
		ifstream f_in(filename);
		string no_space;
		if (f_in.is_open()){
			string token;
			while(f_in >> token){
				no_space += token;
			}
		}
		stack<string> opening_tags, closing_tags;
		bool tagopen;
		
		for (size_t i = 0; i < no_space.size(); i++){
			const auto* character =&no_space.at(i);
			if(*character == '<'){
				string cur_tag;

				if (*(character + 1) == '/'){
					tagopen = false;
					i++;
					character++;
				}
				else tagopen = true;{
				
				i++;
				character++;}
				
				while(*character != '>'){
					cur_tag += *character;
					i++;
					character++;
					
				}
				if (tagopen){
					opening_tags.push(cur_tag);
				}
				else if(!tagopen){
					closing_tags.push(cur_tag);
				}
			}
		}

		while(!opening_tags.empty()){
			cout<<opening_tags.top()<<endl;
			opening_tags.pop();
		}
		cout<<endl;
		while(!closing_tags.empty()){
			cout<<closing_tags.top()<<endl;
			closing_tags.pop();
		}
		/*
			string tag;
			int pos = 0;
			getline (cin,tag);
			int ts = tag.find("<",pos);
			while (ts!=string::npos){
				int te = tag.find(">", ts+1);
				cout<<tag.substr(ts, te-ts+1);
				pos = te + 1;
				ts = tag.find("<",pos);
			}
		*/
	}
}
