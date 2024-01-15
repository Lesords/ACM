#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：将所有数去重，然后统计去重后各个数出现的次数
//枚举所有数需要删除的操作数，取较小值
//每个数的操作数为：num[i]+1 （所有数之间的间隔加上首尾）
//若当前即出现首尾的位置，则需要--

const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        vector<int> b,num(n+1);//b为去重后的数组，num为对应值出现的次数
        for(int i = 1;i <= n;i++) {
            if(i==1) {//首个数值
                b.push_back(a[i]);
                num[a[i]]++;
            }
            else {
                if(a[i]!=a[i-1]) {//不等于前一个才进数组（去重）
                    b.push_back(a[i]);
                    num[a[i]]++;
                }
            }
        }
        int ans = INF;//初始化为INF，取最小值
        for(int i = 1;i <= n;i++) {
            if(num[i]==0) continue;//跳过不出现的数值
            int tmp = num[i]+1;//所有间隔
            if(b[0]==i) tmp--;//出现在首位置
            if(b.back()==i) tmp--;//出现在尾位置
            ans = min(ans, tmp);//更新答案
        }
        cout<<ans<<"\n";
    }
    return 0;
}
