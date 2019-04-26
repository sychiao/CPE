#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#include <algorithm>
#include <vector>

int compare(string a, string b)
{
    size_t posa1 = 0, posb1 = 0;
    size_t posa2 = a.find("\\");
    size_t posb2 = b.find("\\");
    if (a.substr(posa1, posa2) == b.substr(posb1, posb2))
    {
        if (posa2 == string::npos)
        {
            return true;
        }
        else if (posb2 == string::npos)
        {
            return false;
        }
        else
        {
            return compare(a.substr(posa2 + 1, a.length()), b.substr(posb2 + 1, b.length()));
        }
    }
    else
    {
        return a.substr(posa1, posa2) < b.substr(posb1, posb2);
    }
}

int main()
{
    int line = 0;
    int first = 0;
    while (scanf("%d", &line) == 1)
    {  
        string *dir = new string[line];
        for (int i = 0; i < line; i++)
        {
            cin >> dir[i];
        }

        sort(dir, dir + line, compare);

        vector<string> state;
        for (int i = 0; i < line; i++)
        {
            std::size_t found;
            int level = 0;
            int a = 0;
            do
            {
                found = dir[i].find("\\");
                string name = dir[i].substr(0, found);
                if (state.size() == 0)
                {
                    state.push_back(name);
                    cout << name << "\n";
                }
                else if (state.size() > level)
                {
                    if (state[level] != name)
                    {
                        for (int i = 0; i < level; i++)
                            cout << " ";
                        cout << name << "\n";
                        state.resize(level+1);
                        state[level] = name;
                    }
                }
                else
                {
                    state.push_back(name);
                    for (int i = 0; i < level; i++)
                        cout << " ";
                    cout << name << "\n";
                }
                level++;
                if (found != string::npos)
                {
                    dir[i] = dir[i].substr(found + 1, dir[i].length());
                }
            } while (found != string::npos);
        }
        cout << "\n";
    }
    return 0;
}