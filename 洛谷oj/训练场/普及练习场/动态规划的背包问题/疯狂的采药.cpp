#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4+5;
ll tim[MAXN],val[MAXN],dp[MAXN*10];//���鿪С�ˣ�����
//dp[i] ��ʾiʱ���ڿ��Բɵ�������ֵ�Ĳ�ҩ
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m;i++) cin>>tim[i]>>val[i];
	for(int i = 1;i <= m;i++) {
		for(int j = tim[i];j <= n;j++) {//�������
			dp[j] = max(dp[j],dp[j-tim[i]]+val[i]);
		}//��Ϊ���Զ��ѡ��ò�ҩ
	}
	cout<<dp[n];
	return 0;
}
