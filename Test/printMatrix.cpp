#include <iostream>
#include <string>

using namespace std;

int main()
{
    string emotions;
    cin >> emotions;

    int score = 0;
    for (size_t i = 0; i < emotions.size(); i++)
    {
        if (emotions[i] == ':' && i + 1 < emotions.size())
        {
            if (emotions[i + 1] == ')')
            {
                if (i + 2 < emotions.size() && emotions[i + 2] == ')')
                {
                    score += 4;
                    i++;
                }
                else
                {
                    score += 2;
                }
            }
            else if (emotions[i + 1] == '(')
            {
                if (i + 2 < emotions.size() && emotions[i + 2] == '(')
                {
                    score -= 5;
                    i++;
                }
                else
                {
                    score -= 1;
                }
            }
        }
    }

    cout << score << endl;

    return 0;
}
