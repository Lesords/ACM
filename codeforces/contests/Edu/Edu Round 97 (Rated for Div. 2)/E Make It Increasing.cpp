#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺�����������Ҫ�ϸ�����
//��ô���Զ�ԭ�����ȥ��Ӧ���±꣨�������򣩣�ת��Ϊ��ǵݼ�����
//��ֱ�Ӽ����޷������м�ֵ�޸ĺ��Ƿ�����������ת����ֵ�������
//��ô�����г�ȥ �ǵݼ����� ʣ��ľ�����Ҫ�޸ĵ�����
//����ָ��λ�ò����޸�
//��ô���԰���ָ��λ�������֣�����ÿ��С���е� �ǵݼ����� ��Ȼ������ۼ�
//�������߿��ܻ���©���ģ����Կ�������β���������ǣ�һ��-INF��һ��INF
//���ָ��λ�����߲�����ǵݼ������޽�
//ע�⣺ÿ��С���е� �ǵݼ����� ����Ҫ����β����ָ��λ��ֵ�ķ�Χ�ڣ�����

const int MAXN = 5e5+5;
int a[MAXN],b[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) cin>>a[i], a[i] -= i;//ת��
    a[0] = -INF,a[n+1] = INF;//�������ߵı߽�
    b[k+1] = n+1;//��¼���һ���߽��λ�ã���һ������Ϊ0�����������¼
    for(int i = 1;i <= k;i++) cin>>b[i];
    //�ҷǵݼ������ڻ�����������
    int ans = 0;
    for(int i = 1;i <= k+1;i++) {                       //��������С����
        int l = b[i-1], r = b[i];                       //lΪ��λ�ã�rΪ��λ��
        if(a[l]>a[r]) {                                 //ָ��λ�ò��������������޽�
            cout<<"-1\n";
            return 0;
        }
        vector<int> v;                                  //�洢��i�ķǵݼ���ֵ
        for(int j = l+1;j < r;j++) {                    //�۳��߽�λ��
            if(a[l]<=a[j]&&a[j]<=a[r]) {                //��Ҫ�����ڱ߽�ֵ�ķ�Χ��
//                vector<int>::iterator pos = upper_bound(v.begin(),v.end(),a[j]);
                auto pos = upper_bound(v.begin(),v.end(),a[j]);//����ȣ�������upper_bound
                if(pos==v.end()) v.push_back(a[j]);     //û�ҵ�����ֱ�����
                else *pos = a[j];                       //������¶�Ӧֵ
            }
        }
        ans += (r-l-1)-v.size();                        //�۳��߽�ͷǵݼ����У�ʣ��ļ�Ϊ��Ҫ�޸ĵ�
    }
    cout<<ans;
	return 0;
}
