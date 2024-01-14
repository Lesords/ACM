#include<iostream>//ac  并查集
#include<set>
#include<algorithm>
using namespace std;

//题解：set计算社区的总人数
//每个部落做并查集，（部落中的第一个人和其他人合并）
//将第一个人看作首领，则只需要判断所有人中总共有多少个首领，就有多少个不相交的部落了

const int MAXN = 1e4+5;
int fa[MAXN];
set<int> st;//记录社区的人
int getf(int a) {//路径压缩
    return a==fa[a]?a:fa[a] = getf(fa[a]);
}
void Merge(int a,int b) {//合并
    a = getf(a),b = getf(b);
    if(a!=b) fa[b] = a;//向左合并
}
int main() {
    for(int i = 1;i < MAXN;i++) fa[i] = i;//初始化！！！
    int n,q,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int k;cin>>k;
        int first = 0;//记录当前部落第一个人的编号
        for(int j = 1;j <= k;j++) {
            int tmp;cin>>tmp;
            st.insert(tmp);
            if(j==1) {//保存第一个人的编号
                first = tmp;continue;
            }
            Merge(first,tmp);//剩余的都需要合并
        }
    }
    for(int i = 1;i <= st.size();i++) ans += fa[i]==i;//祖先为本身的即为一个部落首领
    cout<<st.size()<<" "<<ans<<"\n";
    cin>>q;
    while(q--) {
        int a,b;
        cin>>a>>b;
        if(getf(a)==getf(b)) cout<<"Y\n";//判断对应的首领是否一致
        else cout<<"N\n";
    }
    return 0;
}
