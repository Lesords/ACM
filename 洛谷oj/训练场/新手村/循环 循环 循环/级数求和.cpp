#include<iostream>//ac
using namespace std;
int main() {
	int k,n = 1;//��ʼֵΪ1
	cin>>k;
	double s = 1;//��ʼֵΪ1
	while(s<=k) {
		n++;
		s += 1.0/n;//�ܺ�++ 
	}
	cout<<n<<endl;
	return 0;
} 
