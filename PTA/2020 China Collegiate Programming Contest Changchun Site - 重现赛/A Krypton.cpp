#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：利用dfs寻找所有的方案，然后计算最大值

int num[] = {1,6,28,88,198,328,648};
int siz[] = {8,18,28,58,128,198,388};
int ans,vis[10];
void solve(int n,int val) {
    if(n==0) {
        ans = max(val,ans);
        return;
    }
    int flag = 1;
    for(int i = 0;i < 7;i++) {
        if(vis[i]==0) {
            flag = 0;break;
        }
    }
    if(flag==1) {
        ans = max(ans,val+n*10);
        return ;
    }
    for(int i = 0;i < 7;i++) {
        if(vis[i]==0&&n>=num[i]) {
            vis[i] = 1;
            int tmp = val+num[i]*10+siz[i];
            solve(n-num[i],tmp);
            vis[i] = 0;
        }
    }
    ans = max(ans,val+n*10);
}
int main() {
    int n;
    cin>>n;
    solve(n,0);
    cout<<ans<<endl;
    return 0;
}
