#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int *arr;
    int $size;

public:
    Stack(int s) {
        $size = s;
        top = -1;
        arr = new int[$size];
    }

    // push to stack
    void push(int data) {
        if (top < $size - 1) {
            arr[++top] = data;
        } else {
            cout << "Stack is full, no space to push " << data << endl;
        }
    }

    // pop --->display and print the deleted element
    void pop() {
        if (top >= 0) {
            cout << "Popped element: " << arr[top] << endl;
            top--;
        } else {
            cout << "Stack is already empty " << endl;
        }
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
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
    Stack myStack(5);
    myStack.pop();

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);


    myStack.pop();
    myStack.pop();
    myStack.push(7);

    myStack.pop();
    myStack.pop();
   myStack.pop();
    return 0;
}
