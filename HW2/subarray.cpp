#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        max_current = max(arr[i], max_current + arr[i]);
        max_global = max(max_global, max_current);
    }

    return max_global;
}

int main() {
    string input;
    getline(cin, input);
    
    istringstream iss(input);
    vector<int> arr;
    int num;
    
    while (iss >> num) {
        arr.push_back(num);
    }

    int result = maxSubarraySum(arr);
    cout << result << endl;

    return 0;
}
