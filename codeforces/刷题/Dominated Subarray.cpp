#include<iostream>//ac
#include<cstring>
//��̵���������������Ϊ����������ͬ�����ֵ�����
//�������ֵ�λ�ã����ж���С����
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5; 
int book[MAXN];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(book,0,sizeof(book));
		int minn = INF,tmp;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			if(book[tmp]) {//ȡ��Сֵ
				minn = min(minn,i-book[tmp]+1);
			}
			book[tmp] = i;//��������λ��
		} 
		if(minn!=INF) cout<<minn<<endl;
		else cout<<"-1"<<endl;//���������-1 
	}
	return 0;
}
