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
int WinMain() // ������graphics.h���Ѿ������˺��Զ�����չ���ɺϷ����������Լ����������鷳��ͬʱ������ƭC-Free
{
	char cmd;
	int fl=0;
	srand(time(0));

    initgraph(500, 652);  //����һ������
    
    PIMAGE img1 = newimage();  //���ڴ�������һ��ռ� img1
	//��img�ļ��е�2048_bg.png ͼƬ��䵽 img1 �ڴ���
	getimage(img1, "img\\2048_bg.png");  

	//���ڴ�img1 �е�ͼƬ���� ���Ƶ���Ļ��
	putimage(0, 0, img1);

	//���ڴ����img1 �ڴ�ռ��ͷ�
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
                printf("��Ϸ����\n");
                flag=0;
                break;
            default :printf("�������\n");
                     break;
        }
       if(fl==16){
            flag=0;
            show_map();
    
            PIMAGE img2 = newimage();  //���ڴ�������һ��ռ� img1
	//��img�ļ��е�2048_bg.png ͼƬ��䵽 img1 �ڴ���
	        getimage(img2, "img\\game_over.png");  

	//���ڴ�img1 �е�ͼƬ���� ���Ƶ���Ļ��
	        putimage(300, 300, img2);

	//���ڴ����img1 �ڴ�ռ��ͷ�
	        delimage(img2);
            
       }
    }

    getch();   
    closegraph();  //�رմ���
    return 0;
}