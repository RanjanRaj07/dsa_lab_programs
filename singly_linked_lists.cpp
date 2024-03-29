#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
    string usn;
    string name;
    string branch;
    int sem;
    string phno;
    Node* next;

    Node(string u, string n, string b, int s, string p){
        usn = u;
        name = n;
        branch = b;
        sem = s;
        phno = p;
        next = nullptr;
    }
};

class SSL{
    private:
        Node* head;
    
    public:
        SSL(){
            head = nullptr;
        }
        ~SSL(){
            Node* current = head;
            Node* next;
            while(current != nullptr){
                next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }

        void insert_atBegining(string usn, string name, string branch, int sem, string phno){
            Node* newNode = new Node(usn,name,branch,sem,phno);
            newNode->next = head;
            head = newNode;
        }
        void insert_atEnd(string usn, string name, string branch, int sem, string phno){
            cout <<usn<<name<<branch<<sem<<phno<<endl;
            Node* newNode = new Node(usn,name,branch,sem,phno);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void display() {
            Node* temp = head;
            if(temp == nullptr){
                cout << "List is empty\n";
                return;
            }
            while(temp != nullptr){
                cout << "USN: "<< temp->usn<<", Name: "<<temp->name<<", Branch: "<<temp->branch<<", Sem: "<<temp->sem<<", Phno: "<<temp->phno<<endl;
                temp = temp->next;
            }
        }

        void delete_atBegining(){
            if(head == nullptr){
                cout << "List is empty. Cannot delete.\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void delete_atEnd(){
            if (head == nullptr){
                cout << "List is empty. Cannot delete\n";
                return;
            }
            if (head->next == nullptr){
                delete head;
                head = nullptr;
                cout << "deleting student data\n";
            cout <<"USN: "<< head->usn<<", Name: "<<head->name<<", Branch: "<<head->branch<<", Sem: "<<head->sem<<", Phno: "<<head->phno<<endl;
                return;
            }
            Node* temp = head;
            while (temp->next->next != nullptr){
                temp = temp->next;
            }
            cout << "deleting student data\n";
            cout <<"USN: "<< temp->usn<<", Name: "<<temp->name<<", Branch: "<<temp->branch<<", Sem: "<<temp->sem<<", Phno: "<<temp->phno<<endl;
            delete temp->next;
            temp->next = nullptr;
        }
};

int main(){
    int ch = 1, n , i, sem;
    string usn,name,branch,phno;
    SSL studentlist;
    while(1){
        cout << "-------------------------Menu---------------------------\n";
        cout << "1:Create SLL\t2:display\t3:insert_atEnd\n4:delete_atEnd\t5:insert_atBegining\t6:delete_atBegining\n7:exit\n";
        cout << "--------------------------------------------------------\n";
        cout << "enter your choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the number of students\n";
            cin >> n;
            for (i=0;i<n;i++){
                cout << "Enter the "<<i+1<<" students details in the order usn, name, branch, sem, phno\n";
                cin >> usn >> name >> branch >> sem >> phno;
                studentlist.insert_atEnd(usn,name,branch,sem,phno);
            }
            break;
        case 2:
            studentlist.display();
            break;
        case 3:
            cout << "Enter the students details in the order usn, name, branch, sem, phno\n";
            cin >> usn >> name >> branch >> sem >> phno;
            studentlist.insert_atEnd(usn,name,branch,sem,phno);
            break;
        case 4:
            studentlist.delete_atEnd();
            break;
        case 5:
            cout << "Enter the student details in the order usn, name, branch, sem, phno\n";
            cin >> usn >> name >> branch >> sem >> phno;
            studentlist.insert_atBegining(usn,name,branch,sem,phno);
            break;
        case 6:
            studentlist.delete_atBegining();
            break;
        case 7:
            exit(0);
            break;
        
        default:
            cout << "wrong choice\n";
            break;
        }
    }
}