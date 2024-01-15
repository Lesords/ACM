#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//��⣺����st�����������ֵ��������Сֵ�������Ϊ���

const int MAXN = 5e4+5;
int a[MAXN],top[MAXN][20],bottom[MAXN][20];//top�������ֵ��bottom������Сֵ
int n,m,t;
void ST_prework() {//��ʼ��
    for(int i = 1;i <= n;i++) top[i][0] = bottom[i][0] = a[i];//��ʼ���߽�
    for(int i = 1;i < t;i++) {//�ȳ��ȣ������
        for(int j = 1;j <= n-(1<<i)+1;j++) {
            int len = 1<<(i-1);//������ֳ�����С���䣬lenΪС���䳤��
            top[j][i] = max(top[j][i-1],top[j+len][i-1]);//���ֵ
            bottom[j][i] = min(bottom[j][i-1], bottom[j+len][i-1]);//��Сֵ
        }
    }
}
int query_max(int l,int r) {//�������ֵ
    int t = log(r-l+1)/log(2);
    return max(top[l][t],top[r-(1<<t)+1][t]);
}
int query_min(int l,int r) {//������Сֵ
    int t = log(r-l+1)/log(2);
    return min(bottom[l][t],bottom[r-(1<<t)+1][t]);
}
int main() {
    cin>>n>>m;//ȫ�ֱ���������һ���꣡����
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    t = log(n)/log(2)+1;//��Ҫ�����Ĵ�С
    ST_prework();
    for(int i = 1;i <= m;i++) {
        int l,r;
        cin>>l>>r;
        cout<<query_max(l,r)-query_min(l,r)<<"\n";
    }
    return 0;
}
