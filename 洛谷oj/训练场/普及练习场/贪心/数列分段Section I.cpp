#include<iostream>//ac
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
	int n,m,ans = 1,tmp = 0;//��ʼ��Ϊ1��������һ�Σ�
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++) {
		if(tmp+a[i]>m) ans++,tmp = a[i];//��ǰ�������������¶κ�
		else tmp += a[i];//��ǰ�εĺ�����
	}
	cout<<ans<<endl;
	return 0;
}
