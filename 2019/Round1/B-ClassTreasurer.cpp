#include <bits/stdc++.h>

using namespace std;

int minPay(int N, int K, string &students, vector<unsigned long long> &aux) {
    unsigned long long res = 0;
    int a = 0, b = 0, i = N - 1;
    while (i >= 0) {
        if (students[i] == 'A') {
            a++;
            if (a > b) {
                a = 0;
                b = 0;
            }
        } else {
            b++;
            if (b - a > K) {
                b--;
                a++;
                res += aux[i];
                res = res % 1000000007;
                if (a > b) {
                    a = 0;
                    b = 0;
                }
            }
        }
        i--;
    }
    return res;
}

void powers(vector<unsigned long long> &v) {
    int i = 0;
    int n = 1;
    while (i < 1000000) {
        n = (n * 2) % 1000000007;
        v[i] = n;
        i++;
    }
}

int main() {
    vector<unsigned long long> aux(1000000);
    powers(aux);
    int T, N, K;
    string students;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K >> students;
        cout << "Case #" << i << ": " << minPay(N, K, students, aux) << "\n";
    }
    return 0;
}
