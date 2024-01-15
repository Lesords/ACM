#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�߶���+������û�

const int MAXN = 1e5+5;
struct node{
    int l,r;
    ll val,add;
}tree[MAXN<<2];
ll a[MAXN];
//rtΪ��ǰ�ڵ㣬[l,r]Ϊ��ǰ���䣨�����볣���޲
void build(int rt,int l,int r) {
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].add = 0;
    if(l==r) {//Ҷ�ӽڵ�
        tree[rt].val = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(rt*2, l, mid);//��������
    build(rt*2+1, mid+1, r);
    tree[rt].val = tree[rt*2].val + tree[rt*2+1].val;
}
//rtΪ��ǰ�ڵ㣬[l, r]Ϊ��Ӧ�������䣬valΪ����ֵ
void update(int rt,int l,int r,ll val) {
    int L = tree[rt].l;//��ǰ�ڵ������
    int R = tree[rt].r;
    //��ʱ [l,r] ����϶������� [L,R] ��
    //��ǰ�ڵ�����¶�Ӧֵ
    tree[rt].val += (r-l+1)*val;
    //���ں����жϻ��ֶ��и����䣬�������϶����غϣ�����
    if(l==L&&R==r) {//�����غϣ�ֱ����ӱ�ǣ�Ȼ�󷵻�
        tree[rt].add += val;
        return;
    }
    int mid = (L+R)/2;
    if(r<=mid) update(rt*2, l, r, val);//������������
    else if(mid<l) update(rt*2+1, l, r, val);//������������
    else update(rt*2, l, mid, val), update(rt*2+1, mid+1, r, val);
    //������[l,r]����������֣�[l,mid]��[mid+1,r]
    //Ȼ��ֱ��������������ֵ
}
//rtΪ��ǰ�ڵ㣬[l,r]Ϊ�������䣬markΪ��ǣ��Ե�ǰ�ڵ��й��ף�
ll query(int rt, int l, int r, ll mark) {
    int L = tree[rt].l;//��ǰ�ڵ������
    int R = tree[rt].r;
    //�����غϣ�������Ƕ�Ӧ�Ĺ��׺͵�ǰֵ���ܺ�
    //��ʱmark��û������ǰ�ڵ�ı�ǣ�����
    if(l==L&&R==r) return (R-L+1)*mark+tree[rt].val;
    int mid = (L+R)/2;
    mark += tree[rt].add;//�ۼӱ��
    if(r<=mid) return query(rt*2, l, r, mark);//������
    else if(mid<l) return query(rt*2+1, l, r, mark);//������
    else return query(rt*2, l, mid, mark)+query(rt*2+1, mid+1, r, mark);
    //�ָ���������䣬Ȼ��������������ĺ�
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    build(1, 1, n);
    while(m--) {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op==1) {
            cin>>k;
            update(1, x, y, k);
        }
        else {
            cout<<query(1, x, y, 0)<<"\n";
        }
    }
    return 0;
}
