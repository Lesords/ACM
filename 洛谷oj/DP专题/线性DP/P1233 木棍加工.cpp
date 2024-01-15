#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����dp
//�����й��Ӱ����ȳ��ȴӴ�С���ڿ�ȴӴ�С����
//��ô�������й�����˵������������˳��ѡ��Ļ����ȶ���������
//���Կ��Ժ��Գ��ȣ�ֻ��ע��ȼ���
//���������п���� ����������� ����ȱ�ǰ��������׼���������Ŀɺ�ǰ��һ��ӹ���
//��nlogn��n^n���������� �����������

const int MAXN = 5e3+5;
struct node{
    int l, w;
    friend bool operator < (node a,node b) {
        if(a.l==b.l) return a.w > b.w;  //����һ�£�����ݿ�ȴӴ�С
        return a.l > b.l;               //���ݳ��ȴӴ�С
    }
}a[MAXN];
int b[MAXN],dp[MAXN];//b�洢�����Ŀ�ȣ�dp[i]Ϊ��iΪ��β������������еĴ�С
vector<int> ans;//�洢������������ж�Ӧλ�õ����ֵ
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].l>>a[i].w;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        b[i] = a[i].w;
    }
//    nlogn����
//    for(int i = 1;i <= n;i++) {
//        //Ϊ�գ����߿���ֱ�ӷ������λ��
//        if(ans.empty()||b[i]>ans.back()) ans.push_back(b[i]);
//        else {
//        //�����ҳ�����������������Сλ�ã�Ȼ���滻��Ӧֵ
//            *lower_bound(ans.begin(),ans.end(), b[i]) = b[i];
//        }
//    }
//    cout<<ans.size();

    int ans = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;                  //�ǵó�ʼ��
        for(int j = 1;j < i;j++) {  //��������ǰ������
            if(b[i]>b[j]) {         //��ǰ��С����������
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
