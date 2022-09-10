
// https://codeforces.com/gym/397599/problem/G

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_array(int* arr, int sz) {
     for (int i = 0; i < sz; i++) {
        std::cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int* num_a = new int[n + 1];
    int* num_b = new int[n + 1];
    num_a[0] = num_b[0] = 0;
    for (int i = 1; i <= n; i++) {
        num_a[i] = num_a[i - 1] + (s[i - 1] == 'a' ? 1: 0);
        num_b[i] = num_b[i - 1] + (s[i - 1] == 'b' ? 1: 0);
    }
    // print_array(num_a, n + 1);
    // print_array(num_b, n + 1);

    int max_beauty = 0;
    for (int i = 0; i < n; i++) {
        int max_a_possible = upper_bound(num_b + i + 1, num_b + n + 1, num_b[i] + k) - num_b - i - 1;
        int max_b_possible = upper_bound(num_a + i + 1, num_a + n + 1, num_a[i] + k) - num_a - i - 1;
        // cout << "i = " << i << " max_a = " << max_a_possible << " max_b = " << max_b_possible << "\n";
        max_beauty = max(max_beauty, max(max_a_possible, max_b_possible));
    }

    cout << max_beauty << "\n";
}