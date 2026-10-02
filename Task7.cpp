#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x) {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void removeDuplicates() {
        if (head == nullptr) {
            return;
        }
        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                Node* duplicate = curr->next;
                curr->next = duplicate->next;
                if (duplicate->next != nullptr) {
                    duplicate->next->prev = curr;
                }
                delete duplicate;
            } else {
                curr = curr->next;
            }
        }
    }

    void print() {
        Node* temp = head;
        cout << "NULL <- ";
        while (temp != nullptr) {
            cout << "[" << temp->val << "]";
            if (temp->next != nullptr) {
                cout << " <=> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(3);
    list.append(3);
    list.append(4);

    cout << "Original List: ";
    list.print();

    list.removeDuplicates();

    cout << "Cleaned List: ";
    list.print();

    return 0;
}