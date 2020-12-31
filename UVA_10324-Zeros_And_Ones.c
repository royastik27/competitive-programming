/**
* UVA 10324 - Zeros and Ones
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    char str[1000001];
    int nQueries, i, j, k, TC = 1;
    bool isPossible;

    while(scanf("%c", &str[0]) != EOF){

        if(str[0] == '\n')
            break;

        /* getting input string */
        for(i = 1; ; ++i){
            scanf("%c", &str[i]);
            if(str[i] == '\n'){
                str[i] = '\0';
                break;
            }
        }

        scanf("%d", &nQueries);
        printf("Case %d:\n", TC++);

        for(k = 0; k<nQueries; ++k){
            scanf("%d %d", &i, &j);

            /* getting the low index */
            if(i > j){
                i = i + j;
                j = i - j;
                i = i - j;
            }

            /* traversing */
            isPossible = true;
            while(i < j){
                if(str[i] != str[i+1]){
                    isPossible = false;
                    break;
                }
                ++i;
            }

            /* printing the session */
            if(isPossible) printf("Yes\n");
            else printf("No\n");
        }
        getchar();
    }

    return 0;
}
