#include <stdio.h>

#define N 10

int id[N] ;

void quik_find(){
    int i,p,q, t, id[N]; 
    for (i = 0; i< N; i++) id[i] =i;
    printf("-\t-\t");
    for (int j = 0; j<N; j++ ){
            printf("%d\t", id[j]);
    }
    printf("\n");

    while(1) {
        scanf("%d %d", &p, &q);
        // printf("p %d q %d", p,q);
        if (id[p] == id[q]) continue;

        for (t = id[p],i=0; i < N; i++){
            if (id[i] == t) id[i]= id[q]; 
        }

        printf("%d\t%d\t", p, q); 
        for (int j = 0; j<N; j++ ){
            printf("%d\t", id[j]);
        }
        printf("\n");
        // printf("%d %d\n", p, q); 
     }
}

int find(int i){

    while (id[i]!=i)
    {
        i = id[i];
    }
    return i;
}

void union_find(){
    // 初始化环境
    int i,p,q, t; 
    for (i = 0; i< N; i++) id[i] =i;
    printf("-\t-\t");
    for (int j = 0; j<N; j++ ){
            printf("%d\t", id[j]);
    }

    printf("\n");

    while(1) {
        scanf("%d %d", &p, &q);

        // int index, value = 0;

        int index = find(p);
        int value = find(q);

        if (id[index] == id[value]) continue;

        id[index] = value;
        
        printf("%d\t%d\t", p, q); 
        for (int j = 0; j<N; j++ ){
            printf("%d\t", id[j]);
        }
        printf("\n");
        // printf("%d %d\n", p, q); 
     }
}



int main() { 
    union_find();
    return 0;
}