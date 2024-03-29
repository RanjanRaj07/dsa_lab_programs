#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int compute(char symbol, float a, float b){
    switch (symbol)
    {
    case '+': return a+b;
        break;
    case '-': return a-b;
        break;
    case '*': return a*b;
        break;
    case '/': 
        if (b==0) cout<<"divide by zero error\n";
        else return a/b;
        break;
    case '$': break;
    case '^': return pow(a,b);
        break;
    default:
        break;
    }
    return -1;
}

int main(){
    int s[20], res, a, b;
    int top, i;
    char postfix[20], symbol;
    cout << "enter the postfix expression\n";
    cin >> postfix;
    top = -1;

    for(i=0;i< strlen(postfix); i++){
        symbol = postfix[i];
        if(isdigit(symbol)){
            s[++top]=symbol-'0';
        }
        else{
            b=s[top--];
            a=s[top--];
            int result = compute(symbol, a, b); 
            s[++top]= result;
        }
    }
    res = s[top--];
    cout << "\nthe result of the expression is: "<<res<<endl;
}