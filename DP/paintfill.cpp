#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void printScreen(vector<vector<int>> screen) {
    for (auto row : screen) {
        for (auto column : row) {
            cout << column << " ";
        }
        cout << endl;
    }
}

void paint(vector<vector<int>> &screen, int x, int y, int newColor) {
    int originalColor = screen[y][x];

    queue<pair<int, int>> nextPoint;
    nextPoint.push(make_pair(x,y));
    pair<int, int> currentPoint;
    int currX, currY;
    while (!nextPoint.empty()) {
        currentPoint = nextPoint.front();
        nextPoint.pop();

        currX = currentPoint.first;
        currY = currentPoint.second;

        if (currX < 0 || currX >= screen.size() || currY < 0 || currY >= screen.size()) {
            continue;
        }
        if (screen[currY][currX] != originalColor) {
            continue;
        }

        screen[currentPoint.second][currentPoint.first] = newColor;

        printScreen(screen);
        cout << endl;

        nextPoint.push(make_pair(currX - 1, currY));
        nextPoint.push(make_pair(currX + 1, currY));
        nextPoint.push(make_pair(currX, currY - 1));
        nextPoint.push(make_pair(currX, currY + 1));
    }
}

int main() {
    vector<vector<int>> screen = {{0,0,0,0}, {1,1,1,1}, {0,1,0,1}, {1,0,0,1}};

    paint(screen, 0, 1, 2);

    return 0;
}
