#include <stdio.h>

typedef struct {
    double xm_offset;
    double ym_offset;
} MapSize;

typedef struct {
    int debug_mode;
    MapSize map_sz;
} Window;

void set_default_window_data(Window *window) {
    window->debug_mode = 1;
    window->map_sz.xm_offset = 5.0;
    window->map_sz.ym_offset = 10.0;
}

int main() {
    Window *myWindow;
    set_default_window_data(myWindow);

    // Accessing the modified values outside the function
    printf("Debug Mode: %d\n", myWindow->debug_mode);
    printf("xm_offset: %f\n", myWindow->map_sz.xm_offset);
    printf("ym_offset: %f\n", myWindow->map_sz.ym_offset);

    return 0;
}