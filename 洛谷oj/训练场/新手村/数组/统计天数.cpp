#include<iostream>//ac
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int main() {
	int n,ans = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	int tmp = 1;
	for(int i = 2;i <= n;i++) {
		if(a[i]>a[i-1]) tmp++;
		else {
			if(tmp>ans) ans = tmp;//ȡ�ϴ�ֵ
			tmp = 1;//��1
		}
        if(tmp>ans) ans = tmp;//ʵʱ���´𰸣�����
	}
	cout<<ans<<endl;
	return 0;
}
