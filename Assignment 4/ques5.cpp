#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;  // active: q1

public:
    void push(int x) {
        // 1) Put new item in the empty q2
        q2.push(x);
        // 2) Move everything from q1 to q2 so x ends up in front
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // 3) Swap roles: q1 becomes the new active queue
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) { cerr << "Stack underflow\n"; return; }
        q1.pop();
    }

    int top() const {
        if (q1.empty()) { cerr << "Stack is empty\n"; return INT_MIN; }
        return q1.front();
    }

    bool empty() const { return q1.empty(); }

    int size() const { return (int)q1.size(); }
};

int main() {
    StackTwoQueues st;
    st.push(10);
    st.push(20);
    st.push(30);   // top -> 30
    cout << st.top() << "\n"; // 30
    st.pop();                 // remove 30
    cout << st.top() << "\n"; // 20
    st.push(40);              // top -> 40
    cout << st.top() << "\n"; // 40
    return 0;
}
