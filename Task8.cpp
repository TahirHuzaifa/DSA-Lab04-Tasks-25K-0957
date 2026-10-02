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

    int countTriplets(int X) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0;
        }
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            Node* left = curr->next;
            Node* right = head;
            while (right->next != nullptr) {
                right = right->next;
            }
            while (left != nullptr && right != nullptr && left != right && left->prev != right) {
                int sum = curr->val + left->val + right->val;
                if (sum == X) {
                    count++;
                    left = left->next;
                    right = right->prev;
                } else if (sum < X) {
                    left = left->next;
                } else {
                    right = right->prev;
                }
            }
            curr = curr->next;
        }
        return count;
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
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    int X = 6;

    cout << "Input List: ";
    list.print();
    cout << "X = " << X << endl;

    int result = list.countTriplets(X);
    cout << "Number of triplets summing to " << X << ": " << result << endl;

    return 0;
}