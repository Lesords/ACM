#include<iostream>//ac
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 15e4+5;
int a[MAXN];
int main() {
	int n;
	set<int> s;//�����һ�޶���ȭ����
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);//����
	for(int i = 1;i <= n;i++) {
		//���������������Ƚ�����ȭ���ֵ�����
		//Ȼ���жϲ��������
		if(a[i]>1&&s.count(a[i]-1)==0) s.insert(a[i]-1);
		else if(s.count(a[i])==0) s.insert(a[i]);
		else if(s.count(a[i]+1)==0) s.insert(a[i]+1);
	}
	cout<<s.size();//�������
	return 0;
}
