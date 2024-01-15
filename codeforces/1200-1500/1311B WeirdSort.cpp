#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：标记所有可以移动的位置，然后将所有标记段排序
//最后判断数组是否为有序即可

int a[105],p[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,flag = 0;
        cin>>n>>m;
        memset(p,0,sizeof(p));//初始化位置
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= m;i++) {
            int pos;
            cin>>pos;
            p[pos] = 1;//标记可转移的位置
        }
        for(int i = 1;i <= n;i++) {
            if(p[i]!=1) continue;//跳过不可移动的位置
            int j = i+1;//i为起点
            while(j<=n&&p[j]) j++;//j为不可转移的位置
            sort(a+i,a+j+1);//转移包括后一位，所以+1！！！
        }
        for(int i = 2;i <= n;i++) {
            if(a[i]<a[i-1]) {//不是有序的
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
