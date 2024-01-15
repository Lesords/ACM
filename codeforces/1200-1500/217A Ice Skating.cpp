#include<iostream>//ac
#include<vector>
#include<algorithm>
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

//��⣺������ͨ�����������Ϊ��ͨ������-1
//Ѱ���Ƿ���x���y������ͬ����ĵ㼴Ϊ��ͨ

const int MAXN = 1005;
int a[MAXN][MAXN],vis[MAXN][MAXN];
vector<pii> v;
void dfs(int x,int y) {
    vis[x][y] = 1;//��ǵ�ǰ��
    for(int i = 1;i <= 1000;i++) {//��ͬ��x��Ѱ�ҵ�
        if(a[x][i]&&!vis[x][i]) {
            dfs(x,i);
        }
    }
    for(int i = 1;i <= 1000;i++) {//��ͬ��y��Ѱ�ҵ�
        if(a[i][y]&&!vis[i][y]) {
            dfs(i,y);
        }
    }
}
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
        a[x][y] = 1;//��¼��
    }
    for(int i = 0;i < v.size();i++) {
        int x = v[i].fi;
        int y = v[i].se;
        if(vis[x][y]) continue;//�ѱ�ǣ�������
        dfs(x,y);
        ans++;//ͳ����ͨ������
    }
    cout<<ans-1;
    return 0;
}
