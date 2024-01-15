#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解；利用双指针来计算，每个统计a或者b的数量
//如果a或b的数量小于k，则表示区间[l,r]满足条件，更新答案，r继续移动
//否则根据l的位置修改a或b的数量，l和r都移动

int main() {
    int n,k,ans = 0;
    string s;
    cin>>n>>k>>s;
    int l = 0,r = 0,numa = 0,numb = 0;
    while(r<n) {//不超过范围则继续计算
        if(s[r]=='a') numa++;//统计a或b的数量
        else numb++;
        if(numa<=k||numb<=k) {//小于k则表示满足条件
            ans = max(ans, r-l+1);//更新答案
            r++;//r继续移动
        }
        else {
            if(s[l]=='a') numa--;//根据l的位置修改a或b的数量
            else numb--;
            l++,r++;//两种都移动（l移动为了删除，r移动为了继续计算）
        }
    }
    cout<<ans<<"\n";
    return 0;
}
