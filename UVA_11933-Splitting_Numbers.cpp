/** UVA 11933 **/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int data, i;
    bitset <32> bits, num1, num2;
    bool fil_first;
    
    while(1)
    {
        cin >> data;
        if(!data) break;

        bits = data;

        num1.reset();
        num2.reset();
        fil_first = true;
        
        for(i = 0; i<bits.size(); ++i)
        {
            if(bits[i])
            {
                if(fil_first)
                {
                    num1.set(i);
                    fil_first = false;
                }
                else
                {
                    num2.set(i);
                    fil_first = true;
                }
                
            }
        }

        cout << num1.to_ulong() << ' ' << num2.to_ulong() << endl;
    }

    return 0;
}
