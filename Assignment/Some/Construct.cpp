#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode* Gen(int sizee, vector<int> pre, vector<int> in) {
    if (!sizee) return nullptr;
    int rootval = pre[0];
    BinaryTreeNode* root = new BinaryTreeNode(rootval);
    vector<int> rightside, rightside_, leftside, leftside_;
    auto it = find(in.begin(), in.end(), rootval);
    for (auto itt = in.begin(); itt != it; itt++) {
        leftside.push_back(*itt);
    }
    for (int i = 1; i <= 0 - distance(it, in.begin()); i++) {
        leftside_.push_back(pre[i]);
    }
    root->left = Gen(leftside.size(), leftside_, leftside);
    for (auto itt = it + 1; itt != in.end(); itt++) {
        rightside.push_back(*itt);
    }
    for (int i = 0 - distance(it, in.begin()) + 1; i < pre.size(); i++) {
        rightside_.push_back(pre[i]);
    }
    root->right = Gen(rightside.size(), rightside_, rightside);
    return root;
}

int main() {
    int n; cin >> n;
    vector<int> PreOr, InOr;

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        PreOr.push_back(val);
    }

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        InOr.push_back(val);
    }

    BinaryTreeNode* root = Gen(n, PreOr, InOr);

    vector<BinaryTreeNode*> vals = { root };
    while (!vals.empty()) {

        vector<BinaryTreeNode*> Tran;
        for (int i = 0; i < vals.size(); i++) {
            cout << vals[i]->data << " ";
            if(vals[i]->left)Tran.push_back(vals[i]->left);
            if(vals[i]->right)Tran.push_back(vals[i]->right);
        }
        vals = Tran;
        cout << endl;
    }

    return 0;
}
