#include <stdio.h>
#include <stdlib.h>

void rpoland(){
    char str[] = "((9*2)*(9+1))";

    char stack[20];
    int stack_top = 0;
    char ret[20];
    int ret_idx = 0;

    int i = 0;
    while (str[i] != 0)
    {
        char ch = str[i++];
        // printf("in %c", ch);
        // i++;
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            stack[stack_top++] = ch;
            // stack_top++;
            break;
        
        case '(':
            break;
        
        case ')':
            printf(" %c", stack[stack_top-1]);
            ret[ret_idx++] = stack[--stack_top];
            // stack_top--;
            break;
        default:
            printf(" %c", ch);
            ret[ret_idx++] = ch;
            break;
        }
    }
    ret[ret_idx] = 0;
    printf(" %c", stack[stack_top-1]);
    printf("\n");
    printf("ret: %s\n",ret);

    i = 0;
    char* s[20];
    for (int i=0; i<20; i++){
        char a[2];
        a[0] = '0';
        a[1] = 0;
        s[i] = a;
    }
    int s_top = 0;
    int v = 0;
    while (ret[i] != 0)
    {
        char* lv;char *rv;
        // int v = 0;
        if (ret[i] >='0' && ret[i] <= '9'){

            char *ch = malloc(2*sizeof(char));
            // char ch[2] = "\0"; 
            ch[0] = ret[i++];
            s[s_top][1] = 0;
            // s[s_top][0] = 'c';
            // s[s_top][0] = ret[i++];
            s[s_top++] = ch; // ret[i++] - '0';
            continue;
        }

        switch (ret[i])
        {
        case '+':
            lv = s[--s_top];
            rv = s[--s_top];
            v = atoi(lv) + atoi(rv); 
            // char ch[10] = "\0";
            char *ch1 = malloc(10*sizeof(char));
            // char *vv = sprintf("%d", v);
            sprintf(ch1, "%d", v);
            // itoa(v, ch, 10);
            s[s_top++] = ch1;
            i++;
            break;
        case '-':
        case '*':
            lv = s[--s_top];
            rv = s[--s_top];
            v = atoi(lv) * atoi(rv); 
            // char ch[10] = "\0";
            char *ch = malloc(10*sizeof(char));
            // char *vv = sprintf("%d", v);
            sprintf(ch, "%d", v);
            // itoa(v, ch, 10);
            s[s_top++] = ch;
            i++;
            break;
        case '/':
           
            break;
        default:
            break;
        }
    }
    printf("ret %d\n",v);
    
}

int main(){
    rpoland();
    return 0;
}