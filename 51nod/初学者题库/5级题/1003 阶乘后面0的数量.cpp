#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int n, sum = 0;
	cin>>n;
	while(n) {//��5����0��ֻ��Ҫ��¼5�Ĵ���
		sum += n/5;// 5 25 125��
		n /= 5;
	}
	cout<<sum<<endl;
	return 0;
}
