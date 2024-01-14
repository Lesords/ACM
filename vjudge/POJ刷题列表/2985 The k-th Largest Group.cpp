#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAXN = 2e5+5;

//���⣺����n��è����������������
//1. ������è�Ѻϲ�
//2. ��ѯ������k���è�� ����
//��⣺���鼯+��״����
//ÿ�κϲ���ʱ�����ò��鼯���ж϶�Ӧ�Ķѣ�Ȼ����ϲ������¶�Ӧ����
//��ʼ����Ӧ�ѵ�����Ϊ1
//������Ҫ��ѯ��k����ô��������״������ά��ÿ���������ֵĴ�����Ȩֵ��״���飩
//��ʼ��ʱ����״������ 1 ��ֵΪn������
//ÿ�κϲ���ʱ�򣬽���״������ ��Ӧ���� ��ֵ-1
//����״������ ��Ӧ������ ��ֵ +1������С�Ѻϲ�������
//������״��������� k С��ֵ����ô���Խ���k��ת��Ϊ��Ӧ�ĵ� n-k+1 С(nΪ����)
//���鼯�ϲ���ʱ��˳���¼�ѵ�����

int tree[MAXN],dis[MAXN],num[MAXN];//tree��״����ά����Ӧֵ���ֵĴ���
//dis��¼���ȣ�num��¼��Ӧ���ȶѵ�����
int n, m, cnt;//cntΪ��ǰ�ѵ�����

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
int getf(int pos) {//Ѱ��pos������
    return pos==dis[pos]?pos:dis[pos]=getf(dis[pos]);
}
void add(int pos, int val) {//posλ�����val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int kth(int rk) {//���rk��
    int siz = log2(n);//������
    int num = 0,pos = 0;//numΪ��ǰͳ��������posΪ��ǰ�����λ��
    rk = cnt-rk+1;//ת��Ϊ�� cnt-rk+1 С
    for(int i = siz;~i;i--) {//���㵽-1ʱ����
        pos += 1<<i;//�ۼ�λ��
        //λ�ò��ܴ��ڵ���n�������������ܴ��ڵ���rk
        //Ҳ����˵����һ���߽磬ʹ�õ�ǰλ�ö������㣬��ô����һ��λ��һ��������������
        if(pos>=n||num + tree[pos]>=rk) {
            pos -= 1<<i;
        }
        else num += tree[pos];//�����������ۼ�����
    }
    return pos+1;//��һ��λ�ü�Ϊ���
}
int main() {
    re(n), re(m);
    cnt = n;//��ʼ���ѵ�������Ϊn
    //��ʼ������Ϊ������Ӧ����Ϊ1
    for(int i = 1;i <= n;i++) dis[i] = i,num[i] = 1;
    add(1, n);//��״������1������Ϊn
    for(int cas = 1;cas <= m;cas++) {
        int op,x,y;
        re(op), re(x);
        if(op==0) {
            re(y);
            x = getf(x);
            y = getf(y);
            if(x==y) continue;//Ϊͬһ�ѣ�����ϲ�
            cnt--;//�ϲ�֮�󣬾ͻ���һ����
            add(num[x], -1);//������������Ӧ��ֵ����
            add(num[y], -1);
            add(num[x]+num[y], 1);//�������ܺͶ�Ӧ��ֵ���ӣ��ϲ�
            //����ϲ�������
            dis[y] = x;//y������Ϊx
            num[x] += num[y];//��ôx��������Ҫ����
        }
        else printf("%d\n", kth(x));
    }
    return 0;
}
