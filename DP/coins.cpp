#include <cstdio>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

void printMap(map<int, vector<int>> S) {
    for (auto pair : S) {
        cout << pair.first << ": ";
        for (int i : pair.second) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    int N = 11;
    map<int, vector<int>> S;

    S[1].push_back(1);
    S[5].push_back(1);
    S[10].push_back(1);
    S[25].push_back(1);

    for (int i = 1; i <= N; ++i) {
        S[1].push_back(1);

        if (i < 5) {
            S[5].push_back(1);
        } else {
            S[5].push_back(S[1][i] + S[5][i - 5]);
        }

        if (i < 10) {
            S[10].push_back(S[5][i]);
        } else {
            S[10].push_back(S[5][i] + S[10][i - 10]);
        }

        if (i < 25) {
            S[25].push_back(S[10][i]);
        } else {
            S[25].push_back(S[10][i] + S[25][i - 25]);
        }
    }

    printMap(S);

    cout << "Solution: " << S[25][N] << endl;

    return 0;
}
