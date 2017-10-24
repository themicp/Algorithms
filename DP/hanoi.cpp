#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

void move(int disks, stack<int> *start, stack<int> *helper, stack<int> *target) {
    if (disks <= 0) {
        return;
    }

    if (disks == 1) {
        int top = start->top();
        start->pop();
        target->push(top);
    } else {
        move(disks - 1, start, target, helper);
        move(1, start, helper, target);
        move(disks - 1, helper, start, target);
    }
}

int main() {
    int disks[] = {1,2,3};
    int N = 3;
    stack<int> start;
    stack<int> helper;
    stack<int> target;

    for (int i = 0; i < N; ++i) {
        start.push(disks[i]);
    }

    move(N, &start, &helper, &target);

    return 0;
}
