#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
int a[MAXN];
bool left[MAXN],right[MAXN];
vector<int> gleft[MAXN],gright[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 2;i <= n;i++) {
        int pos = 1;
        if(a[i]<=a[1]) {
        }
    }
    return 0;
}
