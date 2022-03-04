//
// Created by Max Benson on 3/1/2022.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using std::ostream;

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void Prepend(int item);
    bool InsertAfter(int item, int after);
    bool RemoveItem(int item);
    void Print(ostream& output) const;

    bool Insert(size_t pos, int item);
    bool Remove(size_t pos, int& item);
    bool Get(size_t pos, int& item) const;
    size_t Find(int item, size_t start = 0) const;
    size_t Size() const;

private:
    class Node {
    public:
        int item;
        Node* next;
    };

    // Hide copy constructor and copy assignment operator
    LinkedList(const LinkedList&);
    const LinkedList& operator=(const LinkedList&);

    // Helper functions
    bool RemoveNotInHead(int item);
    Node* FindItem(int item) const;
    Node* FindItemBefore(int item) const;
    Node* GetPtrToNode(size_t pos) const;

    Node* _head;
};

#endif //LINKEDLIST_H
