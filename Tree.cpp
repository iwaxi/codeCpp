#include<iostream>
#include"myQueue.h"
using namespace std;

template<typename T>
T myMax(T a, T b){
    return (a > b) ? a : b;
}

int Times = 0;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* CreateNode(){
    int data = 0;
    cin >> data;
    TreeNode* node = new TreeNode;
    if(data < 0){                   // end condition
        node = nullptr;
    }
    else{
        node->value = data;
        node->left  = CreateNode(); // priority
        node->right = CreateNode(); // secondly
    }
    return node;
}

int nodeNumber(TreeNode* tr){
    if(tr)  return 1 + nodeNumber(tr->left) + nodeNumber(tr->right);
    else return 0;
}

class BinaryTree
{ 
public:
    TreeNode *root;
    BinaryTree(){
        root = nullptr;
    }
    void CreateTree(){
        root = CreateNode();
    }
    int Depth(TreeNode* tr){
        Times ++;
        if(tr){
            return myMax(1 + Depth(tr->left), 1 + Depth(tr->right));
        }
        else
            return 0;
    }
    int Degree(TreeNode* tr){
        if(tr){
            int i = 0;
            if(tr->left) i++;
            if(tr->right)i++;
            return myMax(i, myMax(Degree(tr->left), Degree(tr->right)));
        }
        else return 0;
    }
    bool isFull(TreeNode* tr){
        return ((1 << Depth(tr)) - 1) == nodeNumber(tr);
    }
    void checkFull(TreeNode* tr){
        if(isFull(tr)) cout << "The Tree is a Full Binary Tree.\n"; 
        else cout << "The Tree is Not a Full Binary Tree.\n";
    }
    
    void preOrderTraversal(TreeNode* tr){
        if(tr){
            if(tr == root) cout << "\npre-order Traversal: " << endl;
            cout << tr->value << " ";
            preOrderTraversal(tr->left);
            preOrderTraversal(tr->right);
            if(!tr->left && !tr->right) cout << endl;
        }
    }

    void inOrderTraversal(TreeNode* tr){
        if(tr){
            if(tr == root) cout << "\nin-order Traversal: " << endl;
            inOrderTraversal(tr->left);
            cout << tr->value << " ";
            inOrderTraversal(tr->right);
            if(!tr->left && !tr->right) cout << endl;
        }
    }

    void postOrderTraversal(TreeNode* tr){
        if(tr){
            if(tr == root) cout << "\npost-order Traversal: " << endl;
            postOrderTraversal(tr->left);
            postOrderTraversal(tr->right);
            cout << tr->value << " ";
            if((!tr->left && !tr->right) || tr == root) cout << endl;
        }
    }
    
    void levelTraversal(TreeNode* tr){
        // 1. Queue version
        myQueue<TreeNode*> queue;
        TreeNode* cur = tr;
        queue.push_back(cur);
        while(!queue.isEmpty()){
            cur = queue.frontElem();  // get front
            queue.pop();              // pop front
            if(cur == tr) cout << "\nlevel Traversal: " << endl;
            cout << cur->value << " ";
            if(cur->left) queue.push_back(cur->left);
            if(cur->right) queue.push_back(cur->right);
        }
        cout << endl << endl;

        // 2. Array version
        int len = (1 << this->Depth(tr)) - 1;
        TreeNode** level = new TreeNode* [len]{tr}; // level[0] = tr;
        for(int i = 0; 2 * i + 2 < len; i++){       // boundary !!!
            if(level[i]){
                level[2 * i + 1] = level[i]->left;
                level[2 * i + 2] = level[i]->right;
            }
        }
        cout << "\nlevel traversal(another): " << endl;
        for(int i = 0, j = 1; i < len; i++){
            if(level[i])   cout << level[i]->value << " ";
            if(i == (1 << j) - 2) {cout << endl;  j++;} // depth
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.CreateTree();
    TreeNode* ptr = tree.root;
    cout << "\nFor the Tree input: \n\n";
    cout << "Depth: " << tree.Depth(tree.root) << endl; 
    cout << "Degree: " << tree.Degree(ptr) << endl;
    cout << "Node numbers: " << nodeNumber(ptr) << endl;
    cout << "Travel Times: " << Times << endl;

    tree.checkFull(ptr);
    tree.checkFull(ptr->right);
    
    tree.preOrderTraversal(ptr);
    //cout << "pre-Order times: " << preTime << endl;
    tree.inOrderTraversal(ptr);
    //cout << "in-Order times: " << inTime << endl;
    tree.postOrderTraversal(ptr);
    //cout << "post-Order times: " << postTime << endl;
    tree.levelTraversal(ptr);
    system("pause");
    return 0;
}    