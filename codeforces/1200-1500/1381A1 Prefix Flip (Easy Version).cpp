#include<iostream>//ac
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���ڶ�ͬһǰ׺��ת���Σ��������
//���Կ��ԴӺ���ǰ��ʼ�жϣ�������߲�ͬ�Ļ��������ȷ�ת��ǰǰ׺
//Ȼ��ת��һ�����ٷ�ת��ǰǰ׺����ʹ��ǰλ�ñ仯���������䣩

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string a,b;
        vector<int> ans;//��¼��ת��λ��
        cin>>n>>a>>b;
        for(int i = n-1;i >= 0;i--) {//�Ӻ���ǰ��ʼ����
            if(a[i]!=b[i]) {//����
                ans.push_back(i+1);//i+1λ�ã��洢���Ϊ0��
                ans.push_back(1);//��ǰλ�÷�ת���Σ�����λ�÷�ת
                ans.push_back(i+1);
            }
        }
        cout<<ans.size();//������������Ͳ�������
        for(int i = 0;i < ans.size();i++) cout<<" "<<ans[i];
        cout<<"\n";
    }
    return 0;
}
