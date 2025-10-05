#include <iostream>
#include <stack>

std::string subnumbers(std::string str1, std::string str2){
	std::stack<int> str1stack;
	std::stack<int> str2stack;
	std::stack<int> addedstack;

	int count1 = 0;
	int count2 = 0;
	if(str1 < str2){
		std::string temp;
		temp = str1;
		str1 = str2;
		str2 = temp;
	}

	for(char c: str1){
		str1stack.push(c - '0');
	}
	for(char c: str2){
		str2stack.push(c - '0');
	}

	int borrow = 0;
	while(!str1stack.empty() && !str2stack.empty()){
		int a = str1stack.top();
		str1stack.pop();
		int b = str2stack.top();
		str2stack.pop();
		a -= borrow;
		if(a < b){
			a += 10;
			borrow = 1;
		}else{
			borrow = 0;
		}
		int num = a - b;
		addedstack.push(num);
		
	}
	while(!str1stack.empty() ){
		int a = str1stack.top();
		str1stack.pop();
		
		a -= borrow;
		if(a < 0){
			a += 1;
			borrow = 1;
		}else{
			borrow = 0;
		}

		addedstack.push(a);
		
	}
	

	std::string addednumber;
	while(!addedstack.empty()){
		addednumber += std::to_string(addedstack.top());
		addedstack.pop();
	}
	while(addednumber[0] == '0'){
		addednumber.erase(0,1);
	}
	return addednumber;
}

int main(){
	srand(time(0));
	std::string array[10];
	for(int i = 0; i < 10; i++){
		long long num = (((rand() % 7) + 1) * 1000000000000000) + (((rand() % 8) + 1) * 100000000000000) + (((rand() % 8) + 1) * 10000000000000)
		+ (((rand() % 8) + 1) * 1000000000000) + (((rand() % 8) + 1) * 100000000000) + (((rand() % 8) + 1) * 10000000000) + (((rand() % 8) + 1) * 1000000000) 
		+ (((rand() % 8) + 1) * 100000000) + (((rand() % 8) + 1) * 10000000) + (((rand() % 8) + 1) * 1000000) + (((rand() % 8) + 1) * 100000)
		+ (((rand() % 8) + 1) * 10000) + (((rand() % 8) + 1) * 1000) + (((rand() % 8) + 1) * 100) + (((rand() % 8) + 1) * 10) + (((rand() % 8) + 1) * 1)
		+ 1000000000000000;
		array[i] = std::to_string(num);
		std::cout << array[i] << std::endl;
	}


	for(int j = 0; j < 9; j++){
		std::cout << "Num1= " << array[j] << std::endl;
		std::cout << "Num2= " << array[j + 1] << std::endl;
		array[j + 1] = subnumbers(array[j], array[j + 1]);
		std::cout << "Sum= " << array[j + 1] << "\n" << std::endl;
	}
}