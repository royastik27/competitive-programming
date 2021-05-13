/**
* UVa 10026 - Shoemaker's Problem
* AUTHOR: Astik Roy
**/

#include <bits/stdc++.h>

using namespace std;

struct Type {
    int day, fine, pos;

    Type(int _d, int _f, int _p) {
        day = _d;
        fine = _f;
        pos = _p;
    }
};

bool cmp(struct Type a, struct Type b) {

    return (a.fine * b.day > b.fine * a.day);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, nJobs, day, fine;
    vector <Type> job;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> nJobs;

        for(i = 1; i <= nJobs; ++i) {
            cin >> day >> fine;

            job.push_back(Type(day, fine, i));
        }

        sort(job.begin(), job.end(), cmp);

        cout << job[0].pos;
        for(i = 1; i < job.size(); ++i)
            cout << ' ' << job[i].pos;
        cout << '\n';

        if(TC) cout << '\n';

        job.clear();
    }

    return 0;
}
