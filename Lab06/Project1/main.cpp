#include <iostream>
#include <vector>

int DPRecursiveFib(int n, std::vector<int>& calculated){
	if(n < 0){
		std::cout << "Not a valid n value must be n >= 0";
	}
	while(n >= calculated.size()){
		calculated.push_back(-1);
	}
	if(n < calculated.size() && calculated[n] != -1){
		return calculated[n];
	}
	

	if(n == 0){
		calculated[n] = 0;
		return calculated[n];
	}
	if(n == 1){
		calculated[n] = 1;
		return calculated[n];
	}
	if(n == 2){
		calculated[n] = 2;
		return calculated[n];
	}
	calculated[n] = DPRecursiveFib(n - 1, calculated) + DPRecursiveFib(n - 2, calculated) + DPRecursiveFib(n - 3, calculated);
	return calculated[n];
}

int main(){
	int x;
	std::vector<int> calculated;
	std::cout << "Enter in a Value for N: ";
	std::cin >> x;
	std::cout << "The Fibonacci variant given " << x << " is " << DPRecursiveFib(x, calculated) << "\n";

}
