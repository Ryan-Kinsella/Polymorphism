#include <utility>
//Ryan Kinsella, 15rklk , 10194574

#include "ShapesGood.h"
#include <iostream>
#include <string>

using namespace std;

Shape::Shape() : length(0), width(0) {}
Shape::Shape(int len, int wid, string bColour) : length(len), width(wid), baseColour(bColour) {}
Shape::~Shape() {}
int Shape::getLength() { return length; }
int Shape::getWidth() { return width; }
string Shape::getBaseColour() const {
    return baseColour;
}

Square::Square(int len, int wid,const string bColour) : Shape(len, wid,bColour) {}
Square::~Square(){}
void Square::draw() {
    cout << "\nDrawing a " + getBaseColour() + " square.";
}

Fillable::Fillable(string fill) : fillColour(fill){}
Fillable::~Fillable(){}
string Fillable::getFillColour() const {
    return fillColour;
}
void Fillable::fill() const {
    cout << " With " + fillColour + " fill.";
}

Labelled::Labelled(string aLabel) : textLabel(aLabel) {}
Labelled::~Labelled() {}
void Labelled::drawText() const {
    cout << " Containing the text: \"" << textLabel << "\".";
}
string Labelled::getTextLabel() const {
    return textLabel;
}

FilledSquare::FilledSquare(int len, int wid, const string bC, const string fl ) : Square(len, wid,bC), Fillable(fl) {}
FilledSquare::~FilledSquare() {}
void FilledSquare::draw() {
    cout << "\nDrawing a " + getBaseColour() + " square.";
    fill();
}

FilledTextSquare::FilledTextSquare(int len, int wid, const string bC, const string fl, const string msg)
: Shape(len, wid,bC), Fillable(fl), Labelled(msg) {}
FilledTextSquare::~FilledTextSquare() {}
void FilledTextSquare::draw() {
    cout << "\nDrawing a " + getBaseColour() + " square.";
    fill();
    drawText();
}

Circle::Circle(int len, int wid, const string bC) : Shape(len, wid,bC) {}
Circle::~Circle() {}
void Circle::draw() {
    cout << "\nDrawing a " + getBaseColour() + " circle.";
}

FilledCircle::FilledCircle(int len, int wid, const string bC, const string fl) : Circle(len, wid,bC), Fillable(fl) {}
FilledCircle::~FilledCircle(){}
void FilledCircle::draw() {
    cout << "\nDrawing a " + getBaseColour() + " circle.";
    fill();
}

Arc::Arc(int len, int wid, const string bC) : Shape(len, wid,bC) {}
Arc::~Arc(){};
void Arc::draw() {
    cout << "\nDrawing a " + getBaseColour() + " arc.";
}