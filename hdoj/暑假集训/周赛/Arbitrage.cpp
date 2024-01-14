#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
double a[35][35];
int main() {
	int n,cnt=1;
	ios::sync_with_stdio(false);
	while(cin>>n) {
		if(n==0) break;
		memset(a,0,sizeof(a));
		map<string,int> map;
		for(int i=1;i<=n;i++) {
			string name;
			cin>>name;
			map[name]=i;//����map������ת��Ϊ���� 
		}
		int m;
		cin>>m;//�Լ����Լ��ڿ� 
		for(int i=1;i<=m;i++) {
			float num;
			string name1,name2;
			cin>>name1>>num>>name2;
			a[map[name1]][map[name2]]=num;
		}
		for(int k=1;k<=n;k++) 
			for(int i=1;i<=n;i++)
				if(a[i][k]!=0)
				for(int j=1;j<=n;j++)
				if(a[i][j]<a[i][k]*a[k][j])
				a[i][j]=a[i][k]*a[k][j];
		int flag=0;
		for(int i=1;i<=n;i++)
			if(a[i][i]>1) {//����װ������1 
				flag=1;
				break;
			}
		cout<<"Case "<<cnt++<<": ";
		if(flag) cout<<"Yes"<<endl;//ֻ������ĸ��д 
		else cout<<"No"<<endl;
	}
	return 0;
} 
