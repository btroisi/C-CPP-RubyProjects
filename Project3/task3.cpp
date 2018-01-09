// member initialization
#include <iostream>
using namespace std;

class Rectangle {
	int width,height;
public:
	Rectangle(double,double);
	double area() {return (width*height);}
	double perimeter() {return (2*width+2*height);}
	double modfunc() {return (width%height);}

};

Rectangle::Rectangle(double a,double b){
	width=a;
	height=b;
}

int main () {
  Rectangle recta (6.4,6.5);
  Rectangle rectb (7.9,8.3);
  cout << "recta area: " << recta.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  cout << "recta perimeter: " << recta.perimeter() << endl;
  cout << "rectb perimeter: " << rectb.perimeter() << endl;
  cout << "recta widthmodheight: " << recta.modfunc() << endl;
  cout << "rectb widthmodheight: " << rectb.modfunc() << endl;
  cout << "Difference in perimeter rectb and rect a: " << rectb.perimeter()-recta.perimeter() <<endl;
  cout << "Ratio of areas of rectb and recta: " <<rectb.area()/recta.area() << endl;
  return 0;
}