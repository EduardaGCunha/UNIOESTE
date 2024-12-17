#include "singleton.h"
#include <iostream>
using namespace std;

SingletonLog *SingletonLog::me = 0;

SingletonLog::SingletonLog(){

};

SingletonLog *SingletonLog::getInstance(){
    if(!me) me = new SingletonLog();
    return me;
}

void SingletonLog::doLog(string msg){
    cout << msg << endl;
}


SingletonLog::~SingletonLog(){
    me=0;
}