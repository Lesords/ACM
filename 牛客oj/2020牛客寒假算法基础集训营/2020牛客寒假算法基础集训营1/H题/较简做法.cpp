//代码长度：486 运行时间： 24 ms 占用内存：804K

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 2e5 + 10;

map<char, int> q;

char x[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    cin >> x;
    int start = 0, end = 0, sum = 0;
    while (start <= end && end < n) {
        q[x[end]]++;//标记0或1的数量
        while (min(q['0'], q['1']) > k )//子串操作数过多
        {
            q[x[start++]]--;//右移并减去标记
        }
        if (min(q['0'], q['1']) <= k) {
            if (end - start + 1 > sum) {//较大则更新答案
                sum = end - start + 1;
            }
        }
        end++;
    }
    cout << sum << endl;
    return 0;
}
