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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int num,pos;
    friend bool operator < (node a,node b) {
        if(a.num!=b.num) return a.num < b.num;
        return a.pos < b.pos;
    }
};
vector<int> posa;
vector<node> v;
int main() {
    int n,k,num = 0,last = -1;
    string s;
    cin>>n>>k>>s;
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='a') posa.push_back(i);
    }
    if(posa.empty()) {//特判没有a字符的情况！！！
        for(int i = 0;i < k;i++) {
            s[i] = 'a';
        }
        cout<<k-1<<"\n"<<s<<"\n";
        return 0;
    }
    for(int i = 1;i < posa.size();i++) {
        if(posa[i]!=posa[i-1]+1) {
            v.push_back({posa[i]-posa[i-1]-1,posa[i-1]+1});
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i < v.size();i++) {
        node tmp = v[i];
        if(tmp.num<=k) {
            k -= tmp.num;
            for(int j = 0;j < tmp.num;j++) {
                s[j+tmp.pos] = 'a';
            }
            if(k==0) break;
        }
        else {
            for(int j = 0;j < k;j++) {
                s[j+tmp.pos] = 'a';
            }
            k = 0;
            break;
        }
    }
    if(k&&posa[0]>0) {
        for(int i = posa[0]-1;i >= 0;i--) {
            k--;
            s[i] = 'a';
            if(k==0) break;
        }
    }
    if(k&&posa[posa.size()-1]<n-1) {
        for(int j = posa[posa.size()-1]+1;j < n;j++) {
            k--;
            s[j] = 'a';
            if(k==0) break;
        }
    }
    for(int i = 1;i < n;i++) {
        if(s[i]==s[i-1]&&s[i]=='a') num++;
    }
    cout<<num<<"\n"<<s;
	return 0;
}
/*
9 5
ccccaaccc

9 2
cacccaccc
*/
