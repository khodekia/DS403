#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> removeElements(vector<int>& arr, int k) {
    stack<int> stk;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top() < arr[i] && k > 0) {
            stk.pop();
            k--;
        }
        stk.push(arr[i]);
    }

    // حالا استک را به یک وکتور تبدیل می‌کنیم
    vector<int> result(stk.size());
    for (int i = stk.size() - 1; i >= 0; i--) {
        result[i] = stk.top();
        stk.pop();
    }

    return result;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    vector<int> result = removeElements(arr, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
