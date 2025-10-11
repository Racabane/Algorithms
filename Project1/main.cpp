#include <iostream>
#include <stack>


void combinations(double numbersdecided[9], std::stack<double> numbersRemaining){
	if(numbersRemaining.empty()){
		if(numbersdecided[0] / numbersdecided[1] * numbersdecided[2] +
		numbersdecided[3] * numbersdecided[4] * numbersdecided[5] / numbersdecided[6] +
		numbersdecided[7] * numbersdecided[8] == 100){
			std::cout << numbersdecided[0] <<  " / " << numbersdecided[1] << " * " 
			<< numbersdecided[2] << " + " << numbersdecided[3] << " * "  << numbersdecided[4] 
			<< " * " << numbersdecided[5] << " / " << numbersdecided[6] << " + " <<
			numbersdecided[7] << " * " << numbersdecided[8] << " = 100\n";
		}
	}
	int remains = numbersRemaining.size();
	for(int i = 0; i < remains; i++){
		std::stack<double> temp = numbersRemaining;
		std::stack<double> temp2;
		double selected;
		int index = 0;
		for(int k = 0; k < remains - i - 1; k++){
			temp2.push(temp.top());
			temp.pop();
		}
		selected = temp.top();
		temp.pop();
	
		while(!temp2.empty()){
			temp.push(temp2.top());
			temp2.pop();
		}
		while(index < 9 && numbersdecided[index] != 0){
			index++;
		}
		numbersdecided[index] = selected;

		combinations(numbersdecided, temp);
		numbersdecided[index] = 0;

	}
}

int main(){
	std::stack<double> numbersRemaining, numbersdecided;

	double array[9] = {9,8,7,6,5,4,3,2,1};
	double array2[9] = {0};
	for(int i = 0; i < 9; i++){
		numbersRemaining.push(array[i]);
	}
	
	combinations(array2, numbersRemaining);
	
	return 0;
}