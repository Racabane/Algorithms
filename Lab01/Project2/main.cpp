#include <iostream>

template <class genType>
void myswap(genType &el1, genType &el2){
	genType tmp = el1;
	el1 = el2;
	el2 = tmp;
}

int main(){
	int n =2;
	int m = 3;
	double x = 10.5;
	double y = 2.7;

	std::cout << "Ints Swap: " << std::endl;
	std::cout << "Before Swap: N: " << n << " M: " << m << std::endl;
	myswap(n, m);
	std::cout << "After  Swap: N: " << n << " M: " << m << std::endl;


	std::cout << "\nDoubles Swap: " << std::endl;
	std::cout << "Before Swap: X: " << x << " Y: " << y << std::endl;
	myswap(x, y);
	std::cout << "After  Swap: X: " << x << " Y: " << y << std::endl;

	// std::cout << "\nDifferent type Swap: " << std::endl;
	// std::cout << "Before Swap: X: " << x << " N: " << n << std::endl;
	// myswap(x, n);
	// std::cout << "After  Swap: X: " << x << " N: " << n << std::endl;


	return 0;
}