#include<iostream>//ac
#include<set>
using namespace std;
const int MAXN = 1005;
int main() {
	set<int> s[MAXN];
	int n,m,k,tmp;
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++) {//i����ѧ��
		for(int j = 1;j <= m;j++) {//j����ģ�������
			cin>>tmp;//tmpΪ�пյ�ʱ���
			s[tmp].insert(j);//�ڶ�Ӧʱ�����������
		}
	}
	for(int i = 1;i <= k;i++) {
		if(i!=1) cout<<' ';
		cout<<s[i].size();//��������Ӧ��������������
	}
	return 0;
}
