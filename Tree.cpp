#include<iostream>
using namespace std;

template<typename T>
T myMax(T a, T b){
    return (a > b) ? a : b;
}

int deepTimes = 0;
int preTime = 0;
int inTime = 0;
int postTime = 0;

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
bool isComplete(TreeNode* tr){
    if(tr){
        if((tr->left && !tr->right) || (!tr->left && tr->right))
            return false;
        else
            return true && isComplete(tr->left) && isComplete(tr->right);
    }
    else return true;
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
    int Deep(TreeNode* tr){
        deepTimes ++;
        if(tr){
            return myMax(1 + Deep(tr->left), 1 + Deep(tr->right));
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
    void checkComplete(TreeNode* tr){
        if(isComplete(tr)) cout << "Tree is Complete\n"; 
        else cout << "Tree is Not Complete\n";
    }
    void preOrderTraversal(TreeNode* tr){
        preTime ++;
        if(tr){
            if(tr == root) cout << "\npre-order Traversal: " << endl;
            cout << tr->value << " ";
            preOrderTraversal(tr->left);
            preOrderTraversal(tr->right);
            if(!tr->left && !tr->right) cout << endl;
        }
    }
    void inOrderTraversal(TreeNode* tr){
        inTime ++;
        if(tr){
            if(tr == root) cout << "\nin-order Traversal: " << endl;
            inOrderTraversal(tr->left);
            cout << tr->value << " ";
            inOrderTraversal(tr->right);
            if(!tr->left && !tr->right) cout << endl;
        }
    }
    void postOrderTraversal(TreeNode* tr){
        postTime ++;
        if(tr){
            if(tr == root) cout << "\npost-order Traversal: " << endl;
            postOrderTraversal(tr->left);
            postOrderTraversal(tr->right);
            cout << tr->value << " ";
            if((!tr->left && !tr->right) || tr == root) cout << endl;
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.CreateTree();
    TreeNode* ptr = tree.root;

    cout << "Depth: " << tree.Deep(tree.root) << endl; 
    cout << "Travel deepTime: " << deepTimes << endl;
    cout << "Degree: " << tree.Degree(ptr) << endl;

    tree.checkComplete(ptr);
    tree.checkComplete(ptr->right);
    
    tree.preOrderTraversal(ptr);
    cout << "pre-Order times: " << preTime << endl;
    tree.inOrderTraversal(ptr);
    cout << "in-Order times: " << inTime << endl;
    tree.postOrderTraversal(ptr);
    cout << "post-Order times: " << postTime << endl;

    system("pause");
    return 0;
}    
//cout << ptr->value << " " << ptr->left->value << " " << ptr->left->left->value << " " << endl;