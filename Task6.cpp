#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
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
    }

    void oddEvenList() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->val << "]";
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(2);
    list.append(1);
    list.append(3);
    list.append(5);
    list.append(6);
    list.append(4);
    list.append(7);

    cout << "Original List: ";
    list.print();

    list.oddEvenList();

    cout << "After Rearrangement: ";
    list.print();

    return 0;
}