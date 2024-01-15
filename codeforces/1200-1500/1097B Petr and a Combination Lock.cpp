#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：dfs即可，步骤为加或减，条件为%360的值为0

int n,a[20],flag;
void dfs(int pos,int val) {
    if(pos==n) {
        //%360为0即可
        if(val%360==0) flag = 1;//存在一种可能性即可
        return ;
    }
    dfs(pos+1, val+a[pos+1]);
    dfs(pos+1, val-a[pos+1]);
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    dfs(0,0);//dfs
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
