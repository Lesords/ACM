#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�����߶���
//��q�β�����ת����������Ϊq���߶���
//ÿ�β������Ƕ��߶����е�Ҷ�ӽڵ���в������������޸�
//���� 1 ����ֱ���޸� ��Ӧ����������Ӧ��λ�� ��ֵ
//���� 2 �����޸� ����λ�� ��ֵ

const int MAXN = 1e5+5;
struct node{
    int l,r;
    ll val;//������Ҫlonglong
}tree[MAXN<<2];
int q,m;
void build(int rt,int l,int r) {//������[l,r]Ϊ��Ӧ����
    tree[rt].l = l, tree[rt].r = r;
    if(l==r) {//Ҷ�ӽڵ㣬����ֵ
        tree[rt].val = 1%m;
        return ;
    }
    int mid = (l+r)/2;
    build(rt*2, l, mid);//�ֱ�����������
    build(rt*2+1, mid+1, r);
    tree[rt].val = tree[rt*2].val*tree[rt*2+1].val%m;
}
void update(int rt,int pos,int val) {//��posλ�õ�ֵ�޸�Ϊval
    int L = tree[rt].l;//��ǰ�ڵ������
    int R = tree[rt].r;
    if(L==R) {//��ΪҶ�ӽڵ㣬��Ϊ����Ҫ�޸ĵĽڵ�
        tree[rt].val = val%m;
        return;
    }
    int mid = (L+R)/2;
    //�ж�pos���ĸ��������޸Ķ�Ӧ������
    if(pos<=mid) update(rt*2, pos, val);
    else update(rt*2+1, pos, val);
    tree[rt].val = tree[rt*2].val * tree[rt*2+1].val % m;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>q>>m;
        build(1, 1, q);
        for(int i = 1;i <= q;i++) {
            int op,x;
            cin>>op>>x;
            if(op==1) {
                update(1, i, x);
            }
            else update(1, x, 1);
            //���ڵ㼴Ϊ����ֵ
            cout<<tree[1].val%m<<"\n";
        }
    }
    return 0;
}
