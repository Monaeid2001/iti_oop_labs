#include <iostream>
#include <string.h>
#include<graphics.h>
using namespace std;
class Point{
private:
	int x;
	int y;
public:
    //Point(){}
	Point(int _x=0 , int _y=0) {
		x = _x;
		y = _y;
	}
	void setx(int _x) {
		x = _x;
	}
	void sety(int _y) {
		y = _y;
	}
	void setxy(int _x,int _y) {
		x = _x;
		y = _y;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	friend istream& operator>>(istream& in, Point& p);
};  //end class
istream& operator>>(istream& in, Point& p){
        in>>p.x>>p.y;
        return in;
	}
class Shape{

string color;
Point p1,p2;

public:
    void setColor(string x){
        color = x;
    }
    void setPoint1(int _x,int _y){
        p1.setxy(_x,_y);
    }
    void setPoint2(int _x,int _y){
        p2.setxy(_x,_y);
    }
    void setTwoPoints(int x1,int y1,int x2,int y2){
        p1.setxy(x1,y1);
        p2.setxy(x2,y2);
    }
    int getx1(void){
        return p1.getx();
    }
    string getColor(void){
        return color;
    }
    int gety1(void){
        return p1.gety();
    }
    int getx2(void){
        return p2.getx();
    }
    int gety2(void){
        return p2.gety();
    }
    void draw(){}
};
class Rctangle:public Shape{

public:
    Rctangle(){}
    Rctangle(int x, int y,int z,int w){
        Shape::setTwoPoints(x,y,z,w);
    }
    void draw(){
        rectangle(Shape::getx1(),Shape::gety1(),Shape::getx2(),Shape::gety2());
    }
};

class Line:public Shape{
public:
    Line(){
    }
    Line(int x,int y,int z,int w){
        Shape::setTwoPoints(x,y,z,w);
    }
    void draw(){
//            int gd  = DETECT , gm;
//        initgraph(&gd,&gm,(char*)"");
        line(Shape::getx1(),Shape::gety1(),Shape::getx2(),Shape::gety2());
//	    getch();
//        closegraph();
    }
};
class Circle:public Shape{
    int r;
public:
    Circle(){}
    Circle(int x,int y){
        Shape::setPoint1(x,y);
    }
    void setr(int _r){
        r=_r;
    }
    int getr(){
        return r;
    }
    void draw(){
        cout<<getx1()<<" "<<gety1()<<" "<<getr();
        circle(getx1(),gety1(),getr());
    }
};

int main()
{
    int n,choice,x1,y1,x2,y2,color;
    cout<<"Enter number of shapes you want to draw\n";
    cin>>n;
    cout<<"Enter color of shapes you want\n";
    cin>>color;
    int type[n];
    Circle *circles[n];
    Rctangle* rectangles[n];
    Line* lines[n];
    for(int i = 0;i<n;i++){
        cout<<"To draw Line press 1 ,To draw Circle press 2, To draw Rectangle press 3:\n";
        cin>>choice;
        type[i] = choice;
        switch(choice){
        case 1:
            {
                cout<<"Enter two points\n";
                cin>>x1>>y1>>x2>>y2;
                lines[i] = new Line();
                lines[i]->setTwoPoints(x1,y1,x2,y2);
                break;
        }
        case 2:
           {
            int r;
            cout<<"Enter radius and one point\n";
            cin>>x1>>y1>>r;
            circles[i] = new Circle();
            circles[i]->setPoint1(x1,y1);
            circles[i]->setr(r);
            break;
        }
        case 3:{
            cout<<"Enter two points\n";
            cin>>x1>>y1>>x2>>y2;
            rectangles[i] = new Rctangle();
            rectangles[i]->setTwoPoints(x1,y1,x2,y2);
            break;
            }
        }
    }

    int gd  = DETECT , gm;
    initgraph(&gd,&gm,(char*)"");
    setcolor(color);
    for(int i = 0;i<n;i++){
        switch(type[i]){
        case 1:
            lines[i]->draw();
            break;
        case 2:
            circles[i]->draw();
            break;
        case 3:
            rectangles[i]->draw();
            break;
            }
        }
    getch();
    closegraph();
    for (int i = 0; i < n; i++) {
        delete lines[i];
        delete circles[i];
        delete rectangles[i];
    }
    delete[] lines;
    delete[] circles;
    delete[] rectangles;
    return 0;
}
