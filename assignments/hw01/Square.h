/*************************************************************************
 *
 * HW01: Building a basic shape and square class to highlight C++ concepts.
 *      - Polymorphis
 *      - Inheritance
 *      - Exception handling
 *
 * File Name:  Square.h
 * Name:       Nicholas Morin
 * Course:     CPTR 242
 * Date:       4/15/18
 * Time Taken: ?
 *
 */

#ifndef Square_h
#define Square_h


#include "Shape.h"
#include "NegativeLengthException.h"

class Square: public Shape{
private:
    double sideLength;
public:
    Square();
    Square(double sideLength);
    double getSideLength() const;
    friend ostream& operator << (ostream& output, const Square & square);
    
};



#endif /* Square_hpp */
