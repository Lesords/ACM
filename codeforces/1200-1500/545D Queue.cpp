#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：按升序排序，从小到大选择可以满足条件的人，跳过不满足条件的人
//因为不满足条件的人会耽误时间！！！

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans = 0,time = 0;//ans为满足条件的人数，time为当前的等待时间
    for(int i = 1;i <= n;i++) {
        if(a[i]>=time) {//满足条件的才计算，其他的跳过
            ans++;
            time += a[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
