#include "Circle.h"

Circle getCircleFromUser(){
    float radius;
    while(true){
    try {
        std::cout<<"Enter the size of the circle: ";
        std::cin>>radius;
        Circle circle(radius);
        return circle;
    } catch (NegativeLengthException& i) {
        cerr << "Input Error: " << i.what() << endl;
        }
    }
}

Circle::Circle(){
    this->radius = 5;
}


Circle::Circle(int radius):Shape("Circle"){
    
        this->radius = radius;
        if(radius < 0){
            throw NegativeLengthException();
        }
}

int Circle::getRadius() const{
    return radius; 
}

ostream& operator << (ostream& output, const Circle & circle) {
    output << circle.getName();
    output <<"(" << circle.getRadius() << ")";
    return output;
}


