#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> Grid;

void printGrid(Grid grid) {
    for (vector<int> row : grid) {
        for (int x : row) {
            if (x >= 0) {
                cout << " ";
            }
            cout << x << " ";
        }
        cout << endl;
    }
}

Grid markRow(Grid G, int row) {
    for (int i = 0; i < G[row].size(); ++i) {
        G[row][i] = -1;
    }

    return G;
}

Grid markDiagonals(Grid G, int row, int column){
    int i = row - 1;
    int j = column - 1;

    while (i >= 0 && j >= 0) {
        G[i][j] = -1;
        --i;
        --j;
    }

    i = row - 1;
    j = column + 1;
    while (i >= 0 && j < G.size()) {
        G[i][j] = -1;
        --i;
        ++j;
    }

    i = row + 1;
    j = column + 1;
    while (i < G.size() && j < G.size()) {
        G[i][j] = -1;
        ++i;
        ++j;
    }

    i = row + 1;
    j = column - 1;
    while (i < G.size() && j >= 0) {
        G[i][j] = -1;
        ++i;
        --j;
    }

    return G;
}

Grid markColumn(Grid G, int column){
    for (int i = 0; i < G.size(); ++i) {
        G[i][column] = -1;
    }

    return G;
}

int counter = 0;
int placeQueen(Grid G, int row) {
    if (row >= G.size()) {
        return 1;
    }

    int ways = 0;
    for (int i = 0; i < G[row].size(); ++i) {
        Grid temp = G;
        if (temp[row][i] == 0) {
            temp = markDiagonals(markColumn(markRow(temp, row), i), row, i);
            temp[row][i] = 2;

            ways += placeQueen(temp, row + 1);
        }
    }

    return ways;
}

int main() {
    Grid G;

    for (int y = 0; y < 8; ++y) {
        G.push_back({});

        for (int x = 0; x < 8; ++x) {
            G[y].push_back(0);
        }
    }

    cout << "Ways to place the queens: " << placeQueen(G, 0) << endl;

    return 0;
}
