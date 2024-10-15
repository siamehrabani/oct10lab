// Mehrabani, Siavash
// CS136, Lab6 D-Linked List
// Room 2 or 9 

#include<iostream>
using namespace std;

template <typename T>
class Node {
public: // defined public to make it easier to access
    T data; //value of the node
    Node* prev; //pointer to the previous node
    Node* next; //pointer to the next node

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    // constructor to initialize the node with a value
};    

template <typename T>
class DLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DLinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }   

    void insertAtEnd(T val){
        Node<T>* newNode = new Node<T>(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteFromStart() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;   
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;   
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }else {
            head = nullptr; // list becomes empty
        }
        delete temp;
    }    

    bool checkDuplicate(T val) {
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr) {
            if (current->data == val) {
                count++;
            }
            current = current->next;
        }
        return count > 1;
    }    

    void reverse () {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) { // swap next and prev pointers 
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) { // swap head and tail pointers
            head = temp->prev;
        }
    }    

    void printForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }          

    void printBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DLinkedList<int> intlist;
    
    intlist.insertAtStart(20);
    intlist.insertAtEnd(30);
    intlist.insertAtStart(10);
    intlist.insertAtEnd(40);

    cout << "Doubly Linked List (Forward): ";
    intlist.printForward();

    cout << "Doubly Linked List (Backward): ";
    intlist.printBackward();

    cout << "Deleting from start" << endl;
    intlist.deleteFromStart();
    intlist.printForward();

    cout << "Deleting from end" << endl;
    intlist.deleteFromEnd();
    intlist.printForward();

    cout << "Checking duplicate of 30: " << endl;
    cout << intlist.checkDuplicate(30) << endl;

    cout << "Reversing the list" << endl;
    intlist.reverse();
    intlist.printForward();

    return 0;
}