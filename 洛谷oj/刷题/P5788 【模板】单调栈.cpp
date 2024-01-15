#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;

//题解：从后往前面扫，维护较大值的位置
//需要判断相等的情况！！！
//如果当前位置的值大于栈顶位置的值，则说明栈顶位置不满足条件，需出栈
//当前栈为空，说明没有值比当前大即为0，否则为栈顶的值
//接着把当前位置入栈

const int MAXN = 3e6+6;
int a[MAXN],ans[MAXN];
stack<int> st;
int main() {
    int n;
    ios::sync_with_stdio(0);//加速
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = n;i >= 1;i--) {//从后往前进行
        while(!st.empty()&&a[st.top()]<=a[i]) st.pop();//弹出比当前小的值
        ans[i] = st.empty()?0:st.top();//计算当前结果
        st.push(i);//当前位置入栈
    }
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}
