#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace chrono;
typedef unsigned long long ll;
void run(int count){
    while(count-->0){
        cout<<count<<"-CppNuts"<<endl;

    }
    this_thread::sleep_for(seconds(5));
    cout<<"Thread finish:"<<endl;
}
int main(){
    thread t1(run,10);
    cout<<"main()"<<endl;
    //t1.detach();
    cout<<"main() after"<<endl;
    return 0;
}