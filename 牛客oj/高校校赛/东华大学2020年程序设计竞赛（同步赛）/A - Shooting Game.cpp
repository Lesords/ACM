#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int id,sum;
	friend bool operator < (node a,node b) {
		if(a.sum!=b.sum) return a.sum > b.sum;
		return a.id < b.id;
	}
}a[105];
int main() {
	int n,id,red,white,black;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>id>>red>>white>>black;
		a[i].id = id;
		a[i].sum = red+white*2+black*3;
	}
	sort(a+1,a+n+1);
	cout<<a[1].id<<' '<<a[1].sum;
	return 0;
}
