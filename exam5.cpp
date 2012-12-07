#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

std::vector<std::string> split(std::string line){
	
	std::vector<std::string> words;
	
	for(int i = 0; i < (int)line.size(); i++){
		int index = line.find(' ',i);
		int rindex = line.rfind(' ');
		
		words.push_back(line.substr(i,index-i));
		i = index;
		
		if(index == rindex){
			words.push_back(line.substr
				(rindex+1,rindex-line.size()));
			break;
		}
	}
	return words;
}

int main(int argc, char* argv[]){
	
	if(argc!=3){
		std::cout << "Usage: [Input File] [Output File]" << std::endl;
	}else{
		std::map<std::string,int> wordList;
		std::string line;
		std::fstream myfile(argv[1]);
		
		if(myfile.is_open()){
			while(myfile.good()){
				getline(myfile,line);
				std::vector<std::string> words = split(line);
				for(int i = 0; i < (int)words.size(); i++){
					std::string word = words[i];
					if(wordList.count(word)>0){
					    wordList[word] = wordList[word]+1;
					}else{
					    if(word.size()>0){
					        wordList.insert(std::pair<std::string,int>(word,1));
					    }
					}
				}
			}	
			myfile.close();
		}
		
		std::multimap<int,std::string> reverseMap;

		std::map<std::string,int>::iterator it;
		std::multimap<int, std::string>::reverse_iterator it2;

		
		int wordCount = 0;

		for(it = wordList.begin(); it!=wordList.end(); it++){
			reverseMap.insert(std::pair<int,std::string>
			   (it->second,it->first));
			wordCount+=it->second;
		}
		
		std::ofstream outfile(argv[2]);
		
		if(outfile.is_open()){
		  outfile << "Unique Words: " << wordList.size() << "\n";
		  outfile << "Lexical Diversity: " << 
			wordCount/(wordList.size()+0.0) << "\n";
		  

		  for(it2 = reverseMap.rbegin(); it2!=reverseMap.rend(); it2++){
			 outfile << it2->second<<" "<<it2->first << "\n";
		  }

		  outfile.close();
		}

	}
		
	return 0;
}
