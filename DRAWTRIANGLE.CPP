#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x, int y, int size) {
    line(x, y, x + size, y); // Bottom line
    line(x, y, x + size / 2, y - size); // Left side
    line(x + size, y, x + size / 2, y - size); // Right side
}

// Recursive function to generate the Sierpinski Triangle
void sierpinski(int x, int y, int size, int depth) {
    if (depth == 0) {
        drawTriangle(x, y, size);
    } else {
        int halfSize = size / 2;
        sierpinski(x, y, halfSize, depth - 1); // Top triangle
        sierpinski(x + halfSize, y, halfSize, depth - 1); // Bottom right triangle
        sierpinski(x + halfSize / 2, y - halfSize, halfSize, depth - 1); // Bottom left triangle
    }
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, driver); // Initialize graphics mode

    int x = 100; // Starting X-coordinate
    int y = 400; // Starting Y-coordinate
    int size = 300; // Size of the triangle
    int depth = 4; // Recursion depth (adjust for more or fewer iterations)

    sierpinski(x, y, size, depth);

    delay(5000); // Delay to view the result

    closegraph(); // Close graphics mode
    return 0;
}
