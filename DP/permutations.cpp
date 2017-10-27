#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <vector>

using namespace std;

string setToString(set<char> characters) {
    string converted = "";
    for (char c : characters) {
        converted += c;
    }

    return converted;
}

void printSetOfString(set<string> V) {
    for (string s : V) {
        cout << s << endl;
    }
}

void printVectorOfStrings(vector<string> V) {
    for (string s : V) {
        cout << s << endl;
    }
}

vector<string> getPerms(string remainder, string prefix, set<string> &foundPermutations) {
    if (remainder.size() == 1) {
        return {prefix + remainder};
    }

    string leftPart, rightPart;
    vector<string> perms;
    vector<string> currentPerms;
    for (int i = 0; i < remainder.size(); ++i) {
        leftPart = remainder.substr(0, i);
        rightPart = "";
        if (i < remainder.size() - 1) {
            rightPart = remainder.substr(i + 1);
        }

        currentPerms = getPerms(leftPart + rightPart, prefix + remainder[i], foundPermutations);
        for (string perm : currentPerms) {
            if (foundPermutations.find(perm) == foundPermutations.end()) {
                foundPermutations.insert(perm);
                perms.push_back(perm);
            }
        }
    }

    return perms;
}

int main() {
    string input = "abcaac";
    set<string> foundPermutations;

    vector<string> permutations = getPerms(input, "", foundPermutations);
    printSetOfString(foundPermutations);
    return 0;
}
