int Max = 0, Min = 0; vector<int> Top;
    void worker(vector<Node*> vec, vector<int> pos) {
        if (!vec.size()) return;
        vector<Node*> h1;vector<int> h2;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i]->left) {
                h1.push_back(vec[i]->left);
                h2.push_back(pos[i] - 1);
            }
            if (vec[i]->right) {
                h1.push_back(vec[i]->right);
                h2.push_back(pos[i] + 1);
            }
            
        }
        int x = 0;
        for (int j = 0; j < h2.size(); j++) {
            if (h2[j] > Max) {
                Max = h2[j];
                Top.push_back(h1[j]->data);
            }
            if (h2[j] < Min) {
                Min = h2[j];
                Top.insert(Top.begin() + x, h1[j]->data);
                x++;
            }
        }
        
        worker(h1, h2);
        
    }
    void topView(Node* root) {
        vector<Node*> vec = { root };
        vector<int> pos = { 0 };
        Top.push_back(root->data);
        worker(vec, pos);
        for (auto it = Top.begin(); it != Top.end(); it++){
            cout << *it << " ";
        }
    }