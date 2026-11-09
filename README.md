# AUSP-3DS

**Anti-USP-3DS** – Advanced lightweight plugin detection for Nintendo 3DS homebrew.

Detects NTR, 3GX, CTRPluginFramework and related loaders **without any filesystem access** by scanning process memory for known signatures.

Fully configurable reaction:
- Show anti-cheat screen
- Call a custom action / callback
- Or both

## Features

- Memory-only detection (no SD card / folder checks)
- Dynamic memory region discovery via `svcQueryMemory`
- Multiple known signatures
- Configurable reaction: screen only / action only / both
- Fully customizable screen text
- Clean modular design
- Drop-in ready

## Installation

1. Download this repository as ZIP
2. Extract it
3. Copy the entire **`AUSP`** folder into your project's `source` or `src` directory
4. Add to your Makefile:

```makefile
include AUSP/Makefile.inc
```

5. In your code (as early as possible):

```c
#include "AUSP/anti_usp.h"

// Optional: set your own action
void my_punish(void)
{
    // e.g. corrupt save, softlock, send online ban signal, etc.
    svcExitProcess();
}

int main(int argc, char **argv)
{
    anti_usp_set_action(my_punish);   // optional
    anti_usp_run();

    // rest of your game
}
```

## Configuration (`AUSP/config.h`)

You can choose the reaction mode:

```c
#define AUSP_REACTION_MODE   AUSP_REACTION_BOTH   // or SCREEN / ACTION
```

Available modes:
- `AUSP_REACTION_SCREEN`  → only show the anti-cheat screen
- `AUSP_REACTION_ACTION`  → only call the registered action
- `AUSP_REACTION_BOTH`    → show screen **and** call the action

All text strings and force-exit behavior are also configurable there.

## Files

| File | Purpose |
|------|---------|
| `anti_usp.h` / `anti_usp.c` | Main API |
| `config.h` | All settings + reaction mode |
| `signatures.h` | Signature database |
| `scanner.c` / `scanner.h` | Memory scanning engine |
| `screen.c` / `screen.h` | Anti-cheat screen |
| `Makefile.inc` | Easy Makefile integration |
| `example_usage.c` | Full example |

## License

Public domain. Do whatever you want.
