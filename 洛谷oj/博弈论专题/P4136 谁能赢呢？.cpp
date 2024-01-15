#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于最为最优策略走步，那么最终肯定是要走完所有的格子的
//则对于n来说，则剩余 n*n-1 个格子可以走的
//对于先手来说，剩余奇数个步数为必胜
//则有 n*n-1 为奇数，即 n*n 为偶数
//由于n*n和n的奇偶性一致，所以直接判断n的奇偶性即可

int main() {
    int n;
    while(cin>>n&&n) {//到0结束输入
        if(n&1) cout<<"Bob\n";//若为奇数，则有偶数个格子，则后手胜利
        else cout<<"Alice\n";
    }
    return 0;
}
