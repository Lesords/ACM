#include<iostream>//ac
#include<algorithm>
#define ll long long
#define two(x) (x)*(x)
using namespace std;
const int MAXN = 305;
int a[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);//��С��������
	ll ans = 0;
	//��һ�������ģ�Ȼ�����ҷ�����������
	int l = 1,r = n,hei = 0;
	while(l<=r) {
		ans += two(hei-a[r]);
		hei = a[r--];//����hei��С
		//��l==rʱ��hei-a[l] = 0���������迼��
		ans += two(hei-a[l]);
		hei = a[l++];//����hei��С
	}
	cout<<ans;
	return 0;
}
