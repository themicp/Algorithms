#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<vector<int>> ListOfSets;

void printVector(ListOfSets a) {
    for (auto v : a) {
        cout << "{";
        for (auto item : v) {
            cout << item << ",";
        }
        cout << "}" << endl;
    }
}

ListOfSets combineSubsets(map<int, ListOfSets> subsets, int* input, int index) {
    ListOfSets newSets;

    for (auto subset : subsets[index]) {
        // maintain previous subsets
        newSets.push_back(subset);

        // combine them with the new element
        subset.push_back(input[index]);

        // store them
        newSets.push_back(subset);
    }

    return newSets;
}

int main() {
    int input[] = {1,3,5,8,2};
    map<int, ListOfSets> subsets;

    // subsets of empty set
    subsets[0] = {{}};

    for (int i = 0; i < 5; ++i) {
        // find all the subsets including all the elements
        // until position i
        subsets[i + 1] = combineSubsets(subsets, input, i);
    }

    printVector(subsets[5]);

    return 0;
}
