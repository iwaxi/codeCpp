#include<iostream>
using namespace std;
struct TreeNode
{
    int elem;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

class BinarySearchTree
{
public:
    TreeNode* root;
    BinarySearchTree(){ root = nullptr; }
    void insert(int a){
        if(!root){
            root = new TreeNode;
            root->left = root->right = root->parent = nullptr;
            root->elem = a;
        } 
        else{
            TreeNode* tr = root;
            while(true){
                if(a >= tr->elem){
                    if(tr->right)
                        tr = tr->right;
                    else{
                        tr->right = new TreeNode;
                        tr->right->parent = tr;
                        tr->right->elem = a;
                        tr->right->left = tr->right->right = nullptr;
                        break;
                    }
                }
                //else if(a == tr->elem) return;
                else{
                    if(tr->left)
                        tr = tr->left;
                    else{
                        tr->left = new TreeNode;
                        tr->left->parent = tr;
                        tr->left->elem = a;
                        tr->left->left = tr->left->right = nullptr;
                        break;
                    }
                }
            }
        }
    }
    void findMax(){
        if(!root) return;
        TreeNode* tr = root;
        while(tr->right)
            tr = tr->right;
        cout << "Maximum element: " << tr->elem << endl;
    }
    void findMin(){
        if(!root) return;
        TreeNode* tr = root;
        while(tr->left)
            tr = tr->left;
        cout << "Minimum element: " << tr->elem << endl;
    }
    void in_order(TreeNode* tr){
        if(!tr) return;
        in_order(tr->left);
        cout << tr->elem << " ";
        in_order(tr->right);
    }
};

int main()
{
    int a[] = {10, 4, 2, 7, 8, 9, 20, 5, 6, 7, 55};
    BinarySearchTree bst;
    for(int i = 0; i < sizeof(a)/ sizeof(*a); i++)
        bst.insert(a[i]);
    bst.findMax();
    bst.findMin();
    bst.in_order(bst.root);
    return 0;
}
