#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	//�ӵ�һ����ʼ���ľ
	ll ans = a[1];
	//����Ļ�ľ���С��ǰ��Ļ�������һ���
	//�������ǰ��Ļ�����Ҫ�ڴ���ڵĲ���
	for(int i = 2;i <= n;i++) {
		//�������ǰ�棬�ٴ��ֵ
		if(a[i]>a[i-1]) ans += a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
