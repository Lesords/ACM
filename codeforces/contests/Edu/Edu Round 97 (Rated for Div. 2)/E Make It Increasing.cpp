#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：由于最后结果需要严格升序
//那么可以对原数组减去对应的下标（满足升序），转化为求非递减序列
//（直接计算无法满足中间值修改后是否满足条件，转化后值可以相等
//那么序列中除去 非递减序列 剩余的就是需要修改的数字
//由于指定位置不能修改
//那么可以按照指定位置来划分，计算每个小段中的 非递减序列 ，然后逐个累加
//由于两边可能会有漏掉的，所以可以在首尾添加两个标记，一个-INF，一个INF
//如果指定位置两边不满足非递减，则无解
//注意：每个小段中的 非递减序列 都需要在首尾两个指定位置值的范围内！！！

const int MAXN = 5e5+5;
int a[MAXN],b[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) cin>>a[i], a[i] -= i;//转化
    a[0] = -INF,a[n+1] = INF;//设置两边的边界
    b[k+1] = n+1;//记录最后一个边界的位置，第一个就是为0，所以无需记录
    for(int i = 1;i <= k;i++) cin>>b[i];
    //找非递减（等于或上升）即可
    int ans = 0;
    for(int i = 1;i <= k+1;i++) {                       //遍历所有小区间
        int l = b[i-1], r = b[i];                       //l为左位置，r为右位置
        if(a[l]>a[r]) {                                 //指定位置不满足条件，则无解
            cout<<"-1\n";
            return 0;
        }
        vector<int> v;                                  //存储第i的非递减的值
        for(int j = l+1;j < r;j++) {                    //扣除边界位置
            if(a[l]<=a[j]&&a[j]<=a[r]) {                //需要满足在边界值的范围内
//                vector<int>::iterator pos = upper_bound(v.begin(),v.end(),a[j]);
                auto pos = upper_bound(v.begin(),v.end(),a[j]);//可相等，所以用upper_bound
                if(pos==v.end()) v.push_back(a[j]);     //没找到，则直接添加
                else *pos = a[j];                       //否则更新对应值
            }
        }
        ans += (r-l-1)-v.size();                        //扣除边界和非递减序列，剩余的即为需要修改的
    }
    cout<<ans;
	return 0;
}
