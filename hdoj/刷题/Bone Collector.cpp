#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1005;
int val[MAXN],vol[MAXN],dp[MAXN];
//dp[i] ��ʾΪ����Ϊiʱ�����ֵ
int main() {
	int t,n,v;
	cin>>t;
	while(t--) {
		cin>>n>>v;
		memset(dp,0,sizeof(dp));//��ʼ��
		for(int i = 1;i <= n;i++) cin>>val[i];
		for(int i = 1;i <= n;i++) cin>>vol[i];
		for(int i = 1;i <= n;i++) {
			for(int j = v;j >= vol[i];j--) {
				//vol[i]�պù��Ž�ֹ
				dp[j] = max(dp[j],dp[j-vol[i]]+val[i]);
			}//Ҫô��ǰ��Ҫ��Ҫô����ֵ������ȡ�ϴ�ֵ
		}
		cout<<dp[v]<<endl;
	}
	return 0;
}
