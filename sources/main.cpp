#include <iostream>
#include <vector>
using namespace std;

#include "../headers/map.h"
#include "../headers/dictionary.h"
#include "../headers/directions.h"
#include "../headers/randomizer.h"

Map playMap;

int main()
{
    seedRand(0);
    int x = 0, y = 0;
    while (true)
    {
        const Room& r = playMap.room(x,y);
        vector<int> doors;
        for (int d = 0; d < NUM_DIRS; ++d)
        {
            if (r.doors[d]) doors.push_back(d);
        }
        if (doors.empty()) cout << "There are no doors.\n";
        else if (doors.size() == 1) cout << "There is a door to the " << absDirNames[doors[0]] << ".\n";
        else
        {
            cout << "There are doors to the ";
            for (size_t i = 0; i < doors.size(); ++i)
            {
                if (i > 0)
                {
                    if (i < doors.size() - 1) cout << ", ";
                    else cout << " and ";
                }
                cout << absDirNames[doors[i]];
            }
            cout << ".\n";
        }
        cin >> x;
        cin >> y;
    }
    return 0;
}
