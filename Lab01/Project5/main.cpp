#include <iostream>
#include <fstream>
#include <vector>
void swap(std::streampos &first, std::streampos &second){
	std::streampos tmp;
	tmp = first;
	first = second;
	second = tmp;
}

int main(){
	std::ifstream infile;
	infile.open("data.txt");
	std::vector<std::streampos> filepos; 
	std::string record, record2;
	char firstletter;

	while(!infile.eof()){
		//gets the postion and stores it then moves to next record
		infile >> firstletter;
		filepos.push_back(infile.tellg());
		infile >> record;
	}
	std::cout << "storing before sorting: ";
	for(int i = 0; i < filepos.size(); i++){
		std::cout << filepos[i] << " ";
	}
	std::cout << std::endl;

	for(int j = 0; j < filepos.size() - 1; j++){
		for(int k = j + 1; k < filepos.size(); k++){
			infile.seekg(filepos[j] - static_cast<std::streampos>(1) );
			infile >> record;
			infile.seekg(filepos[k] - static_cast<std::streampos>(1));
			infile >> record2;
			if(record > record2){
				swap(filepos[j], filepos[k]);
			}
		}
	}


	std::cout << "storing after sorting: ";
	for(int i = 0; i < filepos.size(); i++){
		std::cout << filepos[i] << " ";
	}
	std::cout << std::endl;


	std::cout << "List of words: ";
	for(int i = 0; i < filepos.size(); i++){
		infile.seekg(filepos[i] - static_cast<std::streampos>(1));
		infile >> record;
		std::cout << record << " ";
	}
	std::cout << std::endl;

	return 0;
}