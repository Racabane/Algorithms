#include <iostream>
#include <vector>


int allBasketsminsadded(std::vector<int> numbers){
	//sort the input
	for(int i = 0; i < numbers.size() - 1; i++){
		for(int j = 0; j < numbers.size() - i - 1; j++){
			if(numbers[j] > numbers[j + 1]){
				int temp = numbers[j + 1];
				numbers[j + 1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}

	// for(int k = 0; k < numbers.size(); k ++){
	// 	std::cout << numbers[k] << " ";
	// }
	
	int total = 0;
	//add the smallest of the pair
	for(int i = 0; i < numbers.size(); i += 2){
		total += numbers[i];
	}
	return total;
}

int main(){
	std::vector<int> numbers{7,3,5,9};
	std::cout << allBasketsminsadded(numbers) << "\n";
}
