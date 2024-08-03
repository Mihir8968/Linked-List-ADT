#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
class LinkedList{
private:
    Node* head;
    Node* tail;
    int size;

public:
    void insert(int x, int pos);
};

void LinkedList::insert(int val, int pos){
    //checking for valid pos value
    if(pos > size || pos < 0){
        cout<<"Position on valid!"<<endl;
        return;
    }
    Node* t;
    t->data = val;
    if(pos == 0){//head needs to be modified
        t->next = head;
        head = t;
        ++size;
        return;
    }
    //pos>0 && pos<=size
    Node* p = head;
    for(int i = 0; i < pos-1; i++){
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
}
