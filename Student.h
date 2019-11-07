#ifndef STUDENT_h
#define STUDENT_h

class Student{
public:
    Student(int w, int a, int n, int j);
    Student();
    ~Student();
    int getWaitTime();
    int decWaitTime();
    void setWaitTime(int w);
    int getArrivalTime();
    int getWindow();
    void setWindow(int w);
    void incWaiting();
    int getWaiting();

private:
    int waitTime;
    int arrival;
    int windowNumber;
    int waitingInQueue;
};



#endif
