#include <iostream>
using namespace std;
const int NMAX = 1000005;
int main()
{
    char s[1000001], t[1000001], b[5], c;
    int n, x;
    int p = 0, q = 0;
    bool isPair[1000001];
    std::cin>>n;
    for (int i = 1; i <= n; i++)
    {
        std::cin>>x;
        if (x == 1)
        {
            scanf("%s", b), c = b[0];
            s[++p] = c;
            if (c == ')' && q && t[q] == '(')
                q--, isPair[p] = true;
            else if (c == ']' && q && t[q] == '[')
                q--, isPair[p] = true;
            else if (c == '}' && q && t[q] == '{')
                q--, isPair[p] = true;
            else
                t[++q] = c, isPair[p] = false;
        }
        else if (x == 2)
        {
            if (!p)
                continue;
            c = s[p];
            if (isPair[p])
            {
                if (c == ')')
                    t[++q] = '(';
                else if (c == ']')
                    t[++q] = '[';
                else if (c == '}')
                    t[++q] = '{';
            }
            else
                q--;
            p--;
        }
        else if (x == 3)
        {
            if (!p)  continue;
            std::cout << s[p] << std::endl;
        }
        else if (x == 4)
        {
            if(q)
            cout << "NO"<< endl ;
            else cout << "NO"<< endl ;
        }
    }
    return 0;
}