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

//��⣺�������Ϊ�������е㾡�����Ͽ�������
//��ô�����е���ݺ����꣨�������꣩��С��������
//Ȼ���ͷ��β��ʼ��¼���е�����������Ӧ����ֵ��ȥ��Ӧ�Ŀ��У��У�������
//��Ҫע���ж�һ�£���ǰ�����һ�����������ͬ�����������

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
struct node{
    int x,y,index;//(x,y)Ϊ��Ӧ���꣬indexΪ�±�
}a[MAXN],ans[MAXN];
bool cmp1(node a,node b) {//���ݺ�����x����
    if(a.x==b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(node a,node b) {//����������y����
    if(a.y==b.y) return a.x < b.x;
    return a.y < b.y;
}
int main() {
    int h,w,n;
    cin>>h>>w>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].index = i;//��¼��Ӧ�±�ֵ
    }
    //��������ֱ�������㣡����

    //���������x
    sort(a+1,a+n+1,cmp1);
    int tmp = 0;//tmpΪ��Ӧ�л��еĿ�������
    for(int i = 1;i <= n;i++) {
        int now = a[i].index;
        if(i==1) tmp = a[i].x-1;
        else {
            if(a[i].x!=a[i-1].x) {//����������
                tmp += a[i].x-a[i-1].x-1;
            }
        }
        ans[now].x = a[i].x-tmp;//�۳���Ӧ�Ŀ���
    }
    //����������y
    sort(a+1,a+n+1,cmp2);
    tmp = 0;
    for(int i = 1;i <= n;i++) {
        int now = a[i].index;
        if(i==1) tmp = a[i].y-1;
        else {
            if(a[i].y!=a[i-1].y) {//����������
                tmp += a[i].y-a[i-1].y-1;
            }
        }
        ans[now].y = a[i].y-tmp;//�۳���Ӧ�Ŀ���
    }
    for(int i = 1;i <= n;i++) cout<<ans[i].x<<" "<<ans[i].y<<"\n";
	return 0;
}

