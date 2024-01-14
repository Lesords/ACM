#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
double a[MAXN];
int main() {
    double sum = 0;
    int n;cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],sum += 1.0/a[i];
    sum /= n*1.0;
    printf("%.2f",1.0/sum);
    return 0;
}
