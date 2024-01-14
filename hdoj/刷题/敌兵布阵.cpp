#include<iostream>
#include<cstring>
#include<string>
#define maxn 50005
using namespace std;
int a[maxn],n,sum[maxn<<2];
void Push_up(int rt) {//更新sum数组 
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Build(int l,int r,int rt) {
	if(l==r) {//不可再分节点 
		sum[rt] = a[l];
		return;
	}
	int m = (l+r)>>1;
	Build(l,m,rt<<1);//向左递归 
	Build(m+1,r,rt<<1|1);//向右递归 
	Push_up(rt);//更新数组 
}
void add_op(int L,int C,int l,int r,int rt) {
	if(l==r) {//不可再分节点 
		sum[rt] += C;
		return;
	}
	int m = (l+r)>>1;
	if(L<=m) add_op(L,C,l,m,rt<<1);//寻找L 
	else add_op(L,C,m+1,r,rt<<1|1);
	Push_up(rt);//更新操作 
}
void sub_op(int L,int C,int l,int r,int rt) {
	if(l==r)  {//不可再分节点 
		sum[rt] -= C;
		return;
	}
	int m = (l+r)>>1;
	if(L<=m) sub_op(L,C,l,m,rt<<1);//寻找L 
	else sub_op(L,C,m+1,r,rt<<1|1);
	Push_up(rt);//更新操作 
}
int query(int L,int R,int l,int r,int rt) {
	if(L<=l&&r<=R) {//在查询区间范围内 
		return sum[rt];
	}
	int m = (l+r)>>1;
	int ans = 0;
	if(L<=m) ans += query(L,R,l,m,rt<<1);//判断是否在左半区间
	if(R>m) ans += query(L,R,m+1,r,rt<<1|1);//判断是否在右半区间
	return ans;
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		Build(1,n,1);
		string op;
		int tmp_1,tmp_2;
		cout<<"Case "<<t<<":"<<endl;
		while(cin>>op) {
			if(op=="End") break;
			cin>>tmp_1>>tmp_2; 
			if(op=="Add") {
				add_op(tmp_1,tmp_2,1,n,1);
			}
			else if(op=="Sub") {
				sub_op(tmp_1,tmp_2,1,n,1);
			}
			else {
				cout<<query(tmp_1,tmp_2,1,n,1)<<endl;
			}
		}
	}
	return 0;
}
