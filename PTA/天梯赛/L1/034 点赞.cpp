#include<iostream>//ac
using namespace std;
int a[1005];//记录标签出现数量
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int m,tmp;
        cin>>m;
        for(int i = 1;i <= m;i++) cin>>tmp,a[tmp]++;//统计数量
    }
    int ans = 0,index = 0;;
    for(int i = 1;i <= 1000;i++) {
        if(a[i]>=ans) {//遍历所有标签取大值
            index = i;ans = a[i];
        }
    }
    cout<<index<<" "<<ans;//index是值，ans是数量
    return 0;
}
