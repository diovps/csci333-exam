#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string line){
	
	std::vector<std::string> words;
	for(int i = 0; i < line.size(); i++){
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

int main(){

	std::string line = "Hello my baby hello my darling";
	std::vector<std::string> words = split(line);
	
	for(int i = 0; i < words.size(); i++){
		std::cout << words[i] << std::endl;
	}
	return 0;
}
