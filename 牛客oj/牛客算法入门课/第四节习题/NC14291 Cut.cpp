#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
	ll n,sum = 0,ans = 0;//��int������
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+1+n);//�����������
	for(int i = 1;i < n;i++) {//���һ������Ҫ����
		ans += sum;//���++
		sum -= a[i];//sum�����a[i]
	}
	cout<<ans;
	return 0;
}
