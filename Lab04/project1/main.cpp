#include <iostream>
#include <stack>
bool delimiterMatching(std::string equation){
	std::stack<char> cstack; 
	bool ignore = false;
	for(int i = 0; i < equation.size(); i++){
		char c = equation[i];
		if(ignore){
			if( equation[i - 1] == '*' && c == '/'){
				ignore = false;
			}
			continue;
		}
		if(c == '(' || c == '{' || c == '['){
			cstack.push(c);
		}else if(c == '/' && equation[i + 1] == '*'){
			ignore = true;
		}else if(c == ')' || c == '}' || c == ']'){
			if(cstack.empty()){
				return false;
			}
			if((cstack.top() != '(' && c == ')') || (cstack.top() != '{' && c == '}') || (cstack.top() != '[' && c == ']')){
				return false;
			}
			cstack.pop();
		}
	}
	if(cstack.empty()){
		return true;
	}
	return false;
}
int main(){
	std::string equation;
	std::cout << "Enter an equation: ";
	getline(std::cin, equation);
	if(delimiterMatching(equation)){
		std::cout << "\nMatching" << std::endl;
	}else{
		std::cout << "\nNot Matching" << std::endl;
	}

}
/**/