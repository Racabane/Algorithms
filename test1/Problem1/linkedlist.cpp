#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef>

using namespace std;

class node
{
public:
    int info;
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

    void insert(int data)
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

    void reverse()
    {
        // Implement this method
        tail = head;
        node* tailnext = head->next;
        node* before = nullptr;
        node* after = head;
        node* tmp = head;
        while(tmp != nullptr){
            after = tmp->next;
            tmp->next = before;
            before = tmp;
            tmp = after;
        }
        tailnext->next = tail;
        head = before->next;
    }

    friend ostream &operator<<(ostream &out, const list &l)
    {
        // Implement this method
        for(node* tmp = l.head; tmp->next != nullptr; tmp = tmp->next){
            out << tmp->info << "->";
        }
        out << "||";
        return out;
    }
};

list list1, list2, list3, list4;

void Setup()
{
    int len1 = rand() % 100 + 1;
    int len2 = rand() % 100 + 1;
    int len3 = rand() % 100 + 1;

    // list1 and list2 are supposd to be different
    for (int i = 0; i < len1; i++)
        list1.insert(rand() % 100);
    for (int i = 0; i < len2; i++)
        list2.insert(rand() % 100);

    // For your convenience, list3 and list4 are the same
    for (int i = 0; i < len3; i++)
    {
        list3.insert(rand() % 100);
        list4.insert(rand() % 100);
    }
}

bool Test(list l1, list l2)
{
    // Implement this method
    node* tmp1 = l1.head; 
    node* tmp2 = l2.head;

    while(tmp1->next != nullptr && tmp2->next != nullptr){
        if(tmp1->info != tmp2->info){
            // return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    if((tmp1->next == nullptr && tmp2->next != nullptr) || (tmp1->next != nullptr && tmp2->next == nullptr)){
        return false;
    }
    return true;
}

int main()
{

    srand(time(NULL));

    Setup();

    bool result = Test(list1, list2);

    cout << "List1:" << list1 << endl;
    cout << "List2:" << list2 << endl;
    if (result)
        cout << "They are the same\n";
    else
        cout << "They are not the same\n";

    result = Test(list3, list4);
    cout << "List3:" << list3 << endl;
    cout << "List4:" << list4 << endl;
    if (result)
        cout << "They are the same\n";
    else
        cout << "They are not the same\n";

    list4.reverse();
    cout << "reverse List4:" << list4 << endl;
}