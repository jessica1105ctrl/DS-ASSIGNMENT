#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(NULL) {}
};

Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;

    
    int n = 1;
    Node* tail = head;
    while (tail->next) { tail = tail->next; ++n; }
    k %= n;
    if (k == 0) return head;

    
    tail->next = head;

    
    Node* newTail = head;
    for (int i = 1; i < k; ++i) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void printList(Node* head){
    Node* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << ' ';
        p = p->next;
    }
    cout << '\n';
}

int main() {
    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 4;
    head = rotateLeft(head, k); 
    printList(head);
    return 0;
}
