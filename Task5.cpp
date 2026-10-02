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

    static Node* getIntersectionNode(Node* headA, Node* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        Node* ptrA = headA;
        Node* ptrB = headB;
        while (ptrA != ptrB) {
            if (ptrA == nullptr) {
                ptrA = headB;
            } else {
                ptrA = ptrA->next;
            }
            if (ptrB == nullptr) {
                ptrB = headA;
            } else {
                ptrB = ptrB->next;
            }
        }
        return ptrA;
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
    Node* common = new Node(8);
    common->next = new Node(4);
    common->next->next = new Node(5);

    LinkedList listA;
    listA.head = new Node(4);
    listA.head->next = new Node(1);
    listA.head->next->next = common;

    LinkedList listB;
    listB.head = new Node(5);
    listB.head->next = new Node(6);
    listB.head->next->next = new Node(1);
    listB.head->next->next->next = common;

    cout << "Chain A: ";
    listA.print();
    cout << "Chain B: ";
    listB.print();

    Node* intersection = LinkedList::getIntersectionNode(listA.head, listB.head);

    if (intersection != nullptr) {
        cout << "Intersection point = [" << intersection->val << "]" << endl;
    } else {
        cout << "No Intersection" << endl;
    }

    return 0;
}