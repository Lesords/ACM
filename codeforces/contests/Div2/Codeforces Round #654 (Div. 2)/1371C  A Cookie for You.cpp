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
int main() {
	int t;
	ll a,b,n,m;
	cin>>t;
	while(t--) {
		cin>>a>>b>>n>>m;
		//aΪһ����ɣ�bΪ�������
		//n�������������������
		//mֻ�����������н��ٵ�һ�����
		
		//����a��b�еĽ�Сֵ����ڵ���m����������m��ѡ������
		//ʣ��ı��������ڵ���n��������nҲ���ܵõ�����
		
		if(min(a,b)>=m&&a+b>=n+m) cout<<"Yes\n";
		else cout<<"NO\n";
	}
	return 0;
}
