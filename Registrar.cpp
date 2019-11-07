#include <iostream>
#include <fstream>
#include "Registrar.h"
#include "Metric.h"
using namespace std;

Registrar::Registrar(int w){
    clock = 0;
    numWindows = 0;
    numStudents = 0;
    windows = new Student[w];
    totWindows = w;
    studInLine = w;
    DLLQueue<Student> queue;
    DLLQueue<Student> postqueue;
}


Registrar::~Registrar(){
    delete windows;
}

void Registrar::fillWindow(int index){
    postqueue.insert(windows[index]);  // put the student leaving the window in the post queue
    queue.peek().setWindow(index); // assigns the student the window number
    windows[index] = queue.removeFrontOfLine(); // remove the front of the queue and put them at a window
    ++numWindows;
    --studInLine; // decrease the num of students in the line
}


int Registrar::clockTick(){
    return ++clock;
}

bool Registrar::isFull(){
    return (numWindows == totWindows);
}

ifstream Registrar::readFile(string fileName){
    ifstream infile;
    infile.open(fileName.c_str()); // reading file
    while(infile.fail()){ // error checking the file
        cout << "Could not open file. Please try again." << endl;
        cout << "Please enter the path of the file you wish to read from:" << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
        if(infile.is_open()){
            break;
        }
    }
    return infile;
}

void Registrar::addStudents(string fileName){
    ifstream file = readFile(fileName);
    int s = 0, line = 0;
    while(!file.eof()){
        ++line; // keeping track of lines
        int enter = 0, numStud = 0, wait = 0;
        if(line != 1){
            file >> enter; // second line is when they entered the line
            file >> numStud; // third line is num students
            while(numStud != 0){ // and while the number of students who entered that line have not been added to the queue
                file >> wait;  // take in their wait time
                Student s(wait, enter, 0, 0); // create a new student
                queue.insert(s); // insert the queue
                wait = 0;
                --numStud; // decrease the number of students who arrived at that time
            }
        }
    }
    file.close();
}

void Registrar::simulation(string fileName){
    addStudents(fileName);
    cout << "Added students" << endl;
    int i = 0;
    while(true){
        if(queue.isEmpty()){
            break;
        }
        if(!isFull()){ // if the clock == the arrival time of the first persn in the queue, put them in a window
            while (clock == queue.find(i).getArrivalTime()){
                fillWindow(i);
                ++i;
            }
        }
        for(int i = 0; i < numWindows-1; ++i){ // replacing students who have finished their time at the window
            if(windows[i].getWaitTime() >= clock){
                fillWindow(i);
                --studInLine;
            }
        }
        cout << "Finished for loop" << endl;
        if(!isFull() && !queue.isEmpty()){ // determining idle time of people
            int i = 0;
            int j = studInLine;
            while(studInLine != 0){
                queue.find(i).incWaiting();
                --studInLine;
            }
            studInLine = j;
        }
        cout << "Before clock tick" << endl;
        clockTick();
        cout << "After clock tick" << endl;
    }
    for(int i = 0; i < numWindows-1; ++i){ // insert remaining students in windows into the collection queue
        postqueue.insert(windows[i]);
    }
    cout << "Finished second for loop" << endl;
    Metric m;
    m.printMetrics(postqueue, numStudents);
}
