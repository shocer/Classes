#pragma once
#include<iostream>


template <class V>
class Point {

private:
    //std::vector<T> coordinates;
    V x;
    V y;
    unsigned id;
    static inline unsigned count;
public:
    Point(V, V);
    Point();
    //Point& operator=(const Point&);
    ~Point();

    //void atach(T);
    void print();

    V getX();
    V getY();
    unsigned getId();
};


template <class V>
Point<V>::Point(V p_x, V p_y) : x{ p_x }, y{ p_y }
{
    count++;
    id = count;
    //std::cout << "Point has been created" << std::endl;

    //atach(p_x); atach(p_y);
}

template <class V>
Point<V>::Point() : Point(0, 0) {}

template <class V>
Point<V>::~Point() {//std::cout << "Point has been deleted" << std::endl; 
}

//template<class V>
//void Point<V>::atach(V in) {
//    coordinates.push_back(in);
//    std::cout << coordinates.size() << std::endl;
//}

template<class V>
void Point<V>::print() {
    std::cout << "Point #" << id << "\tX:" << x << "\tY:" << y << std::endl;
}

template<class V>
V Point<V>::getX()
{
    return V(x);
}

template<class V>
V Point<V>::getY()
{
    return V(y);
}

template<class V>
unsigned Point<V>::getId()
{
    return id;
}

