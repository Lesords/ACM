#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
ll a[MAXN],ans,n,k;
bool check(ll mid) {//�ж�mid�Ƿ����
	if(mid == 0) return 1;//����0�����
	ll num = 0;
	for(int i = 1;i <= n;i++) {
		num += a[i]/mid;//ÿ��ľ�Ŀ��ԷֵĶ���
	}
	return num >= k;//�ж��Ƿ�k��
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],ans += a[i];
	ll l = 0,r = ans/k;//��С��ΧΪ0�����Ϊ �ܳ�/k
	while(l<=r) {//���ִ�
		ll mid = (l+r)/2;
		if(check(mid)) {//����
			ans = mid;//���´�
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
