#ifndef ANTI_USP_H
#define ANTI_USP_H

#include <3ds.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AUSP_CLEAN = 0,
    AUSP_PLUGIN_FOUND = 1,
    AUSP_ERROR = -1
} AuspResult;

AuspResult anti_usp_check(void);
void anti_usp_show_screen(void);
void anti_usp_run(void);

#ifdef __cplusplus
}
#endif

#endif
