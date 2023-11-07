#include<dos.h>
#include<stdio.h>
#include<conio.h> 
#include<graphics.h> 
void draw_circle(int,int,int); 
void symmetry(int,int,int,int);
void main()
int xc,yc,R;
initgraph(&gd,&gm, "C:\\TurboC3\\BGI"); printf("Enter the center of the circle:\n");
printf("Xc=");
int gd=DETECT,gm; scanf("%d",&xc); printf("Yc="); printf("Enter the radius of the circle :"); draw_circle(xc,yc,R);
scanf("%d", &yc);
scanf("%d", &R);
getch();
closegraph();
}
void draw_circle(int xc,int yc,int rad)
int x = 0;
int y = rad;
int p = 1-rad;
symmetry(x,y,xc,yc); puter Gra
for(x=0;y>x;x++)
{
p+= 2*x-
else
2*(x-y) +5;
y--;
symmetry(x,y,xc,yc);
delay(50);
}
}
void symmetry(int x,int y,int xc,int yc)
delay(50);
putpixel(xc+x,yc-y,GREEN); //For pixel (x,y)
putpixel(xc+y,yc-x, GREEN); //For pixel (y,x)
delay(50); putpixel(xc+y,yc+x, GREEN); //For pixel (y,-x)
delay(50);
putpixel(xc+x,yc+y, GREEN); //For pixel (x,-y)
delay(50);
putpixel(xc-x,yc+y, GREEN); //For pixel (-x,-y)
delay(50);
putpixel(xc-y,yc+x, GREEN); //For pixel (-y,-x) delay(50);
putpixel(xc-y,yc-x, GREEN); //For pixel (-y,x)
delay(50); putpixel(xc-x,yc-y, GREEN); //For pixel (-x,y)
delay(50);
}
