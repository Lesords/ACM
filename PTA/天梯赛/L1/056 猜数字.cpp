#include<iostream>//ac
#include<cmath>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e4+5;
struct node{
    string name;//名字
    int val;//猜的数
    friend bool operator < (node a,node b) {
        return a.val < b.val;//从小到大排序
    }
}a[MAXN];
int main() {
    int n;
    double sum = 0;//计算总数
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].name>>a[i].val;
        sum += a[i].val;//累加
    }
    sum /= n*2;//除n后再除2
    int ans = INF,index = 0;
    for(int i = 1;i <= n;i++) {
        if(abs(a[i].val-sum)<ans) {//找差值最小的位置
            ans = abs(a[i].val-sum);
            index = i;//记录位置
        }
    }
    cout<<int(sum)<<" "<<a[index].name;
    return 0;
}
