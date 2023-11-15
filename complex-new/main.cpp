#include <iostream>
using namespace std;

class complexNumber
{
private:
    int real;
    int imaginary;

public:
    complexNumber(int r,int i)
    {
        real = r;
        imaginary =i;
    }
    complexNumber()
    {
        real = 0;
        imaginary =0;
    }

    void setReal(int r)
    {
        real =r;
    }
    void setImaginary(int i)
    {
        imaginary =i;
    }
    int getReal() const
    {
        return real;
    }
    int getImaginary()const
    {
        return imaginary;
    }
    void print_complex()
    {
        cout << real;
        if(imaginary > 0 )
        {
            cout << "+" << imaginary << "j";
        }
        else if(imaginary < 0)
        {
            cout << imaginary << "j";
        }
    }

    complexNumber add(complexNumber x)
    {
        complexNumber c;
        c.real = real + x.getReal();
        c.imaginary = imaginary + x.getImaginary();
        return c;
    }

    complexNumber sub(complexNumber x)
    {
        complexNumber c;
        c.real = real - x.getReal();
        c.imaginary = imaginary - x.getImaginary();
        return c;
    }
    complexNumber operator + (const complexNumber & c)
    {
        complexNumber result(real+c.getReal(), imaginary+ c.getImaginary());
        return result;
    }

    complexNumber operator += (const complexNumber & c)
    {
        real = real+c.getReal();
        imaginary = imaginary + c.getImaginary();
        return *this;
    }

    complexNumber operator - (const complexNumber & c)
    {
        complexNumber result(real-c.getReal(), imaginary- c.getImaginary());
        return result;
    }

    complexNumber operator + (int num)
    {
        complexNumber result(real+num, imaginary+num);
        return result;
    }
    complexNumber operator - (int num)
    {
        complexNumber result(real-num, imaginary-num);
        return result;
    }
    int operator == (const complexNumber & c)
    {
        return (real == c.getReal() && imaginary == c.getImaginary());
    }
    complexNumber operator ++()
    {
        real = real +1;
        return *this;
    }
    complexNumber operator ++(int)
    {
        complexNumber temp = *this;
        real = real + 1;
        return temp;
    }
    operator float()
    {
        return  real;
    }
    int operator[](int index)
    {
        if (index == 0)
        {
            return real;
        }
        else if (index == 1)
        {
            return imaginary;
        }
    }
    friend ostream & operator << (ostream &out, const complexNumber &c);
    friend istream & operator >> (istream &in,  complexNumber &c);

};

complexNumber addTwoComplex(complexNumber c1, complexNumber c2);
complexNumber subTwoComplex(complexNumber c1, complexNumber c2);
void swappingm1(int &x ,int &y);
void swappingm2(int &x ,int &y);
void swappingm3(int x ,int y);
void print2(complexNumber c);
complexNumber operator + (int n, complexNumber & c);
complexNumber operator - (int n, complexNumber & c);
ostream & operator << (ostream &out, const complexNumber &c);
istream & operator >> (istream &in,  complexNumber &c);


int main()
{
    //day 3
    /*
       complexNumber c1;
       c1.setReal(3);
       c1.setImaginary(4);
       //c1.print_complex();
       //--------------------
       complexNumber c2;
       c2.setReal(1);
       c2.setImaginary(1);
      //----------------------
       complexNumber c3;
        c3 = c2.add(c1);
       // c3.print_complex();
       //--------------------

       complexNumber c6;
        c6 = c2.sub(c1);
        //c6.print_complex();

       complexNumber c4;
       c4 = addTwoComplex(c1,c2);

       complexNumber c5;
       c5 = subTwoComplex(c1,c2);
       //c5.print_complex();
       //--------------------------------
       int x = 3;
       int y = 4;
       cout << "before " << x << " " << y << "\n";
       swappingm1(x,y);
       cout << "after " << x << " " <<y << "\n";*/


    //day 4
    // + operator
    cout << " testing c + c" << endl;
    complexNumber c6(1,2);
    complexNumber c7(1,2);
    complexNumber c8;
    c8 = c6 + c7;
    c8.print_complex();
    cout << " testing c += c" << endl;
    complexNumber c9(1,2);
    complexNumber c10(1,2);
    c9 += c10;
    c9.print_complex();
    cout << " testing c - c" << endl;
    complexNumber c11(5,6);
    complexNumber c12(1,2);
    complexNumber c13;
    c13 = c11 - c12;
    //c13.print_complex();
    // c + number
    complexNumber c14(5,6);
    complexNumber c15;
    //c15 = c14 + 3 ;
    //c15.print_complex();
    //
    //c15= 5 + (c14);
    //c15.print_complex();

    c15= 3 - (c14);
    //c15.print_complex();

    complexNumber c16(5,6);
    //cout << (c14==c16);
    ++c16;
    //c16.print_complex();
    complexNumber c17(3,2);
    c17++;
    //c17.print_complex();
    //cout <<(float)c17;
    c17[1];
    complexNumber c18;
    cin >> c18;
    cout << c18;

    //float
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


//number +
complexNumber operator + (int n, complexNumber & c)
{
    complexNumber res;
    res.setReal(n+ c.getReal());
    res.setImaginary(c.getImaginary());
    return res;
}

complexNumber operator - (int n, complexNumber & c)
{
    complexNumber res;
    res.setReal(n- c.getReal());
    res.setImaginary(c.getImaginary());
    return res;
}

ostream & operator << (ostream &out, const complexNumber &c)
    {
        out << c.real;
        out << "+j";
        out << c.imaginary;
        return out;
    }

istream & operator >> (istream &in,  complexNumber &c)
    {
        cout << "real :  ";
        in >> c.real;
        cout << "imaginary : ";
        in >> c.imaginary;
        return in;
    }
