#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105],dp[10005];
//dp[i] ��ʾ����iԪ�ķ�����
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	dp[0] = 1;//��0Ԫֻ��1�֣����ǲ���
	for(int i = 1;i <= n;i++) {
		for(int j = m;j >= a[i];j--)
			dp[j] += dp[j-a[i]];
			//ÿ��j������a[i]��һ�ֿ�����
	}//���෽�����ۼ�
	cout<<dp[m]<<endl;
	return 0;
}
