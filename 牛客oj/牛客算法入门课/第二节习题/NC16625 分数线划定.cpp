#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 5e3+5;
struct node{
	int val,num;
	friend bool operator < (node a,node b) {
		//����val����num�����ŷ������ű�����
		if(a.val!=b.val) return a.val > b.val;
		return a.num < b.num;
	}
}a[MAXN];
int main() {
	int n,m,ans = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].num>>a[i].val;
	}
	sort(a+1,a+1+n);
	int line = a[(int)floor(m*1.5)].val;//���Է�����
	for(int i = 1;i <= n;i++) {
		if(a[i].val>=line) ans++;//������ans++
	}
	cout<<line<<' '<<ans<<"\n";
	for(int i = 1;i <= n;i++) {
		if(a[i].val>=line) {//������д���ѡ�ֵ���Ϣ
			cout<<a[i].num<<' '<<a[i].val<<"\n";
		}
	}
	return 0;
}
