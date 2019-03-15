#include "Square.h"

Square::Square(){
    this->sideLength = 12;
}

Square::Square(double sideLength) : Shape("Square"){
   
        this->sideLength = sideLength;
        if(sideLength <0){
            throw NegativeLengthException();
        }
    }

double Square::getSideLength() const{
    return sideLength;
}

ostream& operator << (ostream& output, const Square & square) {
    output << square.getName();
    output << "("<<square.getSideLength()<<")";
    return output;
}


