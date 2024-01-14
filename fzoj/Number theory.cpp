#include<iostream>//ac
#include<cstdio> 
#include<cstring>
#define ll long long
using namespace std;

//��⣺��yi��Ϊ��y��i�ڵ�

const int maxn = 1e5+5;
ll n,m,value,tree[maxn<<2];
void build(int L,int R,int rt) {//��ɾ��
	if(L==R) {
		tree[rt] = 1;
		return;
	}
	int mid = (L+R)>>1;
	build(L,mid,rt<<1);
	build(mid+1,R,rt<<1|1);
	tree[rt] = tree[rt<<1]*tree[rt<<1|1] %m;
}
void update(int l,int r,int rt,int L) {
	if(l==r) {
		tree[rt] = value;
		return ;
	}
	int mid = (l+r)>>1;
	if(L<=mid) update(l,mid,rt<<1,L);
	else update(mid+1,r,rt<<1|1,L);
	tree[rt] = tree[rt<<1]*tree[rt<<1|1]%m;
}
int main() {
	int T,tmp;
	char ch;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		//build(1,n,1);
		for(int i=1;i<=n<<2;i++) tree[i] = 1;//��ʼ�� 
		for(int i=1;i<=n;i++) {
			cin>>ch>>tmp;
			if(ch=='M') {
				value = tmp;
				update(1,n,1,i);//��i�ڵ��޸ĳ�tmp
				cout<<tree[1]<<endl;
			}
			else {
				value = 1;
				update(1,n,1,tmp);//��tmp�ڵ��޸ĳ�1
				cout<<tree[1]<<endl;
			}
		}
	}
	return 0;
}
