
#include <stdlib.h>
#include"2048.h"
#include"rand_map.h"
void rand_map()
{ 
	int i,j;
    do
    {
        j=rand()%4;
        i=rand()%4;
    }
    while(map[j][i]!=0);
    map[j][i]=2;
}
