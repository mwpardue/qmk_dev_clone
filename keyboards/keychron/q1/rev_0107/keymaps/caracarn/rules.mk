VIA_ENABLE = no
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_LEDMAPS = yes

src += caracarn.c

ifeq ($(strip $(RGB_MATRIX_LEDMAPS)), yes)
	SRC += rgb_matrix_ledmaps.c
	OPT_DEFS += -DRGB_MATRIX_LEDMAPS_ENABLED
endif
