#include<stdio.h>
#include<windows.h>
typedef struct Event
{
    int start;
    int end;
} Eve;

void print(Eve e){
    printf("[%d, %d] ", e.start, e.end);
}


void Swap(Eve* a, Eve* b){
    int tempStart = a->start;
    a->start = b->start;
    b->start = tempStart;
    int tempEnd = a->end;    
    a->end = b->end;
    b->end = tempEnd;
}

void printEvent(struct Event* event, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(event[j].start > event[j + 1].start)
                Swap(event + j, event + j + 1);
            }
        }
    //for(int i = 0; i < len; i++)
    //    print(event[i]);
    //printf("\n");
    for(int i = 0; i < len - 1; i++){
        if(event[i].start == event[i + 1].start)
            for(int j = i; j < len - 1; j++){
                if(event[j].start != event[j + 1].start) break;
                if(event[j].end > event[j + 1].end)
                    Swap(event + j, event + j + 1);
            }
            
        }
    for(int i = 0; i < len; i++)
        print(event[i]);
}


int main()
{
    Eve event[50] = {};
    char c = 0;
    int len = 0;
    
    while(TRUE){
        c = getchar();
        if(c >= '1' && c <= '9' && !(event + len)->start){
            (event + len)->start = c - '0';
            c = getchar();
            if(c >= '0' && c <= '9'){
                (event + len)->start *= 10;
                (event + len)->end += c - '0';
            }
        }
        else if(c >= '1' && c <= '9' && !(event + len)->end){
            (event + len)->end = c - '0';
            c = getchar();
            if(c >= '0' && c <= '9'){
                (event + len)->end *= 10;
                (event + len)->end += c - '0';
            }
        }
        if((event + len)->start && (event + len)->end)
            len ++;
        if(c == '\n')
            break;
    }
    //for(int i = 0; i < len; i++)
    //    print(event[i]);
    //printf("\n");
    printEvent(event, len);
    system("pause");
    return 0;
}

// 1.4.2,3,3,4,1,3,10,20,6,9,1,7,4,10,4,20,5,9,12,23,17,20