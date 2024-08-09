#ifndef LINKED_LIST_ADT_H
#define LINKED_LIST_ADT_H

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    // Constructor
    Node(T val)
    {
        this->data = val;
        this->next = NULL;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void insert(T x, int pos);
    void deleteByValue(T val);
    void display();
    void reverse();
    void concatenate(LinkedList &otherLL);
    int length();
    Node<T> *find(T key);
    void merge(LinkedList &otherLL);
    bool isLoop();
    void createLoopByValue(T val);
    LinkedList<T>::~LinkedList();
};

template <typename T>
void LinkedList<T>::insert(T val, int pos)
{
    // Checking for valid pos value
    if (pos > size || pos < 0)
    {
        cout << "Position invalid!" << endl;
        return;
    }
    Node<T> *t = new Node<T>(val);
    if (pos == 0)
    { // head needs to be modified
        t->next = head;
        head = t;
        if (size == 0)
        {
            tail = head;
        }
        ++size;
        return;
    }
    // pos > 0 && pos <= size
    Node<T> *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    if (pos == size)
    {
        tail = t;
    }
    ++size;
}

template <typename T>
void LinkedList<T>::deleteByValue(T val)
{
    if (size == 0)
    { // No node present
        cout << "List is empty!" << endl;
        return;
    }
    Node<T> *q = NULL;
    Node<T> *p = head;
    if (head->data == val)
    { // head needs to be updated
        head = head->next;
        delete p;
        --size;
        if (size == 0)
        {
            tail = NULL;
        }
        return;
    }
    while (p != NULL && p->data != val)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "No such value" << endl;
        return;
    }

    q->next = p->next;
    if (p == tail)
    { // tail needs to be updated
        tail = q;
    }
    delete p;
    --size;
}

template <typename T>
void LinkedList<T>::display()
{
    Node<T> *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <typename T>
void LinkedList<T>::reverse()
{
    Node<T> *p = head;
    Node<T> *q = NULL;
    Node<T> *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

template <typename T>
void LinkedList<T>::concatenate(LinkedList<T> &otherLL)
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

template <typename T>
int LinkedList<T>::length()
{
    return size;
}

template <typename T>
Node<T> *LinkedList<T>::find(T key)
{
    Node<T> *p = head;
    while (p)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    cout << "Value not found" << endl;
    return NULL;
}

template <typename T>
void LinkedList<T>::merge(LinkedList<T> &otherLL)
{
    // Makes the original linked list a merged linked list
    Node<T> *second = otherLL.head;
    Node<T> *last = NULL;
    Node<T> *third = NULL;

    if (head == NULL)
    {
        // If the original list is empty, simply use the other list
        head = otherLL.head;
        tail = otherLL.tail;
        size = otherLL.size;
        otherLL.head = NULL;
        otherLL.tail = NULL;
        otherLL.size = 0;
        return;
    }

    if (otherLL.head == NULL)
    {
        // If the other list is empty, nothing to merge
        return;
    }

    // Initialize the merged list head
    if (head->data <= otherLL.head->data)
    {
        third = last = head;
        head = head->next;
    }
    else
    {
        third = last = second;
        second = second->next;
    }

    // Merge both lists
    while (head != NULL && second != NULL)
    {
        if (head->data <= second->data)
        {
            last->next = head;
            last = head;
            head = head->next;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
        }
    }

    // Attach the remaining nodes, if any
    if (head != NULL)
    {
        last->next = head;
    }
    else
    {
        last->next = second;
    }

    // Update head and tail of the original list
    head = third;
    while (last->next != NULL)
    {
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

template <typename T>
bool LinkedList<T>::isLoop()
{
    Node<T> *p, *q;
    p = q = head;
    do
    {
        p = p->next;
        q = q != NULL ? q->next : NULL;
        q = q != NULL ? q->next : NULL;
    } while (p && q && p != q);
    return p == q;
}

template <typename T>
void LinkedList<T>::createLoopByValue(T val)
{
    if (size == 0)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node<T> *p = find(val);
    if (!p)
    {
        return;
    }
    tail->next = p;
    delete p;
}

LinkedList<T>::~LinkedList()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;                
    }
    head = nullptr; // Ensure head is null after deletion
}

#endif // LINKED_LIST_ADT_H
