#include <bits/stdc++.h>

using namespace std;

void calculateTrips(int N, string &I, string &O, vector<string> &P) {
    int j;
    for (int i = 0; i < N; ++i) {
        P[i][i] = 'Y';
        j = i + 1;
        while (j < N and O[j - 1] == 'Y' and I[j] == 'Y') {
            P[i][j++] = 'Y';
        }
        j = i - 1;
        while (j >= 0 and O[j + 1] == 'Y' and I[j] == 'Y') {
            P[i][j--] = 'Y';
        }
    }
}

void printPossibilities(vector<string> &P) {
    for (auto &i : P) {
        cout << i << "\n";
    }
}

int main() {
    int T, N;
    string I, O;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> I >> O;
        vector<string> P(N, string(N, 'N'));
        calculateTrips(N, I, O, P);
        cout << "Case #" << i << ": \n";
        printPossibilities(P);
    }
    return 0;
}
