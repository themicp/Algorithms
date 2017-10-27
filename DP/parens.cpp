#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printVectorOfStrings(vector<string> V) {
    for (string s : V) {
        cout << s << endl;
    }
}

vector<string> getCombinations(int pairs, map<int, vector<string>> &M) {
    if (pairs < 1) {
        return {""};
    }
    if (pairs == 1) {
        return {"()"};
    }
    if (M.find(pairs) != M.end()) {
        return M[pairs];
    }

    vector<string> allCombinations;
    vector<string> containedCombinations, rightCombinations;
    --pairs;
    int pairsTemp = pairs;
    while (pairsTemp >= 0) {
        containedCombinations = getCombinations(pairsTemp, M);
        rightCombinations = getCombinations(pairs - pairsTemp, M);

        for (string contained : containedCombinations) {
            for (string right : rightCombinations) {
                allCombinations.push_back("(" + contained + ")" + right);
            }
        }

        --pairsTemp;
    }

    M[pairs] = allCombinations;

    return M[pairs];
}

int main() {
    map<int, vector<string>> M;
    vector<string> combinations = getCombinations(3, M);

    printVectorOfStrings(combinations);

    return 0;
}
