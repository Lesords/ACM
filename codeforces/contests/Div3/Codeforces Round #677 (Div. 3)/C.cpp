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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺ֻҪ���ֵ����������������ֵ���н⣬���ֵ��Ψһ

const int MAXN = 3e5+5;
struct node{
    int val,index;//ֵ���±�
    friend bool operator < (node a,node b) {
        if(a.val!=b.val) return a.val > b.val;//��ֵ���±�
        return a.index < b.index;
    }
}b[MAXN];
int a[MAXN],n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            b[i].val = a[i];
            b[i].index = i;
        }
        sort(b+1,b+n+1);
        int tmp = b[1].val,flag = 0,ans = 0;//tmpΪ���ֵ
        for(int i = 1;i <= n;i++) {
            if(b[i].val<tmp) break;//��Ϊ���ֵ��ֱ�ӽ���
            int pos = b[i].index;
            if(pos-1>=1&&a[pos-1]<a[pos]) {//�ж����
                flag = 1;
                ans = pos;break;
            }
            if(pos+1<=n&&a[pos+1]<a[pos]) {//�ж��ұ�
                flag = 1;
                ans = pos;break;
            }
        }
        if(flag) cout<<ans<<endl;//flagΪ1��ʾ�н�
        else cout<<"-1"<<endl;
    }
	return 0;
}
