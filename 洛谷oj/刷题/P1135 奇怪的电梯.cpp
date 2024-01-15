#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 205;
int a[MAXN],book[MAXN],n,A,B;
struct node {
    int pos,step;
};
int bfs(int start) {
    queue<node> q;
    q.push(node{start,0});
    node tmp;
    while(!q.empty()) {
        tmp = q.front();q.pop();
        if(tmp.pos==B) return tmp.step;
        for(int i =  -1;i <= 1;i += 2) {//上下两个位置
            int tx = tmp.pos + a[tmp.pos]*i;
            if(tx<1||tx>n||book[tx]) continue;
            book[tx] = 1;
            q.push(node{tx,tmp.step+1});
        }
    }
    return -1;
}
int main() {
    cin>>n>>A>>B;
    for(int i = 1;i <= n;i++) cin>>a[i];
    cout<<bfs(A)<<endl;
    return 0;
}
