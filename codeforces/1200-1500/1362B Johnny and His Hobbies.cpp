#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：由于数据范围只有1024，所以直接暴力匹配 [1,1024)范围内是否有值满足即可

const int MAXN = 1030;
int a[MAXN],vis[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = -1;//初始化ans为-1
        cin>>n;
        memset(vis, 0, sizeof(vis));//清零
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            vis[a[i]]++;//标记出现的数字
        }
        for(int i = 1;i < 1024;i++) {//不包括1024！！！
            int sum = 0;//统计出现的数字数量
            for(int j = 1;j <= n;j++) {//遍历所有的数
                if(vis[a[j]^i]) sum++;
                //异或的结果唯一，所以判断计算的结果是否出现即可
            }
            if(sum==n) {//有n个表示找到结果
                ans = i;break;
            }
        }
        if(ans!=-1) cout<<ans<<"\n";//不为-1即找到结果
        else cout<<ans<<"\n";
    }
    return 0;
}
