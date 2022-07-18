//
// Created by king on 2022/7/18.
//

#include <iostream>
#include "algorithm"

using namespace std;


void perm(string str, int a, int b) {
    if (a == b) {
//		输出长度为 b+1
        for (int i = 0; i <= b; i++) {
            cout << str[i];
        }
        cout << endl;
    }

    for (int k = a; k <= b; k++) {
        swap(str[k], str[a]);
        perm(str, a + 1, b);
        swap(str[k], str[a]);
    }
}

int main() {
    string str = "qwe";
    sort(str.begin(), str.end());
    int n = str.size();
    perm(str, 0, n - 1);
}