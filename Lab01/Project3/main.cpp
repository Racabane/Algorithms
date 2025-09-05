#include <iostream>

class Node{
	public:
		int *space;
		int size;

		Node(int s[], int a = 0){
			size = a;
			space = new int[a];
			for(int i = 0; i < a; i++){
				space[i] = s[i];
			}
		}
		Node(const Node& node){
			size = node.size;
			space = new int[size];
			for(int i = 0; i < size; i++){
				space[i] = node.space[i];
			}
		}
};


std::ostream& operator<<(std::ostream& out, const Node& node){
	for(int i = 0; i < node.size; i++){
		out << node.space[i] << " ";
	}
	return out;
}

int main(){
	int t[] = {1, 2, 3, 4, 5, 6};
	Node test1(t, sizeof(t)/4), test2(test1);
	test1.space[2] = 7;
	std::cout << test2.space[2] << std::endl;
	std::cout << test1.space[2] << std::endl;
	// std::cin.ignore();
	std::cout << "test1: " << test1 << std::endl;
	std::cout << "test2: " << test2 << std::endl;
}
