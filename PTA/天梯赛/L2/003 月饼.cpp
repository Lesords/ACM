#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
struct node{
    double wei,val,sing;
    friend bool operator < (node a,node b) {
        //�����򵥼ۣ�Ȼ������
        if(a.sing!=b.sing) return a.sing > b.sing;
        return a.wei > b.wei;
    }
}a[MAXN];
int main() {
    int n,d;
    cin>>n>>d;
    for(int i = 1;i <= n;i++) cin>>a[i].wei;//wei������valΪ���ۼ�
    for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].sing = a[i].val/a[i].wei;
    //���� = �ܼ�/����
    sort(a+1,a+n+1);
    double ans = 0;
    for(int i = 1;i <= n;i++) {//dΪ����Ҫ������
        if(d==0) break;//Ϊ0ʱ����
        if(d>a[i].wei) {//��ǰȫ��Ҫ
            ans += a[i].val;
            d -= a[i].wei;//������
        }
        else {
            ans += a[i].sing*d;//ֻ��Ҫ����d����
            break;//����
        }
    }
    printf("%.2f",ans);//������λ����
    return 0;
}
