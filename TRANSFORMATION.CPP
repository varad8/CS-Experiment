#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define MAX_VERTICES 100

typedef struct {
    int x;
    int y;
} Point;

void translate(Point points[], int numVertices, int tx, int ty) {
    for (int i = 0; i < numVertices; i++) {
        points[i].x += tx;
        points[i].y += ty;
    }
}

void scale(Point points[], int numVertices, float sx, float sy) {
    for (int i = 0; i < numVertices; i++) {
        points[i].x = round(points[i].x * sx);
        points[i].y = round(points[i].y * sy);
    }
}

void rotate(Point points[], int numVertices, float angle) {
    float radian = angle * (3.14159265358979323846 / 180.0);
    for (int i = 0; i < numVertices; i++) {
        int new_x = round((points[i].x * cos(radian)) - (points[i].y * sin(radian)));
        int new_y = round((points[i].x * sin(radian)) + (points[i].y * cos(radian)));
        points[i].x = new_x;
        points[i].y = new_y;
    }
}

void reflect(Point points[], int numVertices, char axis) {
    for (int i = 0; i < numVertices; i++) {
        if (axis == 'x' || axis == 'X') {
            points[i].x = -points[i].x;
        } else if (axis == 'y' || axis == 'Y') {
            points[i].y = -points[i].y;
        }
    }
}

void shear(Point points[], int numVertices, float shx, float shy) {
    for (int i = 0; i < numVertices; i++) {
        int new_x = points[i].x + (points[i].y * shx);
        int new_y = points[i].y + (points[i].x * shy);
        points[i].x = new_x;
        points[i].y = new_y;
    }
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, driver);

    int numVertices;
    Point points[MAX_VERTICES];
    float sx, sy, angle, shx, shy;
    char choice;

    printf("2D Transformation Menu:\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("4. Reflection\n");
    printf("5. Shearing\n");
    printf("Enter your choice (1/2/3/4/5): ");
    scanf(" %c", &choice);

    printf("Enter the number of vertices of the shape: ");
    scanf("%d", &numVertices);

    printf("Enter the vertices of the shape (x y for each vertex):\n");
    for (int i = 0; i < numVertices; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    switch (choice) {
        case '1':
            printf("Enter translation factors (tx ty): ");
            int tx, ty;
            scanf("%d %d", &tx, &ty);
            translate(points, numVertices, tx, ty);
            break;
        case '2':
            printf("Enter scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);
            scale(points, numVertices, sx, sy);
            break;
        case '3':
            printf("Enter rotation angle (degrees): ");
            scanf("%f", &angle);
            rotate(points, numVertices, angle);
            break;
        case '4':
            printf("Enter reflection axis (x/y): ");
            char axis;
            scanf(" %c", &axis);
            reflect(points, numVertices, axis);
            break;
        case '5':
            printf("Enter shearing factors (shx shy): ");
            scanf("%f %f", &shx, &shy);
            shear(points, numVertices, shx, shy);
            break;
        default:
            printf("Invalid choice\n");
            closegraph();
            return 1;
    }

    // Draw the original and transformed shape
    for (int i = 0; i < numVertices; i++) {
        putpixel(points[i].x, points[i].y, RED); // Transformed vertices
    }
    
    // Draw lines between transformed vertices to form the transformed shape
    for (int i = 0; i < numVertices - 1; i++) {
        line(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
    line(points[numVertices - 1].x, points[numVertices - 1].y, points[0].x, points[0].y);

    delay(50000); // Delay to view the result
    closegraph(); // Close graphics mode

    return 0;
}
 

