#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 3e5+5;

//题解：由于执行一次前缀转换操作，区间内的0和1数量还是相等的
//所以可以先用前缀和来记录1和0的数量
//然后从后往前开始判断，每次操作的话对应的操作数++
//那么前面的值即为 (a[i]+op)%2 (共0和1，所以模2)

int n, one[MAXN], zero[MAXN];//one和zero记录对应1和0的前缀和
string s,ed;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>s>>ed;
        if(s==ed) {//已经相同，则直接输出YES
            cout<<"YES\n";
            continue;
        }
        for(int i = 0;i < n;i++) one[i] = zero[i] = 0;//初始化为0
        for(int i = 0;i < n;i++) {//记录对应的前缀和
            if(s[i]=='0') zero[i] = zero[i-1]+1,one[i] = one[i-1];
            else one[i] = one[i-1]+1, zero[i] = zero[i-1];
        }
        int cnt_op = 0,flag = 0;//cnt_o为操作数，flag判断是否无解
        for(int i = n-1;i >= 0;i--) {
            int a = s[i]-'0';
            int b = ed[i]-'0';//字符转为数字
            a = (a+cnt_op)%2;//a对应取值，b不变（把a转成b，所以b不变）
            if(a!=b) {//不相等，则执行操作
                if(zero[i]==one[i]) {//前缀区间数量相等可执行操作
                    cnt_op++;
                }
                else {//否则，无解
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
	return 0;
}
