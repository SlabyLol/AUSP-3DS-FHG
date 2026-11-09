#include <3ds.h>
#include "anti_usp.h"

static void my_custom_action(void)
{
    svcExitProcess();
}

int main(int argc, char **argv)
{
    anti_usp_set_action(my_custom_action);

    anti_usp_run();

    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

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
