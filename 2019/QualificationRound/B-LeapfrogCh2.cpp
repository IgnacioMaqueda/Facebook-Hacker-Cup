#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, cantB;
    string L;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> L;
        N = L.size();
        cantB = 0;
        for (int j = 1; j < N; ++j) {
            if (L[j] == 'B') {
                cantB++;
            }
        }
        if ((cantB >= 2 and cantB < N - 1) or (cantB == 1 and N == 3)) {
            cout << "Case #" << i << ": Y\n";
        } else {
            cout << "Case #" << i << ": N\n";
        }
    }
    return 0;
}
