#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;

//题解：存储入栈序列，直接模拟判断是否满足出栈序列
//若栈顶不为出栈的数字，则入栈，直至找到可以出栈的数字
//若找到最后还没找到即无解

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int q,n;
    cin>>q;
    while(q--) {
        cin>>n;
        stack<int> sta;
        int flag = 0,tmp,pos = 0;                   //flag记录是否有解，pos为入栈序列的位置
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) {
            cin>>tmp;
            if(flag) continue;                      //无解，则忽略后面的过程
            while(sta.empty()||sta.top()!=tmp) {    //若栈为空或栈顶数字不满足条件，则入栈
                if(pos+1>n) {                       //所有数字都选过了，则无解
                    flag = 1;break;
                }
                sta.push(a[++pos]);                 //记得移动pos的位置
            }
            if(sta.top()==tmp) sta.pop();           //弹出满足条件的栈顶
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";

    }
    return 0;
}
