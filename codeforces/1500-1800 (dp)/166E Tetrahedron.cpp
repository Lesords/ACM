#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�ߵ�d��·����a��b��c�����㣬�ߵ�a��b��c��·��Ϊ �������� + d
//�����ڶԳ��ԣ�abc����ֵһ�£�������
//��ǰd = ��һ��abc*3%MOD
//��ǰabc = (��һ��abc*2 + ��һ��d)%MOD
//��ʼ����һ��dΪ1

const int MAXN = 1e7+6;
const int MOD = 1e9+7;
int main() {
    int n;
    cin>>n;
    ll ld = 1,now_d = 0;
    ll labc = 0,now_abc = 0;//��ʼ��
    for(int i = 1;i <= n;i++) {//��1��ʼ����ʼ����0��ʼ��
        now_d = (labc*3)%MOD;//����·������d
        now_abc = (labc*2+ld)%MOD;//����������+d
        labc = now_abc;//�����ϸ�·����ֵ
        ld = now_d;
    }
    cout<<now_d;
    return 0;
}
