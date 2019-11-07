#include <iostream>
#include <fstream>
#include <algorithm>
#include "Metric.h"



using namespace std;

Metric::Metric(){

}

float Metric::mean(DLLQueue<Student> s, int limit){
    int count = 0, sum = 0;
    while(limit != 0){ // getting sums
        sum += s.find(limit-1).getWaiting();
        ++count;
        --limit;
    }
    float mean = (float)sum / count;
    return mean;
}


float Metric::median(DLLQueue<Student> s, int limit){
    int arr[limit];
    int temp = limit, sum = 0;
    while(limit != 0){ // getting sum
        arr[limit-1] = s.find(limit-1).getWaiting();
        sum += s.find(limit-1).getWaiting();
    }
    sort(arr, arr+temp); //sort array
    float median = 0;
    if (temp % 2 != 0){ // median calc
        median = (float)arr[temp/2];
        return median;
    }
    median = (float)(arr[(temp-1)/2] + arr[temp/2])/2.0;

    return median;
}


int Metric::longestWait(DLLQueue<Student> s, int limit){
    int wait = 0;
    while(limit != 0){
        if(wait < s.find(limit-1).getWaiting()){
            wait = s.find(limit-1).getWaiting();
        }
        --limit;
    }
    return wait;
}


int Metric::numStudWaitTenMin(DLLQueue<Student> s, int limit){
    int count = 0;
    while(limit != 0){
        if(10 < s.find(limit-1).getWaiting()){
            ++count;
        }
        --limit;
    }
    return count;
}


int Metric::meanIdleTime(){

}


int Metric::longestIdleTime(){

}

int Metric::numIdleWinOverFiveMin(){

}

void Metric::printMetrics(DLLQueue<Student> s, int limit){
    cout << "The mean wait time was " << mean(s, limit) << endl;
    cout << "The median wait time was " << median(s, limit) << endl;
    cout << "The longest wait time was " << longestWait(s, limit) << endl;
    cout << "The number of student who waited over 10 minutes is" << numStudWaitTenMin(s, limit) << endl;
}
