#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���ú�׺�͵�˼�������£���n�����ĺͼ�����Сֵ
//Ȼ���1��n-2�и���ɾ��k���ɻ�õ����ƽ��ֵ�������vector�洢
//������ܲ�Ψһ������

const int MAXN = 1e5+5;
double minn[MAXN],suf[MAXN],a[MAXN];
vector<int> ans;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    minn[n] = suf[n] = a[n];//��ʼ״̬
    for(int i = n-1;i >= 1;i--) {
        minn[i] = min(a[i], minn[i+1]);//�͵�ǰֵa[i]�Ƚϣ�����
        suf[i] = suf[i+1]+a[i];//ά����׺��
    }
    double val = 0;
    for(int i = 1;i <= n-2;i++) {//��Ŀ��ΧΪ1~(n-2)
        //ɾ��ǰi��������i+1����ʼ����
        double tmp = (suf[i+1]-minn[i+1])/(n-i-1);//��Ҫ��ɾ��һ����Сֵ
        if(tmp>val) {
            val = tmp;//���½ϴ�ֵ
            ans.clear();//��վɵĴ�
            ans.push_back(i);
        }
        else if(tmp==val) ans.push_back(i);//���һ�£������
    }
    for(int e:ans) cout<<e<<"\n";
    return 0;
}
