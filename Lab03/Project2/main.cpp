#include <iostream>
#include <fstream>

class node{
	public:
		std::string line;
		node *next;
		node(){

		}
};


class list{
	public:
		list();
		void input(std::string in);
		void listingLines(int num1 = -1, int num2 = -1);
		void deleteLines(int num1 = -1, int num2 = -1);
		void insertLines(int num1 = -1);
		void appendLines();
		void enterLine(std::string line);
		void loadfile(list& commandline, std::string filename);
		void saveToFile(std::string filename);
		int getCurrentLine();
	private:
		node *head;
		node *tail;
		int current = 1;
};


list::list(){
	
}

int list::getCurrentLine(){
	return current;
}
void list::saveToFile(std::string filename){
	std::ofstream outfile;
	outfile.open(filename);
	node* track = head;
	while(track != nullptr){
		outfile << track->line << std::endl;
		track = track->next;
	}
}
void loadfile(list& commandline, std::string filename){
	std::ifstream infile;
	infile.open(filename);
	std::string line;

	while(!infile.eof()){
		std::getline(infile, line);
		commandline.enterLine(line);
	}
}


void list::input(std::string in){
	if(in.length() == 0){
		enterLine("");
		return;
	}

	char commandType;
	std::string numstr1, numstr2;
	int num1 = -1, num2 = -1;
	int count = 0;
	bool iscommand = false;
	if((in[0] == 'L' || in[0] == 'I' || in[0] == 'D' || in[0] == 'E' || in[0] == 'A')){
		if(in[1] == ' ' || in.length() == 1){
			iscommand = true;
		}
	}

	if(iscommand){
		for(char character: in){
			if(character == ' '){
				count++;
			}
			if(count == 0){
				commandType = character;
			}else if(count == 1){
				numstr1 += character;
			}else{
				numstr2 += character;
			}
		}
		if(numstr1.length() > 0){
			num1 = std::stoi(numstr1);
		}
		if(numstr2.length() > 0){
			num2 = std::stoi(numstr2);
		}
		switch(commandType){
			case 'L': 
				listingLines(num1, num2);
				break;
			case 'D':
				deleteLines(num1, num2);
				break;
			case 'I':
				insertLines(num1);
				break;
			case 'A':
				appendLines();
				break;
			default:
				break;
		}
	}else{
		enterLine(in);
	}
}

void list::enterLine(std::string line){
	node* newline = new node();
	newline->line = line;
	if(head == nullptr){
		head = newline;
		tail = newline;
	}else{
		tail->next = newline;
		tail = newline;
	}
	current++;
}


void list::listingLines(int num1, int num2){
	int linenum = 1;
	for(node* tmp = head; tmp != nullptr; tmp = tmp->next){
		if(num1 == -1 || num2 == -1){
			if(num1 != -1 && num1 != linenum){
				linenum++;
				continue;
			}
			std::cout << linenum << "> " << tmp->line << std::endl;
			linenum++;
		}else{
			if(num1 != -1 && (num1 > linenum || linenum > num2)){
				linenum++;
				continue;
			}
			std::cout << linenum << "> " << tmp->line << std::endl;
			linenum++;
		}
	}
}


void list::deleteLines(int num1, int num2){
	int count = 0;
	int linesToDelete = num2 - num1;
	for(node* ptr = head; ptr != nullptr; ptr = ptr->next){
		if(num1 == -1 && num2 == -1){
			if(count == current - 2){
				node* tmp = ptr->next;
				tail = ptr;
				delete ptr->next;
				ptr->next = nullptr;
				current--;
				break;
			}
		}else if(num2 == -1){
			if(ptr->next->next == nullptr && (num1 == current - 1)){
				delete ptr->next;
				ptr->next = nullptr;
				tail = ptr;
				current--;
				break;
			}
			if(num1 == 1){
				node* temp = head;
				head = ptr->next;
				delete temp;
				current--;
				break;
			}
			if(count == num1 - 2){
				node* tmp = ptr->next->next;
				delete ptr->next;
				ptr->next = tmp;
				current--;
				break;
			}
		}else{
			if(count == num1 - 2){
				while(linesToDelete){
					node* tmp = ptr->next->next;
					delete ptr->next;
					ptr->next = tmp;
					current--;
					linesToDelete--;
				}
				break;
			}
		}
	}
}


void list::appendLines(){
	std::string line;
	std::cout << current << "> ";
	std::getline(std::cin, line);
	if(line[0] == 'E' || line[0] == 'A' || line[0] == 'I' || line[0] == 'L' || line[0] == 'D' ){
		input(line);
	}else{
		enterLine(line);
		appendLines();
	}
}


void list::insertLines(int num1){
	std::string line;
	if(num1 == -1){
		std::cout << current - 1 << "> ";
	}else{
		std::cout << num1 << "> ";
	}
	std::getline(std::cin, line);
	if(line[0] == 'E' || line[0] == 'A' || line[0] == 'I' || line[0] == 'L' || line[0] == 'D' ){
		input(line);
	}else{
		node* newline = new node();
		newline->line = line;
		int i = 0;
		if(num1 == -1){
			for(node* ptr = head; ptr != nullptr; ptr = ptr->next){
				if(ptr->next->next == nullptr){
					node* tmp = ptr->next;
					ptr->next = newline;
					newline->next = tmp;
					tail = newline;
					current++;
					insertLines(num1);
					break;
				}
				i++;
			}
		}else{
			for(node* ptr = head; ptr != nullptr; ptr = ptr->next){
				if(i == num1 - 2){
					node* tmp = ptr->next;
					ptr->next = newline;
					newline->next = tmp;
					if(newline->next == nullptr){
						tail = newline;
					}
					current++;
					insertLines(num1 + 1);
					break;
				}
				i++;
			}
		}
		
	}
}

int main(){
	list commandline;
	std::string typed, filename;
	
	std::cout << "EDIT ";
	std::getline(std::cin, filename);
	// loadfile(commandline, filename);

	while(true){
		std::cout << commandline.getCurrentLine() << "> ";
		std::getline(std::cin, typed);
		if(typed[0] == 'E' && typed.length() < 2){
			commandline.saveToFile(filename);
			return 0;
		}
		commandline.input(typed);
	}
}