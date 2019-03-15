/*************************************************************************
 *
 * HW01: Building a basic shape and square class to highlight C++ concepts.
 *      - Polymorphis
 *      - Inheritance
 *      - Exception handling
 *
 * File Name:  Circle.h
 * Name:       Nicholas Morin
 * Course:     CPTR 242
 * Date:       4/15/18
 * Time Taken: ?
 *
 */

#ifndef Circle_hpp
#define Circle_hpp


#include "Shape.h"
#include "NegativeLengthException.h"



class Circle:public Shape{
private:
    int radius;
public:
    Circle();
    Circle(int radius);
    int getRadius() const;
    friend ostream& operator << (ostream& output, const Circle & circle);
};

Circle getCircleFromUser();

#endif /* Circle_hpp */





