#include<iostream>//ac  直接模拟
#include<cstring>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 105;
int main() {
    int t;
    cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        int n,ans = 0,flag = 0;
        string a,b,c;
        set<string> st;//记录已操作过的牌堆，判断是否无解
        cin>>n>>a>>b>>c;
        while(1) {
            string d = "";//初始化为空
            ++ans;//记录操作次数
            //由于输入数据是从下往上给的，所以操作也从下往上操作
            for(int i = 0;i < n;i++) {//两个牌堆合起来
                d += b[i];
                d += a[i];
            }
            if(st.count(d)==1) break;//已操作过，即无解
            else st.insert(d);
            a = b = "";//a和b牌堆各取一半
            for(int i = 0;i < n;i++) {//最低为a，其他给b
                a += d[i];
            }
            for(int i = n;i < n*2;i++) {
                b += d[i];
            }
            if(d==c) {//满足条件，则输出结果
                cout<<cas<<" "<<ans<<"\n";
                flag = 1;break;
            }
        }
        if(!flag) cout<<cas<<" "<<"-1\n";//特判无解的情况
    }
    return 0;
}
