#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺Ȩֵ��״�������k��ֵ
//�������ݷ�Χ�ϴ�������Ҫ�õ���ɢ��
//��ô��Ҫ���߲�������ΪҪ�ȴ洢���ݲ�����ɢ��
//����ÿ����Ҫ ��ȡ�ܵ�ͷ�� ��Ҫ����ô������Ҫ�õ���������¼����Ҫ��
//��ô���� out ����ʱ��ֱ����ȡ���׼���
//����in��out�Ĳ��������Ƕ���������Ӧ����ֵ���ֵĴ���+1��-1
//������������ʵ���Ͼ��Ƕ���״������е����޸�
//��Ӧquery��������ʵ����Ѱ�ҵ�k��

const int MAXN = 1e4+5;
const int MOD = 1e9+7;
string op[MAXN];
int a[MAXN],tree[MAXN],b[MAXN],siz;
int lowbit(int x) {
    return (x)&(-x);
}
int get_val(int pos) {//��ȡposֵ��Ӧ��λ��
    return lower_bound(a+1, a+siz+1, pos)-a;
}
int add(int pos,int val) {//��pos���� +val ����
    while(pos<=siz) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int kth(int mid) {//Ѱ�ҵ� mid С��ֵ
    int num = 0, pos = 0;
    int len = log2(siz);
    for(int i = len;~i;i--) {
        pos += 1<<i;
        if(pos>=siz||num+tree[pos]>=mid) pos -= 1<<i;
        else num += tree[pos];
    }
    return a[pos+1];//��Ӧλ�õ�ֵ��Ϊʵ��ֵ
}
int main() {
    fast;
    int n,cas = 1;
    while(cin>>n) {
        queue<int> q;
        memset(tree, 0, sizeof(tree));//��ʼ��Ϊ0
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            int x;
            cin>>op[i];
            if(op[i]=="in") {
                cin>>x;
                a[++cnt] = x;//��¼���ݣ����ں������ɢ��
                b[cnt] = x;//�ٴμ�¼���ݣ��������߲��� in��
                q.push(x);//���м�¼��Ϣ���������߲��� out��
            }
        }
        sort(a+1, a+cnt+1);
        siz = unique(a+1, a+cnt+1)-a-1;//��ɢ������
        cnt = 1;//in������λ��
        int num = 0;//��ǰ�ܵ������������
        cout<<"Case #"<<cas++<<":\n";//ע�� cas++������
        for(int i = 1;i <= n;i++) {
            if(op[i]=="in") {
                num++;//��ӣ�����++
                add(get_val(b[cnt++]), 1);//��Ӧλ��+1
            }
            else if(op[i]=="out") {
                num--;//���٣�����--
                add(get_val(q.front()), -1);//��Ӧλ��-1
                q.pop();//��������
            }
            else {
                //���� num/2+1 ��ֵ
                cout<<kth(num/2+1)<<"\n";
            }
        }
    }
	return 0;
}
