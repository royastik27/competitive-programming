/**
* Codeforces Round #547 (Div. 3)
* Problem B - Maximal Continuous Rest
* Time: 202 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nHours, hour, restHour, max_hour = 0;
    vector <int> restHours;
    bool firstRest = false;

    cin >> nHours >> restHour;

    if(restHour) firstRest = true;

    for(int i = 1; i < nHours; ++i)
    {
        cin >> hour;

        if(hour == 1)
            ++restHour;
        else
        {
            restHours.push_back(restHour);

            if(restHour > max_hour)
                max_hour = restHour;

            restHour = 0;
        }
    }

    // considering the last rest hour of the day
    restHours.push_back(restHour);

    if(restHour > max_hour)
        max_hour = restHour;

    // for circular checking
    if(restHours.size() && firstRest && hour)
    {
        restHour = restHours[restHours.size() - 1] + restHours[0];

        if(restHour > max_hour)
            max_hour = restHour;
    }

    cout << max_hour << '\n';

    return 0;
}
