#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
	int n,ans = 1,tmp = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 2;i <= n;i++) {
		if(a[i]==a[i-1]+1) tmp++;//����ǰһλ+1ʱ��tmp++
		else ans = max(ans,tmp),tmp = 1;
	}//�������ans,tmp�޸�Ϊ1
	cout<<max(ans,tmp)<<endl;//��n��ʱ����Ҫ����һ��
	return 0;
}
