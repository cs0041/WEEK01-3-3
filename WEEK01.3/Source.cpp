#include <iostream>
#include <math.h>
using namespace std;
bool Error(int a,int b)
{
    if (a > 0 && b > 0)
    {
        return  true;
    }
    else
    {
        return  false;
    }
}
int main()
{
    int a, b;
    bool go = false;
    while (!go)
    {
        cin >> a >> b;
        go = Error( a,  b);
        if(!go)
        {
            cout << "ERROR" << endl;
        }
    }
    int x[10000];
    for (int i = 1; i <= a; i++)
    {
        x[i] = i;
    }
    int where = 0;
    x[abs(a + 1)] = -1;
    for (int k = 0; k < a; k++)
    {
        int num = 0;
        for (int i = 1; i <= a; i++)
        {
            if (x[i] < 0)
            {
                num++;
            }
        }
        if (num == a)
        {
            break;
        }
        for (int i = 1; i <= b; i++)
        {
            where++;
            if (where == a + 1 && i <= b)
            {
                where = 1;
            }
            if (x[where] < 0)
            {
                while (x[where] < 0)
                {
                    where++;
                    if (where == a + 1 && i <= b)
                    {
                        where = 1;
                    }
                }
            }
        }
        cout << "" << where << endl;
        x[where] *= -1;
    }
    return 0;
}
