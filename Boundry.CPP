// Boundary Fill 

#include <stdio.h>
#include <graphics.h>
void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color); // Fill the current pixel
        boundaryFill(x + 1, y, fill_color, boundary_color); // Right
        boundaryFill(x - 1, y, fill_color, boundary_color); // Left
        boundaryFill(x, y + 1, fill_color, boundary_color); // Down
        boundaryFill(x, y - 1, fill_color, boundary_color); // Up
   }}
int main() {
    int gd = DETECT, gm,x,y,x1,y1;
       char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, driver); // Initialize graphics mode
    printf("\n Enter the co-ordinates for rectangle-");
    scanf("%d%d%d%d",&x,&y,&x1,&y1);
    rectangle(x, y, x1, y1);
    boundaryFill(150, 150, 4, 15);
    delay(5000); // Delay to view the result
    closegraph(); // Close graphics mode
    return 0;
}





// Boundary Fill
#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  
void flood(int,int,int,int);  
int main()  
{  
    int gd=DETECT,gm,x,y,x1,y1;
    char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd,&gm,driver);  
    printf("\n Enter the co-ordinates for rectangle-");
    scanf("%d%d%d%d",&x,&y,&x1,&y1);
    rectangle(x, y, x1, y1); 
    flood(x+1,y+1,10,0);  
    getch();
    return 0;  
}  
void flood(int x,int y,int fillColor, int defaultColor)  
{  
    if(getpixel(x,y)==defaultColor)  
    {  
        delay(1);  
        putpixel(x,y,fillColor);  
        flood(x+1,y,fillColor,defaultColor);  
        flood(x-1,y,fillColor,defaultColor);  
        flood(x,y+1,fillColor,defaultColor);  
        flood(x,y-1,fillColor,defaultColor);  
    }  
}  

