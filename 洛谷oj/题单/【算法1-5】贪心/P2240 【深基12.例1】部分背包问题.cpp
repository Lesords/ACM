#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 105;

//��⣺���ݺ�����������С����ѡ�񼴿�
//����������Ϊ����ֵ/����

struct node{
    double wei,val;
    friend bool operator < (node a,node b) {
        return a.val/a.wei > b.val/b.wei;//���Ⱥ��������
    }
}a[MAXN];
int main() {
    int n,t;
    cin>>n>>t;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].wei>>a[i].val;
    }
    sort(a+1,a+n+1);//����
    double ans = 0;
    for(int i = 1;i <= n;i++) {
        if(t>=a[i].wei) {//��װ
            ans += a[i].val;//��ֵȫ��
            t -= a[i].wei;//����ֱ�Ӽ�
        }
        else {//����װ
            ans += t*(a[i].val/a[i].wei);//t*������
            break;//ֱ�ӽ���
        }
    }
    printf("%.2f",ans);
    return 0;
}
