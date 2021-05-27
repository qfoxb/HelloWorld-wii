// Hello world!
// This is just me figuring out C 
// I should have just kept this code to myself because there's nothing to learn from it and devkitPro has better code
// Uses code snippets from https://github.com/devkitPro/wii-examples/
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
static void *xfb = NULL;// snip from devkitpro's wii examples
static GXRModeObj *rmode = NULL; // snip from devkitpro's wii examples

int main(int argc, char **argv) {
    //code copied from devkitpro wii examples
    VIDEO_Init();
    WPAD_Init();
    rmode = VIDEO_GetPreferredMode(NULL);
    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode)); // code from devkitpro's wii examples
    console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
    VIDEO_Configure(rmode);
    VIDEO_SetNExtFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
    printf("\x1b[2;0H");
    printf("Hello World!")
    // anyway please don't bully me for a test repository
    }
