/**
 * Codeforces Round #479 (Div. 3)
 * Problem E - Cyclic Components
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

typedef struct Type
{
    ll time;
    int birthYear;
    string group;
}Type;

class Solution
{
    string str, group, id;
    int n, birthYear;
    Type temp;
    ll time;
    map <string, Type> mp;
    map <string, Type>::iterator it;

    int get_num(int n)
    {
        int i, num = 0;

        for(i = 0; i < n; ++i)
        {
            num = num * 10 + int(str[0]-'0');
            str.erase(str.begin());
        }

        return num;
    }

    ll hash_time()
    {
        int day = get_num(2);
        str.erase(str.begin());

        int month = get_num(2);
        str.erase(str.begin());

        int year = get_num(4);
        str.erase(str.begin());

        int hour = get_num(2);
        str.erase(str.begin());

        int min = get_num(2);
        str.erase(str.begin());

        int sec = get_num(2);

        ll ans = 0;

        ans += year * 10000000000LL;
        ans += month * 100000000LL;
        ans += day * 1000000LL;
        ans += hour * 10000LL;
        ans += min * 100LL;
        ans += sec * 1LL;

        return ans;
    }

    int get_year()
    {
        int ans = 0, i;

        for(i = 0; i < 6; ++i)
            str.erase(str.begin());

        for(i = 0; i < 4; ++i)
            ans = ans * 10 + int(str[i]-'0');

        return ans;
    }
public:
    void solve()
    {
        cin >> n;

        while(n--)
        {
            cin >> str;

            time = hash_time();

            cin >> id;

            cin >> str;
            birthYear = get_year();

            cin >> group;
            cout << "Group: " << group << '\n';

            temp.time = time;
            temp.birthYear = birthYear;
            temp.group = group;

            it = mp.find(id);

            if(it == mp.end())
                mp[id] = temp;
            else if(time >= (it->second).time)
            {
                cout << "HEREEEE!!!\n";
                (it->second).time = temp.time;
                (it->second).birthYear = temp.birthYear;
                (it->second).group = temp.group;
            }

            cout << "Here\n";
        }

        // printing answer
        map <string, int> ans;
        map <string, int>::iterator it2;

        for(it = mp.begin(); it != mp.end(); ++it)
            ++ans[(it->second).group];

        for(it2 = ans.begin(); it2 != ans.end(); ++it2)
            cout << it2->first << ' ' << it2->second << '\n';

        // second answer

        map <int, int> ans2;
        map <int, int>::iterator it3;

        for(it = mp.begin(); it != mp.end(); ++it)
            ++ans2[(it->second).birthYear];

        for(it3 = ans2.begin(); it3 != ans2.end(); ++it3)
            cout << it3->first << ' ' << it3->second << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    sol.solve();

    return 0;
}
