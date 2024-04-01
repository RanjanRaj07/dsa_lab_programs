#include <iostream>
#include <list>

using namespace std;

struct EmployeeRecord{
    int key;
    string name;
    //add other fields as required
};

class HashTable {
    private:
        static const int M = 10; //no of memory locations
        list<EmployeeRecord> table[M];

        int hashFunction(int key){
            return key % M;
        }
    
    public:
        void insertRecord(int key, const string& name){
            int index = hashFunction(key);
            EmployeeRecord record;
            record.key = key;
            record.name = name;

            int probes = 0;
            //Linear probing with  limited number of probes
            while(probes < M && !table[index].empty()){
                ++index;
                index %= M; //wrap around if index goes beyond the size of the hash table
                ++probes;
            }

            if(probes < M){
                table[index].push_back(record);
            }else{
                cout << "Hash table is full. Unable to insert record with key " << key << endl;
            }
        }

        bool searchRecord(int key, EmployeeRecord& result){
            int index = hashFunction(key);

            for(const auto& record : table[index]){
                if(record.key == key){
                    result = record;
                    return true;
                }
            }
            
            for (int i = index+1; i%M != index; ++i){
                int newIndex = i%M;
                for(const auto& record : table[newIndex]){
                    if(record.key == key){
                        result = record;
                        return true;
                    }
                }
            }

            return false;
        }
        
        void deleteRecord(int key){
            int index = hashFunction(key);

            for(auto it = table[index].begin(); it != table[index].end(); ++it){
                if(it->key == key){
                    cout << "Record with key "<< key << " (Name: "<< it->name <<") deleted."<< endl;
                    table[index].erase(it);
                    return;
                }
            }
            for (int i = index+1; i%M != index; ++i){
                int newIndex = i%M;
                for(auto it = table[newIndex].begin(); it != table[newIndex].end(); ++it){
                   if(it->key == key){
                        cout << "Record with key "<< key << " (Name: "<< it->name <<") deleted."<< endl;
                        table[index].erase(it);
                        return;
                    }
                }
            }
            cout << "Record with key "<< key <<" not found for deletion." << endl;
        }


        void displayTable() {
            for(int i=0; i<M; ++i){
                cout << "Memory location "<< i << ":";
                if(table[i].empty()){
                    cout << "Empty" << endl;
                    continue;
                }
                for(const auto& record : table[i]){
                    cout << "(Key : " << record.key <<", Name: "<< record.name <<")";
                }
                cout << endl;
            }
        }
};

int main(){
    HashTable ht;
    EmployeeRecord result;
    string name;
    int choice;
    cout << "Employee Record Table by modulo Hashing with linear probing\n";
    do{
        cout << "\nEmployee HashTable operation\n";
        cout << "1. insert Employee Records\n";
        cout << "2. serach Employee Record\n";
        cout << "3. display Employee Records HashTable\n";
        cout << "4. delete Employee Record\n";
        cout << "5. exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            int key, ans;
            ans=0;
            do{
                cout << "Enter the Employee ID\t";
                cin >> key;
                cout << "Enter the Employee name\t";
                cin >> name;
                cout <<"\ndo you want to add more Employee Records(0/1)\t";
                cin >> ans;
                ht.insertRecord(key, name);
            }while(ans==1);
            break;

        case 2:
            int searchKey;
            cout << "Enter the Employee ID to search: ";
            cin >> searchKey;
            if(ht.searchRecord(searchKey, result)){
                cout << "\nRecord with key "<< searchKey << " found: Employe Name -- "<<result.name << endl;
            }else{
                cout << "\nRecord with key "<< searchKey << " Not Found." << endl;
            }
            break;
        
        case 3:
            cout << "==============Employee Record HashTable================\n";
            ht.displayTable();
            break;
        
        case 4:
            int deleteKey;
            cout << "Enter the Employee ID to delete\n";
            cin >> deleteKey;
            ht.deleteRecord(deleteKey);
            break;
        
        default:
            if(choice != 5)
                cout << "Invalid choice\n";
            break;
        }
    }while(choice != 5);
    
    return 0;
}