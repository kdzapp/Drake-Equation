//
//  main.cpp
//  Drake Equation
//
//  Created by Kyle Zappitell on 11/6/15.
//  Copyright © 2015 Kyle Zappitell. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

//Fairly Accurate Estimations
const long long STARS_IN_GALAXY = 100000000000;
const double HABITABLE_PLANETS = 0.15;
const double PERCENT_LIFE_SUPPORT = 0.1;
const long long LIFETIME_OF_STAR = 10000000000;
const int DIAMETER_OF_GALAXY = 100000;


//Prints Heading
void printHeading();

//Asks Drake Questions
void questionInput(double &life, double &smart, double &radio, int &time);

//Drake Equation
long long drakeEquation(double life, double smart, double radio, int time);

//Calculates, if evenly distributed, how far the nearest aliens are
int howFarFromUs(long long numCivilizations);

int main(int argc, const char * argv[]) {

    double life;
    double smart;
    double radio;
    int time;
    long long numCivilizations;
    
    printHeading();
    questionInput(life, smart, radio, time);
    numCivilizations = drakeEquation(life, smart, radio, time);
    
    cout << "Based on the information you provided there is approximately: " << endl;
    cout << numCivilizations << " Civilizations in our Galaxy"  << endl;
    cout << endl << "The nearest civilization is " << howFarFromUs(numCivilizations) << " light years away!" << endl;
    
    return 0;
}

void printHeading()
{
    cout << "**************************************" << endl;
    cout << "  How Many Alien Civilizations Exist  " << endl;
    cout << "**************************************" << endl;
}

void questionInput(double &life, double &smart, double &radio, int &time)
{
    cout << "   Write all percentages as decmials  " << endl << endl << endl;
    cout << "What percetage of all habitable planets do you think have developed life?" << endl;
    cin >> life; cout << endl;
    cout << "What percetage of planets do you think has developed intellegent life?" << endl;
    cin >> smart; cout << endl;
    cout << "What percetage of intellegent life forms have technology that emits radio signals?"
         << endl;
    cin >> radio; cout << endl;
    cout << "What do you think the length of time (in years) will be for our civilization?" << endl;
    cin >> time; cout << endl;
}


long long drakeEquation(double life, double smart, double radio, int time)
{
    long long aliens = 0;
    double cTime = 0.0;
    
    cTime = (double)time/LIFETIME_OF_STAR;
    
    aliens = STARS_IN_GALAXY * HABITABLE_PLANETS * PERCENT_LIFE_SUPPORT
    * life * smart * radio * cTime;
    
    return aliens;
}

int howFarFromUs(long long numCivilizations)
{
    int radius;
    long long area;
    double pointArea;
    double lightyears;
    
    radius = (DIAMETER_OF_GALAXY/2);
    area = 3.14 * pow(radius, 2);
    pointArea = area/(double)numCivilizations;
    lightyears = sqrt(pointArea/3.14);
    
    return lightyears;
}