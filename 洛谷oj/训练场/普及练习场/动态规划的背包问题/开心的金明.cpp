#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e4 + 5;
int pri[30],w[30],dp[MAXN],p;
//dp[i] ��ʾΪiԪ�򵽵���Ʒ����Ҫ��֮��
int main() {
	int n,m;
	cin>>n>>m;//�����ά�����������Ϊm������
	for(int i = 1;i <= m;i++) cin>>pri[i]>>p,w[i] = p*pri[i];
	for(int i = 1;i <= m;i++) {//����������Ʒ
		for(int j = n;j >= pri[i];j--) {//����������λ
		    dp[j] = max(dp[j],dp[j-pri[i]]+w[i]);
		}//�����ȡ��ֵ���۸�Ϊprice[i]����Ҫ��Ϊ�˻�
	}
	cout<<dp[n]<<endl;
	return 0;
}
