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

//��⣺ֻҪ���������ֵ��ͬ�����н�
//����������Ϊ���ģ�������ɢ����

const int MAXN = 1e4+5;
struct node{
    int val,index;//ֵ���±�
    friend operator < (node a,node b) {
        if(a.val!=b.val) return a.val < b.val;
        return a.index < b.index;
    }
}a[MAXN];
int b[MAXN],ans[MAXN],vis[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        memset(vis,0,sizeof(vis));
        set<int> s;//��¼�м��ְ�
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>b[i];
            a[i].val = b[i],a[i].index=i;
            s.insert(a[i].val);//����ֵ
        }
        sort(a+1,a+n+1);//����
        if(s.size()<2) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            int index = a[1].index,val = a[1].val;//��Сֵ����һ�����ĵ㣩
            vis[index] = 1;//��ǵ�ǰ�㣡����
            for(int i = 2;i <= n;i++) {//����ʣ�����е�
                if(b[a[i].index]!=val) {//ֵ��ͬ������
                    cout<<index<<" "<<a[i].index<<endl;
                    vis[a[i].index] = 1;//���������
                }
            }
            index = a[n].index,val = a[n].val;//���ֵ���ڶ������ĵ㣩
            for(int i = 1;i <= n;i++) {
                if(vis[a[i].index]) continue;//�����ѱ�ǵ�
                cout<<index<<" "<<a[i].index<<endl;//ʣ��Ķ����ڶ������ĵ�
            }
        }
    }
	return 0;
}
