#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;

//注意：出现单链会爆内存，所以用l和r数组来记录左右儿子！！！

const int MAXN = 1e3+5;
int a[MAXN],tree[MAXN],l[MAXN],r[MAXN],cnt;
vector<int> ans;
bool dfs(int rt,int left,int right) {
    tree[rt] = a[left];
    if(left==right) return true;
    int pos = right+1;
    for(int i = left+1;i <= right;i++) {
        if(a[i]>=a[left]) {
            pos = i;break;
        }
    }
    for(int i = pos;i <= right;i++) {
        if(a[left]>a[i]) {
            return 0;
        }
    }
    if(left+1<=pos-1) {
        l[rt] = ++cnt;
        if(!dfs(cnt,left+1,pos-1)) return false;
    }
    if(pos<=right) {
        r[rt] = ++cnt;
        if(!dfs(cnt,pos,right)) return false;
    }
    return true;
}
bool dfs2(int rt,int left,int right) {
    tree[rt] = a[left];
    if(left==right) return true;
    int pos = right+1;
    for(int i = left+1;i <= right;i++) {
        if(a[i]<a[left]) {
            pos = i;break;
        }
    }
    for(int i = pos;i <= right;i++) {
        if(a[left]<=a[i]) {
            return 0;
        }
    }
    if(left+1<=pos-1) {
        l[rt] = ++cnt;
        if(!dfs2(cnt,left+1,pos-1)) return false;
    }
    if(pos<=right) {
        r[rt] = ++cnt;
        if(!dfs2(cnt,pos,right)) return false;
    }
    return true;
}
void ord(int rt) {
    if(tree[l[rt]]) {
        ord(l[rt]);
    }
    if(tree[r[rt]]) {
        ord(r[rt]);
    }
    ans.push_back(tree[rt]);
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    cnt = 1;
    int flag = dfs(1,1,n);
    if(flag) {
        cout<<"YES\n";
        ord(1);
        for(int i = 0;i < ans.size();i++) {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        return 0;
    }
    memset(tree,0,sizeof(tree));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    cnt = 1;
    flag = dfs2(1,1,n);
    if(flag) {
        cout<<"YES\n";
        ord(1);
        for(int i = 0;i < ans.size();i++) {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
