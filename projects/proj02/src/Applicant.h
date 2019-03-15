#ifndef PROJ02_APPLICANT_H
#define PROJ02_APPLICANT_H

#include <iostream>
using namespace std;

class Applicant {
private:
    bool hasChildren;
    bool isMarried;
    int age;
    string name;
    string phone;
    bool hasPriority;
    int position;

public:
    Applicant();
    Applicant(bool c, bool m, int a, string n, string p);
    bool getChildren();
    void setChildren(bool c);
    bool getMarried();
    void setMarried(bool m);
    int getAge();
    void setAge(int a);
    string getName();
    void setName(string n);
    string getPhone();
    void setPhone(string p);
    bool getPriority();
    void setPriority(bool p);
    int getPosition();
    void setPosition(int p);
};


#endif //PROJ02_APPLICANT_H
