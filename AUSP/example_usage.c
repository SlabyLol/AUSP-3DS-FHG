#include <3ds.h>
#include "anti_usp.h"

int main(int argc, char **argv)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    anti_usp_run();

    printf("AUSP version: %s\n", anti_usp_version());
    printf("No plugin detected. Continuing...\n");

    while (aptMainLoop()) {
        hidScanInput();
        if (hidKeysDown() & KEY_START) break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
