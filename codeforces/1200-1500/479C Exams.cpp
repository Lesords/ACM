#include<iostream>//ac
#include<algorithm>
using namespace std;

//���⣺���밴�յ�˳������ʦ�涨�Ŀ���ʱ���ֻ�ǿ�����ǰ��
//��⣺���չ涨ʱ�����ǰʱ��������Ȼ���ø�������¼��ǰʱ��
//�����ǰʱ����ڵ�ǰʱ�䣬�����ѡ����ǰʱ�䣬����ֻ��ѡ��涨ʱ��

const int MAXN = 5005;
struct node{
    int x,y;
    friend bool operator < (node a,node b) {//�������
        if(a.x!=b.x) return a.x < b.x;
        return a.y < b.y;
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1);
    int ans = 0;//��ǰʱ��
    for(int i = 1;i <= n;i++) {
        if(a[i].y>=ans) ans = a[i].y;//������ǰ��
        else ans = a[i].x;//ֻ�ܰ��չ涨ʱ�俼��
    }
    cout<<ans<<"\n";
    return 0;
}
