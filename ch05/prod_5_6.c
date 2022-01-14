#include <stdio.h>

int max(int arr[], int l, int r){

    int u,v;
    int m = (l+r)/2;
    if (l==r) return arr[l];

    u = max(arr, l, m);
    v = max(arr, m+1, r);
    printf("compare %d Vs %d \n", u,v);
    if (u>v){
        return u;
    }else{
        return v;
    }
}

int max2(int arr[], int l, int r){

   
    int first = arr[l];
     if (l==r){
        return first;
    }
    int m = max2(arr, l+1, r);
    if (first>m){
        return first;
    }else{
        return m;
    }

}

int main(){

    int arr[] = {1,2,4,5,2,1,45,0,1};
    int mm = max(arr, 0, 7);
    printf("max is %d\n",mm);
    printf("max2 is %d \n", max2(arr, 0 ,7));
    // printf("1/2 %d\n", 1/2);

    return 0;
}