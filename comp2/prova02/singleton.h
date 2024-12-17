#ifndef SINGLETONLOG_H
#define SINGLETONLOG_H

#include <iostream>
using namespace std;

class SingletonLog {
    private:
        static SingletonLog *me;
        SingletonLog();
    public:
        static SingletonLog *getInstance();
        void doLog(string msg);
        ~SingletonLog(); 
};
#endif