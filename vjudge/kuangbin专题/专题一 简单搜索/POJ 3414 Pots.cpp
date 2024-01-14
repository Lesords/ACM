#include<iostream>//ac
#include<set>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int a,b,step;
    queue<string> ans;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//优先步数少的
    }
};
struct pour{
    int x,y;
    friend bool operator < (pour a,pour b) {
//        return a.x < b.x;
        if(a.x!=b.x) return a.x < b.x;//set的排序规则要完整！！！
        return a.y < b.y;
    }
};
int n,m,k;
int main() {
    cin>>n>>m>>k;
    priority_queue<node> q;
    node tmp;
    tmp.a = tmp.b = tmp.step = 0;
    q.push(tmp);
    set<pour> vis;
    int flag = 0;
    while(!q.empty()) {
        tmp = q.top();q.pop();
        pour hav;
        hav.x = tmp.a,hav.y = tmp.b;
        if(vis.count(hav)) continue;
        else vis.insert(hav);
        if(tmp.a==k||tmp.b==k) {//满足条件
            cout<<tmp.step<<"\n";
            while(!tmp.ans.empty()) {
                cout<<tmp.ans.front()<<"\n";
                tmp.ans.pop();
            }
            flag = 1;
            break;
        }
        node tt = tmp;
        if(tt.a<n) {
            tt.a = n;
            tt.ans.push("FILL(1)");
            tt.step++;
            q.push(tt);
        }
        tt = tmp;
        if(tt.a) {
            tt.a = 0;
            tt.ans.push("DROP(1)");
            tt.step++;
            q.push(tt);
        }
        tt = tmp;
        if(tt.b<m) {
            tt.b = m;
            tt.ans.push("FILL(2)");
            tt.step++;
            q.push(tt);
        }
        tt = tmp;
        if(tt.b) {
            tt.b = 0;
            tt.ans.push("DROP(2)");
            tt.step++;
            q.push(tt);
        }
        int sum = tmp.a+tmp.b;
        if(tmp.b) {
            tt = tmp;
            tt.a = min(sum,n);
            tt.b = sum - tt.a;
            tt.ans.push("POUR(2,1)");
            tt.step++;
            q.push(tt);
        }
        if(tmp.a) {
            tt = tmp;
            tt.b = min(sum,m);
            tt.a = sum - tt.b;
            tt.ans.push("POUR(1,2)");
            tt.step++;
            q.push(tt);
        }
    }
    if(!flag) cout<<"impossible\n";
    return 0;
}
