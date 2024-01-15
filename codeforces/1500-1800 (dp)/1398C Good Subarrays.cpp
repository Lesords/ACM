#include<iostream>//ac
#include<map>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

//题意；求区间长为区间和的数量，那么把每个区间的值-1，可以把问题转换为
//求区间和为0的数量
//利用前缀和计算当前的区间和，如果区间和为0，则结果++
//若区间不为0，假设为k，那么减去前面区间和为k后 所剩余的区间也可为0
//所以当前结果添加为 前缀和为k的数量，可以用map来记录数量

map<int,int> mp;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        mp.clear();//清空
        ll sum = 0,ans = 0;//初始化为0
        cin>>n>>s;
        for(int i = 0;i < s.size();i++) {//遍历所有位置
            sum += s[i]-'1';//当前数-1
            if(sum==0) ans++;//如果为0的话，当前位置需要多加1
            ans += mp[sum]++;//ans添加的是 前面区间和为sum 的值！！！
            //先添加后自增
        }
        cout<<ans<<"\n";
    }
    return 0;
}
