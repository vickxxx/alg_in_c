#include <stdio.h>
#include <stdlib.h>

// 约瑟夫问题
#define N 9
#define M 5

typedef struct  node* link;

struct node{
    int item;
    link next;
};


void dump_link(link head, int cnt){
    link t = head;
    for(int j=0; j<cnt; j++){
            printf("\t%d", t->item);
            t = t->next;
        }
        printf("\n");
}

void dump_arr(int arr[N+1]){

    for (int i=0; i< N+1; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

void dump_arr2(int item[], int next[]){

    printf("idx-:");
    for (int i=0; i< N; i++){
        printf("%d\t", i);
    }
    printf("\n");
    printf("item:");
    for (int i=0; i< N; i++){
        printf("%d\t", item[i]);
    }
    printf("\n");

    printf("next:");
    for (int i=0; i< N; i++){
        printf("%d\t", next[i]);
    }
    printf("\n\n");
}


int josephus_link(){
    link head = malloc(sizeof(head));
    head->next = head;
    head->item = 1;
    link tail = head;
    for (int n=1; n<N; n++){
        link t = malloc(sizeof(t));
        t->item = n+1;
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
    int cnt = N;

    dump_link(head, cnt);

    while (head != head->next)
    {
        /* code */
        // 寻找待删除的父节点
        for(int i=1; i<M-1; i++){
            head = head->next;
        }
        // delete
        head->next = head->next->next;
        head = head->next; // 注意，从父节点删除，需要矫正头节点
        cnt--;

        dump_link(head, cnt);
    }
    
    printf("final node: %d\n", head->item);
    return 0;
}

// 直接采用数组处理
int seat[N+1];
int josephus_arr1(){

    seat[0] = 1; // 消除边界

    int cur_idx = 0;
    int total = N;
    dump_arr(seat);

    while (total>1)
    {
        int clear_idx = cur_idx;
        int step = M;
        while (step>0)
        {
            clear_idx++;
            clear_idx = (clear_idx)%(N+1);
            if (seat[clear_idx] == 1){
                continue;
            }
            step--;
        }
        total--;
        seat[clear_idx]=1;
        cur_idx = clear_idx;
        dump_arr(seat);
        printf("clear_idx:%d;\t", clear_idx);
        printf("total:%d; cur_idx:%d; \n", total, cur_idx);
    }
    printf("final clear %d\n", cur_idx);
    int i = 0;
    while (seat[i])
    {
       i++;
    }
    printf("final live %d\n", i);
    
    return 0;
}


// 数组实现链表
int josephus_arr2(){

    int item[N], next[N];
    for (int i=0; i<N; i++){
        item[i] = i+1;
        next[i] = i+1;
    }
    next[N-1] = 0;

    dump_arr2(item, next);


    int cur_idx = 0;

    while (cur_idx != next[cur_idx])
    {
        int step = M-2; // 寻找父节点
        while(step>0){
            step--;
            cur_idx = next[cur_idx];
        }

        // 删除子节点
        next[cur_idx] = next[next[cur_idx]];
        cur_idx = next[cur_idx]; // 移动浮标

        dump_arr2(item, next);

    }
    
    printf("final %d\n", cur_idx+1); // item 完全没有必要保留

    return 0;
}

int main(){

    // josephus_link();
    // josephus_arr1();
    josephus_arr2();
    
    return 0;
}