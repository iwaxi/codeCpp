#include<iostream>
using namespace std;

// List_exercise on 2022/11/15 by iwaxi_dy

struct LNode    // List Node
{            
    int value;
    LNode* next;
    LNode* prev;
};

class List      // List
{
private:
    LNode* head;
    LNode* cursor;
    LNode* end;
public:
    List(){     // Default construct(empty)
        end = new LNode;
        end->value = -1;
        end->next = end->prev = nullptr;
        head = cursor = end;
    }
    void insert(int x){     // Insert
        LNode* node = new LNode;
        node->value = x;
        node->next = cursor;
        if(cursor->prev) cursor->prev->next = node; // prev is nullptr?
        node->prev = cursor->prev;
        cursor->prev = node;
        cursor = node;  // move to new node
        if(!node->prev) head = node;    // cursor wasn't on head?
    }
    void move(int d){   // Move
        if(d > 0){
            for(int i = 0; i < d; i++)
                cursor = cursor->next;
        }
        else if (d < 0){
            for(int i = 0; i > d; i--)
                cursor = cursor->prev;
        }
    }
    void erase(){       // Erase
        if(cursor != end){
            if(cursor->prev) cursor->prev->next = cursor->next;
            cursor->next->prev = cursor->prev;
            LNode* ptr = cursor->next;  // delete node
            delete cursor;
            cursor = ptr;
        }
    }
    void print(){       // Print the whole list
        LNode* ptr = head;
        for(; ptr->next; ptr = ptr->next)
            cout << ptr->value << endl;
    }
    ~List(){        // Clear the list
        LNode* ptr = head;
        for(; ptr; ){
            LNode* that = ptr;
            ptr = ptr->next;
            delete that;
        }
    }
};

int main()
{
    int q = 0;
    cin >> q;
    List list;
    for(int i = 0; i < q; i++){
        int n = 0;
        cin >> n;
        switch (n){
            case 0:{
                int x = 0; cin >> x;
                list.insert(x);
            } break;
            case 1:{
                int d = 0; cin >> d;
                list.move(d);
            } break;
            case 2: list.erase(); break;
        }
    }
    list.print();
    system("pause");
    return 0;
}