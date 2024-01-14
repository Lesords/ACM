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
			map[name]=i;//利用map将名字转换为数字 
		}
		int m;
		cin>>m;//自己给自己挖坑 
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
			if(a[i][i]>1) {//汇率装换大于1 
				flag=1;
				break;
			}
		cout<<"Case "<<cnt++<<": ";
		if(flag) cout<<"Yes"<<endl;//只有首字母大写 
		else cout<<"No"<<endl;
	}
	return 0;
} 
