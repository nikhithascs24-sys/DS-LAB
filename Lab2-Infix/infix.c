#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int top=-1;
void push(char arr[],char var){
    if(top>=SIZE-1){
        printf("stack overflow\n");

        }
        
        top++;
        arr[top]=var;
        printf("enter the char%s\n",arr);
}
char pop(char arr[]){
     printf("%s %d\n",arr,top);
    if(top==-1){
        printf("stack underflow");
        return 0;
    }

    return arr[top--];
}
int pred(char op){
    switch (op){
        case '^':return 3;break;
        case '*':
        case '/':return 2;break;
        case '+':
        case '-':return 1;break;
        default:return 0;break;
    }
}


int main()
{
    char infix[SIZE],postfix[SIZE],stack[SIZE],op;
    while(1)
    {
        int i=0,j=0;
        top=-1;
        printf("ENTER THE INFIX EXPRESSION:");
        scanf("%s",infix);
        push(stack,'(');

        if(infix[i]=='0')
        {
            break;
        }
        for(i=0;infix[i]!='\0';i++)
        {
            switch (infix[i])
            {
            case '(':
                push(stack,infix[i]);
                break;
            case ')':
                while(stack[top]!='(')
                {
                    postfix[j++]=pop(stack);
                }
                pop(stack);
                break;
            case '*':
            case '/':
            case '^':
            case '+':
            case '-':
               // while((pred(stack[top])>=pred(infix[i]))&& top!=-1)
                while(top!=-1 && pred(stack[top])>=pred(infix[i]))
                {
                    postfix[j++]=pop(stack);
                }
                push(stack,infix[i]);

                break;
            default:
                postfix[j++]=infix[i];
                //push(stack,infix[i]);

            }

        }
        while(top!=-1) 
        //while(top!=-1 && stack[top]!='(')
        {
            postfix[j++]=pop(stack);//stack[top--];
        }
        postfix[j]='\0';
        printf("THE POSTFIX EXPRESSION IS:%s\n",postfix);
    }
    return 0;

}
