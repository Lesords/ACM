#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：走到d的路径有a和b和c三个点，走到a或b或c的路径为 其他两点 + d
//又由于对称性，abc三点值一致，所以有
//当前d = 上一个abc*3%MOD
//当前abc = (上一个abc*2 + 上一个d)%MOD
//初始化上一个d为1

const int MAXN = 1e7+6;
const int MOD = 1e9+7;
int main() {
    int n;
    cin>>n;
    ll ld = 1,now_d = 0;
    ll labc = 0,now_abc = 0;//初始化
    for(int i = 1;i <= n;i++) {//从1开始，初始化从0开始的
        now_d = (labc*3)%MOD;//三个路径走向d
        now_abc = (labc*2+ld)%MOD;//两个其他点+d
        labc = now_abc;//更新上个路径的值
        ld = now_d;
    }
    cout<<now_d;
    return 0;
}
