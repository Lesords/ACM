#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int dis[30005],sum[30005],under[30005];
int getf(int a) {
	/*int tmp;
	if(a!=dis[a]) {
		tmp=getf(dis[a]);
		under[a	]+=under[dis[a]];
		dis[a]=tmp;
	}
	return dis[a];*/
	if(a==dis[a]) return a;
	int ans=getf(dis[a]);
	//����ԭ����������under���� 
	under[a]+=under[dis[a]];
	dis[a]=ans;
	return dis[a];
}
void merge(int a,int b) {
	int t1=getf(a);//a������ 
	int t2=getf(b);//b������ 
	if(t1!=t2) {
		under[t1]=sum[t2];
		//t1�·��Ļ�ľ����Ϊt2��ľ�ѵ����� 
		sum[t2]+=sum[t1];
		//t2��ľ�ѵ�������Ҫ����t1�ѵ����� 
		dis[t1]=t2;
		//t1�����ȸ���Ϊt2 
	}
}
int main() {
	int n,a,b;
	char ch;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<30005;i++) {
		dis[i]=i;
		under[i]=0;
		sum[i]=1;
	}
	for(int i=0;i<n;i++) {
		cin>>ch;
		if(ch=='M') {
			cin>>a>>b;
			merge(a,b);//�ϲ����� 
		}
		if(ch=='C') {
			cin>>a;
			getf(a);//����under���� 
			cout<<under[a]<<endl;
		}
	}
	return 0;
}
