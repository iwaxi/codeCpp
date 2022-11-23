#include<iostream>
#include<cstdlib>
#include<ctime>
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
private:
    TreeNode* root;
public:
    BinarySearchTree(){ root = nullptr; }
    TreeNode* getRoot(){ return root; }

    void insert(int a){
        if(!root){
            root = new TreeNode;
            root->left = root->right = root->parent = nullptr;
            root->elem = a;
        } 
        else{
            TreeNode* tr = root;
            while(true){
                if(a > tr->elem){
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
                if(a == tr->elem){
                    if(rand() % 2){
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
                if(a < tr->elem){
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
    TreeNode* findmax(){
        if(!root) return nullptr;
        TreeNode* tr = root;
        while(tr->right)
            tr = tr->right;
        return tr;
    }
};

void in_order(TreeNode* tr, TreeNode* max){
        if(!tr) return;
        in_order(tr->left, max);
        if(tr != max) cout << tr->elem << " ";
        else cout << tr->elem << endl;
        in_order(tr->right, max);
    }

int main()
{    
    srand(time(0));
    BinarySearchTree bst;
    int n = 0;
    cin >> n;
    int* data = new int[n]{};
    for(int i = 0; i < n; i++)
        cin >> data[i];
    
    for(int i = n / 2; i > 0; i >>= 1){
        bst.insert(data[i]);
        if(n - i != i) bst.insert(data[n - i]);
        data[i] = -114514;
        data[n - i] = -114514;
    }
    for(int i = 0; i < n; i++){
        if(data[i] != -114514)
            bst.insert(data[i]);
    }
    TreeNode* tr = bst.getRoot();
    in_order(tr, bst.findmax());
    system("pause");
    return 0;
}
