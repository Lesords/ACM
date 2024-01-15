#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：dfs遍历各种选择情况，判断总酸度和总苦度的最小绝对差

int s[15],b[15],op[15],n,ans=INF;
//s为酸度，b为甜度，op为当前食物是否选择
void dfs(int pos) {//pos为当前需要判断的食物
    if(pos==n+1) {//n+1时，表示前面n个都已经选择完了
        int tmps = 1,tmpb = 0,flag = 1;//酸度需要初始化为1（乘）
        for(int i = 1;i <= n;i++) if(op[i]) {//有选择时
            tmps *= s[i],tmpb += b[i];
            flag = 0;
        }
        if(flag) return ;//全都没选
        ans = min(ans,abs(tmps-tmpb));//取较小值
        return ;
    }
    dfs(pos+1);//当前不选
    op[pos] = 1;//记录当前pos
    dfs(pos+1);//当前选
    op[pos] = 0;//取消记录（回溯到上一个点时会再次到达pos点）！！！
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>s[i]>>b[i],ans = min(ans,abs(s[i]-b[i]));
    //ans记录 单选食物 的 总酸度和总苦度的最小绝对差
    dfs(1);//dfs所有可能性
    cout<<ans<<endl;
    return 0;
}
