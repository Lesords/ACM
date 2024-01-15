#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：线性dp
//由于题目中出现的是排列，没有重复数字
//所以可以直接记录第二个数列中的数在第一个数列中的位置
//然后在这个位置数组求最长上升子序列即可
//因为公共自序列的话，在第二个排列中顺序肯定也是一样的

const int MAXN = 1e5+5;
int a[MAXN],pos[MAXN];  //pos记录对应数字在第一个排列中的位置
vector<int> ans;        //记录最长上升子序列中对应位置的最大值
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        pos[tmp] = i;   //记录对应位置
    }
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        a[i] = pos[tmp];//保存位置数组，下标是i！！！
    }
    //求最长上升子序列
    for(int i = 1;i <= n;i++) {
        //序列为空，或者可以直接放在最后面
        if(ans.empty()||a[i]>ans.back()) ans.push_back(a[i]);
        else {
            //否则寻找最小的可以交换的位置，并替换对应值
            *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
        }
    }
    cout<<ans.size();
    return 0;
}
