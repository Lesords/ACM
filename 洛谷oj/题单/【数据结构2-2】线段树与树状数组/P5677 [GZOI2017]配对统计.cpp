#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;

//��⣺��״����
//1. �����ȼ��������������������� (l,r)
//����������⹫ʽ|ax-ay| <= |ax-ai|������  1 <= i <= n && i!=x
//�����й�ͬ��x�����Կ������Ϊ ָ��һ��xλ�ã��ҵ�����һ��y��ʹ������ֵ��С
//����Ϊ��Ŀ�в�������ͬ�����֣����Կɽ�������������
//��ô �õ���� �϶������ڵ����������������������㣩
//ע�����������Ҷ˵�����������
//2. ��ѯ���� �Ҷ˵��λ�� ��С����ʼ������
//���߲���
//���������ѯ�����ǿ����Ƚ����� ��� ����һ�飨�����Ҷ˵��С��������
//ÿ�β�ѯһ������ [l, r] ʱ�������� �Ҷ˵�С�ڲ�ѯ������ ����Է�����״�����м�¼
//��״�����м�¼����ÿ�� ��Ե���˵� ����Ϊ�����Ļ���������
//��ǰ������Ե�������Ϊ [1, r] ������
//��״������ ask(l-1) ��Ϊ [1, l-1] ������
//���������Ϊ ��ǰ�����ѯ�Ľ��
//ע�⣺��¼��˵�����Ϊ��ǰ���е���Ҷ˵㶼��������������ֻ����˵��в��������������������

const int MAXN = 3e5+5;
struct node{
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.val < b.val;//����ֵ����
    }
}a[MAXN];//��¼ԭ����
struct dot{
    int l, r;
    friend bool operator < (dot a, dot b) {
        //�ȸ����Ҷ˵� ��С���� ����
        //�ٸ�����˵� ��С���� ����
        if(a.r==b.r) return a.l < b.l;
        return a.r < b.r;
    }
}ans[MAXN*2];//��¼ �õ���� ��Ϣ
struct ques{
    int l, r, pos;
    friend bool operator < (ques a, ques b) {
        //�ȸ����Ҷ˵� ��С���� ����
        //�ٸ�����˵� ��С���� ����
        if(a.r==b.r) return a.l < b.l;
        return a.r < b.r;
    }
}op[MAXN];//��¼��Ӧ�Ĳ�ѯ����
int cnt, n, m;//cntΪ �õ���� ������
int tree[MAXN];//��״���飬��¼��ѯ��Ϣ
void add_pair(int one,int two) {//������
    int minn = min(a[one].pos, a[two].pos);//��λ��
    int maxx = max(a[one].pos, a[two].pos);//��λ��
    ans[++cnt] = {minn, maxx};
}
void add(int pos,int val) {//posλ�õ�ֵ���val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
ll ask(int pos) {//��ѯ [1,pos] ��ֵ
    ll ans = 0;
    while(pos) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    if(n==1) {//����0�����������
        cout<<"0\n";
        return 0;
    }
    for(int i = 1;i <= n;i++) {
        cin>>a[i].val;
        a[i].pos = i;//��¼��Ӧ��λ��
    }
    sort(a+1,a+1+n);//����ֵ����
    add_pair(1,2);//�������Ҷ˵�
    add_pair(n-1, n);
    for(int i = 2;i < n;i++) {//�����м䲿�ֵ� ���
        int dif_l = abs(a[i].val-a[i-1].val);//����ߵĲ�ֵ
        int dif_r = abs(a[i].val-a[i+1].val);//���ұߵĲ�ֵ
        if(dif_l==dif_r) {//�����ȡ
            add_pair(i, i-1);
            add_pair(i, i+1);
        }//����ȡ��Сֵ
        else if(dif_l<dif_r) add_pair(i, i-1);
        else add_pair(i, i+1);
    }
    sort(ans+1, ans+cnt+1);//�����Ҷ˵��С��������
    for(int i = 1;i <= m;i++) {//��¼��ѯ����
        cin>>op[i].l>>op[i].r;
        op[i].pos = i;//��ѯ�ı��
    }
    sort(op+1, op+m+1);//�����Ҷ˵��С��������
    ll res = 0;//resΪ���
    int pos = 1,cur = 0;//posΪ��ǰ�����λ�ã�curΪ�������
    for(int i = 1;i <= m;i++) {//�������в�ѯ
        int now_r = op[i].r;//��ǰ��ѯ������Ҷ˵�
        //���ڵ�ǰ��ԣ�������Ե��Ҷ˵㲻������ǰ����ʱ����¼����״������
        while(pos<=cnt&&ans[pos].r<=now_r) {
            add(ans[pos].l, 1);//��¼�� ��� ���Ҷ˵�λ��
            cur++;//����++
            pos++;//���λ�ú���
        }
        //cur-ask(op[i].l-1) ��Ϊ��ǰ����� ��� ����
        res += op[i].pos*(cur-ask(op[i].l-1));
    }
    cout<<res;
    return 0;
}
