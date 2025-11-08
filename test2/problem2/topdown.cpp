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
	if(n == 2){
		sub[n] = 2;
		return 2;
	}
	sub[n] = fib(n - 2, sub) + fib(n - 1, sub);
	return sub[n];
}

int main(){
	std::vector<unsigned long int> sub;
	std::cout << "one ounce " << fib(1, sub) << "\n";
	std::cout << "two ounce " << fib(2, sub) << "\n";
	std::cout << "three ounce " << fib(3, sub) << "\n";
	std::cout << "four ounce " << fib(4, sub) << "\n";
	std::cout << "45 ounce " << fib(45, sub) << "\n";

}