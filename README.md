# AUSP-3DS

**Anti-USP-3DS** – Advanced lightweight plugin detection for Nintendo 3DS homebrew.

Detects NTR, 3GX, CTRPluginFramework and related loaders **without any filesystem access**.

Always shows a clean **citro2d splash** with the AUSP logo and "Supported by AUSP-3DS" at the start of every homebrew that integrates it.

Fully configurable reaction after detection:
- Show anti-cheat screen
- Call a custom action / callback
- Or both

## Features

- Memory-only detection (no SD card / folder checks)
- Dynamic memory region discovery via `svcQueryMemory`
- Multiple known signatures
- Configurable reaction: screen only / action only / both
- Automatic citro2d splash screen with logo on every start
- Fully customizable texts and colors
- Drop-in ready

## Installation

1. Download this repository as ZIP
2. Extract it
3. Copy the entire **`AUSP`** folder into your project's `source` or `src` directory
4. Make sure your project links against `citro2d` and `citro3d` (standard in most modern 3DS homebrew)
5. Add to your Makefile:

```makefile
include AUSP/Makefile.inc
```

6. In your code (as early as possible):

```c
#include "AUSP/anti_usp.h"

int main(int argc, char **argv)
{
    anti_usp_run();   // shows splash + does detection

    // your own gfx / C2D init can come after if needed
    // rest of your game
}
```

## Configuration (`AUSP/config.h`)

- `AUSP_REACTION_MODE` → SCREEN / ACTION / BOTH
- Splash enable + duration
- All anti-cheat texts
- Force exit behavior

## License

Public domain. Do whatever you want.
