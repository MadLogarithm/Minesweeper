#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<string.h>
#define MAXN 10000
int SIDE=50;
int SIZ=30;
int ROW=10,COL=10,NUM=10;
int cnt=0;
int map[MAXN][MAXN];
PIMAGE img0;
PIMAGE img1;
PIMAGE img2;
PIMAGE img3;
PIMAGE img4;
PIMAGE img5;
PIMAGE img6;
PIMAGE img7;
PIMAGE img8;
PIMAGE img9;
PIMAGE img10;
PIMAGE img11;
PIMAGE img12;
void OpenZero(int r,int c)
{
    map[r][c]-=20;
    cnt++;
    for(int m=r-1;m<=r+1;m++) for(int n=c-1;n<=c+1;n++) if(m>=1&&m<=ROW&&n>=1&&n<=COL) if(map[m][n]>=19&&map[m][n]<=28)
    {
        if(map[m][n]!=20)
        {
            map[m][n]-=20;
            cnt++;
        }
        else OpenZero(m,n);
    }
}
void Draw() //��ӡ����
{
    for(int i=1;i<=ROW;i++)
    {
        for(int j=1;j<=COL;j++)
        {
            if(map[i][j]==-1) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img9); //��
            else if(map[i][j]==0) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img0); //����0
            else if(map[i][j]==1) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img1); //����1
            else if(map[i][j]==2) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img2); //����2
            else if(map[i][j]==3) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img3); //����3
            else if(map[i][j]==4) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img4); //����4
            else if(map[i][j]==5) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img5); //����5
            else if(map[i][j]==6) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img6); //����6
            else if(map[i][j]==7) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img7); //����7
            else if(map[i][j]==8) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img8); //����8
            else if(map[i][j]>=19&&map[i][j]<=28) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img10); //�հ�ͼƬ
            else if(map[i][j]>30) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img11); //���
        }
    }
}
void Draw0()
{
    for(int i=1;i<=ROW;i++)
    {
        for(int j=1;j<=COL;j++)
        {
            if(map[i][j]==-1) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img9); //��
            else if(map[i][j]==0) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img0); //����0
            else if(map[i][j]==1) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img1); //����1
            else if(map[i][j]==2) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img2); //����2
            else if(map[i][j]==3) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img3); //����3
            else if(map[i][j]==4) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img4); //����4
            else if(map[i][j]==5) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img5); //����5
            else if(map[i][j]==6) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img6); //����6
            else if(map[i][j]==7) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img7); //����7
            else if(map[i][j]==8) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img8); //����8
            else if(map[i][j]==19) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img12); //δ���ֵ���
            else if(map[i][j]>19&&map[i][j]<=28) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img10); //�հ�ͼƬ
            else if(map[i][j]>30) putimage((i-1)*SIZ+SIDE,(j-1)*SIZ+SIDE,img11); //���
        }
    }
}
void Init() //�����������
{
    srand((unsigned int)time(NULL));
    for(int i=0;i<=ROW+1;i++) for(int j=0;j<=COL+1;j++) map[i][j]=0;
    int n=0;
    while(n<NUM) //������ɵ���
    {
        int r=rand()%ROW+1;
        int c=rand()%COL+1;
        if(map[r][c]==0)
        {
            map[r][c]=-1;
            n++;
        }
    }
    for(int i=1;i<=ROW;i++) for(int j=1;j<=COL;j++) if(map[i][j]!=-1) for(int m=i-1;m<=i+1;m++) for(int n=j-1;n<=j+1;n++) if(map[m][n]==-1) map[i][j]++; //��������
    for(int i=1;i<=ROW;i++) for(int j=1;j<=COL;j++) map[i][j]+=20; //�򵥼���

}
int Play()
{
    //����һ�������Ϣ
    MOUSEMSG msg={0};
    int r,c;
    while(1)
    {

        msg=GetMouseMsg();
        switch(msg.uMsg)
        {
        case WM_LBUTTONDOWN: //����ɨ�� �հ�ͼƬ
            r=(msg.x-SIDE)/SIZ+1;
            c=(msg.y-SIDE)/SIZ+1;
            if(map[r][c]>=19&&map[r][c]<=28)
            {
                if(map[r][c]==20)
                {
                    OpenZero(r,c);
                }
                else map[r][c]-=20,cnt++;
            }
            return map[r][c];
            break;
        case WM_RBUTTONDOWN: //���һ���հ�ͼƬ ȡ��һ�����ͼƬ
            r=(msg.x-SIDE)/SIZ+1;
            c=(msg.y-SIDE)/SIZ+1;
            if(map[r][c]>=19&&map[r][c]<=28) map[r][c]+=50;
            else if(map[r][c]>30) map[r][c]-=50,cnt++;
            return map[r][c];
            break;
        }
    }
}
void GetZoom(PIMAGE pimg, const char* fileName, int width, int height) //����ͼƬ
{

    PIMAGE temp = newimage();
    getimage(temp,fileName);
    resize(pimg,width,height);
    putimage(pimg,0,0,width,height,temp,0,0,getwidth(temp),getheight(temp));
    delimage(temp);
}
int main()
{
    img0=newimage();
    img1=newimage();
    img2=newimage();
    img3=newimage();
    img4=newimage();
    img5=newimage();
    img6=newimage();
    img7=newimage();
    img8=newimage();
    img9=newimage();
    img10=newimage();
    img11=newimage();
    img12=newimage();
    printf("����ɨ��\n��Tips:����<=����*������\n������");
    scanf("%d",&ROW);
    printf("������");
    scanf("%d",&COL);
    printf("������");
    scanf("%d",&NUM);
    if(ROW*COL<=NUM)
    {
        printf("�ٵ��װɣ����ѡ�\n");
        return 0;
    }
    if(ROW>25||COL>25) SIZ=750/((ROW>COL)?ROW:COL);
     GetZoom(img0,"pic/0.png",SIZ,SIZ);
    GetZoom(img1,"pic/1.png",SIZ,SIZ);
    GetZoom(img2,"pic/2.png",SIZ,SIZ);
    GetZoom(img3,"pic/3.png",SIZ,SIZ);
    GetZoom(img4,"pic/4.png",SIZ,SIZ);
    GetZoom(img5,"pic/5.png",SIZ,SIZ);
    GetZoom(img6,"pic/6.png",SIZ,SIZ);
    GetZoom(img7,"pic/7.png",SIZ,SIZ);
    GetZoom(img8,"pic/8.png",SIZ,SIZ);
    GetZoom(img9,"pic/9.png",SIZ,SIZ);
    GetZoom(img10,"pic/10.png",SIZ,SIZ);
    GetZoom(img11,"pic/11.png",SIZ,SIZ);
    GetZoom(img12,"pic/12.png",SIZ,SIZ);
    initgraph(SIZ*ROW+2*SIDE,SIZ*COL+2*SIDE);
    setbkcolor(WHITE);
    setcaption("ɨ��");
    int width = getwidth(); int height = getheight();
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setfont(24, 0, "����");
    setcolor(BLUE);
    xyprintf(120, 25, "ɨ��%dx%d����%d����", ROW, COL, NUM);
    Init();
    int flag=0;
    while(1&&flag==0)
    {
        Draw();
        if(Play()==-1)
        {
            flag--;
            Draw();
        }
        else if(ROW*COL-NUM==cnt)
        {
            flag++;
            Draw();
        }
    }
    Draw();
    Draw0();
    if(flag>0) MessageBox(NULL,"\t\tWinner!\t\t","��ʾ",0);
    else if(flag<0) MessageBox(NULL,"\t\tGame over!\t\t","��ʾ",0);
    return 0;
}
