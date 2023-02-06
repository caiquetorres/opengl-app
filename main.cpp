#include <iostream>

#include "src/graphics/window.h"

int main()
{
  graphics::window window(1080, 720, "OpenGL");

  window.open();

  while (window.is_open())
  {
    window.clear();
    window.update();
  }

  window.close();

  return 0;
}
