#include <iostream>

const int maxlevel = 7;

class node{
	public:
		int key;
		node **next;
		node(){

		}
		node(int i){
			key = i;
		}
		
};

class skipList{
	public:
		skipList();
		void choosePowers();
		int chooseLevel();
		int* search(int key);
		void insert(int &key);
		void tracelevels();
	private:
		typedef node *nodeptr;
		nodeptr root[maxlevel];
		int powers[maxlevel];

};

skipList::skipList(){
	for(int i = 0; i < maxlevel; i++){
		root[i] = 0;
	}
}

void skipList::choosePowers(){
	powers[maxlevel - 1] = (2 << (maxlevel - 1)) - 1;
	for(int i = maxlevel - 2, j =0; i >= 0; i--, j++){
		powers[i] = powers[i + 1] - (2 << j);
	}
}


int skipList::chooseLevel(){
	int i, r = rand() % powers[maxlevel - 1] + 1;
	for(i = 1; i < maxlevel; i++){
		if(r < powers[i]){
			return i - 1;
		}
	}
	return i - 1;
}


int* skipList::search(int key){
	nodeptr prev, curr;
	int lvl;
	for(lvl = maxlevel - 1; lvl >= 0 && !root[lvl]; lvl--){
		prev = curr = root[lvl];
	}
	while(true){
		if(key == curr->key){
			return &curr->key;
		}else if(key < curr->key){
			if(lvl == 0){
				return 0;
			}else if(curr == root[lvl]){
				curr = root[--lvl];
			}else{
				curr = *(prev->next + --lvl);
			}
		}else{
			prev = curr;
			if(*(curr->next + lvl) != 0){
				curr = *(curr->next + lvl);
			}else{
				for(lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--){
					if(lvl >= 0){
						curr = *(curr->next + lvl);
					}else{
						return 0;
					}
				}
			}
		}

	}
}

void skipList::insert(int &key){
	nodeptr curr[maxlevel], prev[maxlevel], newnode;
	int lvl,i;
	curr[maxlevel - 1] = root[maxlevel - 1];
	prev[maxlevel - 1] = 0;
	for(lvl = maxlevel - 1; lvl >= 0; lvl--){
		while(curr[lvl] && curr[lvl]->key < key){
			prev[lvl] = curr[lvl];
			curr[lvl] = *(curr[lvl]->next + lvl);
		}
		if(curr[lvl] && curr[lvl]->key == key){
			return;
		}
		if(lvl > 0){
			if(prev[lvl] == 0){
				curr[lvl - 1] = root[lvl - 1];
				prev[lvl - 1] = 0;
			}else{
				curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
				prev[lvl - 1] = prev[lvl];
			}
		}
	}
	lvl = chooseLevel();
	std::cout << " level of choice " << lvl << std::endl;
	newnode = new node();
	newnode->next = new nodeptr[sizeof(nodeptr) * (lvl + 1)];
	newnode->key = key;
	for(i = 0; i <= lvl; i++){
		*(newnode->next + i) = curr[i];
		if(prev[i] == 0){
			root[i] = newnode;
		}else{
			*(prev[i]->next + i) = newnode;
		}
	}
}

void skipList::tracelevels(){
	int lvl;
	nodeptr curr;
	for(lvl = maxlevel - 1; lvl >= 0; lvl--){
		std::cout << "Level " << lvl << ": ";
		curr = root[lvl];
		while(curr != nullptr){
			std::cout << curr->key << ", ";
			curr = *(curr->next + lvl);
		}
		std::cout << std::endl;
	}
}

int main(){
	skipList list;
	list.choosePowers();
	int array[128] = {0};
	for(int i = 0; i < 128; i++){
		bool dupe = false;
		int j = (rand() % 1000) + 1;
		for(int k = 0; k < 128; k++){
			if(array[k] == j){
				dupe = true;
				break;
			}
		}
		if(!dupe){
			array[i] = j;
			std::cout << "Inserting number " << j;
			list.insert(j);
		}else{
			i--;
		}
	}
	list.tracelevels();

}