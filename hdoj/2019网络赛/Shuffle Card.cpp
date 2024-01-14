#include<iostream>
#include<cstring>
using namespace std;
int a[200005],book[100005];
int main() {
	int n,m,tmp;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(book,0,sizeof(book));
	for(int i=n;i>=1;i--) {//从n开始输入，重点！！！
		cin>>a[i];
		book[a[i]]=i;//纸牌位置初始化
	}
	int top=n;//纸牌末尾
	for(int i=1;i<=m;i++) {
		cin>>tmp;
		a[book[tmp]]=-1;//原来位置改为-1
		book[tmp]=++top;//数组a末尾为纸牌新位置
		a[book[tmp]]=tmp;//赋值
	}
	for(int i=top;i>=1;i--) {
		if(a[i]==-1) continue;
		cout<<a[i]<<' ';//pe点，末尾加空格
	}
	return 0;
} 
