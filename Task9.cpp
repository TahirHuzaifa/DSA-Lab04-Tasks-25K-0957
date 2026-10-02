#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int sev;
    Node* next;
    Node* prev;
    Node(int i, int s) {
        id = i;
        sev = s;
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

    void append(int id, int sev) {
        Node* newNode = new Node(id, sev);
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

    int getLength() {
        int len = 0;
        Node* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    Node* getNodeAt(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void swapNodes(Node* a, Node* b) {
        if (a == b || a == nullptr || b == nullptr) return;

        if (a->next == b) {
            a->next = b->next;
            b->prev = a->prev;
            if (a->next != nullptr) a->next->prev = a;
            if (b->prev != nullptr) b->prev->next = b;
            b->next = a;
            a->prev = b;
        } else if (b->next == a) {
            swapNodes(b, a);
            return;
        } else {
            Node* aPrev = a->prev;
            Node* aNext = a->next;
            Node* bPrev = b->prev;
            Node* bNext = b->next;

            if (aPrev != nullptr) aPrev->next = b;
            else head = b;
            if (aNext != nullptr) aNext->prev = b;

            if (bPrev != nullptr) bPrev->next = a;
            else head = a;
            if (bNext != nullptr) bNext->prev = a;

            a->prev = bPrev;
            a->next = bNext;
            b->prev = aPrev;
            b->next = aNext;
        }

        if (a->prev == nullptr) head = a;
        if (b->prev == nullptr) head = b;
    }

    void shellSort() {
        int n = getLength();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Node* tempNode = getNodeAt(i);
                int j = i;
                while (j >= gap) {
                    Node* prevNode = getNodeAt(j - gap);
                    if (prevNode->sev <= tempNode->sev) break;
                    swapNodes(prevNode, getNodeAt(j));
                    j -= gap;
                    tempNode = getNodeAt(j);
                }
            }
        }
    }

    void print() {
        Node* temp = head;
        cout << "NULL <- ";
        while (temp != nullptr) {
            cout << "[ID:" << temp->id << ", Sev:" << temp->sev << "]";
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
    list.append(101, 50);
    list.append(102, 20);
    list.append(103, 80);
    list.append(104, 10);
    list.append(105, 60);
    list.append(106, 30);

    cout << "Original List: ";
    list.print();

    list.shellSort();

    cout << "Sorted List (by Severity ascending): ";
    list.print();

    return 0;
}