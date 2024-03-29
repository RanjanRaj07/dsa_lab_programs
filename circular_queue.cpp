#include <iostream>
using namespace std;

class Queue{
    private:
        int front, rear, size;
        int *q;
        int capacity;
    public:
        Queue(int cap){
            capacity = cap;
            q = new int[capacity];
            size = 0;
            front = rear =-1;
        }
        ~Queue(){
            delete[] q;
        }

        void insert(int value){
            if(size == capacity){
                cout << "Queue is full\n";
                return;
            }
            rear = (rear+1) % capacity;
            q[rear]=value;
            size++;
            if (front == -1){
                front = rear;
            }
        }

        void delet(){
            if (front == -1){
                cout << "Queue is empty\n";
                return;
            }
            cout << "Element deleted from the queue is :"<< q[front] << endl;
            front = (front+1) %capacity;
            size--;
            if (size==0){
                front = rear = -1;
            }
        }
        void display(){
            if(front == -1){
                cout << "Queue is empty\n";
                return;
            }
            int i = front;
            while(i!=rear){
                cout << q[i]<<" ";
                i = (i+1)%capacity;
            }
            cout << q[rear] << endl;
        }

};

int main(){
    int ch=1;
    Queue queue(5);
    cout << "\nCircular queue operations\n";
    while(ch){
        cout << "\n1:Insert 2:Delete 3:display\nEnter your choice:\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            cout << "enter the element to be inserted: \n";
            cin >> x;
            queue.insert(x);
            break;
        case 2:
            queue.delet();
            break;
        case 3:
            queue.display();
            break;
        default:
            cout << "invalid operator\n";
            queue.~Queue();
            exit(0);
        }
    }
}