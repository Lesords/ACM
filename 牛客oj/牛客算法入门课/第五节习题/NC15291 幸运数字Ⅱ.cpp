#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 3e3+5;
ll a[MAXN],ans,cnt = 0;
void dfs(ll val) {
	if(val>=4444444444) return;//�������ݷ�Χ
	a[++cnt] = val*10+4;
	a[++cnt] = val*10+7;
	dfs(val*10+4);
	dfs(val*10+7);
}
int main() {
	int l,r;
	dfs(0);//��dfs�������ж�Ӧ����
	sort(a+1,a+1+cnt);//��������������һ��
	cin>>l>>r;
	//�ҵ���һ������l������λ��
	int start = lower_bound(a+1,a+1+cnt,l)-a;
	for(int i = l;i <= r;i++) {
		//�ж�ѡ��λ���Ƿ����i
		//������ֱ�Ӽӣ��������һλ�ټ�
		if(i<=a[start]) ans += a[start];
		else ans += a[++start];
	}
	cout<<ans;
	return 0;
}
