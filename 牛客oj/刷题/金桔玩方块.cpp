#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4 + 5;
int book[MAXN];
int main() {
	int n,m,tmp;
	cin>>n>>m;
	while(m--) {
		cin>>tmp;
		book[tmp]++;//��Ǹ�����λ��
	} 
	int minn = 99999;
	for(int i = 1;i <= n;i++) {
		minn = min(minn, book[i]);//ȡ��Сֵ
	}
	cout<<minn<<endl;
	return 0;
}
