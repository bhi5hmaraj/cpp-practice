// https://codeforces.com/gym/397599/problem/D

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    long long int inventory = x;
    int distressed = 0;
    for (int i = 0; i < n; i++) {
        string op;
        int d;
        cin >> op >> d;
        if (op[0] == '+')
            inventory += d;
        else if (d > inventory) 
            distressed++;
        else
            inventory -= d;
    }

    cout << inventory << " " << distressed << "\n";
}