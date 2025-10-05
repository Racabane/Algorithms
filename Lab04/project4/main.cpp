#include <iostream>
#include <stack>

std::string addnumbers(std::string str1, std::string str2){
	std::stack<int> str1stack;
	std::stack<int> str2stack;
	std::stack<int> addedstack;

	int count1 = 0;
	int count2 = 0;
	for(char c: str1){
		str1stack.push(c - '0');
	}
	for(char c: str2){
		str2stack.push(c - '0');
	}

	int carry = 0;
	while(!str1stack.empty() && !str2stack.empty()){
		int num = str1stack.top() + str2stack.top() + carry;
		str1stack.pop();
		str2stack.pop();
		int rem = num % 10;
		carry = (num - rem) / 10;
		addedstack.push(rem);
	}
	while(!str1stack.empty()){
		int num = str1stack.top() + carry;
		str1stack.pop();
		addedstack.push(num % 10);
		carry = num / 10;
	}
	while(!str2stack.empty()){
		int num = str2stack.top() + carry;
		str2stack.pop();
		addedstack.push(num % 10);
		carry = num / 10;
	}
	if(carry != 0){
		addedstack.push(carry);
	}
	

	std::string addednumber;
	while(!addedstack.empty()){
		addednumber += std::to_string(addedstack.top());
		addedstack.pop();
	}
	return addednumber;
}

std::string TimesNumbers(std::string one, std::string two){
	std::stack<int> stackone, stacktwo, resultStack;
	std::string array[two.size()];
	std::string result;
	int shift = 0;
	for(char c: one){
			stackone.push(c - '0');
	}
	for(char c: two){
			stacktwo.push(c - '0');
	}
	for(int i = 0; i < two.size(); i++){
		int carry = 0;
		while(!stackone.empty()){
			int product = stackone.top() * stacktwo.top() + carry;
			stackone.pop();
			carry = product / 10;
			int digit = product % 10;
			result = (std::to_string(digit)) + result;
		}
		result = (std::to_string(carry)) + result;
		for(int k = 0; k < shift; k++){
			result = result + "0";
		}
		for(char c: one){
			stackone.push(c - '0');
		}
		shift++;
		stacktwo.pop();
		array[i] = result;
		result = "";
	}
	
	for(int j = 0; j < two.size(); j++){
		result = addnumbers(result, array[j]);
	}
	return result;
}

int main(){
	srand(time(0));
	std::string array[2];
	for(int i = 0; i < 2; i++){
		long long num = (((rand() % 7) + 1) * 1000000000000000) + (((rand() % 8) + 1) * 100000000000000) + (((rand() % 8) + 1) * 10000000000000)
		+ (((rand() % 8) + 1) * 1000000000000) + (((rand() % 8) + 1) * 100000000000) + (((rand() % 8) + 1) * 10000000000) + (((rand() % 8) + 1) * 1000000000) 
		+ (((rand() % 8) + 1) * 100000000) + (((rand() % 8) + 1) * 10000000) + (((rand() % 8) + 1) * 1000000) + (((rand() % 8) + 1) * 100000)
		+ (((rand() % 8) + 1) * 10000) + (((rand() % 8) + 1) * 1000) + (((rand() % 8) + 1) * 100) + (((rand() % 8) + 1) * 10) + (((rand() % 8) + 1) * 1)
		+ 1000000000000000;
		array[i] = std::to_string(num);
	}


	std::cout << "Num1= " << array[0] << std::endl;
	std::cout << "Num2= " << array[1] << std::endl;
	array[1] = TimesNumbers(array[0], array[1]);
	std::cout << "Product= " << array[1] << "\n" << std::endl;
}