#include "Student.h"
#include "DLLQueue.h"
#ifndef REGISTRAR_h
#define REGISTRAR_h



class Registrar{
public:
    Registrar(int w);
    ~Registrar();
    void fillWindow(int index);
    int clockTick();
    bool isFull();
    void simulation(string fileName);
    void addStudents(string fileName);
    ifstream readFile(string fileName);



private:
    int clock;
    int numWindows;
    int totWindows;
    Student* windows;
    DLLQueue<Student> postqueue;
    int numStudents;
    DLLQueue<Student> queue;
    int studInLine;

};









#endif
