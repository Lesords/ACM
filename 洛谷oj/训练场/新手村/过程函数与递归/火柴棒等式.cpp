#include<iostream>//ac
using namespace std;
int a[2005] = {6,2,5,5,4,5,6,3,7,6};//�Ϳ��ܴ���1000
int pos[11] = {6,2,5,5,4,5,6,3,7,6};
int main() {
	for(int i = 10;i <= 2000;i++) {//Ԥ����
		int tmp = i;
		while(tmp) {//��λ����
			a[i] += pos[tmp%10];
			tmp /= 10;
		}
	}
	int n, ans = 0;
	cin>>n;
	for(int i = 0;i <= 1000;i++) {
		for(int j = 0;j <= 1000;j++) {//+��=Ϊ4��
			if(a[i]+a[j]+a[i+j]+4==n) ans++;
		}//��������ʱ
	}
	cout<<ans<<endl;
	return 0;
}
