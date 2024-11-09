#include <iostream> 
using namespace std; 
 
int main() { 
 
  int number, k;  
  cin >> number >> k; 
 
  char myArray[number]; 
  for (int i = 0; i < number  ; i++){ 
    char charInArray; 
    cin >> charInArray;; 
    myArray[i] = charInArray; 
  } 
 
  char newValue0 = '0' ; 
  int counter = 0; 
  for (int i = number - 1; i >= 0; i--) { 
    for (int j = 1; j <= k; j++) { 
      if (i - j >= 0) { 
        if (myArray[i] == 'P') { 
          if (myArray[i - j] == 'T') { 
            myArray[i] = newValue0; 
            myArray[i - j] = newValue0; 
            counter++; 
            break; 
            } 
        } else if (myArray[i] == 'T') { 
            if (myArray[i - j] == 'P') { 
              myArray[i] = newValue0; 
              myArray[i - j] = newValue0; 
              counter++; 
              break; 
              } 
        } 
      } 
    } 
  } 
 
  cout << counter; 
  return 0; 
}
