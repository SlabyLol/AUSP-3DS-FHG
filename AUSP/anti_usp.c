#include "anti_usp.h"
#include "config.h"
#include "scanner.h"
#include "screen.h"

AuspResult anti_usp_check(void)
{
    if (ausp_scan_process()) {
        return AUSP_PLUGIN_FOUND;
    }
    return AUSP_CLEAN;
}

void anti_usp_show_screen(void)
{
    ausp_draw_screen();

    if (AUSP_FORCE_EXIT) {
        svcExitProcess();
    }
}

void anti_usp_run(void)
{
    if (anti_usp_check() == AUSP_PLUGIN_FOUND) {
        anti_usp_show_screen();
    }
}

const char *anti_usp_version(void)
{
    static char buf[16];
    snprintf(buf, sizeof(buf), "%d.%d.%d", AUSP_VERSION_MAJOR, AUSP_VERSION_MINOR, AUSP_VERSION_PATCH);
    return buf;
}
