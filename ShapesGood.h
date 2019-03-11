//Ryan Kinsella, 15rklk , 10194574

#ifndef ASSIGNMENT5_SHAPESGOOD_H
#define ASSIGNMENT5_SHAPESGOOD_H
#include<string>

using namespace std;

class Shape {
public:
    Shape();
    Shape(int, int, string);
    virtual ~Shape();
    virtual void draw () =0;
    string getBaseColour() const;
    int getLength();
    int getWidth();
private:
    int length, width;
    const string baseColour;
};

class Fillable{
public:
    Fillable(string fill);
    virtual ~Fillable();
    void fill() const;
    string getFillColour() const; //unused accessor, good practice to put in
private:
    const string fillColour ;
};

class Labelled{
public:
    Labelled(string aLabel);
    virtual ~Labelled();
    void drawText() const;
    string getTextLabel() const;
private:
    const string textLabel;
};

class Square : public Shape {
public:
    Square(int, int, string);
    ~Square();
    //could put or not put override in void draw (and extended classes) since the parent class is
    //declared as virtual there's no need, but in the 320 examples it is used so I will here
    virtual void draw() ;
};

class FilledSquare : public Square, public Fillable {
public:
    FilledSquare(int, int,string,string);
    ~FilledSquare();
    virtual void draw() ;
};

class FilledTextSquare : public Shape, public Fillable, public Labelled {
public:
    FilledTextSquare(int, int,string,string,string);
    ~FilledTextSquare();
    virtual void draw() ;  //using virtual here if other classes would like to extend FilledTextSquare
};

class Circle : public Shape {
public:
    Circle(int, int,string);
    ~Circle();
    virtual void draw() override;
};

class FilledCircle : public Circle, public Fillable {
public:
    FilledCircle(int, int,string,string);
    ~FilledCircle();
    virtual void draw() override;
};

class Arc : public Shape {
public:
    Arc(int, int,string);
    ~Arc();
    virtual void draw() override;
};

#endif //ASSIGNMENT5_SHAPESGOOD_H
