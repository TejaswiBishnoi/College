

int height(node* root) {
    if (!root) return -1;
    else return root->ht;
}

node* rr(node* root) {
    node* temp = root->left;
    node* tempa = temp->right;
    temp->right = root;
    root->left = tempa;

    root->ht = max(height(root->left), height(root->right)) + 1;
    temp->ht = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

node* ll(node* root) {
    node* temp = root->right;
    node* tempa = temp->left;
    temp->left = root;
    root->right = tempa;

    root->ht = max(height(root->left), height(root->right)) + 1;
    temp->ht = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

node* lr(node* root) {
    root->left = ll(root->left);
    return rr(root);
}

node* rl(node* root) {
    root->right = rr(root->right);
    return ll(root);
}

int Balance(node* root) {
    return height(root->left) - height(root->right);
}

node* insert(node* root, int val) {
    if (!root) {
        root = new node; root->val = val; root->ht = 0;
        root->left = nullptr, root->right = nullptr;
        return root;
    }
    if (root->val > val) root->left = insert(root->left, val);
    if (root->val < val) root->right = insert(root->right, val);
    root->ht = max(height(root->left), height(root->right)) + 1;
    if (Balance(root) > 1) {
        if (Balance(root->left) > 0)  return rr(root);
        else return lr(root);
    }
    if (Balance(root) < -1) {
        if (Balance(root->right) > 0) return rl(root);
        else return ll(root);
    }
    return root;
}

