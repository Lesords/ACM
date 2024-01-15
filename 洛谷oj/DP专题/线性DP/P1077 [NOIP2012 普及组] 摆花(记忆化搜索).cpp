#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���仯����
//���� ��ǰλ�õĻ����Ѱڷŵ����� ����״̬
//��ôÿ�ξ���Ϊ��ǰλ�ÿ���ѡ��Ļ����������ѡ��
//���������Ǵ�ǰ�����ѵ�
//���Զ���f[i][j]Ϊ����iλ�õĻ�����i�ֻ�����ʼ�����m-j�����ķ�����

const int MAXN = 105;
const int MOD = 1000007;
int n,m;                    //n�ֻ�����m��
int a[MAXN],f[MAXN][MAXN];  //aΪÿ�ֻ�����������
int dfs(int pos,int num) {  //��ǰλ����pos�������Ѿ�ѡ����num����
    if(num>m) return 0;     //����m��ֱ������
    if(num==m) return 1;    //����m���ʾ��ǰѡ��Ϊһ�η�����
    if(pos>n) return 0;     //����n��λ�ã��Ͳ���Ҫ��������
    if(f[pos][num]) return f[pos][num];     //�Ѽ������ֱ�ӷ���
    int ans = 0;
    for(int i = 0;i <= a[pos];i++) {        //��������ѡ��������
        ans = (ans+dfs(pos+1,num+i))%MOD;   //��ǰ�ۼ�
    }
    return f[pos][num] = ans;               //���ز���ֵ
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    cout<<dfs(1,0);
    return 0;
}
