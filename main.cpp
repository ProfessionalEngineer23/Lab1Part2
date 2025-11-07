// Name: Niki Mardari
// Purpose: Lab 1 Part 2 creating a shapes class and calculating areas of triangle and circle

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// Base class representing a generic shape
class Shape 
{
public:
   // pure virtual function: derived classes must implement getArea()
   // provides an interface that all shapes will share
   virtual double getArea() = 0;

   // virtual destructor so deleting a derived object via Shape* is safe
   virtual ~Shape() {}

   // setWidth: store a width value into the protected member 'width'
   void setWidth(double w)  { width = w; }

   // setHeight: store a height value into the protected member 'height'
   void setHeight(double h) { height = h; }

protected:
   double width;              // protected storage for a width-like measurement
   double height;             // protected storage for a height-like measurement
};
 
// Triangle class derives from Shape and implements getArea()
class Triangle: public Shape
{
public:
   // override getArea to compute triangle area using width and height
   double getArea() override
   { 
      // area of triangle = (base * height) / 2
      return (width * height) / 2.0; 
   }
};

// Circle class derives from Shape but uses its own radius member
class Circle: public Shape
{
public:
   // setRadius stores the circle radius in the private member 'radius'
   void setRadius(double r) { radius = r; }

   // override getArea to compute area of a circle using the M_PI constant
   double getArea() override
   {
      // area = PI * r^2
      return M_PI * radius * radius;
   }

private:
   double radius = 0.0;      // private storage for the circle radius, default 0.0
};



int main()
{
   Triangle Tri;
   Tri.setWidth(5);
   Tri.setHeight(7);
   cout << "Total Triangle area: " << Tri.getArea() << endl;

   Circle cir;
   cir.setRadius(5.0);
   cout << "Circle area (radius = 5.0): " << cir.getArea() << endl;

   return 0;
}
