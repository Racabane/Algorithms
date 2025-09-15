#include <iostream>
#include <chrono>

int main(){
	srand(time(0));
	int array[10];
	std::cout << "Numbers generated: ";
	for(int i = 0; i < 10; i++ ){
		array[i] = rand() % 41 - 20;
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;
	static std::chrono::time_point<std::chrono::high_resolution_clock> start;
	start = std::chrono::high_resolution_clock::now();
	int sum = 0;
	for(int j = 0; j < 10; j++){
		if(array[j] == 0){
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
			std::cout << "Yes ";
			std::cout << array[j];
			std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
			return 0;
		}
		for(int k = j + 1; k < 10; k++){
			if(array[j] + array[k] == 0){
				auto stop = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
				std::cout << "Yes ";
				std::cout << array[j] << " + " << array[k];
				std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
				return 0;
			}
			for(int l = k + 1; l < 10; l++){
				if(array[j] + array[k] + array[l] == 0){
					auto stop = std::chrono::high_resolution_clock::now();
					auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
					std::cout << "Yes ";
					std::cout << array[j] << " + " << array[k] << " + " << array[l];
					std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
					return 0;
				}
				for(int m = l + 1; m < 10; m++){
					if(array[j] + array[k] + array[l] + array[m] == 0){
						auto stop = std::chrono::high_resolution_clock::now();
						auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
						std::cout << "Yes ";
						std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m];
						std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
						return 0;
					}
					for(int n = m + 1; n < 10; n++){
						if(array[j] + array[k] + array[l] + array[m] + array[n] == 0){
							auto stop = std::chrono::high_resolution_clock::now();
							auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
							std::cout << "Yes ";
							std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m] << " + " << array[n];
							std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
							return 0;
						}
						for(int o = n + 1; o < 10; o++){
							if(array[j] + array[k] + array[l] + array[m] + array[n] + array[o] == 0){
								auto stop = std::chrono::high_resolution_clock::now();
								auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
								std::cout << "Yes ";
								std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m] << " + " << array[n] << " + " << 
									array[o];
								std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
								return 0;
							}
							for(int q = o + 1; q < 10; q++){
								if(array[j] + array[k] + array[l] + array[m] + array[n] + array[o] + array[q] == 0){
									auto stop = std::chrono::high_resolution_clock::now();
									auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
									std::cout << "Yes ";
									std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m] << " + " << array[n] << " + " << 
										array[o] << " + " << array[q];
									std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
									return 0;
								}
								for(int x = q + 1; x < 10; x++){
									if(array[j] + array[k] + array[l] + array[m] + array[n] + array[o] + array[q]+ array[x] == 0){
										auto stop = std::chrono::high_resolution_clock::now();
										auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
										std::cout << "Yes ";
										std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m] << " + " << array[n] << " + " << 
											array[o] << " + " << array[q] << " + " << array[x];
										std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
										return 0;
									}
									for(int y = x + 1; y < 10; y++){
										if(array[j] + array[k] + array[l] + array[m] + array[n] + array[o] + array[q] + array[x] + array[y] == 0){
											auto stop = std::chrono::high_resolution_clock::now();
											auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
											std::cout << "Yes ";
											std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m] << " + " << array[n] << " + " << 
												array[o] << " + " << array[q] << " + " << array[x] << " + " << array[y];
											std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;
											return 0;
										}
										for(int z = y + 1; z < 10; z++){
												if(array[j] + array[k] + array[l] + array[m] + array[n] + array[o] + array[q] + array[x] + array[y] + array[z] == 0){
													auto stop = std::chrono::high_resolution_clock::now();
													auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
													std::cout << "Yes ";
													std::cout << array[j] << " + " << array[k] << " + " << array[l] << " + " << array[m] << " + " << array[n] << " + " << 
														array[o] << " + " << array[q] << " + " << array[x] << " + " << array[y] << " + " << array[z];
													std::cout << " equals zero time taken in miliseconds: " << duration << std::endl;										
													return 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

	std::cout << "No " << std::endl;
	std::cout << "Time taken in miliseconds: " << duration << std::endl;

	return 0;

}