#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN],n,k,ans;//��Ҫll������
bool check(ll siz) {//sizΪ��С
	ll num = 0;
	for(int i = 1;i <= n;i++) {
		num += a[i]/siz;//ͳ������
	}
	return num >= k;//�ж������Ƿ�
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],ans += a[i];
	//ansͳ���ܳ��ȣ�Ȼ��ɵó����ֵ r
	ll l = 1,r = ans/k;//ans��int�ˣ�����
	ans = 0;//�ٴ������ڴ𰸵ļ���
	while(l<=r) {
		ll mid = (l+r)/2;
		//����ans�������ƶ�l�����1������l��һֱ����r!!!
		if(check(mid)) ans = max(ans,mid),l = mid+1;
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
