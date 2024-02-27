#include <iostream>
#include <vector>

using namespace std;

int fibonacciLastDigit(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = (a + b) % 10;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cout << "Nhập số nguyên dương n: ";
    cin >> n;

    int result = fibonacciLastDigit(n);
    cout << "Chữ số cuối cùng của số Fibonacci thứ " << n << " là: " << result << endl;

    return 0;
}