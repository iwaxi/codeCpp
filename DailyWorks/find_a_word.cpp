#include<iostream>
#include<string>

using namespace std;
int main()
{
    string word, sentence;
    getline(cin, word);
    string word_U = word;
    word_U[0] = word[0] - ' ';
    int num = 0;
    size_t index = 0;
    while(sentence.find("END_OF_TEXT") == string::npos)
    {
        string input;
        getline(cin, input);
        sentence.append(input);
        size_t t1 = sentence.find(word, index), t2 = sentence.find(word_U, index);
        num += (t1 != string::npos || t2 != string::npos) ? 1 : 0;
        index = (t1 != string::npos || t2 != string::npos) ? index + 1 : index;
    }
    cout << num <<endl;
    system("pause");
    return 0;
}