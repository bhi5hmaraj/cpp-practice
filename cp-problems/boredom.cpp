// https://codeforces.com/gym/397599/problem/A

#include <iostream>
using namespace std;


#define MAX_ELEM 100000

int freq[MAX_ELEM + 1] = {0};
long long int dp[MAX_ELEM + 1] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    dp[1] = freq[1] * 1;
    for (int i = 2; i <= MAX_ELEM; i++) {
        dp[i] = std::max(dp[i - 1], 1LL * freq[i] * i + dp[i - 2]);
    }

    cout << dp[MAX_ELEM] << "\n";
}