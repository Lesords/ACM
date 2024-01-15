#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：SG函数
//对于n和m而言，假设 n >= m
//则有 n = m*k + r
//如果r为0，则当前为必胜态，n - m*k = 0，获取一个0
//否则对于SG(n,m)有：SG(n-m,m),SG(n-2m,m),SG(n-3m,m),···,SG(n%m,m)
//对于这些后继节点而言：
//当k大于等于2时，也就是说SG(n,m)可以转移为SG(n-(k-1)m,m), SG(n%m,m)
//也就是(m+r,m) (m,r) 两种状态，由于(m+r,m)可以转移为(m,r)
//那么则有：两者其中一个是必胜态，另一个是必败态
//那么对于当前而言，可以选择其中一个的必败态来转移，则当前也为必胜态
//对于k小于2的，则继续SG(m,n%m)转移

int judge(int n,int m,int flag) {//flag为赢的人，1为Stan，0为Ollie
    if(n==m||n/m>=2) return flag;//必胜态
    else return judge(m, n-m,flag^1);//否则继续计算
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        if(m<n) swap(m,n);//保证m大于等于n
        if(judge(m,n,1)) cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";
    }
    return 0;
}
