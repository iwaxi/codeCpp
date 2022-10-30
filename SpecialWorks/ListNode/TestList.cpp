#include"ListNode.h"
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    cout << "Welcome to the ListNode by iwaxi_dy.\n\n";
    ListNode* numberList = nullptr;
    int number = 0;
    int n = 0; // length
    cout << "Input size of List: ";
    cin >> n;
    cout << "\nNow you can fill the List, input 114514 to exit any time.\n";
    cout << "tips: Default datatype is integer, if need, you can change element type in line 8.\n\n";
    for(int i = 0; i < n; i++){
        cout << "Input element " << i << " : ";
        cin >> number;
        if(number == 114514)
            break;
        numberList = new ListNode(number, numberList);
    }
    
    cout << "\nThe List has been created.\n   Press 1 to output.\n   Press 2 to delete a member.\n";  
    cout << "   Press 3 to insert a new member.\n   Press 4 to search by value.\n   Press 5 to search by index.\n";
    cout << "   Press 0 to exit\n\nInput: ";
    int key = 0;
    while(cin >> key, key){
        if(numberList == nullptr || numberList->size == 0){
            cout << "Oh, it seems like you have created a zero-length List, so cool.\n  BUT I HAVE TO ERASE IT!!!\n";
            cout << "  Error: 0-length List is illegal.\n";
            system("pause");
            return 0;
        }
        switch (key){
        case 1: numberList->output();break;

        case 2:{
            int indexDel = 0; 
            cout << "Input the index to be deleted: ";  
            cin >> indexDel;
            numberList->delMember(indexDel) == Yes ? cout << " Delete successfully.\n" : cout << " Error: Invalid index.\n";
        } break;

        case 3:{
            int indexInsert = 0; ElemType newValue = 0;
            cout << "Input the insertIndex and newValue: ";
            cin >> indexInsert >> newValue;
            if(numberList->insertMemeber(indexInsert, newValue) == Yes)
                cout << " Insert successfully.\n";
            else if(numberList->insertMemeber(indexInsert, newValue) == 0){
                numberList = new ListNode(newValue, numberList);
                cout << " Insert successfully.\n";
            }
            else
                cout << " Error: Invalid index.\n";
        } break;

        case 4:{
            ElemType Value_to_Find = 0;
            cout << "Input the value to search: ";  cin >> Value_to_Find;
            if(numberList->searchValue(Value_to_Find) != No)
                cout << "The position of value " << Value_to_Find << " is " << numberList->searchValue(Value_to_Find) << endl;
            else
                cout << " Nops = No position to find.\n";
        } break;

        case 5:{
            int Index_to_Find = 0;
            cout << "Input the index to search: "; 
            cin >> Index_to_Find;
            if(numberList->searchIndex(Index_to_Find) != No)
                cout << "The value of index " << Index_to_Find << " is " << numberList->searchIndex(Index_to_Find) << endl;
            else
                cout << " Error: Invalid index.\n";
        } break;

        default: cout << " Error: Invalid operation.\n";  break;
        }
        cout << "\nNext? Input: ";
    }
    numberList->clear();
    numberList = nullptr;
    cout << "Exit safely.\n";
    system("pause");
    return 0;
}