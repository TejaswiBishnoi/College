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

vector<int> dias;

int dia(BinaryTreeNode* root) {
    if (!root) return 0;
    int left = dia(root->left) + 1;
    int right = dia(root->right) + 1;
    int diam = left + right - 1;
    dias.push_back(diam);
    return max(left, right);
}


int main() {
    
    vector<BinaryTreeNode* > nodes;
    int val; cin >> val;
    vector<int> vals;
    BinaryTreeNode* root = new BinaryTreeNode(val);
    nodes.push_back(root);
    while (cin >> val) {
        vals.push_back(val);
    }

    int x = 0;
    while (x < vals.size()) {
        vector<BinaryTreeNode*> Tran;
        for (int i = 0; i < nodes.size(); i++) {
            if (vals[x] != -1) {
                nodes[i]->left = new BinaryTreeNode(vals[x]);
                Tran.push_back(nodes[i]->left);
            }
            x++;
            if (vals[x] != -1) {
                nodes[i]->right = new BinaryTreeNode(vals[x]);
                Tran.push_back(nodes[i]->right);
            }
            x++;
        }
        nodes = Tran;
    }
    dia(root);
    cout << *max_element(dias.begin(), dias.end());
    return 0;
}
