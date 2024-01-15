#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：利用后缀和的思想来更新，后n个数的和及其最小值
//然后从1到n-2中更新删除k个可获得的最大平均值，结果用vector存储
//结果可能不唯一！！！

const int MAXN = 1e5+5;
double minn[MAXN],suf[MAXN],a[MAXN];
vector<int> ans;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    minn[n] = suf[n] = a[n];//初始状态
    for(int i = n-1;i >= 1;i--) {
        minn[i] = min(a[i], minn[i+1]);//和当前值a[i]比较！！！
        suf[i] = suf[i+1]+a[i];//维护后缀和
    }
    double val = 0;
    for(int i = 1;i <= n-2;i++) {//题目范围为1~(n-2)
        //删除前i个，即从i+1个开始计算
        double tmp = (suf[i+1]-minn[i+1])/(n-i-1);//需要多删除一个最小值
        if(tmp>val) {
            val = tmp;//更新较大值
            ans.clear();//清空旧的答案
            ans.push_back(i);
        }
        else if(tmp==val) ans.push_back(i);//结果一致，则添加
    }
    for(int e:ans) cout<<e<<"\n";
    return 0;
}
