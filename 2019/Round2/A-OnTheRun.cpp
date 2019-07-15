#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, M, K, A, B, R1, C1, R2, C2;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> M >> K;
        cin >> A >> B;
        if (K == 1) {
            cin >> R1 >> C1;
            cout << "Case #" << i << ": N\n";
        } else {
            cin >> R1 >> C1;
            cin >> R2 >> C2;
            if (((R1 - A + C1 - B) % 2) == 0 and ((R2 - A + C2 - B) % 2) == 0) {
                cout << "Case #" << i << ": Y\n";
            } else {
                cout << "Case #" << i << ": N\n";
            }
        }
    }
    return 0;
}
