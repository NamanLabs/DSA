//Q2
#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    // Print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    // Insert elements into the list
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);
    linkedList.insert(5);

    // Print the original list
    cout << "Original List: ";
    linkedList.printList();

    // Reverse the list
    linkedList.reverse();

    // Print the reversed list
    cout << "Reversed List: ";
    linkedList.printList();

    return 0;
}








 // Q3
 #include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to create a loop for testing
    void createLoop(int position) {
        if (position < 0) return;
        Node* loopNode = head;
        for (int i = 0; i < position && loopNode; i++) {
            loopNode = loopNode->next;
        }
        if (loopNode) {
            Node* lastNode = head;
            while (lastNode->next) {
                lastNode = lastNode->next;
            }
            lastNode->next = loopNode; // Creating the loop
        }
    }

    bool detectLoop() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;          // Move slow pointer by 1
            fast = fast->next->next;   // Move fast pointer by 2
            if (slow == fast) {
                return true; // Loop detected
            }
        }
        return false; // No loop
    }

    void traverse() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    // Create a loop for testing (uncomment to test)
    // list.createLoop(1); // Creates a loop connecting last node to the second node

    if (list.detectLoop()) {
        std::cout << "Loop detected in the list." << std::endl;
    } else {
        std::cout << "No loop detected in the list." << std::endl;
    }

    return 0;
}
