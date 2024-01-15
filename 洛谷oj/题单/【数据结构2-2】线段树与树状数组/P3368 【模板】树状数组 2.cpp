#include<iostream>//ac
#include<algorithm>
#define lowbit(x) (x)&(-x)
using namespace std;

//��⣺��״������ά�����
//������״����֧�ֵ����޸ĺ������ѯ
//���������ѯ�� ����ǰ׺�� ��˼��
//��ô����������������ǿ������ò��˼��
//����[x,y]�����ڼ�val������add(x,val), add(y+1,-val)
//��ô��ʱ���pos��ѯ��ֵ��Ϊpos�����ԭ��ֵ
//��Ϊ�Բ�ֽ���ǰ׺�͵Ľ����Ϊԭ������ֵ

const int MAXN = 500005;
int n,m,tree[MAXN];
void add(int pos,int val) {//��pos����val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {//��ѯposλ�õ�ֵ
    int ans = 0;
    while(pos>=1) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        add(i,tmp);//[i,i]��������tmp
        add(i+1,-tmp);
    }
    while(m--) {
        int op,x,y,k;
        cin>>op;
        if(op==1) {
            cin>>x>>y>>k;
            //��ֲ���
            add(x,k),add(y+1,-k);
        }
        else {
            cin>>x;
            cout<<ask(x)<<"\n";
        }
    }
    return 0;
}
