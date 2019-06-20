#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int sum = 0;
    int x = 0;
    n = 0;
    sum = 0;
    while (n < 10){ 
        cin >> x;
        n = n + 1;
        sum = sum + x;
    }
    cout << sum << endl;
}
