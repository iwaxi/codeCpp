#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

const int Add = -1000;
const int Minus = -2000;
const int Multiply = -3000;
const int Divide = -4000;

struct TreeNode
{
    double elem;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

class CalculateTree
{
public:
    TreeNode* root;
    CalculateTree(): root(nullptr){};
    void Insert(double data){
        TreeNode* node = new TreeNode;
        node->elem = data;
        node->left = node->right = node->parent = nullptr;
        if(!root){
            root = node;
            return;
        }
        TreeNode* tr = root;
        if(data < 0 && data > -2500){
            node->left = root;
            root->parent = node;
            root = node;
        }
        else if(data < -2500){
            while(tr->right)
                tr = tr->right;
            if(tr->parent) tr->parent->right = node;
            node->parent = tr->parent;
            tr->parent = node;
            node->left = tr;
            if(tr == root) root = node;
        }
        else{
            while(tr->right)
                tr = tr->right;
            tr->right = node;
            node->parent = tr;
        }
    }
    void postOrder(TreeNode* tr, stack<double>& stk){
        if(!tr) return;
        postOrder(tr->left, stk);
        postOrder(tr->right, stk);
        if(tr->elem > 0) stk.push(tr->elem);
        else{
            double a = 0, b = 0, oper = tr->elem;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            if(oper > -1500)
                stk.push(a + b);
            else if(oper > -2500)
                stk.push(b - a);
            else if(oper > -3500)
                stk.push(a * b);
            else
                stk.push(b / a);
        }
    }
};

int main()
{
    while(true){
        stack<double> stk;
        CalculateTree Tree;    
        char str[250] = "";
        cin.getline(str, 250);
        if(str[0] == '0') break;
        for(char* p = str; *p; p++){
            int a = 0;
            for(; *p >= '0' && *p <= '9'; p++)
                a = a * 10 + ((*p) - '0');
            if(*p == '+') a = Add;
            else if(*p == '-') a = Minus;
            else if(*p == '*') a = Multiply;
            else if(*p == '/') a = Divide;
            if(a) Tree.Insert(a);
        }
        Tree.postOrder(Tree.root, stk);
        printf("%.2f\n", stk.top());
    }
    system("pause");
    return 0;
}

/*#include<iostream>
using namespace std;

template<typename ElemType>
class myStack
{
private:
    ElemType* elemStk;
    int sz;
    int space;
    void checkSize(){
        if(sz + 1 >= space){
            space *= 2;
            ElemType* newElemStk = new ElemType[space]{};
            for(int i = 0; i < sz; i++)
                newElemStk[i] = elemStk[i];
            delete[] elemStk;
            elemStk = newElemStk;
        }
    }
public:
    myStack()
        :sz(0), space(16), elemStk(new ElemType[16]){}
    void push(ElemType data){
        checkSize();
        elemStk[sz++] = data;
    }
    void pop(){
        if(sz) sz--;
        else cout << "error" << endl;
    }
    void out(){
        if(sz){
            for(int i = 0; i < sz; i++)
                cout << elemStk[i] << " ";
            cout << endl;
        }
    }
    ~myStack(){
        if(sz) delete[] elemStk;
        space = sz = 0;
    }
};

template<typename ElemType>
struct LNode
{
    ElemType elem;
    LNode<ElemType>* next;
};

template<typename ElemType>
class myQueue
{
private:
    LNode<ElemType>* front;
    LNode<ElemType>* rear;
public:
    myQueue(): front(new LNode<ElemType>), rear(new LNode<ElemType>){
        front->elem = rear->elem = 0;
        front->next = rear;
        rear->next = front;
    }
    void push(ElemType data){
        rear->elem = data;
        LNode<ElemType>* ptr = new LNode<ElemType>;
        rear->next = ptr;
        ptr->elem = 0;
        rear = ptr;
        rear->next = front;
    }
    void pop(){
        if(front->next != rear){
            LNode<ElemType>* del = front->next;
            front->next = del->next;
            delete del;
        }
        else
            cout << "error" << endl;
    }
    void out(){
        if(front->next != rear){
            LNode<ElemType>* ptr = front->next;
            for(; ptr != rear; ptr = ptr->next)
                cout << ptr->elem << " ";
            cout << endl;
        }
    }
    ~myQueue(){
        while(front != rear){
            LNode<ElemType>* del = front;
            front = front->next;
            delete del;
        }
    }
};

int main()
{
    int m = 0;
    cin >> m;
    myStack<int> * stacks = new myStack<int>[m];
    myQueue<int> * queues = new myQueue<int>[m];
    for(int i = 0; i < m; i++){
        int n = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            string str;
            cin >> str;
            if(str == "push"){
                int num = 0;
                cin >> num;
                stacks[i].push(num);
                queues[i].push(num);
            }
            else if(str == "pop"){
                stacks[i].pop();
                queues[i].pop();
            }
        }
        queues[i].out();
        stacks[i].out();
    }
    delete[] stacks;
    delete[] queues;
    system("pause");
    return 0;
}*/
/*int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string Input;
        cin >> Input;
        int year = 0, month = 0, day = 0, q = 0;
        for(size_t j = 0; j < Input.size(); j++){
            if(Input[j] == '/'){
                q ++;
                continue;
            }
            if(q == 0)
                year = year * 10 + (Input[j] - '0');
            else if(q == 1)
                month = month * 10 + (Input[j] - '0');
            else if(q == 2)
                day = day * 10 + (Input[j] - '0');
        }
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(year % 4 == 0 && year % 100 != 0) months[1] = 29;
        else if(year % 100 == 0 && year % 400 == 0) months[1] = 29;
        int dates = day;
        for(int j = 1; j < month; j++){
            dates += months[j - 1];
        }
        cout << dates << endl;
    }*//*
template<typename T>
void Swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void max_heap(T* data, int start, int end){           
    for(int i = start, j = 2 * i + 1; j < end; ){
        if(j + 1 < end && data[j + 1] > data[j])  
            j ++;                                 
        if(data[i] > data[j])                     
            return;                              
        else{
            Swap(&data[i], &data[j]);            
            i = j;                              
            j = 2 * i + 1;                      
        }
    }
}

template<typename T>
void HeapSort(T* data, int len){
    for(int i = len / 2 - 1; i >= 0; i--)
        max_heap(data, i, len);                  
    for(int i = len - 1; i > 0; i--){
        Swap(&data[i], &data[0]);                
        max_heap(data, 0, i);                    
    }
}*/

/*int n = 0;
    cin >> n;
    int* a = new int[n]{};
    for(int i = 0; i < n; i++)
        cin >> a[i];
    HeapSort(a, n);
    int Data = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(a[i] + a[j] > a[k]) Data ++;
                else break;
            }
        }
    }
    cout << Data << endl;
    delete[] a;*/


/*
template<typename T>
void Swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

class student
{
public:
    int ID;
    string name;
    int Chinese;
    int Math;
    int English;
    int Score = 0;

    student(){
        ID = Chinese = Math = English = Score = 0;
    }
    void input(){
        cin >> ID >> name >> Chinese >> Math >> English;
        Score = Chinese + Math + English;
    }
    void out(){
        cout << ID << " " << name << " " << Score << endl;
    }
    int get(int assess){
        if(assess == 0) return Score;
        else if(assess == 1) return Chinese;
        else if(assess == 2) return Math;
        else if(assess == 3) return English;
        else if(assess == 4) return ID;
    }
};

void Sort(student s[], int low, int high, int assess){
    for(int i = low; i < high - 1; i++){
        for(int j = low; j < high - i - 1; j++){
            if((s + j)->get(assess) < (s + j + 1)->get(assess))
                Swap(s + j, s + j + 1);
        }
    }
}

void Sort_a(student s[], int n, int assess){
    for(int left = 0, right = 0; left < n && right < n; left ++, right ++){
        while(s[right].get(1) == s[right + 1].get(1) && right < n)
            right ++;
        Sort(s, left, right, 1);
        left = right;
    }
}
*//*int n = 0;
    cin >> n;
    student* Stu = new student[n];
    for(int i = 0; i < n; i++)
        (Stu + i)->input();
    Sort(Stu, 0, n, 0);
    Sort_a(Stu, n, 1);
    Sort_a(Stu, n, 2);
    Sort_a(Stu, n, 3);
    Sort_a(Stu, n, 4);
    for(int i = 0; i < 5; i ++)
        Stu[i].out();*/

/*
#include<iostream>
using namespace std;

const int Max = 10000001;

int main()
{
    bool* isPrime = new bool[Max];
    for(int i = 0; i < Max; i++)
        isPrime[i] = true;
    for(int i = 2; i <= Max / 2; i++){
        if(isPrime[i]){
            for(int j = 2; i * j < Max; j++){
                isPrime[i * j] = false;
            }
        }
    }
    int n = 0;
    cin >> n;
    unsigned long long ans = 0;
    for(int i = 2; i < n; i++)
        if(isPrime[i]) ans += i;
    cout << ans << endl;
    delete[] isPrime;
    system("pause");
    return 0;
}*/