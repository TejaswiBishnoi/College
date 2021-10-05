
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        if(!root) return -1;
        int lef = height(root->left);
        int rig = height(root->right);
        return max(lef, rig) + 1;
    }