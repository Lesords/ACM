#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣻����˫ָ�������㣬ÿ��ͳ��a����b������
//���a��b������С��k�����ʾ����[l,r]�������������´𰸣�r�����ƶ�
//�������l��λ���޸�a��b��������l��r���ƶ�

int main() {
    int n,k,ans = 0;
    string s;
    cin>>n>>k>>s;
    int l = 0,r = 0,numa = 0,numb = 0;
    while(r<n) {//��������Χ���������
        if(s[r]=='a') numa++;//ͳ��a��b������
        else numb++;
        if(numa<=k||numb<=k) {//С��k���ʾ��������
            ans = max(ans, r-l+1);//���´�
            r++;//r�����ƶ�
        }
        else {
            if(s[l]=='a') numa--;//����l��λ���޸�a��b������
            else numb--;
            l++,r++;//���ֶ��ƶ���l�ƶ�Ϊ��ɾ����r�ƶ�Ϊ�˼������㣩
        }
    }
    cout<<ans<<"\n";
    return 0;
}
