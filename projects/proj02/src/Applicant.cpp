#include "Applicant.h"

Applicant::Applicant() {
    hasChildren = false;
    isMarried = false;
    age = 0;
    name = "";
    phone = "";
    hasPriority = false;
    position = 0;
}

Applicant::Applicant(bool c, bool m, int a, string n, string p) {
    hasChildren = c;
    isMarried = m;
    age = a;
    name = n;
    phone = p;
    hasPriority = hasChildren || isMarried || age >= 25;
    position = 0;
}

bool Applicant::getChildren() {
    return hasChildren;
}

void Applicant::setChildren(bool c) {
    hasChildren = c;
}

bool Applicant::getMarried() {
    return isMarried;
}

void Applicant::setMarried(bool m) {
    isMarried = m;
}

int Applicant::getAge() {
    return age;
}

void Applicant::setAge(int a) {
    age = a;
}

string Applicant::getName() {
    return name;
}

void Applicant::setName(string n) {
    name = n;
}

string Applicant::getPhone() {
    return phone;
}

void Applicant::setPhone(string p) {
    phone = p;
}

bool Applicant::getPriority() {
    return hasPriority;
}

void Applicant::setPriority(bool p) {
    hasPriority = p;
}

int Applicant::getPosition() {
    return position;
}

void Applicant::setPosition(int p) {
    position = p;
}
