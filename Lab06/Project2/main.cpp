#include <iostream>
#include <vector>

int DPButtomFib(int n){
	if(n < 0){
		std::cout << "Not a valid n value must be n >= 0";
	}
	std::vector<int> calculated(n);
	calculated[0] = 0;
	calculated[1] = 1;
	calculated[2] = 2;
	for(int i = 3; i <= n; i++){
		calculated[i] = calculated[i - 1] + calculated[i - 2] + calculated[i - 3];
	}
	return calculated[n];
}

int main(){
	int x;
	std::cout << "Enter in a Value for N: ";
	std::cin >> x;
	std::cout << "The Fibonacci variant given " << x << " is " << DPButtomFib(x) << "\n";

}
