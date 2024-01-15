#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：dfs遍历，以上一个数字+1为起点
//如果选择了m个，则输出并返回

int a[30];
int n,m;
void dfs(int pos) {//当前已经选了pos个
    if(pos==m) {//已经选择了m个
        //输出对应结果并返回
        for(int i = 1;i <= pos;i++) cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }
    //以上一个+1为起点，满足升序情况
    //由于后面选的数肯定比前面大，所以可以不用标记数组！！！
    for(int i = a[pos]+1;i <= n;i++) {
        a[pos+1] = i;//记录当前值
        dfs(pos+1);
    }
}
int main() {
    cin>>n>>m;
    dfs(0);
    return 0;
}
