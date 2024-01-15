#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：对于题目而言，有：总状态 = 相邻有相同 + 相邻没有相同
//对于总状态来说，每个犯人都有m个选择，则结果为 m^n
//对于相邻没有相同的状态来说，最左边的犯人有m中选择
//接下来的犯人只有m-1中选择，再后面的还是只有m-1选择
//所以结果为： m*(m-1)*(n-1)
//相邻有相同（越狱） = m^n - m*(m-1)*(n-1)
//注意：犯人是排成一列的（即房间是一列的，不是二维的

const int MOD = 100003;
int poww(ll a,ll b) {//a^b值
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%MOD;//取模
        }
        a = (a*a)%MOD;//取模
        b >>= 1;
    }
    return ans;
}
int main() {
    ll n,m;
    cin>>m>>n;
    ll all = poww(m,n);//总状态
    ll dif = m*poww((m-1),(n-1))%MOD;//相邻不同的状态，记得取模！！！
    cout<<(all-dif+MOD)%MOD;//如果all取模的值比dif小，结果会为负数，所以需+MOD！！！
    return 0;
}
