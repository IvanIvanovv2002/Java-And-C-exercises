#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void pop_back() {
       
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }       
        delete temp->next;
        temp->next = nullptr;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Error: Cannot pop from an empty list." << endl;
            return;
        }
        head = head->next;
    }

    void insert_at_index(int value, int index) {
        if (index < 0) {
            cout << "Error: Invalid index." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            this->push_front(value);
        }

        else {
            Node* temp = head;
            int currentIndex = 0;
            while (temp != nullptr && currentIndex < index - 1) {
                temp = temp->next;
                currentIndex++;
            }

            if (temp == nullptr) {
                cout << "Error: Index out of range." << endl;
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.insert_at_index(6, 2);

    cout << "Linked List: ";
    list.display();

    return 0;
}
