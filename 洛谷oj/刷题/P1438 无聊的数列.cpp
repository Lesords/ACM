#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�߶���
//�����߶������洢ԭ����Ĳ��ֵ
//��ô�������� [l,r] ���һ���Ȳ����� k+0, k+d, k+2d, k+3d����������
//���У�
//1. �� l λ�õ������k����Ϊ��ǰֵ����k��
//2. �� (l, r) ��Χ�ڵĽ����������������d����Ϊ�����Χ�ڣ�ÿ��������ǰ��һ������k��
//3. �� r+1 λ�ý��е����޸ģ���ȥ k+(l-r)*d������ȥԭ�����ж�Ӧ�Ȳ����е����һ����ֵ��
//Ҳ����˵������ת�������������޸ĺ�һ�������޸�
//ע���ж�λ���Ƿ��й��ף�����
//ע�⣺��������д���ˣ�����

const int MAXN = 1e5+5;
struct node{
    int l, r;
    ll val, add;
}tree[MAXN<<2];
ll a[MAXN],d[MAXN];//aΪԭ���飬dΪ�������
//��ǰ�ڵ�Ϊrt��[l,r]Ϊ��������
void build(int rt,int l,int r) {
    tree[rt].l = l, tree[rt].r = r;//���µ�ǰ�ڵ��Ӧ��Ϣ
    tree[rt].add = 0;
    if(l==r) {//Ҷ�ڵ㣬ֱ�Ӹ���ֵ��Ȼ�󷵻�
        tree[rt].val = d[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid);//�ֱ�����������
    build(rt<<1|1, mid+1, r);
    tree[rt].val = tree[rt<<1].val + tree[rt<<1|1].val;//����ֵ
}
//��ǰ�ڵ�Ϊrt��[l,r]Ϊ��ǰ�ڵ�����䷶Χ��midΪ�м��
void push_down(int rt,int l,int mid,int r) {//���ݱ��
    if(tree[rt].add) {
        //���¶�Ӧ����������ֵ
        tree[rt<<1].val += (mid-l+1)*tree[rt].add;
        tree[rt<<1|1].val += (r-mid)*tree[rt].add;
        //����Ǵ��ݵ���Ӧ����������
        tree[rt<<1].add += tree[rt].add;//���ݱ�ǣ�����
        tree[rt<<1|1].add += tree[rt].add;
        tree[rt].add = 0;//����ǰ��Ǹ���Ϊ0
    }
}
//��ǰ�ڵ�Ϊrt��[l,r]Ϊ�������䣬valΪ��Ӧ����ֵ
void update(int rt,int l,int r,ll val) {
    int L = tree[rt].l;//��ǰ�ڵ������
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//���ǵ�ǰ�ڵ���������
        tree[rt].val += (R-L+1)*val;//��Ӷ�Ӧֵ��ע������ӣ�����
        tree[rt].add += val;//��ӱ��
        return;
    }
    int mid = (L+R)>>1;
    push_down(rt, L, mid, R);//���´��ݱ��
    if(l<=mid) update(rt<<1, l, r, val);//�ж����������Ƿ��н������������
    if(r>mid) update(rt<<1|1, l, r, val);
    tree[rt].val = tree[rt<<1].val + tree[rt<<1|1].val;//����ֵ
}
//��ǰ�ڵ�Ϊrt��[l,r]Ϊ��������
ll query(int rt,int l,int r) {
    int L = tree[rt].l;//��ǰ�ڵ�����
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//���ǵ�ǰ�ڵ����䣬ֱ�ӷ���
        return tree[rt].val;
    }
    int mid = (L+R)>>1;
    ll ans = 0;
    push_down(rt, L, mid, R);//���´��ݱ��
    if(l<=mid) ans += query(rt<<1, l, r);//�����Ӧ����������ֵ
    if(r>mid) ans += query(rt<<1|1, l, r);
    return ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        d[i] = a[i]-a[i-1];//������
    }
    build(1, 1, n);//��ʼ������
    while(m--) {
        int op,l,r;
        ll k,d;
        cin>>op;
        if(op==1) {
            cin>>l>>r>>k>>d;
            update(1, l, l, k);//��λ��+k�� [l,l]��Ϊ�����޸�
            if(l+1<=r) update(1, l+1, r, d);//l+r<=rʱ�����ж�Ӧ������
            if(r+1<=n) update(1, r+1, r+1, -(k+(r-l)*d));//������Χ���������
            //��Ϊ��ѯ���������ֵ�ǰ׺�ͣ�������ֵ�޹�
        }
        else {
            cin>>l;
            cout<<query(1, 1, l)<<"\n";//ǰ׺�ͼ�Ϊԭ����ֵ
        }
    }
    return 0;
}
