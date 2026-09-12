#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace chrono;
typedef unsigned long long ll;

ll oddSum=0;
ll evenSum=0;
void oddsum(ll start,ll end){
	for(ll i=start;i<=end;i++){
		if(i&1){
			oddSum+=i;
		}
	}
}
void evensum(ll start,ll end){
	for(ll i=start;i<=end;i++){
		if(!(i&1)){
			evenSum+=i;
		}
	}
}

int main() {
	ll start=0;
	ll end=19000000000;
	auto startTime=high_resolution_clock::now();
	/*oddsum(start,end);
	evensum(start,end);*/
	thread t1(oddsum,start,end);
	thread t2(evensum,start,end);
	t1.join();
	t2.join();
	auto stopTime=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stopTime-startTime);
	cout<<"OddSum:"<<oddSum<<endl;
	cout<<"EvenSum:"<<evenSum<<endl;
	cout<<"Time:"<<duration.count()/1000000<<endl;
	return 0;
}