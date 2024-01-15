#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于是两两比较，所以可以将所有国家分成两个区间，分别排序
//然后取较小的一个国家即可

const int MAXN = 1<<7+10;
struct node{
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.val > b.val;//从大到小排序
    }
}a[MAXN];
int main() {
    int n,len;
    cin>>n;
    len = 1<<n;
    for(int i = 1;i <= len;i++) {
        cin>>a[i].val;
        a[i].pos = i;
    }
    sort(a+1,a+len/2+1);//左区间
    sort(a+len/2+1,a+len+1);//右区间
    if(a[1].val>a[len/2+1].val) {
        cout<<a[len/2+1].pos;
    }
    else cout<<a[1].pos;
    return 0;
}
