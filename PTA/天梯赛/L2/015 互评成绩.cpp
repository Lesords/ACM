#include<iostream>//ac
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
vector<double> val;//保存最后的平均值
int main() {
    int n,k,m;
    cin>>n>>k>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) cin>>a[j];
        sort(a+1,a+k+1);//从小到大排序
        double ans = 0;
        //去掉一个最高值和一个最低值
        for(int j = 2;j < k;j++) ans += a[j];
        val.push_back(ans/(k-2));//取平均值
    }
    sort(val.begin(),val.end());//排序
    for(int i = n-m;i < n;i++) {//取最大的m个输出即可
        printf("%.3f",val[i]);
        if(i!=n-1) cout<<" ";
    }
    return 0;
}
