#include<iostream>//ac
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
vector<double> val;//��������ƽ��ֵ
int main() {
    int n,k,m;
    cin>>n>>k>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) cin>>a[j];
        sort(a+1,a+k+1);//��С��������
        double ans = 0;
        //ȥ��һ�����ֵ��һ�����ֵ
        for(int j = 2;j < k;j++) ans += a[j];
        val.push_back(ans/(k-2));//ȡƽ��ֵ
    }
    sort(val.begin(),val.end());//����
    for(int i = n-m;i < n;i++) {//ȡ����m���������
        printf("%.3f",val[i]);
        if(i!=n-1) cout<<" ";
    }
    return 0;
}
