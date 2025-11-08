#include <iostream>
#include <vector>

unsigned long int fib(int n, std::vector<unsigned long int>& sub){
	while(n >= sub.size()){
		sub.push_back(0);
	}
	if(n < sub.size() && sub[n] != 0 && n != 0){
		return sub[n];
	}
	if(n == 0){
		sub[n] = 0;
		return 0;
	}
	if(n == 1){
		sub[n] = 1;
		return 1;
	}
	sub[n] = fib(n - 2, sub) + fib(n - 1, sub);
	return sub[n];
}

int main(){
	int count = 0;
	std::vector<unsigned long int> sub;
	unsigned long int array[20] {0};
	int n = 1;
	// std::cout << fib(47 ,sub);

	while(count < 20){
		unsigned long int temp = fib(n, sub);
		// std::cout << temp << ", ";
		if(temp % 2 == 0){
			array[count] = temp;
			// std::cout << array[count] << ", ";
			count++;
		}
		n++;
	}
	std::cout << std::endl;
	unsigned long int total = 0;
	for(int i = 0; i < 20; i ++){
		std::cout << array[i] << ", ";
		total += array[i];
	}
	std::cout << "\nTotal of the sequence " << total << "\n";
}