//
// Created by king on 2022/7/6.
//
#include <iostream>

using namespace std;

void swap(char *a, char *b) {
    char t;
    t = *a;
    *a = *b;
    *b = t;
}

int N = 1;

string *permute(string input, int index) {
    string p[N];
    if (index >= input.length()) {
        p->append(input);
    }
    for (int i = 0; i < input.length(); ++i) {
        swap(input[index], input[i]);
        string *temp = permute(input, index++);

        swap(input[index], input[i]);
    }
    return p;
}

/* 返回一个以空字符串结尾的char*数组 */
char **permute_string(const char *input) {
    char **res;
    string s = input;
    for (int i = s.length(); i > 1; i--) {
        N = N * i;
    }
    return res;

}


int main() {
    return 0;
}
