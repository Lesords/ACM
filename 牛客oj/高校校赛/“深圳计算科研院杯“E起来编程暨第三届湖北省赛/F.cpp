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
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 1e3+5;
const int MOD = 1e9+7;
struct node{
    ll val;
    int pos;
}a[MAXN],b[MAXN];
int main() {
    int n,cnt = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].pos=i;
    while(cnt<n) {//cntΪ�뿪���е�����
        ll index = 0,time = INF;//timeΪ��ǰ��Ҫ���ٻغ�����ʧȥ����
        for(int j = 1;j <= n-cnt;j++) {
            ll tmp = a[j].val/j;
            if(a[j].val%j) tmp++;//��������Ҫ��һ�غϣ�����
            if(tmp<time) {
                time = tmp;
                index = j;
            }
        }
        int num = n-cnt,tmp = 0;
        for(int i = 1,rk = 1;i <= num;i++) {
            //��time-1����i����time��ֻ��Ҫ��rk������
            //��Ϊֻ�е�time��������������
            a[i].val -= i*(time-1)+rk;
            if(a[i].val<=0) {//��ǰ����ʧȥ���ģ�rk����Ҫ����
                cnt++;
                cout<<a[i].pos<<" ";
            }
            else {
                rk++;//��ǰ����û��ʧȥ���ģ�rk����Ҫ����
            }
        }
        for(int i = 1;i <= num;i++) {//����b�����¼ʣ�����
            if(a[i].val<=0) continue;
            b[++tmp] = a[i];
        }
        for(int i = 1;i <= tmp;i++) a[i] = b[i];//Ȼ�����Ƶ�a����
    }
	return 0;
}
