#include<iostream>//ac
#include<set>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：对于关系(a,b)来说，可以理解为将 (a+1,b-1)范围里的高度-1
//差分操作：d[a+1]--,d[b]++
//那么对于位置p而言，差分值肯定为0
//需要注意，每种关系的大小，以及可能有重复的关系出现

const int MAXN = 1e4+5;
int d[MAXN];
set<pii> st;//用于出重关系
int main() {
    int n,m,p,h;
    cin>>n>>p>>h>>m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);//交换大小！！！
        if(st.count({a,b})) continue;//重复了，则跳过
        else st.insert({a,b});//否则记录当前关系
        d[a+1]--;// (a+1,b-1)区间内--
        d[b]++;
    }
    int sum = 0;//用于计算前缀和，即当前位置的高度
    for(int i = 1;i <= n;i++) {
        sum += d[i];//累加
        cout<<sum+h<<"\n";//与h的和即为最大高度
    }
    return 0;
}
