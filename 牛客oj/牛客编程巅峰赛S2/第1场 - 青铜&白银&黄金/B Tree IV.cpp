#include<iostream>//ac
#include<algorithm>
using namespace std;

//��Ҫ�ύ�Ĳ���
//��⣺ֱ�ӱ������в㣬ÿ�μ���һ��ļ�ֵ�ͣ��ۼӼ��ɣ�ע��ȡģ������

#define ll long long
const int MOD = 998244353;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * @param n long������ ��ʾ��׼��ȫ�������Ľ�����
     * @return long������
     */
    ll tree4(ll n) {
        // write code here
        ll pos = 1,ans = 0;//pos��ʾÿ���һ���ڵ�ı��
        for(ll i = 1;;i++) {
            if(pos>n) break;//�����ˣ������
            ll last = pos*2-1;//last��ʾ��ǰ������һ���ڵ�ı��
            if(last>n) last = n;//���last��n�������last�Ĵ�С
            //�Ȳ���͹�ʽ��last-pos+1��ʾ�ò�Ľڵ�����
            ans += i*((pos+last)*(last-pos+1)/2%MOD)%MOD;//ע��ȡģ����
            pos *= 2;//�����׽ڵ��λ��
        }
        return ans%MOD;
    }
};

int main() {
    int n;
    cin>>n;
    Solution a;
    cout<<a.tree4(n);
    return 0;
}
