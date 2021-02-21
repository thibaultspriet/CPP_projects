#include "Voiture.h"
#include <iostream>
using namespace std;

string Voiture::getColor(){
    return color;
};
int Voiture::getNumber(){
    return number;
};
void Voiture::setNumber(int number){
    this->number = number;
};
void Voiture::setColor(string color){
    this->color = color;
};

Voiture::~Voiture(){};
