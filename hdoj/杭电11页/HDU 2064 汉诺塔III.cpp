#include<iostream>//ac
using namespace std;
long long a[36] = {0,2};//�򵥶��巽ʽ
int main() {
	int n;
	//���һ��������n���̣���n-1�����Ƶ�����������Ҫ a[n-1]
	//���� n �����Ƶ��ڶ�������Ҫ +1
	//Ȼ�� n-1 �����Ƶ���һ����Ҳ��Ҫ a[n-1]
	//���� n �����Ƶ��������˻���Ҫ +1
	//��� n-1 �����Ƶ���������Ҳ��Ҫ a[n-1]
	//=> a[n] = 3*a[n-1] + 2
	for(int i = 2;i < 36;i++) {
		a[i] = 3 * a[i-1] + 2;
	}
	while(cin>>n) {
		cout<<a[n]<<endl;
	}
	return 0;
} 
