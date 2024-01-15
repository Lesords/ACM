#include<iostream>//ac
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

//��⣺��״�������������ֵ
//��״�����ÿ���ڵ�x���洢���� [x-lowbit(x)+1, x] ��Χ�ڵ����ֵ

const int MAXN = 2e5+5;
int n,m;
int tree[MAXN],a[MAXN];
int lowbit(int x) { return (x)&(-x); }
void add(int pos,int val) {//��posλ���޸�Ϊval
    a[pos] = val;//ԭ����ֻ��posλ�ò���Ҫ�޸�
    while(pos<=n) {
        tree[pos] = a[pos];//ȡ���ж�pos�й��׵�λ��ȡmax������
        int siz = lowbit(pos);//siz��Ϊ��ǰpos�������С
        for(int i = 1;i < siz;i <<= 1) {//i���ܳ���siz��С
            tree[pos] = max(tree[pos], tree[pos-i]);//pos-i��Ϊ��pos�й��׵�λ��
        }
        pos += siz;
    }
}
int ask(int l,int r) {//��ѯ[l,r]�����ڵ����ֵ
    int ans = 0;
    while(l<=r) {//������������
        ans = max(ans, a[r]);//ȡ�ұ߽�
        r--;//�ұ߽�ǰ��
        while(r-lowbit(r)>=l) {//���r�����䲻��Խ��l�������ڵ���l��
            ans = max(ans, tree[r]);//��rλ�ô��ڹ���
            r -= lowbit(r);//��С������
        }
    }
    return ans;
}
int main() {
    fast;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        add(i, a[i]);//��ʼ������ʵ����һ���������޸�
    }
    while(m--) {
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='Q') {
            cout<<ask(x,y)<<"\n";
        }
        else {
            if(a[x]<y) {//С��y����Ҫ�޸ģ�����
                add(x, y);
            }
        }
    }
    return 0;
}
