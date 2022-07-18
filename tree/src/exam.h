#ifndef EXAM_H
#define EXAM_H

#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

static int depth(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    int left, right = 0;
    left = depth(node->left);
    if (left == -1) return -1;
    right = depth(node->right);
    if (right == -1) return -1;

    return abs(left - right) < 2 ? max(left, right) + 1 : -1;
}

static bool tree_is_balanced(TreeNode *root) {

    return depth(root) != -1;
}

#endif // EXAM_H