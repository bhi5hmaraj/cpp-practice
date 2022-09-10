// https://codeforces.com/gym/397599/problem/H

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
int arr[MAX_N][MAX_N];

int sum_larger_or_smaller(int n, int m, int val, bool get_smaller) {
    /**
     * This function is used to get the sum of differences of values larger or
     * smaller than the given input (val). This is done by using a boolean flag
     * (get_smaller) and xoring it with the filter predicate. The overall effect
     * is that of flipping the comparison sign. 
     * */
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            sum += (arr[i][j] > val) ^ get_smaller ? arr[i][j] - val : 0;
    
    return get_smaller ? -sum : sum;
}  

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;
    int rem = -1;
    bool possible = true;
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            rem = rem == -1 ? arr[i][j] % d : rem; 
            possible &= arr[i][j] % d == rem;   
            sum += arr[i][j];
        }
    
    if (!possible) {
        cout << "-1\n";
        return 0;
    }

    int min_steps = 1e9;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            // steps needed to convert all entries to arr[i][j]
            int steps = (sum_larger_or_smaller(n, m, arr[i][j], false) + 
                        sum_larger_or_smaller(n, m, arr[i][j], true)) / d;
            min_steps = min(min_steps, steps);
        }

    cout << min_steps << "\n";
}