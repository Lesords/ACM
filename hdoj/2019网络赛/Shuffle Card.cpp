#include<iostream>
#include<cstring>
using namespace std;
int a[200005],book[100005];
int main() {
	int n,m,tmp;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(book,0,sizeof(book));
	for(int i=n;i>=1;i--) {//��n��ʼ���룬�ص㣡����
		cin>>a[i];
		book[a[i]]=i;//ֽ��λ�ó�ʼ��
	}
	int top=n;//ֽ��ĩβ
	for(int i=1;i<=m;i++) {
		cin>>tmp;
		a[book[tmp]]=-1;//ԭ��λ�ø�Ϊ-1
		book[tmp]=++top;//����aĩβΪֽ����λ��
		a[book[tmp]]=tmp;//��ֵ
	}
	for(int i=top;i>=1;i--) {
		if(a[i]==-1) continue;
		cout<<a[i]<<' ';//pe�㣬ĩβ�ӿո�
	}
	return 0;
} 
