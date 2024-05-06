#include "window.hpp"

int main()
{
    Window::my_Window win;

    win.window(1080, 1920, "ERP : RECEPE PDF PART v0.0");
    win.loop();
    return 0;
}
