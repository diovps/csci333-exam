#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		std::cout << "Usage: [FILENAME] [THRESHOLD]" << std::endl;
	}else{
		std::map<std::string,int> totalList;
		std::set<std::string> niceList;
		std::string line;
		std::ifstream myfile(argv[1]);
		int threshold = atoi(argv[2]);
		
		if(myfile.is_open()){
			while(myfile.good()){
				getline(myfile,line);
				if(totalList.count(line)>0){
					totalList[line] = totalList[line]+1;
					if(totalList[line] >= threshold){
						niceList.insert(line);
					}
				}else{
					if(line.size()>0){
						totalList.insert(
					   	    std::pair<std::string,int>							    (line,1));
					}
				}
			}
			myfile.close();
			
			std::map<std::string,int>::iterator tl;
			std::set<std::string>::iterator nl;
			
			std::cout << "------------------------" << std::endl;
			std::cout << "Nice" << std::endl;
			std::cout << "------------------------" << std::endl;

			for(nl = niceList.begin(); nl!=niceList.end();nl++){
				std::cout << *nl << std::endl;
			}
		
			std::cout << "------------------------" << std::endl;
			std::cout << "Naughty" << std::endl;
			std::cout << "------------------------" << std::endl;

			for(tl = totalList.begin(); tl!=totalList.end();tl++){
				if(niceList.count(tl->first)==0){
					std::cout << tl->first << std::endl;
				}
			}
		}
	}	
	return 0;
}
