# Optional helper – only use if your Makefile is simple.
# If you get "missing separator" or "overriding recipe" errors,
# do NOT include this file. Instead add the three lines manually:
#
#   SOURCES  += AUSP
#   INCLUDES += AUSP
#   LIBS     += -lcitro2d -lcitro3d
#
# Place them in the variables section of your Makefile (before any rules).

SOURCES  += AUSP
INCLUDES += AUSP
LIBS     += -lcitro2d -lcitro3d
