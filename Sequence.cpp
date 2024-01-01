//Rytham Dawar
//921313627

#include <iostream>
#include <string>
#include <algorithm>
#include <cstddef>
#include "Sequence.h"
using namespace std;



  Sequence::Sequence(void){}
  Sequence::Sequence(const string& desc_str, const string& seq_str) : desc(desc_str), seq(seq_str){}
  string Sequence::findNextMutation(const Sequence& s, const int& pos) const{
		string output;
		bool test = false;
		for(long unsigned int i = pos - 1; i < seq.length(); i++){
				if(seq[i] != s.seq[i]){
					output = seq[i] + to_string(i + 1) + s.seq[i];
					test = true;
					break;
				}
			}
		if(!test){
			output = "no mutation found";
		}
		return output;
		/*
		string Sequence::findNextMutation(const Sequence& s, const int& pos) const{
				string output;
				//bool test = false;
				int length1 = seq.length();
				for(int i = pos - 1; i < length1; i++){
						if(seq[i] != s.seq[i]){
							output = seq[i] + to_string(pos + 1) + s.seq[i];
							//test = true;
							return output;
							break;
						}
					}
					output = "no mutation found";
				return output;
			}*/
	}
  Sequence findMUM(const Sequence& s1, const Sequence& s2){
		//create substrings from the main string, and each substring must be at least of size 20, and then compare it to the otheer string and see if it has a similar substring.
		long unsigned int x = 20;
		long unsigned int y;
		long unsigned int a; //position 1
		long unsigned int b; //position 2
		string temp;
		string substr;
		long unsigned int compare = 0;
		bool uniq = false;
		for(long unsigned int i = 0; i < s1.seq.length(); i++){
			for(long unsigned int j = x; j <= (s1.seq.length() - i); j++){
				string substr = s1.seq.substr(i, j);
				y = s2.seq.find(s1.seq.substr(i, j));
					if(y != string::npos){
						uniq = true;
						if(substr.length() > compare){
							compare = substr.length();
							temp = substr;
							a = i;
							b = y;
					}
					//find the longest substr, and check for uniqueness --> in S1 because dog can't appear twice
					//inside the statement, MUM = y;
					//outside:
					//set sequences sequence to the mum I found
					//if not found, no MUM found
				}
			}
		}

		if(!uniq){
			return Sequence(">No MUM found", "");
		}
		else{
			return Sequence(">MUM pos1=" + to_string(a+1) + " pos2=" + to_string(b+1), temp);
		}
	}
	istream& operator>>(istream& is, Sequence& s ){
		//while
		//stop at blank space
		//use getline - it has two argumens, reading from (is), and where you want to place it to (s.desc)
		//while not end of file and not end of line
		getline(is, s.desc);
		string temp;
		while(getline(is, temp) && !temp.empty()){
			s.seq += temp;
		}
		s.check();
		return is;
	}
	ostream& operator<<(ostream& os, const Sequence& s ){
		//strlen
		//mod 70 == 0, end line, and start new line; do endl after every seqence and then do new line
		//print two new line at the end;
		//every 70 characters
		//read the input when you hit 70 do endl, then new line, then repeat.
		//output every single charcter in the string, and if (i+1) % 70 == 0, then also output a new line
		if(s.desc == ">No MUM found"){
			os << s.desc << "\n";
			os << "\n";
		}else{
		os << s.desc << endl;
		for(long unsigned int i = 0; i < s.seq.length(); i++){
			os << s.seq[i];
			if(((i+1) % 70 == 0) && (i != s.seq.length() - 1)){
				os << "\n";
 			}
		}
		os << "\n"; //one print one of them for one of them
		os << "\n";
	}
		return os;
	}
	void Sequence::check(void) const{
		//end of file, or something besides A-Z is read
	size_t found = seq.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	if (found != std::string::npos)
  {
    throw runtime_error("invalid character in sequence");
  }
}
