#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+10;
int a[MAXN],b[MAXN];
int main() {
	int t,n,m;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		ll ans = 0;//��ʼ��Ϊ0
		for(int i = 1;i <= n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i = 1;i <= m;i++) cin>>b[i];
		sort(b+1,b+m+1);
		//�����С������Ҫ������С��������
		
		//ֻ��Ҫһ��������ȷ�
		//Ȼ������������������ȵı�׼�Ϸ�ʣ������
		int l = 1, r = n,pos=m+1;//��ʼ��pos�������m
		for(int i = 1;i <= m;i++) {
			//������С����a[r]
			if(b[i]==1) ans += 2*1LL*a[r--];
			else {//��¼����1������������λ��
				pos = i;break;
			}
		}
		//��ʼ��pos�����������ظ�����
		for(int i = m;i >= pos;i--) {//�����������
			ans += a[r--]+a[l];//�������������С��
			l += b[i]-1;//��С����һ��ֳ�ȥ(����Խ��Խ��)
			//����λ����Ҫ��ȥ����һ��
			//l���µ�ֵ����Ϊʣ�����������Сֵ��λ��
		}
		cout<<ans<<endl;
	}
	return 0;
}
