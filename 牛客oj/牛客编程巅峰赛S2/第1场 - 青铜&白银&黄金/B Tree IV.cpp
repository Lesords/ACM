#include<iostream>//ac
#include<algorithm>
using namespace std;

//需要提交的部分
//题解：直接遍历所有层，每次计算一层的价值和，累加即可，注意取模！！！

#define ll long long
const int MOD = 998244353;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param n long长整型 表示标准完全二叉树的结点个数
     * @return long长整型
     */
    ll tree4(ll n) {
        // write code here
        ll pos = 1,ans = 0;//pos表示每层第一个节点的编号
        for(ll i = 1;;i++) {
            if(pos>n) break;//超过了，则结束
            ll last = pos*2-1;//last表示当前层的最后一个节点的编号
            if(last>n) last = n;//如果last比n大，则更新last的大小
            //等差求和公式，last-pos+1表示该层的节点数量
            ans += i*((pos+last)*(last-pos+1)/2%MOD)%MOD;//注意取模操作
            pos *= 2;//更新首节点的位置
        }
        return ans%MOD;
    }
};

int main() {
    int n;
    cin>>n;
    Solution a;
    cout<<a.tree4(n);
    return 0;
}
