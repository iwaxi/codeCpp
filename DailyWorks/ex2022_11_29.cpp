#include<iostream>
#include<ctime>
#include<cstdlib>
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
    BinarySearchTree():root(nullptr){}

    void insert(int data){
        TreeNode* node = new TreeNode;  
        node->elem = data;
        node->left = node->right = node->parent = nullptr;
        if(!root){
            root = node;
            return;
        }
        TreeNode* tr = root;
        while(true){
            if(data < tr->elem){
            __LEFT:
                if(tr->left) tr = tr->left;
                else{
                    tr->left = node;
                    node->parent = tr;
                    return;
                } 
            }
            else if(data > tr->elem){
            __RIGHT:
                if(tr->right) tr = tr->right;
                else{
                    tr->right = node;
                    node->parent = tr;
                    return;
                } 
            }
            else{
                if(rand() % 2) goto __LEFT;
                else goto __RIGHT;
            }
        }
    }

    TreeNode* maxNode(){
        TreeNode* tr = root;
        if(!tr) return nullptr;
        while(tr->right)
            tr = tr->right;
        return tr;
    }

    void Delete(){
        TreeNode* tr = root;
        if(!tr) return;
        while(tr->right)
            tr = tr->right;
        if(tr == root)
            root = root->left;
        else{
            if(tr->left)
                tr->parent->right = tr->left;
            else tr->parent->right = nullptr;
        }
        delete tr;
    }
};

int main()
{
    srand(time(0));
    int n = 0, q = 0;
    cin >> n >> q;
    BinarySearchTree* BSTs = new BinarySearchTree[n];
    for(int i = 0; i < q; i++){
        int a = 0, id = 0;
        cin >> a >> id;
        if(a == 0){
            int num = 0;
            cin >> num;
            BSTs[id].insert(num);
        }
        else if(a == 1){
            TreeNode* tr = BSTs[id].maxNode();
            if(tr) cout << tr->elem << endl;
        }
        else if(a == 2){
            BSTs[id].Delete();
        }
    }
    system("pause");
    return 0;
}


/*template<typename ElemType>
struct LNode
{
    ElemType elem;
    LNode* next;
};

template<typename ElemType>
class BinarySearchTreeivate:
    LNode<ElemType>* front;
    LNode<ElemType>* rear;
public:
    BinarySearchTreeront(new LNode<ElemType>), rear(new LNode<ElemType>){
        front->elem = rear->elem = 0;
        front->next = rear;
        rear->next = front;
    }
    void push_back(ElemType data){
        rear->elem = data;
        LNode<ElemType>* ptr = new LNode<ElemType>;
        rear->next = ptr;
        ptr->elem = 0;
        rear = ptr;
        rear->next = front;
    }
    void frontElem(){
        cout << front->next->elem << endl;
    }
    void pop(){
        if(front->next != rear){
            LNode<ElemType>* del = front->next;
            front->next = del->next;
            delete del;
        }
    }
    bool isEmpty(){ return front->next == rear;}
};*/

/*template<typename ElemType>
class BinarySearchTreeivate:
    ElemType* elem;
    int sz;
    int space;
    void checkSize(){
        if(sz + 1 >= space){
            space *= 2;
            ElemType* newElem = new ElemType[space]{};
            for(int i = 0; i < sz; i++)
                newElem[i] = elem[i];
            delete[] elem;
            elem = newElem;
        }
    }
public:
BinarySearchTree      :sz(0), space(16), elem(new ElemType[16]{}){}
    void push(ElemType data){
        checkSize();
        elem[sz++] = data;
    }
    void top(){
        if(sz) cout << elem[sz - 1] << endl;
    }
    void pop(){
        if(sz) sz--;
    }
    bool isEmpty(){
        return sz == 0;
    }
    ~BinarySearchTree       delete[] elem;
        space = sz = 0;
    }
};*/


/*int main()
{
    int n = 0;
    cin >> n;
    int* data = new int[n]{};
    for(int i = 0; i < n; i++)
        cin >> data[i];
    int index = 1;
    int* ans = new int[n]{};
    ans[0] = data[0];
    for(int i = 0; i < n; i++){
        if(data[i] != ans[index - 1])
            ans[index++] = data[i];
    }
    for(int i = 0; i < index; i++)
        cout << ans[i] << " ";
    cout << endl;
    delete[] data;
    delete[] ans;
    system("pause");
    return 0;
}*/
/*
#include<iostream>
using namespace std;

struct LNode
{
    int elem;
    LNode* next;
    LNode* prev;
};

class List
{
private:
    LNode* head;
public:
    List(): head(new LNode){
        head->next = head->prev = nullptr;
        head->elem = 0;
    }
    void insert(int a){
        LNode* node = new LNode;
        node->elem = a;
        node->next = node->prev = nullptr;
        if(!head->next){
            head->next = node;
            node->prev = head;
        }
        else{
            LNode* ptr = head;
            for(; ptr->next; ptr = ptr->next){
                if(ptr->next->elem >= a) break;
            }
            if(ptr->next) ptr->next->prev = node;
            node->next = ptr->next;
            node->prev = ptr;
            ptr->next = node;
        }
    }
    void merge(LNode* h){
        for(; h; h = h->next)
            insert(h->elem);
    }
    void clear(){
        for(; head->next != nullptr; ){
            LNode* ptr = head;
            head = head->next;
            delete ptr;
        }
    }
    void out(){
        LNode* ptr = head->next;
        for(; ptr; ptr = ptr->next)
            cout << ptr->elem << " ";
        cout << endl;
    }
    LNode* getHead(){ return head;}

    ~List(){
        clear();
    }
};

int main()
{
    int n = 0, q = 0;
    cin >> n >> q;
    List* lists = new List[n];
    for(int i = 0; i < q; i++){
        int a = 0, id = 0;
        cin >> a >> id;
        if(a == 0){
            int num = 0;
            cin >> num;
            lists[id].insert(num);
        }
        if(a == 1){
            lists[id].out();
        }
        if(a == 2){
            int idNew = 0;
            cin >> idNew;
            lists[idNew].merge(lists[id].getHead()->next);
            lists[id].clear();
        }
    }
    delete[] lists;
    system("pause");
    return 0;
}*/