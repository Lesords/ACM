#include<iostream>//ac
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;

//题解：单调栈
//单调栈记录高度从小到大的点
//当当前点高度大于栈顶时，直接入栈
//否则弹出栈顶的点
//每次弹出栈顶的时候，顺便计算对应点的矩形大小
//然后将累加后的宽度合并到当前点的宽度！！！

const int MAXN = 1e5+5;
ll a[MAXN],w[MAXN],que[MAXN];//a记录对应点的高度，w记录对应点的宽度
//que为单调栈记录对应点x坐标
int main() {
    fast;
    int n;
    while(cin>>n&&n) {
        int top = 0;
        ll ans = 0;
        for(int i = 1;i <= n;i++) cin>>a[i];
        a[n+1] = 0;//多添加一个点，用于计算前面所有点（防止栈不为空）
        for(int i = 1;i <= n+1;i++) {
            //当前大于栈顶，直接入栈，并记录对应宽度即可
            if(a[i]>a[que[top]]) que[++top] = i,w[i] = 1;
            else {
                int width = 0;//当前弹出大小的累计宽度
                //如果当前点小于栈顶，则弹出，并计算对应矩形大小
                while(a[i]<a[que[top]]) {
                    int now = que[top--];//记录栈顶的点，并弹出
                    width += w[now];//累计宽度
                    ans = max(ans, width*a[now]);//计算栈顶的点对应的矩形大小
                }
                w[i] = width+1;//前面所有弹出的点的宽度，累计到当前位置
                que[++top] = i;//入栈
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
