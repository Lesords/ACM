#include<iostream>//ac
using namespace std;
int ans[11],n,m;
int main() {
	cin>>n>>m;
	for(int i = n;i <= m;i++) {//����n��m
		int tmp = i;
		while(tmp) {//ͳ������������ֵĴ���
			ans[tmp%10]++;
			tmp /= 10;
		}
	}
	for(int i = 0;i <= 9;i++) {//���
		if(i) cout<<' ';
		cout<<ans[i];
	}
	return 0;
}
