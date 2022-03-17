// adjusts backlight by cursor movement
// useful for tablet

#include <stdio.h>
#include <stdlib.h>
#include <xdo.h>

int main(void) {
  xdo_t* xdo = xdo_new(NULL);
  if (!xdo) {
    fprintf(stderr, "failed to allocate xdo\n");
    return 1;
  }

  int w, h;
  if (xdo_get_viewport_dimensions(xdo, &w, &h, 0)) {
    fprintf(stderr, "failed to query screen dimension\n");
    return 1;
  }

  int px, py, sc;
  xdo_get_mouse_location(xdo, &px, &py, &sc);
  for (;;) {
    int x, y;
    xdo_get_mouse_location(xdo, &x, &y, &sc);

    const int dx = x-px, dy = y-py;
    if (dx*dx+dy*dy > 30000) break;

    if (dx*dx+dy*dy > 4) {
      if (dy > dx) {
        system("xbacklight -dec 10 -time 50");
      } else {
        system("xbacklight -inc 10 -time 50");
      }
    }
    usleep(50000);
    px = x, py = y;
  }

  printf("done\n");
  xdo_free(xdo);
}
