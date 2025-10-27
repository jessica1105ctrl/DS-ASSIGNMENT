#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(NULL) {}
};


void removeLoop(Node* head)
{
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return; 

    
    slow = head;
    if (slow == fast) 
    { 
        while (fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return;
    }
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
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
    
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(3);
    head->next->next->next = new Node(6);

    Node* last = head;
    while (last->next) last = last->next;
    last->next = head->next; 

    removeLoop(head);
    printList(head);         
    return 0;
}
