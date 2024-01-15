#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：现将原数组排序一遍，然后用排序后的数组与原数组对比
//找出 第一个 值不一样的位置和 最后一个 值不一样的位置
//若位置值为0，则说明已排序，则选择任意一个位置交换即可
//否则需要遍历这个区间，判断正反的值是否一样，不一样则不行

const int MAXN = 1e5+5;
int a[MAXN], b[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],b[i] = a[i];
    sort(a+1,a+n+1);//排序
    int pos1 = 0,pos2 = 0;//找个两个极端位置
    for(int i = 1;i <= n;i++) {//从左到右找
        if(a[i]!=b[i]) {
            pos1 = i;break;
        }
    }
    for(int i = n;i >= 1;i--) {//从右到左找
        if(a[i]!=b[i]) {
            pos2 = i;break;
        }
    }
    if(pos1==0) {//若为0即为有序
        cout<<"yes\n1 1\n";
        return 0;
    }
    for(int i = pos1,j = pos2;i <= pos2;i++,j--) {//遍历这段区间
        if(a[i]!=b[j]) {//若值不同则不行
            cout<<"no\n";
            return 0;
        }
    }
    cout<<"yes\n"<<pos1<<" "<<pos2<<"\n";
    return 0;
}
