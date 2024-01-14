#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN = 1e4+5;
int main() {
    int n;
    cin>>n;
    int year = n/100;
    int day = n%100;
    if(year>999) {
        cout<<year<<"-";
        if(day<10) cout<<"0";
        cout<<day;
    }
    else if(year<22) {
        cout<<"20";
        if(year<10)cout<<"0";
        cout<<year<<"-";
        if(day<10) cout<<"0";
        cout<<day;
    }
    else {
        cout<<"19";
        if(year<10)cout<<"0";
        cout<<year<<"-";
        if(day<10) cout<<"0";
        cout<<day;
    }
    return 0;
}
