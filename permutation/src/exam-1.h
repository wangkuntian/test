#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>

using namespace std;

void permute(string str, int k, string *result) {
    if (k == str.size() - 1) {
        result->append(str);
        cout << str << endl;
    } else if (k >= str.size()) return;
    for (int i = k; i < str.size(); i++) {
        swap(str[i], str[k]);
        permute(str, k + 1, result);
        swap(str[i], str[k]);
    }
}

char **permute_string(string str) {
    int N = 1;
    for (int i = str.length(); i > 1; i--) {
        N = N * i;
    }
    string res[N];
    char **result = 0;
    result = (char **) malloc(sizeof(char *) * N);
    permute(str, 0, res);
    for (int i = 0; i < res->size(); ++i) {
        result[i] = const_cast<char *>(res[i].c_str());
        cout << res[i] << endl;
    }
    return result;
}


#endif // EXAM_H
