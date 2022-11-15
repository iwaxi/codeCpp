#include<iostream>
using namespace std;
struct LNode
{
    int value;
    LNode* next;
    LNode* prev;
};

class deque
{
private:
    LNode* head;
    LNode* tail;
public:
    deque(){
        head = tail = nullptr;
    }
    void push(int p, int n){
        LNode* node = new LNode;
        node->value = n;
        node->next = node->prev = nullptr;
        if(head){
            if(p){
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            else{
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        else{
            head = tail = node;
        }
    }
    void randomAccess(int p){
        int index = 0;
        for(LNode* ptr = head; ptr; ptr = ptr->next, index++){
            if(index == p){
                cout << ptr->value << endl;
                break;
            }
        }
    }
    void pop(int p){
        if(p){
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        else{
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
    }
    ~deque(){
        if(head){
            LNode* ptr = head, *del = nullptr;
            for(; ptr;){
                del = ptr;
                ptr = ptr->next;
                delete del;
                cout << "delele.\n";
            }
        }
    }
};
int main()
{
    int n = 0, m = 0;
    cin >> n;
    deque Deque;
    for(int i = 0; i < n; i++){
        cin >> m;
        switch (m){
            case 0:{
                int p = 0, a = 0;
                cin >> p >> a;
                Deque.push(p, a);
            } break;
            case 1:{
                int p = 0;
                cin >> p;
                Deque.randomAccess(p);
            } break;
            case 2:{
                int p = 0;
                cin >> p;
                Deque.pop(p);
            } break;
        }
    }
    system("pause");
    return 0;
}