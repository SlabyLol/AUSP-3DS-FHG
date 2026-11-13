# AUSP-3DS

**Anti-USP-3DS** – Advanced lightweight plugin detection for Nintendo 3DS homebrew.

Detects NTR, 3GX, CTRPluginFramework and related loaders **without any filesystem access**.

Always shows a clean **citro2d splash** with the AUSP logo and "Supported by AUSP-3DS" at the start of every homebrew that integrates it.

**Nimbus (Pretendo) is explicitly ignored** so legitimate online players are not blocked.

Fully configurable reaction after detection:
- Show anti-cheat screen
- Call a custom action / callback
- Or both

## Features

- Memory-only detection (no SD card / folder checks)
- Dynamic memory region discovery via `svcQueryMemory`
- Multiple known signatures
- **Ignores Nimbus / Pretendo plugin** (configurable)
- Configurable reaction: screen only / action only / both
- Automatic citro2d splash screen with logo on every start
- Fully customizable texts and colors
- Drop-in ready

## Installation (IMPORTANT)

1. Download this repository as ZIP
2. Extract it
3. Copy the entire **`AUSP`** folder into your project's `source` (or `src`) directory  
   → Result should look like: `source/AUSP/anti_usp.c` etc.

4. **Do NOT use `include AUSP/Makefile.inc`** if you get Makefile errors.

   Instead open your project's `Makefile` and add these three lines **in the variables section** (where `SOURCES`, `INCLUDES` and `LIBS` are already defined):

```makefile
SOURCES  += AUSP
INCLUDES += AUSP
LIBS     += -lcitro2d -lcitro3d
```

   Make sure these lines are **not** indented with tabs and are placed **before** any rules (`build:`, `3dsx:`, etc.).

5. In your code (as early as possible):

```c
#include "anti_usp.h"

int main(int argc, char **argv)
{
    anti_usp_run();   // shows splash + does detection (ignores Nimbus)

    // rest of your game
}
```

   Note: Because `INCLUDES += AUSP` is used, include the header as `"anti_usp.h"` (not `"AUSP/anti_usp.h"`).

### Common Makefile / compile errors & fixes

| Error | Cause | Fix |
|-------|-------|-----|
| `*** missing separator` | Recipe line starts with spaces instead of a real Tab | Use a real Tab character for recipe lines |
| `overriding recipe for target 'build'` | `include` placed in wrong location | Remove the include and add the 3 lines manually |
| `C2D_Color32 undeclared` / citro2d errors | Old version of config.h | Update to latest AUSP (fixed in v1.4.2) |
| `No rule to make target ... AUSP/...` | Folder not found | Make sure `AUSP` is inside your `source` folder |
| `anti_usp.h: No such file` | Wrong include path | Use `#include "anti_usp.h"` with `INCLUDES += AUSP` |

## Configuration (`AUSP/config.h`)

```c
#define AUSP_REACTION_MODE      AUSP_REACTION_BOTH   // SCREEN / ACTION / BOTH
#define AUSP_IGNORE_NIMBUS      1                    // 1 = ignore Pretendo/Nimbus
#define AUSP_SPLASH_ENABLE      1
#define AUSP_SPLASH_DURATION    90                   // frames
```

All anti-cheat texts, splash colors (as separate R/G/B/A values) and force-exit behavior are also editable there.

## License

Public domain. Do whatever you want.
