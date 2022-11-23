#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
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
    TreeNode* getRoot(){
        return root;
    }
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
    int height(TreeNode* tr){
        if(!tr) return 0;
        else  return 1 + max(height(tr->left), height(tr->right));
    }
    void level(TreeNode* tr){
        int h = height(tr);
        int len = (1 << h) - 1;
        TreeNode** ptr = new TreeNode*[len]{tr}; 
        for(int i = 0; 2 * i + 2 < len; i++){
            if(ptr[i]){
                ptr[2 * i + 1] = ptr[i]->left;
                ptr[2 * i + 2] = ptr[i]->right;
            }
        }
        for(int i = 0, j = 1; i < len; i++){
            if(ptr[i]){
                cout << setw(1 << (h - j)) << ptr[i]->elem;
                for(int k = 0; k < 1 << (h - j); k++)
                    cout << " ";
            } 
            else{
                for(int k = 0; k < 1 << (h - j + 1); k++)
                    cout << " ";
            }
            if(i == (1 << j) - 2){
                cout << endl;
                j ++;
            }
        }
    }
};

int main()
{    
    srand(time(0));
    int a[] = {10, 4, 2, 7, 8, 9, 20, 5, 6, 7, 55};
    int b[20] = {};    
    BinarySearchTree bst;
    for(int i = 0; i < 20; i++){
        bst.insert(5);
    }

    /*for(int i = 0; i < sizeof(a)/ sizeof(*a); i++)
        bst.insert(a[i]);*/
    bst.findMax();
    bst.findMin();
    TreeNode* tr = bst.getRoot();
    //bst.in_order(tr);
    cout << bst.height(tr) << endl;
    bst.level(tr);
    return 0;
}
