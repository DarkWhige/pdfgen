#include "window.hpp"

int main() 
{
    Window::my_Window win;

    win.window(1080, 1920, "ERP : RECE PDF PART v0.0");
    UI(win);
    win.loop();
    return 0;
}
