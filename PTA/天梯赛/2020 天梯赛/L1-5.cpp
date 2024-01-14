#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4+5;
int a[5],maxx,mark[5];
int main() {
    double low,dis;
    for(int i = 1;i <= 4;i++) cin>>a[i],maxx = max(maxx,a[i]);
    cin>>low>>dis;
    int flag = 0;
    for(int i = 1;i <= 4;i++) {
        if(abs(maxx-a[i])<=dis&&a[i]>=low) continue;
        mark[i] = 1;
        flag++;
    }
    if(flag==0) {
        cout<<"Normal";return 0;
    }
    if(flag>1) {
        cout<<"Warning: please check all the tires!";
        return 0;
    }
    for(int i = 1;i <= 4;i++) {
        if(mark[i]) {
            cout<<"Warning: please check #"<<i<<"!";
            return 0;
        }
    }
    return 0;
}
