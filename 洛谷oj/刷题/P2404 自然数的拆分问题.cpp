#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺dfs�����������������Ϊ����Ͳ����ظ�
//��һ��λ�ò��ܳ����ܺ͵�һ�룬��Ȼ���ظ�(Ҳ�ɱ�����ֵ�����n)
//��һ��λ�õ�������С��ǰһ��λ�õ���

int a[10] = {1},n;//��0��λ�ó�ʼ��Ϊ1
void dfs(int sum,int pos) {//sum���ܺͣ�pos�ǵ�ǰλ��
    if(sum==n) {//�ܺ���������
        for(int i = 1;i < pos;i++) {//��ǰλ��û���㣬����Ҫ���
            if(i!=1) cout<<"+";
            cout<<a[i];
        }
        cout<<"\n";
        return ;
    }
    //�� ǰһ������ֵ ������ ʣ��ֵ��С
    for(int i = a[pos-1];i <= n-sum;i++) {
        if(pos==1&&i>n/2) break;//��һ��λ�ò��ܴ��� �ܺ͵�һ��
        a[pos] = i;
        dfs(sum+i,pos+1);//����dfs
    }
}
int main() {
    cin>>n;
    dfs(0,1);//��ʼ�ܺ�Ϊ0��λ��Ϊ1
    return 0;
}
