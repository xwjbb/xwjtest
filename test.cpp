#include <graphics.h>
#include <time.h>
#include<stdio.h>
#include "rand_map.h"
#include "show_map.h"
#include"wbw.h"
#include"dwbwin.h"
#include"dwbful.h"

int map[4][4]={0};
int s = 0;
int flag=1;
int WinMain() // 这里在graphics.h里已经定义了宏自动把它展开成合法的声明，以减免声明的麻烦，同时用来欺骗C-Free
{
	char cmd;
	int fl=0;
	srand(time(0));

    initgraph(500, 652);  //创建一个窗口
    
    PIMAGE img1 = newimage();  //在内存中申请一块空间 img1
	//将img文件夹的2048_bg.png 图片填充到 img1 内存中
	getimage(img1, "img\\2048_bg.png");  

	//将内存img1 中的图片数据 绘制到屏幕上
	putimage(0, 0, img1);

	//将内存变了img1 内存空间释放
	delimage(img1);


	rand_map();
	rand_map();

	while(flag)
    {
        show_map();
        cmd=getch();
        switch(cmd)
        {
            case 'w':
                printf("up\n");
                up();
                rand_map();
                fl=ful();
                win();
                break;
            case 's':
                printf("down\n");
                down();
                rand_map();
                fl=ful();
                win();
                break;
            case 'a':
                printf("left\n");
                left();
                rand_map();
                fl=ful();
                win();
                break;
            case 'd':
                printf("right\n");
                right();
                rand_map();
                fl=ful();
                win();
                break;
            case 'q':
                printf("游戏结束\n");
                flag=0;
                break;
            default :printf("输入错误\n");
                     break;
        }
       if(fl==16){
            flag=0;
            show_map();
    
            PIMAGE img2 = newimage();  //在内存中申请一块空间 img1
	//将img文件夹的2048_bg.png 图片填充到 img1 内存中
	        getimage(img2, "img\\game_over.png");  

	//将内存img1 中的图片数据 绘制到屏幕上
	        putimage(300, 300, img2);

	//将内存变了img1 内存空间释放
	        delimage(img2);
            
       }
    }

    getch();   
    closegraph();  //关闭窗口
    return 0;
}