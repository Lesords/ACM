#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：dfs遍历所有情况，记得添加上一个数字为当前遍历的起点
//使得满足，每行都是递增的情况

int a[20],n;
void dfs(int last, int pos) {
    //输出当前状态
    for(int i = 1;i <= pos;i++) cout<<a[i]<<" ";
    cout<<"\n";
    //以 last+1 为起点，保证升序！！！
    for(int i = last+1;i <= n;i++) {
        a[pos+1] = i;
        dfs(i, pos+1);
    }
}
int main() {
    cin>>n;
    dfs(0,0);
    return 0;
}
