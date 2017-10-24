#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;

string setToString(set<char> characters) {
    string converted = "";
    for (char c : characters) {
        converted += c;
    }

    return converted;
}

pair<int, vector<string>> calculatePermutations(set<char> characters, map<string, pair<int, vector<string>>> &M) {
    string charactersString = setToString(characters);
    if (M.find(charactersString) != M.end()) {
        return M[charactersString];
    }

    if (characters.size() <= 1) {
        return make_pair<int, vector<string>>(1, {charactersString});
    }

    int counter = 0;
    set<char> temp;
    vector<string> permutations;
    for (char c : characters) {
        temp = characters;
        temp.erase(c);

        pair<int, vector<string>> subPermutations = calculatePermutations(temp, M);

        counter += subPermutations.first;
        for (string permutation : subPermutations.second) {
            permutations.push_back(string(1, c) + permutation);
        }
    }

    M[charactersString] = make_pair(counter, permutations);
    return M[charactersString];
}

int main() {
    string input = "abcde";
    set<char> characters;
    map<string, pair<int, vector<string>>> M;

    for (int i = 0; i < input.size(); ++i) {
        characters.insert(input[i]);
    }

    calculatePermutations(characters, M);
    for (string permutation : M[input].second) {
        cout << permutation << ", ";
    }
    cout << endl;
    return 0;
}
