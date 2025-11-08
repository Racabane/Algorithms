#include <iostream>
#include <vector>

unsigned long int buttomup(int n){
	std::vector<unsigned long int> sub(n + 1);
	sub[0] = 0;
	sub[1] = 1;
	sub[2] = 2;
	sub[3] = 3;
	for(int i = 4; i <= n; i++){
		sub[i] = sub[i - 2] + sub[i - 1];
		// std::cout << sub[i] << " , ";
	}
	// std::cout <<  " " << sub[4] << "\n";
	return sub[n];
}

int main(){
	std::cout << "45 ounces ways is " << buttomup(45) << "\n";
}