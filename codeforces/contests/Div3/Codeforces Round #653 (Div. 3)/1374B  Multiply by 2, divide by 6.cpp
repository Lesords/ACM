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

//����:��2���6���ٴο���Ϊ1���������-1

int main() {
	int t;
	ll n;
	cin>>t;
	while(t--) {
		cin>>n;
		ll ans = 0,flag = 0;//��ʼ��Ϊ0
		if(n==1) cout<<'0'<<endl;//1ֱ���������
		else {
			while(n!=1) {
				while(n%6==0) ans++,n/=6;//���Ա�6��
				if(n==1) break;//Ϊ1����
				//������Ա�3������ô*2֮�󼴿ɱ�6��
				if(n%3==0) n*=2,ans++;
				else {//����˵���޽�
					flag = 1;break;
				}
			}
			if(flag) cout<<"-1"<<endl;
			else cout<<ans<<endl;
		}
	}
	return 0;
}
