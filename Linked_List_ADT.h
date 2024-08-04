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
    Node* q = nullptr;
    Node* p = head;
    if (head->data == val) { // head needs to be updated
        head = head->next;
        delete p;
        --size;
        if (size == 0) {
            tail = nullptr;
        }
        return;
    }
    while (p != nullptr && p->data != val) {
        q = p;
        p = p->next;
    }

    if (p == nullptr) {
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
    if (otherLL.head == nullptr)
    {
        // other linked list empty, do nothing
        return;
    }
    if (head == nullptr)
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
    otherLL.head = nullptr;
    otherLL.tail = nullptr;
    otherLL.size = 0;
}

#endif // LINKED_LIST_ADT_H
