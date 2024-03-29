#include <iostream>

using namespace std;

#define MAX 5

class Stack{
    int stack[MAX], top=-1;
    public:
        void push(){
            int item;
            if (top==(MAX-1))
                cout << "Stack Overflow\n";
            else{
                cout << "enter the elements to be inserted:\t";
                cin >> item;
                top += 1;
                stack[top]=item;
            }
        }

        void pop(){
            if (top==-1)
                cout<<"Stack Underflow\n";
            else{
                int item = stack[top];
                top -= 1;
                cout << "\n The elemened poped is :"<<item<<endl;
            }
        }

        void pali(){
            int len=top+1,stop=top, ind=0;
            int num[5], rev[5], i=0;
            while(stop!=-1){
                num[i]=stack[stop];
                stop--;
                i++;
            }
            cout << "the elements in stack are:\n";
            for(int j=0; j<len; j++) cout<<num[j]<<" ";
            cout << endl;
            for(int k=len-1; k>=0; k--){
                rev[k] = num[ind];
                ind++;
            }
            cout << "the elements in the reverse order:\n";
            for(int k=0; k<len; k++) cout<<rev[k]<<" ";
            cout << endl;
            for (i=0; i<len; i++){
                if (num[i]!=rev[i]){
                    cout << "!!The stack is not palindrome\n";
                    break;
                }   
            }
            if (i==len) cout << "the stack is a palindrome\n";
        }

        void display(){
            int i;
            if(top == -1)
                cout << "Stack is Empty\n";
            else{
                cout << "the elements of the stack are: \n";
                for(i=top; i>=0; i--) cout <<stack[i]<<" ";
                cout<<endl;
            }
        }
};

int main(){
    int choice=1;
    Stack s;
    while(choice){
        cout << "------------------STACK OPEATIONS--------------------\n";
        cout << "1.push 2.pop 3.checkpalindrome 4.display 5.exit\n";
        cout << "enter your choice: \t";
        cin >> choice;
        switch (choice)
        {
        case 1: s.push();
            break;
        case 2: s.pop();
            break;
        case 3: s.pali();
            break;
        case 4: s.display();
            break;
        case 5 : exit(0);        
        default: cout <<"\ninvalid choice\n";
            break;
        }
    }
    return 0;
}