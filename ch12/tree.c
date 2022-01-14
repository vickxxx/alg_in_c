#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node link;


struct node
{
    int data;
    link* left;
    link* right;

};

link* new(int data){

    link* n = (link*)malloc(sizeof(link));

    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void dump_tree(link* head, char* prefix){

    static int prefix_space = 0;

    for (int i=0; i<prefix_space; i++){
        printf("   ");
    }
    if (prefix == NULL){
        prefix = "|- ";
    }
     printf("%s", prefix);
    
    printf("%d\n", head->data);
    if (head->left!=NULL){
        prefix_space++;
        dump_tree(head->left, "|<- ");
        prefix_space--;
    }

    if (head->right!=NULL){
        prefix_space++;
        dump_tree(head->right,  "|-> ");
        prefix_space--;
    }
}

link* find(link* head, int data){

    link* taget = head;
    if (head->data==data){
        return head;
    }
    if ( data < head->data && head->left!=NULL){
        taget = find(head->left, data);
    }
    if ( data > head->data && head->right!=NULL){
        taget = find(head->right, data);
    }
    return taget;
}


link* insert(link* head, int data){

    if (head==NULL){
        return new(data);
    }

    link* parent = find(head, data);
    if (parent->data==data){
        return parent;
    }
    if(data < parent->data){
        parent->left = new(data);
    }else{
        parent->right = new(data);
    }

    return head;
}


link* roll_left(link* head){
    if (head->right==NULL){
        return head;
    }

    link* left = head->left;
    link* right = head->right;
    int data = head->data;

    head->data = right->data;
    head->right = right->right;

    right->data = data;
    right->right = right->left;
    right->left = left;

    head->left = right;

    return head;
}

link* roll_right(link* head){

    if (head->left==NULL){
        return head;
    }


    link* left = head->left;
    link* right = head->right;
    int data = head->data;

    head->data = left->data;
    head->left = left->left;

    left->data = data;
    left->left = left->right;
    left->right = right;

    head->right = left;

    return head;
}

link* insert_root(link* head, int data){

    if (head==NULL || head->data==data){
        head = new(data);
        return head;
    }

    if (data < head->data){
        link* left = insert_root(head->left, data);
        head->left = left;
        roll_right(head);
    }else{
        link* right = insert_root(head->right, data);
        head->right = right;
        roll_left(head);
    }

    return head;
}


int main(){
    printf("hello tree\n");
    time_t t;
    srand((unsigned) time(&t));


    // link* head = new(5);
    // link* n4 = new(4);
    // link* n3 = new(3);
    // link* n2 = new(2);
    // n4->left = n2;
    // head->left = n4;
    // head->right = n3;
    // dump_tree(head, NULL);

    // roll_left(head);
    // dump_tree(head, NULL);

    // roll_right(n4);
    // dump_tree(head, NULL);
    // dump_tree(find(head, 1));

    // link* head = NULL;
    // for (int i=0; i<20; i++){
    //     head = insert(head, i);
    //     i++;
    // }
    // insert(head,2);
    // dump_tree(head, NULL);


    link* head = NULL;
    for (int i=0; i<2000; i++){
        int data = rand() % 50;
        head = insert_root(head, data);
    }
    dump_tree(head, NULL);


    return 0;
}