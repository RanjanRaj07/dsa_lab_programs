#include <iostream>
using namespace std;

//Array operations creating, inserting displaying, deleting
class ArrayOperations {
    int n;
    int* array;
    public :
    void create(){
        cout <<"enter the size of the array element "<<endl;
        cin >> n;
        array = new int[n];
        cout << "enter the array elements"<<endl;
        for (int i=0; i<n ;i++){
            cin >> array[i];
        }
    }
    void display(){
        cout << "The array elements are \n";
        for(int i=0;i<n;i++){
            cout << array[i] <<"\t";
        }
    }
    void insert(){
        int p,val;
        cout << "enter the position"<<endl;
        cin >> p;
        if(p >> n || p << 0) 
            cout << "Invalid position\n";
        else{
            cout << "enter the element to be inserted\n";
            cin >> val;
            for (int i=n; i>p; i--){
                array[i] = array[i-1];
            }
            array[p] = val;
            n += 1;
            display();
        }
    }

    void deleteElm(){
        int p,val;
        cout << "enter the position of element to be deleted\n";
        cin >> p;
        if (p > n || p < 0)
            cout <<"invalid position\n";
        else{
            val = array[p];
            for(int i=p; i<n; i++){
                array[i] = array[i++];
            }
            n = n-1;
            cout << "the item deleted is "<<val<<endl;
            display();
        }
    }
    void clearArray(){
        delete[] array;
    }
};

int main(){
    ArrayOperations arr;
    int choice = 1;
    while(choice){
        cout << "\nEnter the your choice\n1) CREATE\n2) DISPLAY \n3) INSERT\n4) DELETE\n5) EXIT"<<endl;
        cin >> choice;
            switch(choice){
                case 1: arr.create(); break;
                case 2: arr.display(); break;
                case 3: arr.insert(); break;
                case 4: arr.deleteElm(); break;
                case 5: exit(0);
                default:
                    cout << "invalid choice\n";
                    arr.clearArray();
                    break;
            }
    }
    return 0;
    
}