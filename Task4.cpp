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

    static Node* mergeTwoLists(Node* head1, Node* head2) {
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        if (head1 != nullptr) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }
        Node* result = dummy->next;
        delete dummy;
        return result;
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
    LinkedList listA;
    listA.append(1);
    listA.append(3);
    listA.append(5);
    listA.append(7);

    LinkedList listB;
    listB.append(2);
    listB.append(4);
    listB.append(6);
    listB.append(8);

    cout << "Chain A: ";
    listA.print();
    cout << "Chain B: ";
    listB.print();

    LinkedList merged;
    merged.head = LinkedList::mergeTwoLists(listA.head, listB.head);

    cout << "Merged List: ";
    merged.print();

    return 0;
}