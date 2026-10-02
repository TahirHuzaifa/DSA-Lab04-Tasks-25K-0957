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

    Node* findMiddle() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    LinkedList oddList;
    oddList.append(1);
    oddList.append(2);
    oddList.append(3);
    oddList.append(4);
    oddList.append(5);

    cout << "Odd Length List: ";
    oddList.print();
    Node* midOdd = oddList.findMiddle();
    cout << "Middle = [" << midOdd->val << "]" << endl << endl;

    LinkedList evenList;
    evenList.append(1);
    evenList.append(2);
    evenList.append(3);
    evenList.append(4);
    evenList.append(5);
    evenList.append(6);

    cout << "Even Length List: ";
    evenList.print();
    Node* midEven = evenList.findMiddle();
    cout << "Middle Box = [" << midEven->val << "]" << endl;

    return 0;
}