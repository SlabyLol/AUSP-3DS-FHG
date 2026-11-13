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
3. Copy the entire **`AUSP`** folder into your project  
   - Either into `source/` **or** into the project root (both work)
4. Open your `Makefile` and add these lines in the **variables section** (before any rules):

```makefile
SOURCES  += AUSP
INCLUDES += AUSP
LIBS     += -lcitro2d -lcitro3d
```

   Do **not** use `include AUSP/Makefile.inc` if you get Makefile errors.

5. In your code (as early as possible):

```c
#include "anti_usp.h"

int main(int argc, char **argv)
{
    anti_usp_run();

    // rest of your game
}
```

### Common errors & fixes

| Error | Fix |
|-------|-----|
| `ausp_signatures` / `AUSP_SIGNATURE_COUNT` undeclared | Update to latest AUSP (fixed in v1.4.3 – signatures moved to .c) |
| `C2D_Color32 undeclared` | Update to latest AUSP |
| `*** missing separator` | Recipe lines need a real Tab, not spaces |
| `overriding recipe for target 'build'` | Remove any `include AUSP/Makefile.inc`, add the 3 lines manually |
| `anti_usp.h: No such file` | Make sure `INCLUDES += AUSP` is set and use `#include "anti_usp.h"` |

## Configuration (`AUSP/config.h`)

```c
#define AUSP_REACTION_MODE      AUSP_REACTION_BOTH
#define AUSP_IGNORE_NIMBUS      1
#define AUSP_SPLASH_ENABLE      1
#define AUSP_SPLASH_DURATION    90
```

## License

Public domain. Do whatever you want.
