#include <3ds.h>
#include "anti_usp.h"

static void my_custom_action(void)
{
    // Example actions you can do here:
    // - softlock the game
    // - corrupt temporary data
    // - force a crash
    // - write a flag for later ban checks
    // - etc.

    // For demonstration we just exit hard
    svcExitProcess();
}

int main(int argc, char **argv)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    anti_usp_set_action(my_custom_action);

    anti_usp_run();

    printf("AUSP version: %s\n", anti_usp_version());
    printf("No plugin detected. Continuing normally...\n");

    while (aptMainLoop()) {
        hidScanInput();
        if (hidKeysDown() & KEY_START)
            break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
