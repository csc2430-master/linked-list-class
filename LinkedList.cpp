//
// Created by Max Benson on 3/1/2022.
//

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
#include "LinkedList.h"

LinkedList::LinkedList() {
    _head = nullptr;
}

LinkedList::~LinkedList() {
    while(_head != nullptr) {
        Node* nodeToDelete = _head;
        _head = _head->next;
        delete nodeToDelete;
    }
}

void LinkedList::Prepend(int item) {
    Node *newHead;

    newHead = new Node;
    newHead->item = item;
    newHead->next = _head;
    _head = newHead;
}

bool LinkedList::InsertAfter(int itemToInsert, int afterItem) {
    Node* ptr = FindItem(afterItem);

    if (ptr != nullptr) {
        Node* newNode = new Node;
        newNode->item = itemToInsert;
        newNode->next = ptr->next;
        ptr->next = newNode;
        return true;
    }
    return false;
}

bool LinkedList::RemoveItem(int item) {
    if (nullptr == _head) {
        return false;
    }
    else if (_head->item == item) {
        Node* nodeToDelete = _head;	// Save pointer to node to be deleted
        _head = _head->next;	// Update pointer to head
        delete nodeToDelete;		// Deallocate the old head node
        return true;
    }
    else {
        return RemoveNotInHead(item);
    }
}

void LinkedList::Print(ostream &output) const {
    output << "[";
    for (Node* ptr = _head; ptr != nullptr; ptr = ptr->next) {
        if (ptr != _head) {
            output << ", ";
        }
        output << ptr->item;
    }
    output << "]" << endl;
}

bool LinkedList::Insert(size_t pos, int item) {
    if (0 == pos) {
        Prepend(item);
    }
    else {
        Node* ptr = GetPtrToNode(pos-1);
        if (ptr == nullptr) {
            return false;
        }
        Node* newNode = new Node;
        newNode->item = item;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return true;
}

bool LinkedList::Remove(size_t pos, int& item) {
    Node* nodeToDelete;

    if (0 == pos) {
        nodeToDelete = _head;
        _head = _head->next;
    }
    else {
        Node* ptr = GetPtrToNode(pos-1);
        if (ptr== nullptr || ptr->next == nullptr) {
            return false;
        }
        nodeToDelete = ptr->next;
        ptr->next = nodeToDelete->next;
    }
    item = nodeToDelete->item;
    delete nodeToDelete;
    return true;
}

bool LinkedList::Get(size_t pos, int& item) const {
    Node* ptr = GetPtrToNode(pos);
    if (ptr != nullptr) {
        item = ptr->item;
        return true;
    }
    return false;
}

size_t LinkedList::Find(int item, size_t start) const {
    size_t pos = start;

    for ( Node* ptr = GetPtrToNode(start); ptr != nullptr; ptr = ptr->next) {
        if (ptr->item == item) {
            return pos;
        }
        pos ++;
    }
    return -1;
}

size_t  LinkedList::Size() const {
    size_t count = 0;

    for (Node* ptr = _head; ptr != nullptr; ptr = ptr->next) {
        count++;
    }
    return count;
}

bool LinkedList::RemoveNotInHead(int item) {
    Node* nodeToDelete;
    Node* nodeBefore = FindItemBefore(item);

    if (nullptr == nodeBefore) {
        return false;
    }
    nodeToDelete = nodeBefore->next;
    nodeBefore->next = nodeToDelete->next;
    delete nodeToDelete;
    return true;
}

LinkedList::Node* LinkedList::FindItem(int item) const {
    // Starting at "head" search the linked list for a node containing item
    // If found, return a pointer to the node, otherwise return nullptr
    for (Node* ptr = _head; ptr != nullptr; ptr = ptr->next) {
        if (ptr->item == item) {
            return ptr;
        }
    }
    return nullptr;
}

LinkedList::Node* LinkedList::FindItemBefore(int item) const {
    // Starting at "head" search the linked list for a node    // containing item.  If found return a pointer to the node before
    // before, otherwise return nullptr
    if (_head != nullptr) {
        for (Node* ptr = _head; ptr->next != nullptr; ptr = ptr->next) {
            if (ptr->next->item == item) {
                return ptr;
            }
        }
    }
    return nullptr;
}

LinkedList::Node* LinkedList::GetPtrToNode(size_t pos) const {
    size_t cur = 0;

    for (Node* ptr = _head; ptr != nullptr; ptr = ptr->next) {
        if (cur == pos) {
            return ptr;
        }
        cur++;
    }
    return nullptr;
}

