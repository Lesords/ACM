#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺�ֳ� k-1 ����λ���� һ�� �������ͼ�Ϊ��

bool cmp(char a, char b) {//�Ӵ�С����
    return a > b;
}
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * �������͵��ַ���
     * @param x string�ַ��� ����Ŀ�����������ַ���
     * @param k int���� ����Ŀ������������k
     * @return string�ַ���
     */
    string Maxsumforknumers(string x, int k) {
        // write code here
        sort(x.begin(),x.end(),cmp);//������
        string tmp = "",num = "",ans = "";//tmpΪ������numΪk-1С���ĺͣ�ansΪ���
        int len = x.size(),val = 0,jin = 0;//val��ʾk-1С���ĺͣ�jinΪ��λֵ
        for(int i = 0;i <= len-k;i++) tmp += x[i];
        for(int i = len-k+1;i < len;i++) {
            val += x[i]-'0';//k-1�����ĺ�
        }
        reverse(tmp.begin(),tmp.end());//��ת��ʹ�ÿ�ͷΪ��λ
        while(val) {
            char ch = val%10 + '0';
            num += ch;//ת���ַ�����������
            val /= 10;
        }//���Ϊ��λ
        while(tmp.size()<num.size()) tmp += '0';//���ȶ���
        while(num.size()<tmp.size()) num += '0';
        tmp += '0',num += '0';//���㣨��λ��
        for(int i = 0;i < tmp.size();i++) {//��λ���
            int a = tmp[i] - '0';
            int b = num[i] - '0';
            ans += (a+b+jin)%10 + '0';
            jin = (a+b+jin)/10;//��λֵ
        }
        reverse(ans.begin(),ans.end());//��ת��Ϊ������ֵ
        if(ans[0]=='0') ans.erase(0,1);//ȥ��ǰ����
        return ans;
    }
};

int main() {
    string s;
    int k;
    cin>>s>>k;
    Solution a;
    cout<<a.Maxsumforknumers(s,k);
    return 0;
}
