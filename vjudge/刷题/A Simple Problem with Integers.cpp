#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
ll a[MAXN],sum[MAXN<<2],add[MAXN<<2];
void build(int l,int r,int rt) {
	if(l==r) {
		sum[rt] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void push_down(int rt,int ln,int rn) {//���¸���
	if(add[rt]) {
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt] * ln;
		sum[rt<<1|1] += add[rt] * rn;
		add[rt] = 0;
	}
}
ll query(int L,int R,int l,int r,int rt) {//LR������
	ll ans = 0;
	if(l<=L&&R<=r) return sum[rt];
	int mid = (L+R)>>1;
	push_down(rt,mid-L+1,R-mid);
	if(l<=mid) ans += query(L,mid,l,r,rt<<1);
	if(r>mid) ans += query(mid+1,R,l,r,rt<<1|1);
	return ans;
}
void add_op(int L,int R,int l,int r,ll V,int rt) {//LR������
	if(l<=L&&r>=R) {
		sum[rt] += V * (R-L+1);//����
		add[rt] += V;//��Ҫ��ӵ�����
		return ;
	}
	int mid = (L+R)>>1;
	push_down(rt,mid-L+1,R-mid);//���¸�����Ҫ��ӵ�����
	if(l<=mid) add_op(L,mid,l,r,V,rt<<1);
	if(r>mid) add_op(mid+1,R,l,r,V,rt<<1|1);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int main() {
	int n,q;
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,n,1);
	char op;
	int a,b;
	ll c;
	for(int i=1;i<=q;i++) {
		cin>>op;
		if(op=='Q') {
			cin>>a>>b;
			cout<<query(1,n,a,b,1)<<endl;//��ѯa b����
		}
		else {
			cin>>a>>b>>c;
			add_op(1,n,a,b,c,1);//a b������ÿ���� + c
		}
	}
	return 0;
}
