/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3434
#define MANUFACTURER    Keychron
#define PRODUCT         Keychron Q8

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, A15, A14, A13 }
#define MATRIX_COL_PINS { A10, A9, A8, B1, B0, A7, A6, A5, A4, A3, A2, A1, A0, C15, C14 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* RGB Matrix Driver Configuration */
#define DRIVER_COUNT 1
#define DRIVER_ADDR_1 0b1110100

/* Disable DIP switch in matrix data */
#define MATRIX_MASKED

/* NKRO */
#define FORCE_NKRO

/* turn off effects when suspended */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* Use 5 dynamic keymap layers */
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* DIP switch */
#define DIP_SWITCH_MATRIX_GRID  { {3, 4} }

/* BOOTMAGIC LITE key */
#define BOOTMAGIC_LITE_ROW 3
#define BOOTMAGIC_LITE_COLUMN 5

/* Set USB polling rate as 1 milliseconds */
#define USB_POLLING_INTERVAL_MS 1

/* Disable a single effect */
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_HUE_BREATHING
#define DISABLE_RGB_MATRIX_HUE_PENDULUM
#define DISABLE_RGB_MATRIX_HUE_WAVE

/* Test LEDs */
#define RGB_MATRIX_KEYPRESSES

