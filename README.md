# AUSP-3DS

Anti-USP-3DS – Lightweight plugin detection for Nintendo 3DS homebrew without filesystem access.

Detects common NTR / 3GX / CTRPluginFramework signatures in memory and shows a fully customizable anti-cheat screen.

## Installation

1. Download the repository as ZIP.
2. Extract the ZIP.
3. Copy the entire `AUSP` folder into the `source` (or `src`) directory of your 3DS project.
4. Add the following to your Makefile (adjust paths if needed):

```makefile
SOURCES += AUSP
INCLUDES += AUSP
```

Or simply include the files manually in your build.

5. In your main code call once early:

```c
#include "AUSP/anti_usp.h"

// ...
anti_usp_run();
```

## Customization

Edit `AUSP/config.h` to change the screen text, colors and behavior.

## License

Public domain / use freely.
