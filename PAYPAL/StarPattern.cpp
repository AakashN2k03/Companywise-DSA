// CODE 360:  Star Pattern

#include <iostream>
using namespace std;

void printPattern(int n) {
    for(int i = 0; i < n; i++) {
        // print spaces
        for(int space = 0; space < n - i-1 ; space++) {
            cout << " ";
        }
        // print stars
        for(int star = 0; star < 2 * i + 1; star++) {
            cout << "*";
        }
        cout << endl;
    }
}
// 🕒 Time Complexity: O(n²)
// 🧠 Space Complexity: O(1)
