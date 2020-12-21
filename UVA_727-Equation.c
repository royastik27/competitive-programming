/**
* UVA 727 - Equation
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>

char stack[50];
int top = -1;

void push(char a){
    stack[++top] = a;
    return;
}

void pop(){
    --top;
    return;
}

int isEmpty(){
    return (top == -1) ? 1 : 0;
}

int calcPrecedence(char a){

    switch(a){

    case '(':
        return 0;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    }
}

int main(){

    int test, preCh, preTop, i;
    char ch, str[51];

    scanf("%d", &test);

    getchar();
    getchar();

    while(test--){

        i = -1;
        while(scanf("%c", &ch)!=EOF){

            if(ch == '\n')
                break;

            if(ch == '(')
                push(ch);
            else if((int)ch >= 48){
                str[++i] = ch;
            }
            else if(ch == ')'){
                while(stack[top] != '('){
                    str[++i] = stack[top];
                    pop();
                }
                pop();
            }
            else{
                if(isEmpty()){
                    push(ch);
                }
                else{
                    preCh = calcPrecedence(ch);
                    preTop = calcPrecedence(stack[top]);

                    while(preCh <= preTop){
                        str[++i] = stack[top];
                        pop();

                        if(isEmpty())
                            break;

                        preTop = calcPrecedence(stack[top]);
                    }

                    push(ch);
                }
            }
            getchar();
        }

        while(!isEmpty()){
            str[++i] = stack[top];
            pop();
        }

        str[++i] = '\0';
        printf("%s\n", str);

        if(test){
            printf("\n");
        }
    }

    return 0;
}
