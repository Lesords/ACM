#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;

//题解：升序排序，左右各一半，特判奇数时的中间一位，哪边大跟哪边

int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int mid = n/2,sum1 = 0,sum2 = 0;
    for(int i = 1;i <= mid;i++) sum1 += a[i];//左一半
    int st = mid+1,num1 = mid,num2 = mid;//左右两边的数量各一半
    if(n%2) st++;//奇数时，右边起点后移一位
    for(int i = st;i <= n;i++) sum2 += a[i];//左一半
    if(n%2) {//奇数时，特判中间数属于哪边
        if(sum1>sum2) sum1 += a[mid+1],num1++;//左边大，跟左边
        else sum2 += a[mid+1],num2++;//右边大
    }
    cout<<"Outgoing #: "<<num2<<"\n";//Outgoing是活跃度高的
    cout<<"Introverted #: "<<num1<<"\n";
    cout<<"Diff = "<<max(sum1,sum2)-min(sum1,sum2);
    return 0;
}
