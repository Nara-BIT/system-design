#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace chrono;
typedef unsigned long long ll;
mutex mtx;
bool isLock=false;
void check(){
    //mtx.lock();
    if(!isLock)
        cout<<"Not locked"<<endl;
    else{
        cout<<"Locked"<<endl;
    }
    isLock=true;
    //mtx.unlock();
}
int main(){
    thread t1(check);
    thread t2(check);
    
    t1.join();
    
   
    t2.join();
    
    return 0;
}