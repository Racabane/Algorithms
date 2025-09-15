#include <iostream>

int main(){
	srand(time(0));
	long num;
	long array[20];
	for(int i = 0; i < 20; i++){
		num = 0;
		num = ((rand() % 9 + 1) * 100000) + ((rand() % 10) * 10000) + ((rand() % 10) * 1000) 
		+ ((rand() % 10) * 100) + ((rand() % 10) * 10) + (rand() % 10);
		array[i] = num;

	}

	for(int i = 0; i < 20; i++ ){
		int count = 0;
		int checks = 0;
		num = array[i];
		std::cout << num << ": ";
		for(int i = 2; i < num; i++){
			checks++;
			if(num % i == 0){
				count++;
				break;
			}
		}
		if(count){
			std::cout << "Not a prime number" << ", number of tests: " << checks << std::endl;
		}else{
			std::cout << "is a prime number" << ", number of tests: " << checks << std::endl;
		}
	}

}