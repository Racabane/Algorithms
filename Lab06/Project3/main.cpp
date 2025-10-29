#include <iostream>
#include <vector>

int DPButtomUpBox(int items, int capacity, int weights[], int values[]){
	std::vector<std::vector<int>> knapsack(items + 1, std::vector<int>(capacity + 1));
	for(int i = 1; i <= items; i++){
		for(int k = 0; k <= capacity; k++){
			if(weights[i - 1] < k){
				if(knapsack[i - 1][k] > knapsack[i - 1][k - weights[i - 1]] + values[i - 1] ){
					knapsack[i][k] = knapsack[i - 1][k];
				}else{
					knapsack[i][k] = knapsack[i - 1][k - weights[i - 1]] + values[i - 1];
				}
			}else{
				knapsack[i][k] = knapsack[i - 1][k];
			}
		}
	}
	//for printing to debug
	// for(int l = 0; l < 6; l++){
	// 	for(int v = 0; v < 13; v++){
	// 		std::cout << knapsack[l][v] << " ";
	// 		if(knapsack[l][v] < 10){
	// 			std::cout << " ";
	// 		}
	// 	}
	// 	std::cout << "\n";
	// }
	return knapsack[items][capacity];
}

int main(){
	int array[5] = {1,3,4,6,9};
	int array2[5] = {1,7,23,16,32};
	std::cout << "Optimal value is " << DPButtomUpBox(5, 12, array, array2) << "\n";
}
