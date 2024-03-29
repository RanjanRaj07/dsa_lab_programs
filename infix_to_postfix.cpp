#include<iostream>
#define SIZE 50

using namespace std;

char s[SIZE];
int top=-1;

void push(char elem){
    s[++top] = elem;
}

char pop(){
    char elem=s[top];
    s[top]='\0';
    top--;
    return elem;
}

int pre(char elem){
    switch (elem)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '+':
    case '-':
        return 2;
        break;  
    case '*':
    case '/':
    case '%':
        return 3;
        break;
    case '^':
        return 4;
        break;
    }
    return -1;
}

int main(){
    char infix[SIZE], pofix[SIZE], ch, elem;
    int i=0,k=0;
    cout << "enter the infix expression\n";
    cin >> infix;
    cout <<"stack   |s[top]  |symb   |pofix    |\n";
    cout <<"-----------------------------------\n";
    push('#');
    while((ch=infix[i++])!='\0'){
        cout << s <<"\t|"<<s[top]<<"\t|"<<ch<<"\t|"<<pofix<<endl;
        if(ch=='(') push(ch);
        else if(ch==')'){
            while(s[top] != '('){
                pofix[k++] = pop();
                cout << s <<"\t|"<<s[top]<<"\t|"<<ch<<"\t|"<<pofix<<endl;
            }
            elem = pop();                
        }
        else if(isalnum(ch))
            pofix[k++] = ch;
        else{
            while(pre(s[top]) >= pre(ch))
                pofix[k++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#'){
        pofix[k++] = pop();
        cout << s <<"\t|"<<s[top]<<"\t|"<<ch<<"\t|"<<pofix<<endl;
    } 
    cout << s <<"\t|"<<s[top]<<"\t|"<<ch<<"\t|"<<pofix<<endl;
    pofix[k]='\0';
    if (elem == '(')
    cout << "given infix exp: "<<infix<<"\npofix exp obtained: "<<pofix<<endl;
    return 0;
}
