#include<iostream>
#include<algorithm>
using namespace std;
int a[505]; 
int main() {
	int T,n,cnt,tmp,ans;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n;
		ans = 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++) ans += a[i] - a[i-1] -1;//ȫ�����
		ans -= min(a[n]-a[n-1]-1,a[2]-a[1]-1);//ɾ��һ����С��������
		cout<<ans<<endl;
	}
	return 0;
} 
