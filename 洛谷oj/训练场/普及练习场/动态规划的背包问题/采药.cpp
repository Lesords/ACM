#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105],b[105],dp[1005];
//a���鱣��ʱ�䣬b����Ϊ��ֵ
//dp[i] ��ʾiʱ�����ܲɵ�������ֵ
int main() {
	int T,M;
	cin>>T>>M;
	for(int i = 1;i <= M;i++) cin>>a[i]>>b[i];
	for(int i = 1;i <= M;i++) {
		for(int j = T;j >= a[i];j--) {
			//Ŀ������T - ��ֹ����
			dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
		}//Ҫô�ɣ�Ҫô���ɣ�ȡ��ֵ
	}
	cout<<dp[T]<<endl;
	return 0;
}
