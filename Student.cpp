#include "Student.h"
using namespace std;

Student::Student(int w, int a, int n, int j){
    waitTime = w;
    arrival = a;
    windowNumber = n;
    waitingInQueue = j;
}
Student::Student(){
    waitTime = 0;
    arrival = 0;
}
Student::~Student(){}

int Student::getWaitTime(){
    return waitTime;
}
int Student::decWaitTime(){
    return --waitTime;
}
void Student::setWaitTime(int w){
    waitTime = w;
}
int Student::getArrivalTime(){
    return arrival;
}

int Student::getWindow(){
    return windowNumber;
}

void Student::setWindow(int w){
    windowNumber = w;
}

void Student::incWaiting(){
    ++waitingInQueue;
}
int Student::getWaiting(){
    return waitingInQueue;
}
