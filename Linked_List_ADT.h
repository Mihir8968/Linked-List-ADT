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
    void deleteByValue(int val);
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

void LinkedList::deleteByValue(int val){
    if(size == 0){//No node present
        cout<<"Not valid!"<<endl;
        return;
    }
    Node *q = NULL;
    Node *p = head;
    if(head->data == val){//head needs to be updated
        p = head->next;
        q = head;
        head = p;
        delete q;
        --size;
        return;
    }
    while((p->next)->next){//Traversing till second last node so that tail node case can be handles separately
        if(p->data == val){
            q->next = p->next;
            delete p;
            --size;
            return;
        }
        q = p;
        p = p->next;
    }
    if(tail->data == val){//tail updated
        p->next = NULL;
        delete tail;
        tail = p;
        --size;
        return;
    }
    cout<<"No such value"<<endl;
}
