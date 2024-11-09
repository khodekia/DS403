#include <iostream> 
using namespace std; 
 
long long merge2(int arr[], int temp[], int left, int mid, int right) { 
    int i = left; 
        int j = mid + 1; 
    int k = left; 
    long long inv_count = 0; 
 
    while (i <= mid && j <= right) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } else { 
            temp[k++] = arr[j++]; 
            inv_count += (mid - i + 1); 
        } 
    } 
 
    while (i <= mid) { 
        temp[k++] = arr[i++]; 
    } 
 
    while (j <= right) { 
        temp[k++] = arr[j++]; 
    } 
 
    for (i = left; i <= right; i++) { 
        arr[i] = temp[i]; 
    } 
 
    return inv_count; 
} 
 
long long merge1(int arr[], int temp[], int left, int right) { 
    long long inv_count = 0; 
    if (right > left) { 
        int mid = (right + left) / 2; 
        inv_count += merge1(arr, temp, left, mid); 
        inv_count += merge1(arr, temp, mid + 1, right); 
        inv_count += merge2(arr, temp, left, mid, right); 
    } 
    return inv_count; 
} 
 
int main() { 
    int n; 
    cin >> n; 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
 
    int temp[n]; 
    long long inversions = merge1(arr, temp, 0, n - 1); 
 
    cout << inversions << endl; 
 
    return 0; 
}
