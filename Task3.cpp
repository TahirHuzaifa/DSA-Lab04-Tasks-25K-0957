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

    Node* reverse(Node* node) {
        Node* prev = nullptr;
        Node* curr = node;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* secondHalf = reverse(slow->next);
        Node* firstHalf = head;
        Node* temp = secondHalf;
        bool result = true;
        while (temp != nullptr) {
            if (firstHalf->val != temp->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        slow->next = reverse(secondHalf);
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
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(1);

    cout << "Input List: ";
    list.print();

    if (list.isPalindrome()) {
        cout << "Output: TRUE" << endl;
    } else {
        cout << "Output: FALSE" << endl;
    }

    return 0;
}