#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ͳ��0��1�ĸ���
//���У��������Ϊ1�Ļ���������Ҫ��תһ���������1
//Ȼ��ֱ��ɨһ�飬�ж������γ���0�Ĵ�����0��1�ɵ����������ֵ
//��1�ĸ�����Ӽ���

int a[105];
int main() {
    int n,one = 0,zero = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        a[i]?one++:zero++;
    }
    if(one==n) {//���ж�Ϊ1�����������
        cout<<one-1<<"\n";
        return 0;
    }
    int num = 0,ans = 0;//numΪ�ֲ���0�ĸ�����ansΪ���ֵ
    for(int i = 1;i <= n;i++) {
        if(a[i]==0) {
            num++;
            ans = max(ans,num);
        }
        else {
            num--;
            if(num<0) num = 0;//Ϊ�����������¼���
        }
    }
    ans = max(ans,num);
    cout<<ans+one<<"\n";
    return 0;
}
