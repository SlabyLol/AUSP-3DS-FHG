# AUSP-3DS

**Anti-USP-3DS** – Advanced lightweight plugin detection for Nintendo 3DS homebrew. (USP stands for Unsigned-Plugin)

Detects NTR, 3GX, CTRPluginFramework and related loaders **without any filesystem access** by scanning process memory for known signatures. Shows a fully customizable anti-cheat screen and can force-exit the process.

## Features

- Memory-only detection (no SD card / folder checks)
- Multiple known signatures for NTR, CTRPF, 3GX, PLG headers
- Dynamic memory region discovery via `svcQueryMemory`
- Fully customizable screen text and behavior via `config.h`
- Clean modular design
- Drop-in ready (just copy the `AUSP` folder)

## Installation

1. Download this repository as ZIP
2. Extract it
3. Copy the entire **`AUSP`** folder into your project's `source` or `src` directory
4. Add to your Makefile:

```makefile
include AUSP/Makefile.inc
```

or manually:

```makefile
SOURCES += AUSP
INCLUDES += AUSP
```

5. In your code (as early as possible):

```c
#include "AUSP/anti_usp.h"

int main(int argc, char **argv)
{
    // your init code...

    anti_usp_run();

    // rest of your game
}
```

## Customization

Edit **`AUSP/config.h`** to change every text string, whether the process should exit, and detection sensitivity.

## Files

| File | Purpose |
|------|---------|
| `anti_usp.h` / `anti_usp.c` | Main API |
| `config.h` | All user-editable settings |
| `signatures.h` | Signature database |
| `scanner.c` / `scanner.h` | Memory scanning engine |
| `screen.c` / `screen.h` | Anti-cheat screen renderer |
| `Makefile.inc` | Easy Makefile integration |
| `example_usage.c` | Minimal integration example |

## License

Public domain. Do whatever you want.
