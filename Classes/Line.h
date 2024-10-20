#include <iostream>
#include <math.h>
#include "Point.h"
#include "Point.h"
#pragma once

template <class V>
class Line {
    friend double getAngle(Line<V>& , Line<V>& );
    friend double scalMult(Line<V>&, Line<V>&);
    friend double vecMult(Line<V>&, Line<V>&);
private:
    Point<V> a;
    Point<V> b;
    V len;
    unsigned id;
    static inline unsigned count;
public:
    Line(Point<V>&, Point<V>&);

    ~Line();

    V getLen();
    void print();
    void printCoordinates();

    V vec(int);

};


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

template<class V>
inline V Line<V>::vec(int i)
{
    if (i ==0) { return b.getX() - a.getX(); }
    else if(i ==1)
    { return b.getY() - a.getY(); }
    else{
        std::cout << "Неизвестный аргумент" << std::endl;
        return 0;
    }
}

template <typename V>
std::ostream& operator<<(std::ostream& os, const Line<V>& x) {
    os << x.id;
    return os;
}

template <typename M>
double scalMult(Line<M>& a, Line<M>& b)
{
    return (((a.vec(0) * b.vec(0)) + (a.vec(1) * b.vec(1))));
}

template <typename M>
double vecMult(Line<M>& a, Line<M>& b)
{
    return ((a.getLen() * b.getLen()));
}

template <typename M>
double getAngle(Line<M>& a, Line<M>& b)
{
    return (std::acos(scalMult(a, b) / vecMult(a, b)) * 180.0 / 3.14159265);
}

double scalMult(Line<double>& a, Line<double>& b)
{
    return (((a.vec(0) * b.vec(0)) + (a.vec(1) * b.vec(1))));
}

double vecMult(Line<double>& a, Line<double>& b)
{
    return ((a.getLen() * b.getLen()));
}

double getAngle(Line<double>& a, Line<double>& b)
{
    return (std::acos(scalMult(a, b) / vecMult(a, b)) * 180.0 / (3.14159265));
}