#include<iostream>
using namespace std;
int main() {
	int T,flag=0,tmp;
	cin>>T;
	while(T--) {
		cin>>tmp;
		if(tmp) flag=1;
	}
	flag?cout<<"HARD"<<endl:cout<<"EASY"<<endl; 
	return 0;
}
