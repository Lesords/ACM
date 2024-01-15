#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题意：不超过n^2操作使序列有序，操作为区间为三的范围内，最后一位提前，剩余后移
//题解：由于有序序列的逆序对为0，而每次操作都会使逆序对-2（第三位最小，往前两位）
//所以当逆序对为奇数次时必有解，只需要暴力排序即可
//当逆序对为偶数的时候，判断是否有两个数值相同，交换两者位置也可有解(逆序+1)
//否则无解


const int MAXN = 505;
int a[MAXN];
vector<int> ans;
vector<pair<int,int>> pos;//pai先按fi升序排序，再按se升序排序
void change(int i) {//移动操作，i为区间的中间位置
    int tmp = a[i+1];
    a[i+1] = a[i],a[i] = a[i-1];
    a[i-1] = tmp;
}
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        pos.clear(),ans.clear();//初始化
        for(int i = 1;i <= n;i++) cin>>a[i],pos.push_back({a[i],i});
        sort(pos.begin(),pos.end());//排序判断每个数应该处的位置
        for(int i = 0;i < pos.size();i++) {
            a[pos[i].se] = i+1;//数据小标从1开始，需加1
        }//se保存的是原来数据的下标
        int num = 0;//求逆序对数
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j <= n;j++) num += a[i]>a[j];
        }
        if(num&1) {//逆序对为奇数时
            for(int i = 0;i < pos.size()-1;i++) {
                if(pos[i].fi==pos[i+1].fi) {//移动两个值应处的位置
                    swap(a[pos[i].se],a[pos[i+1].se]);
                    break;
                }
            }
        }
        for(int i = 1;i <= n-2;i++) {//暴力找前n-2个数的位置
            int tmp = INF,index;
            for(int j = i;j <= n;j++) {//找最小值
                if(a[j]<tmp) tmp = a[j],index = j;
            }
            if(index==i) continue;//index表示要移动到前面的数
            while(index-2>=i) {//不能超过i位置
                ans.push_back(index-2);//ans保存的是区间第一个数字的下标！！！
                change(index-1);//区间中间修改
                index -= 2;//移动当前数的位置
            }
            if(index!=i) {//如果不在i位置，需原地变换两次
                ans.push_back(index-1),ans.push_back(index-1);
                change(index),change(index);
            }
        }
        int flag = 0;
        for(int i = 1;i <= 3;i++) {//最后两个数的排序只有三种可能
            if(is_sorted(a+1,a+1+n)) {//若已排序，则结束
                flag = 1;break;
            }
            ans.push_back(n-2);//区间初始位置
            change(n-1);
        }
        if(!flag) {
            cout<<"-1"<<endl;continue;
        }
        cout<<ans.size()<<endl;
        for(int i = 0;i < ans.size();i++) {
            if(i!=0) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl
    }
	return 0;
}
