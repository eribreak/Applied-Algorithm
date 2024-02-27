#include <bits/stdc++.h>
using namespace std;
int n, p, s,b[1000];
vector<int> a[1000];
bool check(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
void Try(int x){
    if(x==n-1)
}

int main(int argc, char **argv)
{
    cin >> n >> p >> s;
    int i;
    if (p % 2 == 1)
        i = p + 2;
    else
        i = p + 1;
    for (i; i < s - (p * (n-1)); i += 2)
    {
        if (check(i))
        {
            a->push_back(i);
         Try(0);
        }
    }

    return 0;
}