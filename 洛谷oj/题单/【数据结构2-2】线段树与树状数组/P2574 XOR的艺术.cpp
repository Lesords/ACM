#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//��⣺������1����൱��ȡ��
//���Կ�����lazy�����Ҫȡ��������
//lazyΪ0��ʾ����Ҫȡ����lazyΪ1��ʾ��Ҫȡ��

const int MAXN = 2e5+5;
struct node{
    int l,r,val,chg;//val��¼1��������chg��ʾ�Ƿ���Ҫȡ��
}tree[MAXN<<2];
int a[MAXN];//ԭ����
void build(int pos,int l,int r) {//����
    tree[pos].l = l,tree[pos].r = r;//��¼��ǰ�ڵ�����ұ߽�
    if(l==r) {//Ҷ�ӽڵ㣬�����ֵ
        tree[pos].val = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(pos*2, l, mid);//������������
    build(pos*2+1, mid+1, r);
    tree[pos].val = tree[pos*2].val + tree[pos*2+1].val;//ȡ��
}
void push_down(int pos,int len) {//��ǰ�ڵ�Ϊpos�����ҿ��Ϊlen
    if(tree[pos].chg) {//����ǰ�б��
        tree[pos*2].chg ^= 1;//�����������������
        tree[pos*2+1].chg ^= 1;
        tree[pos].chg = 0;//�������ǰ���
        //������������������
        // len>>1Ϊ���������������� (len - (len>>1) ) Ϊ������������
        tree[pos*2].val = (len-(len>>1))-tree[pos*2].val;//ȡ���������
        tree[pos*2+1].val = (len>>1) - tree[pos*2+1].val;
    }
}
void change(int pos,int l,int r) {// [l,r]Ϊ��������
    if(l<=tree[pos].l&&tree[pos].r<=r) {
        //�������䶼��Ҫ����ʱ��ֻ�޸ĵ�ǰλ�ã������һ��lazy���
        tree[pos].chg ^= 1;
        tree[pos].val = (tree[pos].r-tree[pos].l+1) - tree[pos].val;
        return;
    }
    //���ݱ�ǵ�ʱ�򣬼ǵó����õĲ���l��r������
    push_down(pos, tree[pos].r-tree[pos].l+1);
    int mid = (tree[pos].l+tree[pos].r)/2;
    if(l<=mid) {//���������ཻ����
        change(pos*2, l, r);
    }
    //��ס�������жϵ�Ϊ mid+1 ������
    if(r>=mid+1) {//���������ཻ����
        change(pos*2+1, l, r);
    }
    //�޸ĺ󣬼ǵø��µ�ǰ�ڵ��ֵ������
    tree[pos].val = tree[pos*2].val + tree[pos*2+1].val;
}
int query(int pos, int l,int r) {// [l,r] Ϊ��ѯ����
    //�������˵�ǰ�ڵ���������䣬��ֱ�ӷ���
    if(l<=tree[pos].l&&tree[pos].r<=r) {
        return tree[pos].val;
    }
    push_down(pos, tree[pos].r-tree[pos].l+1);//���´���lazy���
    int mid = (tree[pos].l+tree[pos].r)/2;
    int ans = 0;//ͳ�ƽ��
    if(l<=mid) ans += query(pos*2, l, r);//ͳ��������
    //ע�� ������ ���Ϊ mid+1 ������
    if(r>=mid+1) ans += query(pos*2+1, l, r);//ͳ��������
    return ans;//���ؽ��
}
int main() {
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i = 0;i < s.size();i++) a[i+1] = s[i]=='1';//��¼ԭ����
    build(1,1,n);//����
    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==0) {
            change(1,l,r);//�޸����� [l,r]
        }
        else {
            //��ѯ���� [l,r] �Ľ��
            cout<<query(1,l,r)<<"\n";
        }
    }
    return 0;
}
