
/**
* AtCoder Beginner Contest 203
* Problem C - Friends and Travel costs
* Time: 163 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Friend {
    long long int vill;
    int yen;
};
 
bool cmp(struct Friend a, struct Friend b)
{
    return a.vill < b.vill;
}
 
int main()
{
    int nFriends;
    long long int vill;
    vector <struct Friend> vec;
    vector <struct Friend>::iterator it;
    struct Friend fr;
    register int i;
 
    cin >> nFriends >> vill;
 
    for(i = 0; i < nFriends; ++i) {
        cin >> fr.vill >> fr.yen;
        vec.push_back(fr);
    }
 
    sort(vec.begin(), vec.end(), cmp);
 
    for(it = vec.begin(); it != vec.end(); ++it) {
        if(it->vill > vill)
            break;
 
        vill += it->yen;
    }
 
    cout << vill << '\n';
 
    return 0;
}
