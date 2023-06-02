#include <iostream>
#include <cmath>

using namespace std;

// 소수인지 여부를 확인하는 함수
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool found = false;
    for (int i = 2; i <= n/2; i++) {
        if (isPrime(i) && isPrime(n-i)) {
            cout << i << " " << n-i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "-1 -1" << endl;
    }
    return 0;
}