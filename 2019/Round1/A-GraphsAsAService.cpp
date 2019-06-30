#include <bits/stdc++.h>

using namespace std;

bool isPossible(int N, vector<vector<int> > &adjMatrix, vector<vector<bool> > &requirements) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]) {
                    if (requirements[i][j]) {
                        return false;
                    }
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                }
            }
        }
    }
    return true;
}

void printAdjList(vector<vector<pair<int, int> > > &adjList) {
    for (unsigned int i = 0; i < adjList.size(); ++i) {
        for (unsigned int j = 0; j < adjList[i].size(); ++j) {
            cout << i << " " << adjList[i][j].first << " " << adjList[i][j].second << "\n";
        }
    }
}

int main() {
    int infDist = 1000001;
    int T, N, M, Xi, Yi, Zi;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> M;
        vector<vector<pair<int, int> > > adjList(N + 1);
        vector<vector<int> > adjMatrix(N, vector<int>(N, infDist));
        vector<vector<bool> > requirements(N, vector<bool>(N, false));
        for (int j = 0; j < M; ++j) {
            cin >> Xi >> Yi >> Zi;
            adjMatrix[Xi - 1][Yi - 1] = Zi;
            adjMatrix[Yi - 1][Xi - 1] = Zi;
            requirements[Xi - 1][Yi - 1] = true;
            requirements[Yi - 1][Xi - 1] = true;
            if (Xi < Yi) {
                adjList[Xi].push_back({Yi, Zi});
            } else {
                adjList[Yi].push_back({Xi, Zi});
            }
        }
        cout << "Case #" << i << ": ";
        if (isPossible(N, adjMatrix, requirements)) {
            cout << M << "\n";
            printAdjList(adjList);
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
