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

    void createLoop(int pos) {
        if (head == nullptr || pos <= 0) return;
        Node* loopStart = head;
        for (int i = 1; i < pos; i++) {
            if (loopStart->next == nullptr) return;
            loopStart = loopStart->next;
        }
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = loopStart;
    }

    void detectAndRemoveLoop() {
        if (head == nullptr || head->next == nullptr) return;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (slow != fast) return;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        Node* loopStart = slow;
        Node* ptr = loopStart;
        while (ptr->next != loopStart) {
            ptr = ptr->next;
        }
        ptr->next = nullptr;
    }

    void print() {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < 20) {
            cout << "[" << temp->val << "]";
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
            count++;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    list.createLoop(3);

    cout << "List with Loop (printing limited): ";
    list.print();

    list.detectAndRemoveLoop();

    cout << "After Removing Loop: ";
    list.print();

    return 0;
}