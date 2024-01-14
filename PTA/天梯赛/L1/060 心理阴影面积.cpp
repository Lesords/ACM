#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
    int x,y;
    cin>>x>>y;//三角形-空的面积即可
    cout<<5000-(x*y/2)-(100-x)*(100-y)/2-(100-x)*y;
    return 0;
}
