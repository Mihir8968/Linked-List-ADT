#include <bits/stdc++.h>
using namespace std;
#include "Linked_List_ADT.h"

int main()
{
    LinkedList<int> list;

    // Test insertion
    list.insert(1, 0);
    list.insert(3, 1);
    list.insert(2, 1); // Inserting 2 at position 1
    list.insert(4, 3); // Inserting 4 at the end
    list.display();    // Expected Output: 1 2 3 4

    // Test deletion
    list.deleteByValue(3);
    list.display(); // Expected Output: 1 2 4

    // Test reverse
    list.reverse();
    list.display(); // Expected Output: 4 2 1

    // Test length
    cout << "Length of list: " << list.length() << endl; // Expected Output: 3

    // Test search
    Node<int> *found = list.find(2);
    cout << "Found value: " << (found ? found->data : -1) << endl; // Expected Output: 2

    // Test concatenation
    LinkedList<int> list2;
    list2.insert(5, 0);
    list2.insert(6, 1);
    list2.insert(7, 2);
    list.concatenate(list2);
    list.display(); // Expected Output: 4 2 1 5 6 7

    // Test merge
    LinkedList<int> list3;
    list3.insert(8, 0);
    list3.insert(3, 0); // Sorted insertions
    list3.insert(9, 2);
    list3.insert(7, 2);
    list.merge(list3);
    list.display(); // Expected Output: 3 4 2 1 5 6 7 7 8 9

    // Test loop detection and creation
    list.createLoopByValue(6);
    cout << "Loop detected: " << (list.isLoop() ? "Yes" : "No") << endl; // Expected Output: Yes

    return 0;
}
