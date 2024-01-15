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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：根据D1的方法判断是否为YES
//如果为YES，输出对应方案
//1. 先判断行是否为奇数，若为奇数，则最后一行横向铺骨牌
//利用cnt来判断当前铺的编号，根据编号奇偶性来记录骨牌的字符
//记得修改行的大小（注意提前赋值原来的表格大小
//2. 判断列是否为奇数，若为奇数，则最后一列纵向铺骨牌
//利用cnt来记录当前铺的编号，根据编号奇偶性来记录骨牌的字符
//记得修改列的大小
//3. 将剩余所有位置全部两个两个的纵向铺骨牌
//4. 然后在这个铺过纵向骨牌上面，两个两个的铺剩余的横向骨牌
//因为重复铺的话，剩余的位置都是纵向的了，不需要特判！！！

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
char ans[105][105];//记录最后的结果
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        int min_h = n%2?m/2:0;
        int max_h = n*m/2 - (m%2?n/2:0);
        if(min_h<=k&&k<=max_h&&(k-min_h)%2==0) {//若为YES
            cout<<"YES\n";
            int len_n = n,len_m = m;//先记录原表格大小
            if(n%2) {//先判断有没有多余的一行需要横向铺骨牌
                int cnt = 1;
                for(int i = 1;i < m;i += 2) {//每次跳两格
                    ans[n][i] = ans[n][i+1] = cnt%2?'a':'b';//根据奇偶性来选择骨牌的字符
                    k--,cnt++;
                }
                n--;//减去一行
            }
            if(m%2) {//判断是否有多余的一列需要纵向摆放骨牌
                int cnt = 1;
                for(int i = 1;i < n;i += 2) {//每次跳两格
                    ans[i][m] = ans[i+1][m] = cnt%2?'c':'d';//根据奇偶性来选择骨牌的字符
                    cnt++;
                }
                m--;//减去一列
            }
            //将剩余所有位置全部纵向摆放
            int cnt = 1;
            for(int i = 1;i <= n;i += 2) {
                for(int j = 1;j <= m;j += 2) {
                    //两个两个摆放
                    ans[i][j] = ans[i+1][j] = cnt%2?'m':'n';//字符独立选择
                    ans[i][j+1] = ans[i+1][j+1] = cnt%2?'o':'p';
                }
                cnt++;//根据 行 的奇偶性来选择字符！！！
            }
            //然后再水平摆放剩余k个的骨牌
            for(int i = 1;i <= n;i += 2) {
                for(int j = 1;j <= m;j += 2) {
                    if(k==0) break;//为0，结束
                    ans[i][j] = ans[i][j+1] = cnt%2?'e':'f';
                    ans[i+1][j] = ans[i+1][j+1] = cnt%2?'g':'h';
                    k -= 2,cnt++;//根据奇偶性选择骨牌的字符
                }
                if(k==0) break;//为0，结束
            }
            for(int i = 1;i <= len_n;i++) {//输出最后的结果
                for(int j = 1;j <= len_m;j++) cout<<ans[i][j];
                cout<<"\n";
            }
        }
        else cout<<"NO\n";
    }
    return 0;
}
