#include<iostream>//ac
using namespace std;
int main() {
	double n, go = 2;
	cin>>n;
	int cnt = 0;
	while(n>0) {
		cnt++;//����++
		n -= go;//�������
		go *= 0.98;//����ǰ������
	}
	cout<<cnt<<endl;
	return 0;
} 
