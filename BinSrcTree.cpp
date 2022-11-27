#include<iostream>
#include"myStack.h"
#include"myQueue.h"
#include<cstdlib>
#include<ctime>
using namespace std;

// Tree node
struct TreeNode
{
    int elem;
    TreeNode* left;
    TreeNode* right;
};

// Maximum
template<typename T>
T myMax(T a, T b){
    return (a > b) ? a : b;
}

// Count node number
int nodeNum(TreeNode* tr){
    if(tr) return 1 + nodeNum(tr->left) + nodeNum(tr->right);
    else return 0;
}

// return tree height
int height(TreeNode* tr){
    if(tr) return 1 + myMax(height(tr->left), height(tr->right));
    else return 0;
}

int last = INT_MIN;
// check Valid BST
bool isBST(TreeNode* tr){
    if(!tr) return true;
    if(!isBST(tr->left)) return false;
    if(tr->elem <= last) return false;
    last = tr->elem;
    if(!isBST(tr->right))return false; 
    return true;
}

// Binary Search Tree
class BinSrcTree
{
private:
    TreeNode* root;
public:
    BinSrcTree() {root = nullptr;}
    TreeNode* getRoot() {return root;}
    // insert element
    void insert(int data){
        TreeNode* node = new TreeNode;  // create new node
        node->elem = data;
        node->left = node->right = nullptr;
        if(!root){             // if root is NULL
            root = node;
            return;
        }
        TreeNode* tr = root;
        while(true){
            if(data < tr->elem){
            __LEFT:     // label left, for lesser
                if(tr->left) tr = tr->left;
                else{
                    tr->left = node;
                    return;
                } 
            }
            else if(data > tr->elem){
            __RIGHT:    // label right, for larger
                if(tr->right) tr = tr->right;
                else{
                    tr->right = node;
                    return;
                } 
            }
            else{       // if equal, goto
                if(rand() % 2) goto __LEFT;
                else goto __RIGHT;
            }
        }
    }
    void preSort(TreeNode* tr){
        if(!tr) return;
        myStack<TreeNode*> stkTr; // stack 
        TreeNode* ptr = nullptr;  // in place of recursive
        stkTr.push(tr);
        while(!stkTr.isEmpty()){
            ptr = stkTr.get();
            stkTr.pop();
            if(ptr->right) stkTr.push(ptr->right);
            cout << ptr->elem << " ";
            if(ptr->left)  stkTr.push(ptr->left);
        }
        cout << endl;
    }
    // in-order traversal
    void inSort(TreeNode *tr){
        if(!tr) return;
        inSort(tr->left);
        cout << tr->elem << " ";
        inSort(tr->right);
    }
    // level traversal
    void level(TreeNode* tr){
        cout << endl;
        int len = (1 << height(tr)) - 1;
        TreeNode** nodes = new TreeNode*[len]{tr};
        for(int i = 0; 2 * i + 2 < len; i++){
            if(!nodes[i]) continue;
            nodes[2 * i + 1] = nodes[i]->left;
            nodes[2 * i + 2] = nodes[i]->right;
        }
        for(int i = 0, j = 0; i < len; i++){
            if(nodes[i])
                cout << nodes[i]->elem << " ";
            if(i == (1 << (j + 1)) - 2){
                cout << endl;
                j ++;
            }
        }
        delete[] nodes;
    }
    // get max_node
    TreeNode* maxNode(TreeNode* tr){
        if(!tr) return nullptr;
        while(tr->right)
            tr = tr->right;
        return tr;
    }
    // get min_node
    TreeNode* minNode(TreeNode* tr){
        if(!tr) return nullptr;
        while(tr->left)
            tr = tr->left;
        return tr;
    }
    ~BinSrcTree(){

    }
};

int main()
{
    srand(time(0));
    BinSrcTree bst;
    /*for(int i = 0; i < 25; i ++)
        bst.insert(5);*/
        
    int a[] = {45, 51, 22, 87, 21, 46, 100, 0, -55};
    for(int i = 0; i < sizeof(a) / sizeof(*a); i++)
        bst.insert(a[i]);
    TreeNode* tr = bst.getRoot();
    bst.inSort(tr);
    bst.level(tr);
    system("pause");
    return 0;
}