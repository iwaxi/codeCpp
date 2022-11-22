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
    TreeNode* ancestor;
};

TreeNode* CreateNode(){
    int data = 0;
    cin >> data;
    TreeNode* node = new TreeNode;
    if(data < 0){           // end recursive
        node = nullptr;
    }
    else{
        node->value = data;
        node->left  = CreateNode(); // left
        if(node->left) node->left->ancestor = node;
        node->right = CreateNode(); // right
        if(node->right) node->right->ancestor = node;
    }
    return node;
}

int nodeNumber(TreeNode* tr){
    if(tr)  return 1 + nodeNumber(tr->left) + nodeNumber(tr->right);
    else return 0;
}

int nodeDepth(TreeNode* tr){
        int depth = 0;
        if(!tr) return 0;
        for(TreeNode* ptr = tr; ptr->ancestor; ptr = ptr->ancestor)
            depth ++;
        return depth;
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
        if(root) root->ancestor = nullptr;
    } 
    int Degree(TreeNode* tr){
        if(tr){
            int i = 0;
            if(tr->left) i++;
            if(tr->right)i++;
            return myMax(i, myMax(Degree(tr->left), 
            Degree(tr->right)));
        }
        else return 0;
    }

    int Height(TreeNode* tr){
        Times ++;
        if(tr){
            return myMax(1 + Height(tr->left), 1 + Height(tr->right));
        }
        else
            return 0;
    }
    void Depth(TreeNode* tr){
        cout << "the depth of node is: " << nodeDepth(tr) << endl;
    }
    bool isPerfect(TreeNode* tr){
        return ((1 << Height(tr)) - 1) == nodeNumber(tr) && nodeNumber(tr) > 1;
    }
    void checkPerfect(TreeNode* tr){
        if(isPerfect(tr)) cout << "The Tree is a Perfect Binary Tree.\n"; 
        else cout << "The Tree is Not a Perfect Binary Tree.\n";
    }
    
    void preOrderTraversal(TreeNode* tr){
        if(tr){
            if(tr == root) cout << "\n\npre-order Traversal: " << endl;
            cout << tr->value << " ";
            preOrderTraversal(tr->left);
            preOrderTraversal(tr->right);
            //if(!tr->left && !tr->right) cout << endl;
        }
    }

    void inOrderTraversal(TreeNode* tr){
        if(tr){
            if(tr == root) cout << "\n\nin-order Traversal: " << endl;
            inOrderTraversal(tr->left);
            cout << tr->value << " ";
            inOrderTraversal(tr->right);
            //if(!tr->left && !tr->right) cout << endl;
        }
    }

    void postOrderTraversal(TreeNode* tr){
        if(tr){
            if(tr == root) cout << "\n\npost-order Traversal: " << endl;
            postOrderTraversal(tr->left);
            postOrderTraversal(tr->right);
            cout << tr->value << " ";
            //if((!tr->left && !tr->right) || tr == root) cout << endl;
        }
    }
    
    void levelTraversal(TreeNode* tr){
        if(!tr) return;
        // 1. Queue version
        myQueue<TreeNode*> queue;
        TreeNode* cur = tr;
        queue.push_back(cur);
        while(!queue.isEmpty()){
            cur = queue.frontElem();  // get front
            queue.pop();              // pop front
            if(cur == tr) cout << "\n\nlevel Traversal: " << endl;
            cout << cur->value << " ";
            if(cur->left) queue.push_back(cur->left);
            if(cur->right) queue.push_back(cur->right);
        }
        cout << endl;

        // 2. Array version
        int len = (1 << this->Height(tr)) - 1;
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
            if(i == (1 << j) - 2) {cout << endl;  j++;} // Height
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.CreateTree();
    TreeNode* ptr = tree.root;
    cout << "\nFor the Tree input: \n\n";
    cout << "Tree Height: " << tree.Height(tree.root) << endl; 
    cout << "Degree: " << tree.Degree(ptr) << endl;
    cout << "Node numbers: " << nodeNumber(ptr) << endl;
    cout << "Travel Times: " << Times << endl;

    tree.checkPerfect(ptr);
    tree.checkPerfect(ptr->right);
    
    tree.Depth(ptr->left);

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