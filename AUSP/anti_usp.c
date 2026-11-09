#include "anti_usp.h"
#include "config.h"
#include <3ds.h>
#include <string.h>
#include <stdio.h>

static const u8 sig_ntr[] = {0x4E, 0x54, 0x52, 0x20, 0x43, 0x46, 0x57};
static const u8 sig_ctrpf[] = {0x43, 0x54, 0x52, 0x50, 0x46};
static const u8 sig_plg[] = {0x50, 0x4C, 0x47, 0x00};
static const u8 sig_3gx[] = {0x33, 0x47, 0x58};

static bool scan_region(const u8 *base, size_t size, const u8 *sig, size_t siglen)
{
    if (!base || size < siglen) return false;
    for (size_t i = 0; i <= size - siglen; i++) {
        if (memcmp(base + i, sig, siglen) == 0) return true;
    }
    return false;
}

AuspResult anti_usp_check(void)
{
    const u8 *regions[] = {
        (const u8 *)0x00100000,
        (const u8 *)0x08000000,
        (const u8 *)0x14000000
    };
    const size_t sizes[] = {
        0x00700000,
        0x01000000,
        0x02000000
    };

    for (int r = 0; r < 3; r++) {
        if (scan_region(regions[r], sizes[r], sig_ntr, sizeof(sig_ntr)) ||
            scan_region(regions[r], sizes[r], sig_ctrpf, sizeof(sig_ctrpf)) ||
            scan_region(regions[r], sizes[r], sig_plg, sizeof(sig_plg)) ||
            scan_region(regions[r], sizes[r], sig_3gx, sizeof(sig_3gx))) {
            return AUSP_PLUGIN_FOUND;
        }
    }
    return AUSP_CLEAN;
}

void anti_usp_show_screen(void)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("\x1b[2;1H");
    printf("  ========================================\n");
    printf("           %s\n", AUSP_TITLE);
    printf("           %s\n", AUSP_SUBTITLE);
    printf("  ========================================\n\n");
    printf("  %s\n", AUSP_LINE1);
    printf("  %s\n\n", AUSP_LINE2);
    printf("  %s\n", AUSP_LINE3);
    printf("  %s\n\n", AUSP_LINE4);
    printf("  %s\n\n", AUSP_LINE5);
    printf("  ========================================\n");
    printf("           %s\n", AUSP_FOOTER);
    printf("  ========================================\n");

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (AUSP_EXIT_ON_KEY && kDown) break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();

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
