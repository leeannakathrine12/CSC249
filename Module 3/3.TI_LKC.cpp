// CSC 249
// 3.TI - Linked Lists
// Leeanna Kathrine Coleman
// 03/09/25

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int initialData) {
        data = initialData;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode) {
            Node* toBeDeleted = currentNode;
            currentNode = currentNode->next;
            delete toBeDeleted;
        }
    }

    void Append(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Prepend(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void InsertAfter(Node* currentNode, Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (currentNode == tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    void RemoveAfter(Node* currentNode) {
        if (currentNode == nullptr && head) {
            Node* nodeBeingRemoved = head;
            head = head->next;
            delete nodeBeingRemoved;

            if (head == nullptr) {
                tail = nullptr;
            }
        }
        else if (currentNode != nullptr && currentNode->next != nullptr) {
            Node* nodeBeingRemoved = currentNode->next;
            Node* succeedingNode = currentNode->next->next;
            currentNode->next = succeedingNode;
            delete nodeBeingRemoved;

            if (succeedingNode == nullptr) {
                tail = currentNode;
            }
        }
    }

    void PrintList(ostream& printStream = cout, const string& separator = ", ") const {
        Node* node = head;
        if (node) {
            printStream << node->data;
            node = node->next;
        }
        while (node) {
            printStream << separator << node->data;
            node = node->next;
        }
        printStream << endl;
    }
};

int main() {
    LinkedList numList;

    Node* nodeA = new Node(12);
    Node* nodeB = new Node(24);
    Node* nodeC = new Node(36);
    Node* nodeD = new Node(1);
    Node* nodeE = new Node(2);
    Node* nodeF = new Node(3);

    numList.Append(nodeB);
    numList.Append(nodeC);
    numList.Append(nodeE);

    numList.Prepend(nodeA);

    numList.InsertAfter(nodeC, nodeD);
    numList.InsertAfter(nodeE, nodeF);

    cout << "List after adding nodes: ";
    numList.PrintList(cout);

    numList.RemoveAfter(nodeE);
    numList.RemoveAfter(nullptr);

    cout << "List after removing nodes: ";
    numList.PrintList(cout);
   
}