#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class represents a singly linked list
class LinkedList {
private:
    Node* head; // Points to the first node in the list

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    //Constructors -- not here.
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}

    // Destructor to free memory when the list is destroyed
    ~LinkedList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    // Insert elements at the beginning
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    // Display the linked list
    std::cout << "Linked List: ";
    myList.display();

    return 0;
}
