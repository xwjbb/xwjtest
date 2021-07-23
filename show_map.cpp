#include<stdio.h>
#include <graphics.h>
#include "2048.h"
/*
 void show_map()
{
        int i,j;
    
        printf("+-------------------+\n");
        printf("|       2048        |\n");
        for(i=0;i<4;i++)
        {
            printf("+----+----+----+----+\n");
            for(j=0;j<4;j++)
            {
                if(map[i][j]!=0)
                    printf("|%4d",map[i][j]);
                else
                    printf("|    ");
            }
            printf("|\n");
        }
        printf("+----+----+----+----+\n");   

        printf("|        k           |\n");
        printf("|h<------+-------->j |\n");
        printf("|        j  score=%4d   |\n",score);
        printf("+----+----+----+----+|\n");
   }
   */
void show_map(){
	int i,j;

     for(j=0;j<4;j++)
        {      
            for(i=0;i<4;i++) 
			{
				char str[20]={0};
				char num[20]={0};
				sprintf_s(str,"img\\%d.png",map[j][i]);
				sprintf_s(num,"%4d",s);


                  PIMAGE img1 = newimage();  //在内存中申请一块空间 img1
				//将img文件夹的2048_bg.png 图片填充到 img1 内存中
				getimage(img1, str);  

				//将内存img1 中的图片数据 绘制到屏幕上
				putimage(21+i*120, 173+j*120, img1);

				//将内存变了img1 内存空间释放
				delimage(img1);
                setcolor(EGERGB(116, 107, 97));
				setfontbkcolor(EGERGB(187, 173, 160));
				setfont(30, 0, "宋体");
			    outtextxy(170,90, num);
				



			}
	 }


}