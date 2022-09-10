// https://codeforces.com/gym/397599/problem/C

#include <iostream>
using namespace std;

#define MAX_N 5 * 100000
int arr[MAX_N] = {0};
long long int prefix_sum[MAX_N + 1] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }
    if (prefix_sum[n] % 3 != 0) {
        // We can't split it anyways
        cout << 0 << "\n";
        return 0;
    }
    long long int per_sum = prefix_sum[n] / 3;
    long long int required_prefix_sum = per_sum * 2;
    int required_prefix_sum_count = 0; // Even if the last prefix sum is possible we don't take it
    long long int cnt = 0;

    for (int i = n - 1; i >= 1; i--) {
        // If the ps[i] is T / 3 then we count the number of ps[j] = 2 * T / 3 where j > i 
        cnt += prefix_sum[i] == per_sum ? required_prefix_sum_count : 0;
        required_prefix_sum_count += (prefix_sum[i] == required_prefix_sum) ? 1 : 0;
    }

    cout << cnt << "\n";
}