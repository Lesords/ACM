#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2) {//x坐标相同，则y坐标不变
        int dis = max(y1,y2)-min(y1,y2);//计算差值
        cout<<x1+dis<<" "<<y1<<" "<<x1+dis<<" "<<y2<<"\n";
    }
    else if(y1==y2) {//y坐标相同，则x坐标不变
        int dis = max(x1,x2)-min(x1,x2);//计算差值
        cout<<x1<<" "<<y1+dis<<" "<<x2<<" "<<y1+dis<<"\n";
    }
    else {
        int xdis = max(x1,x2)-min(x1,x2);
        int ydis = max(y1,y2)-min(y1,y2);//计算两个差
        if(xdis!=ydis) cout<<"-1\n";//不相等即表示不为正方形
        else cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<"\n";//重新组合即可
    }
    return 0;
}
