/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    auto temp = root;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '1') temp = temp->right;
        else temp = temp->left;
        if (!(temp->left) && !(temp->right)) {
            cout << temp->data; 
            temp = root;
        }
    }
}