#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于同一个物品有两个属性
//并且每次都是考虑最大化自己与对方得分的差
//则对于牛牛来说得到一个物品得分 + ai而对方少了bi分
//则每次选取的物品应该是 ai + bi 较大的物品

const int MAXN = 2e5 + 5;
int ans_1[MAXN],ans_2[MAXN],A[MAXN];
struct node{
	int val,num;
	friend bool operator < (node a,node b) {
		return a.val > b.val;//从大到小排序
	}
}a[MAXN];
int main() {
	int n,one = 0,two = 0,tmp;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>A[i];
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		a[i].num = i;
		a[i].val = tmp+A[i];//!!!
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) {
		if(i%2) ans_1[++one] = a[i].num;
		else ans_2[++two] = a[i].num;
	}
	for(int i = 1;i <= one;i++) {
		if(i!=1) cout<<' ';
		cout<<ans_1[i];
	}
	cout<<endl;
	for(int i = 1;i <= two;i++) {
		if(i!=1) cout<<' ';
		cout<<ans_2[i];
	}
	cout<<endl;
	return 0;
}
