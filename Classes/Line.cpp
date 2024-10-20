#include <iostream>
#include<math.h>
#include "Point.h"
#include "Line.h"


template <class V>
Line<V>::Line(Point<V>& p_a, Point<V>& p_b) :a{ p_a }, b{ p_b } {
    count++;
    id = count;
    getLen();
    std::cout << "Line #" << id << " has been created betveen points:" << p_a.getId() << " and " << p_b.getId() << " lengh:" << getLen() << std::endl;
}

template<class V>
Line<V>::~Line() {}

template<class V>
V Line<V>::getLen() {
    if (len > 0) {
        return V(len);
    }
    else {
        len = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
        return V(len);
    }
}

template<class V>
void Line<V>::print() {
    std::cout << "Line #" << id << "\t from point #" << a.getId() << " to point #" << b.getId() << " has lenght-" << getLen() << std::endl;
}

template<class V>
void Line<V>::printCoordinates() {
    std::cout << "Line #" << id << "\t Point #" << a.getId() << " X:" << a.getX() << " Y:" << a.getY() <<
        " and point #" << b.getId() << " X:" << b.getX() << " Y:" << b.getY() << std::endl;
}


