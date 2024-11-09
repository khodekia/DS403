#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string postfix;
    cin >> postfix;
    stack<int> stk;

    for (char ch : postfix) {
        if (isdigit(ch)) { // age char adade
            stk.push(ch - '0'); // addro be stack vared mikonim
        } else { 
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break; 
            }
            stk.push(result); // natije ra ro return miknim
        }
    }

    cout << stk.top() << endl;
    return 0;
}
