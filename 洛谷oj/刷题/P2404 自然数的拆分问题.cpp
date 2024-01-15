#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：dfs生成所有情况，序列为升序就不会重复
//第一个位置不能超过总和的一半，不然会重复(也可避免出现单独的n)
//后一个位置的数不能小于前一个位置的数

int a[10] = {1},n;//第0个位置初始化为1
void dfs(int sum,int pos) {//sum是总和，pos是当前位置
    if(sum==n) {//总和满足条件
        for(int i = 1;i < pos;i++) {//当前位置没计算，不需要输出
            if(i!=1) cout<<"+";
            cout<<a[i];
        }
        cout<<"\n";
        return ;
    }
    //从 前一个数的值 遍历到 剩余值大小
    for(int i = a[pos-1];i <= n-sum;i++) {
        if(pos==1&&i>n/2) break;//第一个位置不能大于 总和的一半
        a[pos] = i;
        dfs(sum+i,pos+1);//继续dfs
    }
}
int main() {
    cin>>n;
    dfs(0,1);//初始总和为0，位置为1
    return 0;
}
