#include <bits/stdc++.h>

using namespace std;

bool canReconstitute(int N, string &C) {
    int countA = 0;
    for (auto &i : C) {
        if (i == 'A') {
            ++countA;
        }
    }
    return countA == N / 2 or countA == N / 2 + 1;
}

int main() {
    int T, N;
    string C;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> C;
        if (canReconstitute(N, C)) {
            cout << "Case #" << i << ": Y\n";
        } else {
            cout << "Case #" << i << ": N\n";
        }
    }
    return 0;
}
