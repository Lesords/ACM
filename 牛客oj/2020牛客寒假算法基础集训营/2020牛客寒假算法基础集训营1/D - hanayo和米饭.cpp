#include<iostream>//ac
using namespace std;
const int MAXN = 1e5+5;
int book[MAXN];
int main() {
	int n,tmp,ans = 0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n-1;i++) cin>>tmp,book[tmp] = 1;
	//������г��ֹ�������
	//Ȼ���ٱ���һ��Ѱ��һ��δ��ǵ����ּ�Ϊ��
	for(int i = 1;i <= n;i++) if(!book[i]) {//δ���
		ans = i;break;
	}
	cout<<ans<<endl;
	return 0;
}
