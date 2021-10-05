
/*
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
    vector<Node*> vec;
    void levelOrder(Node * root) {
        vector<Node*> vec;
        vec.push_back(root);
        LevelPrint(vec);
    }
    void LevelPrint(vector<Node*> vec){
        if (!vec.size()) return;
        vector<Node*> Desc;
        for (int i = 0; i < vec.size(); i++){
            cout << vec[i]->data << " ";
            
            if (vec[i]->left) Desc.push_back(vec[i]->left);
            if (vec[i]->right) Desc.push_back(vec[i]->right);
        }
        LevelPrint(Desc);
    }