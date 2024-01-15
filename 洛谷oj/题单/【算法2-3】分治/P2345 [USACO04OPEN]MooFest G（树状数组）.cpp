#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;

//��⣺��������ֵ����С��������
//Ȼ��������״�������洢��Ӧλ�õ�������ֵ
//����������Сѡ����ţ����ô����ÿ���·���һ������Ϊval����ţnow��˵
//�����ţ������Ϊ��(now - left1 + now - left2 + ������)*val
//�ұ���ţ������Ϊ��(rigt1 - now + right2 - now + ������)*val
//�ܺ�Ϊ��val*(now*�����ţ���� - �����ţλ�ú� + �ұ���ţλ�ú� - now*�ұ���ţ����)
//������ţ�� λ�ú� �Լ� ������ ��������״������ά��
//��״����Ĵ�С��Ϊ����Ĵ�С����״���������ţ��Ӧ��λ����ά������


const int MAXN = 2e4+5;
const int MAXR = 2e4;
struct node{
    int v,x;
    friend bool operator < (node a,node b) {
        //�ȸ���������С���������ٸ���λ�ô�С��������
        if(a.v!=b.v) return a.v < b.v;
        return a.x < b.x;
    }
}a[MAXN];
int num[MAXN],sum[MAXN];//num��¼������sum�����ܺ�
void add_num(int pos) {//posλ�õ�����+1
    for(;pos<=MAXR;pos += lowbit(pos)) num[pos] += 1;
}
void add_val(int pos) {//posλ�õ�ֵ+pos
    int val = pos;//ֵ�ȸ�ֵ����Ϊpos��ֵ��䣡����
    for(;pos<=MAXR;pos += lowbit(pos)) sum[pos] += val;
}
ll ask_num(int pos) {//��posǰ�������ܺ�
    ll sum = 0;
    for(;pos;pos -= lowbit(pos)) sum += num[pos];
    return sum;
}
ll ask_sum(int pos) {//��posǰ�������ܺ�
    ll ans = 0;
    for(;pos;pos -= lowbit(pos)) ans += sum[pos];
    return ans;
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int v,x;
        cin>>v>>x;
        a[i] = {v,x};
    }
    sort(a+1,a+1+n);//����
    ll ans = 0;
    for(int i = 1;i <= n;i++) {//���������ţ���������Ӧ������
        ll lnum = ask_num(a[i].x);//��ߵ�����
        ll rnum = i-lnum-1;//����-�������-��ǰһ��
        ll lsum = ask_sum(a[i].x);//�������ܺ�
        ll rsum = ask_sum(MAXR)-lsum;//�������ܺ� = �ܺ� - �������ܺ�
        ans += a[i].v*(a[i].x*lnum-lsum+rsum-a[i].x*rnum);
        add_num(a[i].x);//a[i].xλ�õ�����+1
        add_val(a[i].x);//a[i].xλ�õ�����+a[i].x
    }
    cout<<ans;
    return 0;
}
