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
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		//ż���԰�ּ�Ϊ��
		//�����Ļ������м�Ϊ��׼������ƽ�ּ�Ϊ��
		if(n%2==0) cout<<n/2<<endl;
		else cout<<n/2+1<<endl;
	}
	return 0;
}
