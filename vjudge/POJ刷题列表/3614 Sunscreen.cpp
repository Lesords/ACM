#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：所有的牛根据较小值来从大到小排序
//遍历所有的牛，对于当前的牛来说，在满足条件下，选spf值较高的为最优解
//因为后面的牛的spf值会越来越小
//注意：防晒霜的值会有相同的！！！

const int MAXN = 3e3+5;
struct node{
    int st,ed;
    friend bool operator < (node a,node b) {
        if(a.st!=b.st) return a.st > b.st;//从大到小排序
        return a.ed > b.ed;
    }
}a[MAXN];
int num[MAXN],c,l,ans;//num存储对应防晒霜值的数量
int main() {
    cin>>c>>l;
    for(int i = 1;i <= c;i++) {
        cin>>a[i].st>>a[i].ed;
    }
    sort(a+1,a+1+c);//排序
    for(int i = 1;i <= l;i++) {
        int tmp,tnum;
        cin>>tmp>>tnum;
        num[tmp] += tnum;//要用累加，会出现相同的防晒霜！！！
    }
    for(int i = 1;i <= c;i++) {//依次遍历所有的牛
        for(int j = 1000;j >= 1;j--) {//从大到小寻找满足条件的防晒霜
            if(num[j]==0) continue;//跳过没有剩余数量的
            if(j>=a[i].st&&j<=a[i].ed) {//满足当前牛的范围
                ans++;
                num[j]--;//数量--
                break;//结束寻找
            }
        }
    }
    cout<<ans;
    return 0;
}
