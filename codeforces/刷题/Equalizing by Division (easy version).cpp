#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 999999
using namespace std;
const int maxn=2e5+5;
int a[55],cnt[maxn],num[maxn];
int main() {
	int n,k,ans=INF;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		int tmp=0;
		int x=a[i];
		while(x) {
			cnt[x]++;//������¼x������
			num[x]+=tmp;//��������תΪx�Ĳ�����
			if(cnt[x]==k) {//x����������Ҫ��
				ans=min(ans,num[x]);//ȡС
				break;
			}
			tmp++;
			x/=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
