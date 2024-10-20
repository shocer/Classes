#include<iostream>
#include<math.h>
#include "Point.h"
#include "Line.h"


int main() {
Point<float> a1(0,0);
Point<float> a2(.0, 3.0);
Point<float> a3(3.0, .0);
Point<float> a4(3.0, 3.0);

Point<float> a0;

a1.print();
a2.print();
a3.print();
a4.print();

Line<float> l1(a1, a2);
Line<float> l2(a1, a3);
Line<float> l3(a1, a4);
Line<float> l4(a2, a3);
Line<float> l5(a2, a4);
Line<float> l6(a3, a4);

std::cout << l1.getLen() << std::endl;
l1.printCoordinates();




//std::cout << getAngle(l1, l2) << std::endl;

//getAngle(l6,l1);

    return 0;
}

