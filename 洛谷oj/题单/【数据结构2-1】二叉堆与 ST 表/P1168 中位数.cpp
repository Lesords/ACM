#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;

//题解：对顶堆求第k大，也可求中位数
//上半部分为小根堆，从小到大排列
//下半部分为大根堆，从大到小排列
//两个堆的之间的大小差不能超过1
//查询的时候，输出数量较大的堆的堆顶即可

priority_queue<int> down;//大根堆 下半部分（从大到小
priority_queue<int, vector<int>, greater<int> > up;//小根堆 上半部分（从小到大
void Insert(int tmp) {
    //小根堆为空，或者当前值大于小根堆的堆顶，则插入小根堆
    if(up.empty()||tmp>up.top()) up.push(tmp);
    else down.push(tmp);//否则插入大根堆
    //两个堆的大小需要独立判断（不能用else！！！
    //把另外一个堆的堆顶放入当前堆中
    if(down.size()>up.size()+1) up.push(down.top()),down.pop();
    if(up.size()>down.size()+1) down.push(up.top()),up.pop();
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        Insert(tmp);//添加操作
        if(i&1) {//奇数则需要查询
            //数量较大的堆，取堆顶
            cout<<(up.size()>down.size()?up.top():down.top())<<"\n";
        }
    }
    return 0;
}
