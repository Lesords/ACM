#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��״����
//���ڶ��ڸ�����������˵�����һ������γ��֣���ôֻȡ���һ�γ��ֵ�λ�ü���
//Ҳ����˵�������ظ���������˵��ֻ�������ֵĴ������й���
//��ô���ǿ������߲���
//�����в�ѯ���а����������С��������
//������״������ά��ÿ�����ֳ��ֹ��׵�λ�ã���ǰλ���й��ף���Ϊ1��
//����last�����¼��Ӧ���ֳ��ֵ����һ����λ��
//Ȼ��ÿ�ν���ǰ��ѯ������ǰ������֣����µ���״������ȥ
//�ǵ�ɾ�� �ظ������� �Ĺ���

const int MAXN = 1e6+6;
struct node{
    int l,r,id;//idΪ��ѯ�ı��
    friend bool operator < (node a,node b) {
        //���������С�������������С����
        if(a.r==b.r) return a.l < a.l;
        return a.r < b.r;
    }
}que[MAXN];//��¼��ѯ
int a[MAXN], last[MAXN], ans[MAXN], tree[MAXN];
//last��¼����λ�ã�ansΪ�������treeΪ��״����
int n,m;

inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}

int lowbit(int x) { return (x)&(-x); }
void add(int pos, int val) {//posλ�����val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {//��ѯpos��ǰ׺��
    int ans = 0;
    while(pos) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    re(n);
    for(int i = 1;i <= n;i++) {
        re(a[i]);
    }
    re(m);
    for(int i = 1;i <= m;i++) {
        re(que[i].l),re(que[i].r);
        que[i].id = i;
    }
    sort(que+1, que+m+1);//�����ѯ
    int pos = 0;//��ǰ������ԭ����λ��
    for(int i = 1;i <= m;i++) {
        while(pos+1<=que[i].r) {//�����һ��λ���ڲ�ѯ��Χ��
            pos++;//�Ƶ���һ��λ�ã���һ��λ�ò��ǲ���λ�ã�����
            int lst = last[a[pos]];//��¼��ǰ�ַ���һ�γ��ֵ�λ��
            if(lst) add(lst, -1);//���ֹ�����ɾ����Ӧ�Ĺ���
            add(pos, 1);//��ӵ�ǰλ�õĹ���
            last[a[pos]] = pos;//���¶�Ӧλ��
        }
        int id = que[i].id;
        ans[id] = ask(que[i].r)-ask(que[i].l-1);//ǰ׺�ͲΪ����ֵ
    }
    for(int i = 1;i <= m;i++) cout<<ans[i]<<"\n";
    return 0;
}
