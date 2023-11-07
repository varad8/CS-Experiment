
#include <stdio.h>
#include <graphics.h>
void scanlineFill(int x[], int y[], int n, int fill_color) {
    int i, j, temp, x1, x2;
    int ymin = y[0], ymax = y[0];

    // Find the minimum and maximum y-coordinates
    for (i = 1; i < n; i++) {
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }

    // Scan each scanline from ymin to ymax
    for (i = ymin; i < ymax; i++) {
        int x_intersections[20]; // Adjust the size as needed
        int count = 0;

        // Find the intersections of the scanline with the edges
        for (j = 0; j < n; j++) {
            int next = (j + 1) % n;
            if ((y[j] < i && y[next] >= i) || (y[next] < i && y[j] >= i)) {
                x_intersections[count++] = x[j] + (i - y[j]) / (float)(y[next] - y[j]) * (x[next] - x[j]);
            }
        }

        // Sort the intersections in increasing order
        for (j = 0; j < count - 1; j++) {
            for (int k = 0; k < count - j - 1; k++) {
                if (x_intersections[k] > x_intersections[k + 1]) {
                    temp = x_intersections[k];
                    x_intersections[k] = x_intersections[k + 1];
                    x_intersections[k + 1] = temp;
                }
            }
        }

        // Fill the scanline between pairs of intersections
        for (j = 0; j < count; j += 2) {
            x1 = x_intersections[j];
            x2 = x_intersections[j + 1];
            for (int k = x1; k < x2; k++) {
                putpixel(k, i, fill_color);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
     char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, driver); // Initialize graphics mode

    int x[] = {100, 200, 300, 250, 150};
    int y[] = {100, 150, 200, 300, 250};
    int n = sizeof(x) / sizeof(x[0]);

    int fill_color = 10; // Fill color (You can change it to your desired color)
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        line(x[i], y[i], x[next], y[next]);
    }
    scanlineFill(x, y, n, fill_color);

    delay(5000); // Delay to view the result

    closegraph(); // Close graphics mode
    return 0;
}
