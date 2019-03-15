/*************************************************************************
 *
 * The interface for Shape class.
 * Part of HW01 assignment for CPTR242.
 *
 * File Name:  Shape.h
 * Course:     CPTR 242
 *
 * Provided Code...
 */

#ifndef Shape_h
#define Shape_h


#include <iostream>
using namespace std;


class Shape {
private:
    string name;
public:
    Shape();
    Shape(string name);
    string getName() const;
    friend ostream& operator << (ostream& output, const Shape & shape);
};
#endif /* Shape_hpp */
