#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

//题解：贪心
//记录当前所有已经选了的集合，及其总和
//每次都将当前的值选进去，然后判断集合的总和是否小于0
//若小于0的话，则将集合中最小的数弹出，直至集合的和不小于0
//最后集合的数量即为答案
//利用优先队列来记录集合中的最小值！！！

const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int n;
    cin>>n;
    ll sum = 0;//集合的总和
    priority_queue<int, vector<int>, greater<int> > q;//从小到大
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        q.push(a[i]);//将当前的数放入集合中
        sum += a[i];//累加和
        while(sum<0) {//若和小于0
            sum -= q.top();//删除对应的最小值
            q.pop();//弹出该值
        }
    }
    cout<<q.size();//集合总数即为结果
    return 0;
}
