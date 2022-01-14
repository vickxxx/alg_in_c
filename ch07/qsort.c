#include <stdio.h>


int part(int arr[], int l, int r){

    int flag = arr[l];

    int i = l;
    int j = r;
    for (; i<=r; i++){
        if (arr[i] <= flag){
            continue;
        }

        while (arr[j]>=flag)
        {
            /* code */
            j--;
            if (j<=i){
                break;
            }
        }
        

        if (i>=j){
            break;
        }

        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    arr[l] = arr[i-1];
    arr[i-1] = flag;

    printf(" flag: %d\t", flag);
    for (int i=0; i<8; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return i-1;

}


int partition (int arr[], int l, int r)
{
    int i = l-1, j=r;
    int v = arr[r];

    for (;;){
        while (arr[++i]< v);
        while (arr[--j] >= v)
        {
           if (j == i) break;
        }

        if (i>=j) break;
        
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;

       
        
    }

    // int t = arr[r];
    arr[r] = arr[i];
    arr[i] = v;
    printf(" flag: %d\t", v);
    for (int i=0; i<8; i++){
    printf("%d\t", arr[i]);
    }
    printf("\n");
    return  i;
} 




int q_sort(int arr[], int l , int r){
    if (r-l<1) return 0;

    int i = part(arr, l, r);

    printf("sort %d - %d \n", l, i-1);
    q_sort(arr, l, i-1);
    printf("sort %d - %d \n", l, i+1);
    q_sort(arr, i+1, r);

    return 0 ;
}

int main(){
    int arr[] = {4,6,5,4,7,2,1,0};
    for (int i=0; i<8; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    // int index = part(arr, 0, 7);

    // int index = partition(arr, 0, 7);

    q_sort(arr, 0, 7);
    for (int i=0; i<8; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    // printf("\n index %d\n",index);

    return 0;
}