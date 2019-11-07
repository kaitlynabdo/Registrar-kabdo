#include "DLLQueue.h"
#include "Student.h"
#ifndef METRIC_h
#define METRIC_h

class Metric{
public:
    Metric();
    float mean(DLLQueue<Student> s, int limit);
    float median(DLLQueue<Student> s, int limit);
    int longestWait(DLLQueue<Student> s, int limit);
    int numStudWaitTenMin(DLLQueue<Student> s, int limit);
    int meanIdleTime();
    int longestIdleTime();
    int numIdleWinOverFiveMin();
    void printMetrics(DLLQueue<Student> s, int limit);

};

#endif
