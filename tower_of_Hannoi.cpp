#include <iostream>

using namespace std;

void transfer(int n, char s, char t, char d){
    if(n==0) return;
    transfer(n-1, s, d, t);
    cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<endl;
    transfer(n-1, t, s, d);
}

int main(){
    int n;
    cout <<"enter the number of discs\t";
    cin >> n;
    transfer(n,'A','B','C');
    return 0;
}