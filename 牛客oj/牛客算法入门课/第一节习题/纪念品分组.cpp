#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e4+5;
int a[MAXN];
int main() {
	int w,k;
	cin>>w>>k;
	for(int i = 1;i <= k;i++) cin>>a[i];
	sort(a+1,a+k+1);//����
	int l = 1, r = k,ans = 0;
	while(l<=r) {
		if(l==r) l++,ans++;//λ��ͬһ��λ��
		else if(a[r]+a[l]>w) r--,ans++;//ֻ�ܷ���ϴ�ֵΪһ��
		else r--,l++,ans++;//����һ��
	}
	cout<<ans;
	return 0;
}
