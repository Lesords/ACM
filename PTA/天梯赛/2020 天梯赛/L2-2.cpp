#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e3+5;
struct node{
    string name,id;
    int body,hour,minute,pos;
    friend bool operator < (node a,node b) {
        if(a.hour!=b.hour) return a.hour < b.hour;
        if(a.minute!=b.minute) return a.minute < b.minute;
        return a.pos < b.pos;
    }
}a[MAXN];
bool check(string tmp) {
    if(tmp.size()!=18) return 0;
    for(int i = 0;i < (int)tmp.size();i++) {
        if(tmp[i]>='0'&&tmp[i]<='9') continue;
        return 0;
    }
    return 1;
}
int main() {
    int n,p;
    queue<node> bad;
    map<string,int> time;
    cin>>n>>p;
    for(int day = 1;day <= n;day++) {
        int t,s;
        cin>>t>>s;
        for(int i = 1;i <= t;i++) {
            cin>>a[i].name>>a[i].id>>a[i].body;
            a[i].pos = i;
            scanf("%d:%d",&a[i].hour,&a[i].minute);
        }
        sort(a+1,a+1+t);
        for(int i = 1;i <= t;i++) {
            if(check(a[i].id)==0) continue;
            if(a[i].body==1) {
                bad.push(a[i]);
            }
            if(time.count(a[i].id)) {
                if(day-time[a[i].id]<=p) continue;
            }
            cout<<a[i].name<<" "<<a[i].id<<"\n";
            time[a[i].id] = day;
            s--;
            if(s==0) break;
        }
    }
    set<string> vis;
    while(!bad.empty()) {
        node tmp = bad.front();bad.pop();
        if(vis.count(tmp.id)) continue;
        cout<<tmp.name<<" "<<tmp.id<<"\n";
        vis.insert(tmp.id);
    }
    return 0;
}
