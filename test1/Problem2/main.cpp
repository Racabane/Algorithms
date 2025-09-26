#include <iostream>


class node
{
public:
    long info;
    node *next;

    node()
    {
        next = NULL;
    }

    node(int data)
    {
        info = data;
        next = NULL;
    }
};

class list
{
public:
    node *head, *tail;

    list()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insert(long data)
    {
        node *p = new node(data);
        if (isEmpty())
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

	

};

int transpose(list &l, long x){
		int count = 0;
		//if list is empty
		if(l.head == nullptr){
			l.insert(x);
		}
		//checks each element making comparisons each element in order to find
		//element thats being accessed then moves element one node forwadr in list
		for(node* tmp = l.head; tmp->next != nullptr; tmp = tmp->next){
			count++;
			if(tmp->next->info == x){
				count++;
				long store = tmp->next->info;
				tmp->next->info = tmp->info;
				tmp->info = store;
				return count;
			}
		}
		//not found in list add new node
		l.insert(x);
		return count;
}

int moveToFront(list &l, long x){
	int count = 0;
	//if list is empty
	if(l.head == nullptr){
		l.insert(x);
	}

	//checks each element making comparisons each element in order to find
	//element thats being accessed then moves element to front of list
	for(node* tmp = l.head; tmp->next != nullptr; tmp = tmp->next){
		count++;
		//suppose to move accessed element to the front
		if(tmp->next->info == x){
			count++;
			node* target = tmp->next;
			tmp->next = tmp->next->next;
			target->next = l.head;
			l.head = target;
			return count;
		}
	}
	//not found in list add new node
	l.insert(x);
	return count;
}

int main(){
	list list1, list2, list3, list4;
	int totalComparisons1 = 0;
	int totalComparisons2 = 0;
	int totalComparisons3 = 0;
	int totalComparisons4 = 0;

	srand(time(0));
	for(int i = 0; i < 30; i++){
		long x = rand() % 30;
		//if desired element is not in list make new node or access it and reorder based 
		//on method
		totalComparisons1 += transpose(list1, x);
		totalComparisons2 += moveToFront(list2, x);
	}
	
	std::cout << "Number of Comparisons for transpose for 30 Random Numbers: " << 
		totalComparisons1 << std::endl;
	std::cout << "Number of Comparisons for move to front for 30 Random Numbers: " 
	<< totalComparisons2 << std::endl;

	for(int i = 0; i < 30000; i++){
		long x = rand() % 100000;
		totalComparisons3 += transpose(list3, x);
		totalComparisons4 += moveToFront(list4, x);
	}
	std::cout << "Number of Comparisons for transpose for 30k Random Numbers: " << 
		totalComparisons3 << std::endl;
	std::cout << "Number of Comparisons for move to front for 30K Random Numbers: " 
	<< totalComparisons4 << std::endl;

	return 0;
}