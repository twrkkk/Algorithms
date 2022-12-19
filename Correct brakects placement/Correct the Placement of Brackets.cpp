#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

int m[51][51], res;

string s;

int explore(char c, char d)
{
    string p = "([{)]}";
    if (p.find(c) / 3 > 0 && p.find(d) / 3 < 1) return 2;
    if (p.find(c) % 3 == p.find(d) % 3 && c != d) return 0;
    return 1;
}

int resursion(int i, int j)
{
    if (i > j) return 0;
    if (m[i][j] != -1) return m[i][j];

    int r = resursion(i + 1, j - 1) + explore(s[i], s[j]);
    for (int k = i + 1; k < j; k += 2)
        r = std::min(r, resursion(i, k) + resursion(k + 1, j));

    return m[i][j] = r;

}

int main()
{
    memset(m, -1, sizeof(m));
    std::ifstream file("data.txt");
    if (file)
    {
        while (!file.eof())
        {
            std::getline(file, s);
            res = resursion(0, s.size() - 1);
            cout << res << ' ' << s << std::endl;
            memset(m, -1, sizeof(m));
        }
    }
    else
        std::cout << "no file\n";
    
}
