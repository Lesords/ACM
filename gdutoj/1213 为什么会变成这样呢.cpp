#include<iostream>//?
#include<cstdio>
#define uint unsigned int
using namespace std;
const int MAXN = 1e6+6;
uint a[MAXN];
int solve(int val) {
    int pos = 1;
    while(val) {
        if(val&1) {
            return 1<<(pos-1);
        }
        val >>= 1;
        pos++;
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        uint sum = 0;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            sum ^= a[i];
        }
        int pos = solve(sum),one = 0,two = 0;
        for(int i = 1;i <= n;i++) {
            if(a[i]&pos) {
                one ^= a[i];
            }
        }
        for(int i = 1;i <= n;i++) {
            if((a[i]&pos)==0) {
                two ^= a[i];
            }
        }
        if(one>two) swap(one, two);
        printf("%d %d\n", one,two);
    }
    return 0;
}
