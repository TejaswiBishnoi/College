/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/



    Node* insert(Node* root, int data) {
        if (!root) root = new Node(data);
        if (root->data > data && !root->left) root->left = new Node(data);
        else if (root->data < data && !root->right) root->right = new Node(data);
        else {
            if (root->data > data) insert(root->left, data);
            else if (root->data < data) insert(root->right, data);
        }
        
        return root;
    }