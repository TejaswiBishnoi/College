/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool check(Node* root, int max, int min) {
        if (!root) return true;
        if (root->data >= max || root->data <= min) return false;
        return (check(root->right, max, root->data) && check(root->left, root->data, min));
    }

    bool checkBST(Node* root) {
        return (check(root->right, 100000, root->data) && check(root->left, root->data, -1));
    }