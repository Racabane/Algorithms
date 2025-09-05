#include <iostream>
#include <cstring>

template <class genType, int size = 50>
class genClass
{
	public:
		genType storage[size];
};

int main(){
	genClass<int> intObject;
	genClass<float, 123> floatObject;

	for(int i = 1; i < 11; i++){
		intObject.storage[i] = i;
		std::cout << intObject.storage[i] << ", ";
	}

	float x = 1.0;
	std::cout << std::endl;

	for(int j = 1; j < 22; j++){
		floatObject.storage[j] = x;
		x += 0.1;
		if(j < 11){
			std::cout << floatObject.storage[j] << ", ";
		}
	}

	
	std::cin.ignore();
	return 0;
}