#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    int rootX, rootY, winX, winY;
    unsigned int mask;

    Window root_disp, child_disp;
    while(1){
        if(XQueryPointer(display, root, &root_disp, &child_disp, &rootX, &rootY, &winX, &winY, &mask)){
            if(mask & Button1Mask){
                printf("(%4d, %4d) \n", rootX, rootY);
                break;
            }
        }
    }
    XCloseDisplay(display);

    return 0;
}