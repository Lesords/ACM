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
	//调用原函数，更新under数组 
	under[a]+=under[dis[a]];
	dis[a]=ans;
	return dis[a];
}
void merge(int a,int b) {
	int t1=getf(a);//a的祖先 
	int t2=getf(b);//b的祖先 
	if(t1!=t2) {
		under[t1]=sum[t2];
		//t1下方的积木数量为t2积木堆的总数 
		sum[t2]+=sum[t1];
		//t2积木堆的总数量要加上t1堆的数量 
		dis[t1]=t2;
		//t1的祖先更新为t2 
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
			merge(a,b);//合并操作 
		}
		if(ch=='C') {
			cin>>a;
			getf(a);//更新under数组 
			cout<<under[a]<<endl;
		}
	}
	return 0;
}
