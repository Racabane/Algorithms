#include <iostream>
#include <stack>
#include <chrono>


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

std::string Fibonacci(int num){
	std::string temp, first, second;
	first = "0";
	second = "1";
	if(num == 1){
		return "0";
	}
	for(int i = 0; i < num - 2; i++){
		temp = addnumbers(first, second);
		first = second;
		second = temp;
	}
	return second;
}

int main(){
	int num;
	std::cout << "Enter a number between 1 to 100,000: ";
	std::cin >> num;
	if( 1 <= num  && num <= 100000){
		static std::chrono::time_point<std::chrono::high_resolution_clock> start;
		start = std::chrono::high_resolution_clock::now();
		std::cout << "Result: " << Fibonacci(num) << std::endl;
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "Time taken in miliseconds: " << duration << std::endl;
	}

}