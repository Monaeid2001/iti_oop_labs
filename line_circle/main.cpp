#include <iostream>
#include <graphics.h>
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

class Line1
{
    Point p1, p2;

public:
    Line1(int p1x, int p1y, int p2x, int p2y) : p1(p1x, p1y), p2(p2x, p2y) {}

    void draw()
    {
        p1.print();
        p2.print();
    }
    void drawLine()
    {
        initwindow(300,400,"graph");
        line(p1.get_x(),p1.get_y(),p2.get_x(),p2.get_y());
        getch();
        closegraph();
    }
};

class Line2
{
    Point *p1;
    Point *p2;

public:
    Line2() : p1(NULL), p2(NULL) {}

    void setPoints(Point *pc, Point *pb)
    {
        p1 = pc;
        p2 = pb;
    }

    void draw()
    {
        p1->print();
        p2->print();
    }
    void drawLine()
    {
        initwindow(300,400,"graph");
        line(p1->get_x(),p1->get_y(),p2->get_x(),p2->get_y());
        getch();
        closegraph();
    }

};


class Line3
{
public:
    Line3() {}

    void draw(Point pc, Point pb)
    {
        pc.print();
        pc.print();
        initwindow(300,400,"graph");
        line(pc.get_x(),pc.get_y(),pb.get_x(),pb.get_y());
        getch();
        closegraph();
    }
};

class Circle1
{
    int radius;
    Point p;

public:
    Circle1(int r, int x, int y) : p(x, y)
    {
        radius = r;
    }

    void draw()
    {
        cout << radius << endl;
        p.print();
    }

    void drawCircle()
    {
        initwindow(300,400,"graph");
        circle(p.get_x(),p.get_y(),radius);
        getch();
        closegraph();
    }
};

class Circle2
{
    int radius;
    Point *p;

public:
    Circle2(int r) : radius(r), p(NULL) {}

    void draw(Point *pc)
    {
        p = pc;
        cout << radius << endl;
        p->print();
    }
    void drawCircle()
    {
        initwindow(300,400,"graph");
        circle(p->get_x(),p->get_y(),radius);
        getch();
        closegraph();
    }
};

class Circle3
{
public:

    void draw(Point pc, int radius )
    {
        cout << radius << endl;
        pc.print();
        initwindow(300,400,"graph");
        circle(pc.get_x(),pc.get_y(),radius);
        getch();
        closegraph();
    }
};

int main()
{
    // using composition
    /*Line1 l(100, 30, 80,60);
    l.draw();
    l.drawLine();
    cout << "----------------" << endl;
    // using aggregation
    Point p1(100, 30);
    Point p2(70, 60);
    Line2 l2;
    l2.setPoints(&p1,&p2);
    l2.draw();
    l2.drawLine();
    cout << "----------------" << endl;
    //using association
    cout << "----------------" << endl;
    Line3 l3;
    Point p3(100, 30);
    Point p4(70, 60);
    l3.draw(p3,p4);*/

/*
    cout << "------- circle -----------" << endl;
    Circle1 c1(50, 70, 80);
    c1.draw();
    c1.drawCircle();
    Point p5(70, 80);

    cout << "----------------" << endl;
    Circle2 c2(50);
    c2.draw(&p5);
    c2.drawCircle();*/

    cout << "----------------" << endl;
    Circle3 c4;
    Point p9(70,80);
    c4.draw(p9,50);


    return 0;
}
