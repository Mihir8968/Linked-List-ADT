#ifndef LINKED_LIST_ADT_H
#define LINKED_LIST_ADT_H

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void insert(int x, int pos);
    void deleteByValue(int val);
    void display();
    void reverse();
    void concatenate(LinkedList &otherLL);
    int length();
    Node* find(int key);
    void merge(LinkedList &otherLL);
    bool isLoop();
};

void LinkedList::insert(int val, int pos) {
    // Checking for valid pos value
    if (pos > size || pos < 0) {
        cout << "Position invalid!" << endl;
        return;
    }
    Node* t = new Node(val);
    if (pos == 0) { // head needs to be modified
        t->next = head;
        head = t;
        if (size == 0) {
            tail = head;
        }
        ++size;
        return;
    }
    // pos > 0 && pos <= size
    Node* p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    if (pos == size) {
        tail = t;
    }
    ++size;
}

void LinkedList::deleteByValue(int val) {
    if (size == 0) { // No node present
        cout << "List is empty!" << endl;
        return;
    }
    Node* q = NULL;
    Node* p = head;
    if (head->data == val) { // head needs to be updated
        head = head->next;
        delete p;
        --size;
        if (size == 0) {
            tail = NULL;
        }
        return;
    }
    while (p != NULL && p->data != val) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "No such value" << endl;
        return;
    }

    q->next = p->next;
    if (p == tail) { // tail needs to be updated
        tail = q;
    }
    delete p;
    --size;
}

void LinkedList::display() {
    Node* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void LinkedList::reverse(){
    Node* p = head;
    Node* q = NULL;
    Node* r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void LinkedList::concatenate(LinkedList &otherLL)
{
    if (otherLL.head == NULL)
    {
        // other linked list empty, do nothing
        return;
    }
    if (head == NULL)
    {
        // If this list is empty, set head and tail to the head and tail of otherLL
        head = otherLL.head;
        tail = otherLL.tail;
    }
    else
    {
        // Otherwise, link the tail of this list to the head of the other list
        tail->next = otherLL.head;
        tail = otherLL.tail;
    }

    // Update the size
    size += otherLL.size;

    // Clear the other list
    otherLL.head = NULL;
    otherLL.tail = NULL;
    otherLL.size = 0;
}

int LinkedList::length(){
    return size;
}

Node* LinkedList::find(int key){//returns a pointer to the corresponding node
    Node* p = head;
    while(p){
        if(p->data == key){
            return p;
        }
        p = p->next;
    }
    cout<<"Value not found"<<endl;
    return NULL;
}

void LinkedList::merge(LinkedList &otherLL) {
    // Makes the original linked list a merged linked list
    Node* second = otherLL.head;
    Node* last = NULL;
    Node* third = NULL;

    if (head == NULL) {
        // If the original list is empty, simply use the other list
        head = otherLL.head;
        tail = otherLL.tail;
        size = otherLL.size;
        otherLL.head = NULL;
        otherLL.tail = NULL;
        otherLL.size = 0;
        return;
    }

    if (otherLL.head == NULL) {
        // If the other list is empty, nothing to merge
        return;
    }

    // Initialize the merged list head
    if (head->data <= otherLL.head->data) {
        third = last = head;
        head = head->next;
    } else {
        third = last = second;
        second = second->next;
    }

    // Merge both lists
    while (head != NULL && second != NULL) {
        if (head->data <= second->data) {
            last->next = head;
            last = head;
            head = head->next;
        } else {
            last->next = second;
            last = second;
            second = second->next;
        }
    }

    // Attach the remaining nodes, if any
    if (head != NULL) {
        last->next = head;
    } else {
        last->next = second;
    }

    // Update head and tail of the original list
    head = third;
    while (last->next != NULL) {
        last = last->next;
    }
    tail = last;

    // Update the size of the merged list
    size += otherLL.size;

    // Clear the other list
    otherLL.head = NULL;
    otherLL.tail = NULL;
    otherLL.size = 0;
}

bool LinkedList::isLoop(){
    Node *p, *q;
    p = q = head;
    do{
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    }while(p && q && p != q);
    return p == q ? true : false;
}

#endif // LINKED_LIST_ADT_H
