#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],b[MAXN];

//��⣺����ÿ��ѧ��Ѱ�Ҳ�ֵ��С��ѧУ����

int main() {
	int n,m;
	ll ans = 0;//��ʼ��Ϊ0
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= m;i++) cin>>b[i];
	sort(b+1,b+m+1);
	for(int i = 1;i <= m;i++) {
		int pos = lower_bound(a+1,a+n+1,b[i])-a;//��λ��
		if(pos==1) ans += llabs(a[pos]-b[i]);//û�����
		else ans += min(llabs(a[pos]-b[i]),llabs(a[pos-1]-b[i]));
		//������ʱ������ֵҲ��Ҫ�жϣ�����
	}
	cout<<ans;
	return 0;
}
