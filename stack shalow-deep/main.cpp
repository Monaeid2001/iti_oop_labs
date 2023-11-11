#include <iostream>

using namespace std;


class Stack
{
private:
    int * arr;
    int top;
    int Size;

public:
    Stack(int Size)
    {
        this-> Size = Size;
        top= -1;
        arr = new int[this->Size] {0};
        //cout << "done";
    }
    //deep copy constructor

    Stack(Stack & s){
        this-> Size = s.Size;
        this-> top= s.top;
        arr = new int[s.Size];
        for(int i=0; i<=s.top; i++){
            arr[i] = s.arr[i];
        }
    }
    //shallow copy constructor (shallow)

    Stack(Stack &s){
        this-> Size = s.Size;
        this-> top= s.top;
        arr = s.arr;
    }

    int push(int n)
    {

        if(top < Size-1)
        {
            top++;
            arr[top]= n;
            return n;
        }
        else
        {
            //cout << "sorry array is full";
            return -1;
        }
    }

    int pop()
    {
        if (top!= -1)
        {
            top--;
            return arr[top+1];
        }
        else
        {
            //cout << "sorry array is already empty";
            return -1;
        }
        arr[top]=-1;

    }

    ~Stack()
    {
        delete[] arr;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "sorry";
        }
        for(int i=0; i<=top; i++)
        {
            cout << arr[i] <<" ";
        }

    };
};

void test(Stack & s)
{
    s.pop();
    s.pop();
    s.pop();
}

int  main()
{
    Stack c1(10);
    cout<<c1.pop();
    cout<<c1.push(5);
    cout<<c1.push(6);
    cout<< c1.pop();
    cout<< c1.pop();
    cout<<c1.push(7);
    test(c1);
    cout<< c1.pop();
    cout<< c1.pop();
    cout<< c1.pop();
    cout<< c1.push(7);
    cout<< c1.pop();
    return 0;
}
