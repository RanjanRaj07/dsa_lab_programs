#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        Node* prev;
        int ssn;
        float sal;
        string name, dept, desg, phno;
        Node* next;
        
        Node(int SSN, string n, string dep, string des, float s, string Pno){
            ssn = SSN;
            phno = Pno;
            sal = s;
            name = n;
            dept = dep;
            desg = des;
            prev = nullptr;
            next = nullptr;
        }
};

class DLL{
    private:
        Node* head;
        Node* lastNode;
        int count;
    public:
        DLL(){
            head = nullptr;
        }
        ~DLL(){
            Node* current = head;
            Node* next;
            while(current != nullptr){
                next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
            lastNode = nullptr;
            count = 0;
        }

        void insert_atBegining(int ssn, string name, string dept, string desg, float sal, string phno){
            Node* newNode = new Node(ssn, name, dept, desg, sal, phno);
            if(head == nullptr){
                head = newNode;
                lastNode = head;
                return;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            count++;
        }

        void insert_atEnd(int ssn, string name, string dept, string desg, float sal, string phno){
            // cout << ssn << name << dept << desg << sal << phno;7
            
            Node* newNode = new Node(ssn, name, dept, desg, sal, phno);
            count++;
            if(head == nullptr){
                head = newNode;
                lastNode = head;
                return;
            }
            // Node* temp = head;
            // while(temp->next != nullptr){
            //     temp = temp->next;
            // }
            else{
                lastNode->next = newNode;
                newNode->prev = lastNode;
                lastNode = newNode;
            }
        }

        void display(){
            Node* temp = head;
            if(temp == nullptr){
                cout << "Employe List is empy.\n";
                return;
            }
            cout << "\t\tList of employees:\n";
            cout << "SSN\tName\tDepartment\tDesignation\tSalary\tPhone_no\n";
            while (temp != nullptr){
                cout <<temp->ssn<<" \t"<<temp->name<<" \t"<<temp->dept<<" \t"<<temp->desg<<" \t"<<temp->sal<<" \t"<<temp->phno<<endl;
                temp = temp->next;
            }
            cout << "The total number of employees = "<<count<<endl;
        }

        int delete_atEnd(){
            Node* temp1 = head;
            Node* temp;
            if (head == nullptr){
                cout << "List is empty. Cannot delete\n";
                return 0;
            }
            if(temp1->next == nullptr){
                free(temp1);
                return 0;
            }
            else{
                temp = lastNode->prev;
                temp->next = nullptr;
                cout <<lastNode->ssn<<" "<<lastNode->name<<" "<<lastNode->dept<<" "<<lastNode->desg<<" "<<lastNode->sal<<" "<<lastNode->phno<<"!! employe details deleted !!\n";
                lastNode = temp;
                count--;
                return 0;
            }
        }

        int delete_atBegining(){
            Node* temp = head;
            if(temp->next == nullptr){
                free(temp);
                head = nullptr;
                return 0;
            }
            else{
                head = head->next;
                cout <<temp->ssn<<" "<<temp->name<<" "<<temp->dept<<" "<<temp->desg<<" "<<temp->sal<<" "<<temp->phno<<"!! employe details deleted !!\n";
                free(temp);
                count--;
                return 0;
            }
        }

};

int main(){
    int ch = 1, n, i;
    int ssn;
    float sal;
    string name, dept, desg, phno;
    DLL employeslist;
    while(1){
        cout << "------------------------------------------------------Menu-----------------------------------------------------------------------\n";
        cout << "1:Create DLL of n employes\t2:display\t3:insert_atEnd\n4:delete_atEnd\t5:insert_atBegining\t6:delete_atBegining\n7:exit\n";
        cout << "---------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "enter your choice\n";
        cin >> ch;
        switch (ch){
            case 1:
                cout << "enter the number of employes\n";
                cin >> n;
                for (i=0;i<n;i++){
                    cout << "Enter the "<<i+1<<" employe's details in the order ssn, name, department, designation, salary and phone_no\n";
                    cin >> ssn >> name >> dept >> desg >> sal >> phno;
                    employeslist.insert_atEnd(ssn, name, dept, desg, sal, phno);
                }
                break;
            case 2:
                employeslist.display();
                break;
             case 3:
                cout << "Enter the Employe's details in the order ssn, name, department, designation, salary and phone_no\n";
                cin >> ssn >> name >> dept >> desg >> sal >> phno;
                employeslist.insert_atEnd(ssn, name, dept, desg, sal, phno);
                break;
            case 4:
                employeslist.delete_atEnd();
                break;
            case 5:
                cout << "Enter the Employe's details in the order ssn, name, department, designation, salary and phone_no\n";
                cin >> ssn >> name >> dept >> desg >> sal >> phno;
                employeslist.insert_atBegining(ssn, name, dept, desg, sal, phno);
                break;
            case 6:
                employeslist.delete_atBegining();
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