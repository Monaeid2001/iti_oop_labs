#include <iostream>
using namespace std;

class complexNumber {
private:
    int real;
    int imaginary;

public:
    void setReal(int r){
        real =r;
    }
    void setImaginary(int i){
        imaginary =i;
    }
    int getReal(){
        return real;
    }
    int getImaginary(){
        return imaginary;
    }
    void print_complex(){
    cout << real;
    if(imaginary > 0 ){
        cout << "+" << imaginary << "j";
    } else if(imaginary < 0){
        cout << imaginary << "j";
    }
    }

    complexNumber add(complexNumber x){
        complexNumber c;
        c.real = real + x.getReal();
        c.imaginary = imaginary + x.getImaginary();
        return c;
    }

    complexNumber sub(complexNumber x){
        complexNumber c;
        c.real = real - x.getReal();
        c.imaginary = imaginary - x.getImaginary();
        return c;
    }
};


complexNumber addTwoComplex(complexNumber c1, complexNumber c2);
complexNumber subTwoComplex(complexNumber c1, complexNumber c2);
void swappingm1(int &x ,int &y);
void swappingm2(int &x ,int &y);
void swappingm3(int x ,int y);
void print2(complexNumber c);

int main()
{
    complexNumber c1;
    c1.setReal(3);
    c1.setImaginary(4);
    c1.print_complex();
    //--------------------
    complexNumber c2;
    c2.setReal(1);
    c2.setImaginary(1);
   //----------------------
    complexNumber c3;
     c3 = c2.add(c1);
     c3.print_complex();
    //--------------------

    complexNumber c6;
     c6 = c2.sub(c1);
     c6.print_complex();

    complexNumber c4;
    c4 = addTwoComplex(c1,c2);

    complexNumber c5;
    c5 = subTwoComplex(c1,c2);
    c5.print_complex();
    //--------------------------------

    int x = 3;
    int y = 4;
    cout << "before " << x << " " << y << "\n";
    swappingm1(x,y);
    cout << "after " << x << " " <<y << "\n";
    return 0;
}

//standalone

complexNumber addTwoComplex(complexNumber c1, complexNumber c2){
    int realSum = c1.getReal() + c2.getReal() ;
    int imageSum = c1.getImaginary() + c2.getImaginary();
    complexNumber c;
    c.setReal(realSum);
    c.setImaginary(imageSum);
    return c;
}

complexNumber subTwoComplex(complexNumber c1, complexNumber c2){
    int realSub = c1.getReal() - c2.getReal() ;
    int imageSub = c1.getImaginary() - c2.getImaginary();
    complexNumber c;
    c.setReal(realSub);
    c.setImaginary(imageSub);
    return c;
}


void swappingm1(int &x ,int &y){
x = x + y;
y = x - y;
x = x - y;
}

void swappingm2(int *x ,int *y){
*x = *x + *y;
*y = *x - *y;
*x = *x - *y;
}

void swappingm3(int x ,int y){
x = x + y;
y = x - y;
x = x - y;
cout << x << " "<< y;
}

void print2(complexNumber c){
    cout << c.getReal();
    if(c.getImaginary() > 0 ){
        cout << "+" << c.getImaginary() << "j";
    } else if(c.getImaginary() < 0){
        cout << c.getImaginary() << "j";
    }
}
