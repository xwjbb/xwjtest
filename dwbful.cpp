#include"2048.h"
int ful(void){
    int fl=0;
	int i,j;
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(map[j][i]!=0)
                fl++;
        }
    }
    return fl;
}
