#include"2048.h"
#include"show_map.h"
#include <graphics.h>
int win(){
	int i=0,j=0;
    int w = 0;
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(map[j][i]==32){
                flag=0;
                w = 1;
                show_map();
               
            }
        }
    }
    return w;
}
