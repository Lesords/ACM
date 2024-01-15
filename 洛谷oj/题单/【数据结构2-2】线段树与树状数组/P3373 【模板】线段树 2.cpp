#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�߶���+����lazy���
//�ص���������ǵļ���˳�򣡣���
//���� �ȼӺ�� ��Ӱ�쾫�ȣ����Բ��� �ȳ˺�� ��˳��

//���ӣ�
//������������ a1, a2, a3����ִ�����β��� +2  *3  +4
//1:    t[1].add += 2, t[1].sum = 3*2��3Ϊ���䳤��
//2:    t[1].mul *= 3
//����� sum = (a1+2)*3 + (a2+2)*3 + (a3+2)*3
//3:    t[1].add += 4

//����ȼӺ�˴�ʱ���Ϊ��
// sum = (a1+2 +4)*3 + (a2+2 +4)*3 + (a3+2 +4)*3
//     = (a1+2)*3 +4*3 + (a2+2)*3 +4*3 + (a3+2)*3 +4*3
//����ʵ�ʽ��Ϊ��
// sum = (a1+2)*3 +4 + (a2+2)*3 +4 + (a3+2)*3 +4
//���߲��ȼۣ���Ҫ�ȼ��� /3��������ʾ��
// sum = (a1+2 + 4/3)*3 + (a2+2 + 4/3)*3 + (a3+2 + 4/3)*3
//��ʱΪʵ�����㣬���о������
//������ �ȳ˺�� ��˳��
//ע�⣺����Ӳ���ʱ������ �� �Գ�û��Ӱ�죬���������޸ĳˣ�
//      ��������˲���ʱ����Ҫ�� �� �Ĳ��ֳ��Զ�Ӧ��ֵ������

const int MAXN = 1e5+5;
struct node{
    int l,r;
    ll val,add,mul;//����Ҫ��long long
    //valΪ�ܺͣ�addΪ�ӱ�ǣ�mulΪ�˱��
}tree[MAXN<<2];
int a[MAXN];
int n,m,p;
void build(int rt,int l,int r) {//rtΪ��ǰ�ڵ㣬[l,r]Ϊ��������
    tree[rt].l = l, tree[rt].r = r;//��¼��Ӧ��������
    tree[rt].add = 0, tree[rt].mul = 1;//���³�ֵ
    if(l==r) {//Ҷ�ӽڵ㣬ֱ�Ӹ���ֵ
        tree[rt].val = a[l];
        return ;
    }
    int mid = (l+r)/2;//l��Lһ�£�����Ҳ����l������
    build(rt*2, l,mid);//�ֱ�����������
    build(rt*2+1, mid+1, r);
    tree[rt].val = (tree[rt*2].val + tree[rt*2+1].val)%p;//�ۼ�����������
}
//rtΪ��ǰ�ڵ㣬[l,r]Ϊ��ǰ�ڵ�����䣬midΪ�м��
void push_down(int rt,int l,int r,int mid) {
    int lsiz = mid-l+1;//��������С
    int rsiz = r-mid;//��������С
    //�ȳ˺��
    //ע�⣺�ӵ�ʱ����Ҫ���Զ�Ӧ������С
    tree[rt*2].val = (tree[rt*2].val*tree[rt].mul%p+tree[rt].add*lsiz%p)%p;
    tree[rt*2+1].val = (tree[rt*2+1].val*tree[rt].mul%p+tree[rt].add*rsiz%p)%p;
    //���ݳ˱�ǣ�ֱ�Ӵ��ݼ���
    tree[rt*2].mul = (tree[rt*2].mul * tree[rt].mul)%p;
    tree[rt*2+1].mul = (tree[rt*2+1].mul * tree[rt].mul)%p;
    //���ݼӱ�ǣ���Ҫ�ȼ��� ԭ���ӱ�Ǻ͵�ǰ�˱�ǵĹ��ף�Ȼ���ۼӵ�ǰ�ӱ�ǣ���
    tree[rt*2].add = (tree[rt*2].add*tree[rt].mul%p + tree[rt].add)%p;
    tree[rt*2+1].add = (tree[rt*2+1].add*tree[rt].mul%p + tree[rt].add)%p;
    tree[rt].add = 0;//��Ϊ��ֵ
    tree[rt].mul = 1;
}
//rtΪ��ǰ�㣬[l,r]Ϊ�������䣬valΪ��Ӧֵ
void update_add(int rt,int l,int r,int val) {
    int L = tree[rt].l;//��ǰ�ڵ���������
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//����������ڵ�ǰ�ڵ����䣬ע��˳�򣡣���
        tree[rt].val = (tree[rt].val + (R-L+1)*val%p)%p;//��Ӷ�Ӧ���䳤��
        tree[rt].add = (tree[rt].add + val)%p;//�ӱ��
        return;
    }
    int mid = (L+R)/2;//ע��������[L,R]������
    push_down(rt, L, R, mid);
    //��mid�жϣ�����
    if(l<=mid) update_add(rt*2, l, r, val);//����������䣬�����
    if(r>mid) update_add(rt*2+1, l, r, val);//����������䣬�����
    tree[rt].val = (tree[rt*2].val + tree[rt*2+1].val)%p;//���������
}
//rtΪ��ǰ�㣬[l,r]Ϊ�������䣬valΪ��Ӧֵ
void update_mul(int rt,int l,int r,int val) {
    int L = tree[rt].l;//��ǰ�ڵ���������
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//����������ڵ�ǰ�ڵ����䣬ע��˳�򣡣���
        tree[rt].val = (tree[rt].val * val)%p;//��Ӧ�����ֱ�ӳ�
        tree[rt].mul = (tree[rt].mul*val)%p;//�˱��
        tree[rt].add = (tree[rt].add*val)%p;//��Ҫ������¼ӱ�ǣ�����
        //Ҳ����˵���ӵ��ⲿ��Ҳ��Ҫ *val
        return;
    }
    int mid = (L+R)/2;//ע��������[L,R]������
    push_down(rt, L, R, mid);
    //��mid�жϣ�����
    if(l<=mid) update_mul(rt*2, l, r, val);//����������䣬�����
    if(r>mid) update_mul(rt*2+1, l, r, val);//����������䣬�����
    tree[rt].val = (tree[rt*2].val + tree[rt*2+1].val)%p;//���������
}
int query(int rt,int l,int r) {
    int L = tree[rt].l;//��ǰ�ڵ���������
    int R = tree[rt].r;
    //����������ڵ�ǰ�ڵ����䣬ע��˳�򣡣���
    if(l<=L&&R<=r) return tree[rt].val%p;
    int mid = (L+R)/2;//ע��������[L,R]������
    int ans = 0;
    push_down(rt, L, R, mid);
    //�ж��Ƿ��ж�Ӧ�������������
    //��mid�жϣ�����
    if(l<=mid) ans = (ans+query(rt*2, l, r))%p;
    if(r>mid) ans = (ans+query(rt*2+1, l, r))%p;
    return ans;
}
int main() {
    cin>>n>>m>>p;
    for(int i = 1;i <= n;i++) cin>>a[i];
    build(1,1,n);//����
    while(m--) {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op!=3) cin>>k;
        if(op==1) {
            update_mul(1, x, y, k);
        }
        else if(op==2) {
            update_add(1, x, y, k);
        }
        else if(op==3) {
            cout<<query(1, x, y)<<"\n";
        }
    }
    return 0;
}
