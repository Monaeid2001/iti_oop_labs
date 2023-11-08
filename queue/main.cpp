#include <iostream>

using namespace std;

class Queue {
private:
    int $front;
    int rear;
    int $size;
    int* arr;

public:
    Queue(int s) {
        $size = s;
        $front = rear = -1;
        arr = new int[$size];
    }

    // insert at rear
    void enqueue(int data) {
        if (rear == $size - 1) {
            cout << "Queue is full no other space " << data << endl;
        } else {
            arr[++rear] = data;
        }
    }

    // remove from front
    void dequeue() {
        if ($front == rear) {
            cout << "queue is empty " << endl;
        } else {
            cout << "Dequeued element :" << arr[++$front] << endl;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};
     /*pop() //empty
push(1)
push(5)
push(6)
pop()//1
pop()//5
push(7)
pop()//6
pop()//7
pop()//Empty
push(7)
pop()//7
1567Empty7
-------------------------------------------------------------
denque()
enque(5)
enque(7)
enque(10)
denque()5
denque()7
enque(11)
denque() 10
denque() 11
denque() //Empty*/

int main() {
    Queue myQueue(5);
    myQueue.dequeue();

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.dequeue();//1
    myQueue.dequeue();//2
   // myQueue.dequeue();
    myQueue.enqueue(8);

    myQueue.dequeue();//3
    myQueue.dequeue();//8
myQueue.dequeue();//8
    return 0;
}
