#include<iostream>//ac
using namespace std;
int main() {
	double n, go = 2;
	cin>>n;
	int cnt = 0;
	while(n>0) {
		cnt++;//步数++
		n -= go;//距离减少
		go *= 0.98;//更新前进距离
	}
	cout<<cnt<<endl;
	return 0;
} 
