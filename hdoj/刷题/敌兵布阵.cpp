#include<iostream>
#include<cstring>
#include<string>
#define maxn 50005
using namespace std;
int a[maxn],n,sum[maxn<<2];
void Push_up(int rt) {//����sum���� 
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Build(int l,int r,int rt) {
	if(l==r) {//�����ٷֽڵ� 
		sum[rt] = a[l];
		return;
	}
	int m = (l+r)>>1;
	Build(l,m,rt<<1);//����ݹ� 
	Build(m+1,r,rt<<1|1);//���ҵݹ� 
	Push_up(rt);//�������� 
}
void add_op(int L,int C,int l,int r,int rt) {
	if(l==r) {//�����ٷֽڵ� 
		sum[rt] += C;
		return;
	}
	int m = (l+r)>>1;
	if(L<=m) add_op(L,C,l,m,rt<<1);//Ѱ��L 
	else add_op(L,C,m+1,r,rt<<1|1);
	Push_up(rt);//���²��� 
}
void sub_op(int L,int C,int l,int r,int rt) {
	if(l==r)  {//�����ٷֽڵ� 
		sum[rt] -= C;
		return;
	}
	int m = (l+r)>>1;
	if(L<=m) sub_op(L,C,l,m,rt<<1);//Ѱ��L 
	else sub_op(L,C,m+1,r,rt<<1|1);
	Push_up(rt);//���²��� 
}
int query(int L,int R,int l,int r,int rt) {
	if(L<=l&&r<=R) {//�ڲ�ѯ���䷶Χ�� 
		return sum[rt];
	}
	int m = (l+r)>>1;
	int ans = 0;
	if(L<=m) ans += query(L,R,l,m,rt<<1);//�ж��Ƿ����������
	if(R>m) ans += query(L,R,m+1,r,rt<<1|1);//�ж��Ƿ����Ұ�����
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
