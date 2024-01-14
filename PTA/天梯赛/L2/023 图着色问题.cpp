#include<iostream>//ac
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int a[MAXN];
vector<int> g[MAXN];
bool judge(int pos) {//�ж���pos���ڵĵ㣬�Ƿ�����ɫ��ͬ��
    for(int i = 0;i < g[pos].size();i++) {
        int now = g[pos][i];
        if(a[pos]==a[now]) {
            return true;//����ͬ�ķ���true
        }
    }
    return false;
}
int main() {
    int v,e,k,n;
    cin>>v>>e>>k;
    for(int i = 1;i <= e;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);//���
        g[y].push_back(x);//�����
    }
    cin>>n;
    for(int i = 1;i <= n;i++) {
        set<int> st;
        for(int j = 1;j <= v;j++) {
            cin>>a[j];
            st.insert(a[j]);//ͳ����ɫ������
        }
        if(st.size()!=k) {//����Ϊk��������
            cout<<"No\n";
            continue;
        }
        int flag = 0;
        for(int j = 1;j <= v;j++) {//ֱ�ӱ����жϣ�����Ҫbfs
            if(judge(j)) {
                flag = 1;break;
            }
        }
        if(!flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
