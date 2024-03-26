#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int level = -1;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (level == 2)
            {
                sum += num;
            }
            num = 0;
            level++;
        }
        else if (s[i] == ')')
        {
            if (level == 2)
            {
                sum += num;
            }
            num = 0;
            level--;
        }
        else
        {
            num = num * 10 + s[i] - '0';
        }
    }
    cout << sum << endl;
}
