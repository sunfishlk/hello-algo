#include <iostream>
#include <stack>
using namespace std;

// 使用C++内置的stack库实现栈，C没有内置的栈库
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;
}