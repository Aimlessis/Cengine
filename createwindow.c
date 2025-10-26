#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    
    Display *display = XOpenDisplay(NULL);
    int screennumber = DefaultScreen(display);
    Window window;
    Bool Running = True;
    unsigned long white = WhitePixel(display, screennumber);
    unsigned long black = BlackPixel(display, screennumber);

    window = XCreateSimpleWindow(display, RootWindow(display, screennumber), 100, 100, 1080, 720, 1, black, white);
    XMapWindow(display, window);

    //handling exit and inputs idk :P
     
    XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask);
    Atom delete_window = XInternAtom(display, "delete_window", False);
    XSetWMProtocols(display, window, &delete_window, 1);

    XEvent event;
    while(Running){
        if(event.type == ClientMessage){
            printf("Stopping window...");
            Running = False;
            break;
        }
    }



 
    XCloseDisplay(display);
    return 0;
}