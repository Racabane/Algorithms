#include <iostream>
int addNumbers(int *ptr, int size){
	int total = 0;
	while(size != 0){
		total += *ptr++;
		size--;
	}
	return total;
}

int removeOdds(int *ptr, int size){
	int *ptr2 = ptr;
	int tmpArray[size];
	int *ptr3 = tmpArray;
	int count = 0;
	int numEvens = 0;
	while(size != 0){
		if(*ptr % 2 == 0){
			numEvens++;
			*ptr3 = *ptr;
			ptr3++;
			count++;
		}
		ptr++;
		size--;
	}

	 ptr3 = tmpArray;
	while(count != 0){
		
			*ptr2 = *ptr3;
		ptr2++;
		ptr3++;

		count--;
	}
	return numEvens;
}

int main(){
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	int *ptr = array;

	std::cout << addNumbers(ptr, 10) << std::endl;
	int newSize = removeOdds(ptr, 10);
	int newArray[newSize];
	ptr = array;

	int* ptr2 = newArray;
	for(int k = 0; k < newSize; k++){
		*ptr2 = *ptr;
		ptr2++;
		ptr++; 
	}
	//new array is condenced
	std::cout << addNumbers(newArray, newSize) << std::endl;


	return 0;
}