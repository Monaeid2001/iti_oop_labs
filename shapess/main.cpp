#include <iostream>
#include <graphics.h>
#include <string.h>
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}

    void set_x(int _x)
    {
        x = _x;
    }

    void set_y(int _y)
    {
        y = _y;
    }
    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }
    void set_point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class shape
{
protected:
    //int color;
    Point p1;
    Point p2;
public :
    shape() {};
    shape(int p1x, int p1y, int p2x=0, int p2y=0) : p1(p1x, p1y), p2(p2x, p2y) {}

    virtual void draw()
    {
        cout << "drawing" << endl;
    }

};



class Line : public shape
{
public:
    Line(int p1x, int p1y, int p2x, int p2y) : shape(p1x, p1y,p2x, p2y) {}

    void draw()
    {

        line(p1.get_x(),p1.get_y(),p2.get_x(),p2.get_y());
    }
};

class Circle : public shape
{
    int radius;

public:
    Circle(int r, int x, int y) : shape(x,y)
    {
        radius = r;
    }

    void draw()
    {
        circle(p1.get_x(),p1.get_y(),radius);
    }
};

class Rect : public shape
{
public:
    Rect() {}
    Rect(int p1x, int p1y, int p2x, int p2y) : shape(p1x, p1y,p2x, p2y)
    {
    }
    void draw()
    {
        rectangle(p1.get_x(),p1.get_y(),p2.get_x(), p2.get_y());
    }

};
int main()
{
    int x;
    cout<< "how many shapes do you want to draw ?" <<  endl;
    cin >> x ;
    shape * shapes[x];

    for(int i=0; i<x; i++){
        char str[100];
        cout<< "please enter shape" << " [" << i+1 <<"]" <<  endl;
        cin >> str;
        if (strcmp(str, "line")==0){
            int x,y,z,l;
            cout << "point 1 x : " << endl;
            cin >> x;
            cout << "point 1 y : " << endl;
            cin >> y;
            cout << "point 2 x : " << endl;
            cin >> z;
            cout << "point 2 y : " << endl;
            cin >> l;
            shapes[i]= new Line(x,y,z,l);
        }
        else if (strcmp(str, "circle")==0)
        {
            int radius;
            int x,y;
            cout << "please radius : " << endl;
            cin >> radius;
            cout << "point x : " << endl;
            cin >> x;
            cout << "point y : " << endl;
            cin >> y;
            shapes[i]= new Circle(radius, x,y);
        }
        else if(strcmp(str, "rectangle")==0)
        {
            int x,y,z,l;
            cout << "point 1 x : " << endl;
            cin >> x;
            cout << "point 1 y : " << endl;
            cin >> y;
            cout << "point 2 x : " << endl;
            cin >> z;
            cout << "point 2 y : " << endl;
            cin >> l;
            shapes[i]= new Rect(x,y,z,l);
        }
    }
    initwindow(300,400,"graph");
    for(int i=0; i<x; i++)
    {
     shapes[i]->draw();

    }
    getch();
    closegraph();

    return 0;

}
