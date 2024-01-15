#include<iostream>//ac  公式推导+埃式筛+唯一分解定理
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//题解：题目可化为求a*b的所有正因素个数
//然后先筛出所有质数，最后用唯一分解定理求正因子个数
//求(x,y)的组数，其实就是求x或y的个数（可由其中一个推出另外一个）
//ax+by=xy  =>  ax+(b-x)y = 0   =>  y = ax/(x-b)
//=>    y = (a(x-b)+ab)/(x-b)   =>  y = a + ab/(x-b)  => 即求ab的正因数个数

const int MAXN = 1e6+5;
vector<int> prime;//保存数据范围内的所有素数
int vis[MAXN];
int main() {
    for(int i = 2;i < MAXN;i++) {
        if(vis[i]) continue;
        prime.push_back(i);//记录质数
        for(int j = i+i;j < MAXN;j+=i) vis[j] = 1;
    }//先筛出所有质数
    int t;
    int len = prime.size()-1;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        ll num = a*b,ans = 1;
        for(int i = 0;i <= len;i++) {
            int tmp = 0;
            while(num%prime[i]==0) {
                num /= prime[i];
                tmp++;//计算指数
            }
            if(tmp) ans *= tmp+1;//个数为：所有质因子的 指数+1 的乘积
            if(num==1) break;//以整除，则结束
        }
        cout<<ans<<"\n";
    }
    return 0;
}
