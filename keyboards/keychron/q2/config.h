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
#define PRODUCT         Keychron Q2

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* RGB Matrix Driver Configuration */
#define DRIVER_COUNT 2
#define DRIVER_ADDR_1 0b1110111
#define DRIVER_ADDR_2 0b1110100

/* Setting number of scan phase in one frame
 * SP    Scan Phase Setting
 * 0x00  Scan phase is CB1 ~ CB12, 1/12.
 * 0x01  Scan phase is CB1 ~ CB11, 1/11, CB12 no-active.
 * 0x02  Scan phase is CB1 ~ CB10, 1/10, CB11~CB12 no-active.
 * 0x03  Scan phase is CB1 ~ CB9,  1/9,  CB10~CB12 no-active.
 * 0x04  Scan phase is CB1 ~ CB8,  1/8,  CB9~CB12 no-active.
 * 0x05  Scan phase is CB1 ~ CB7,  1/7,  CB8~CB12 no-active.
 * 0x06  Scan phase is CB1 ~ CB6,  1/6,  CB7~CB12 no-active.
 * 0x07  Scan phase is CB1 ~ CB5,  1/5,  CB6~CB12 no-active.
 * 0x08  Scan phase is CB1 ~ CB4,  1/4,  CB5~CB12 no-active.
 * 0x09  Scan phase is CB1 ~ CB3,  1/3,  CB4~CB12 no-active.
 * 0x0A  Scan phase is CB1 ~ CB2,  1/2,  CB3~CB12 no-active.
 * 0x0B  Scan phase is only CB1,   1/1,  CB2~CB12 no-active.
 */
#define PHASE_CHANNEL 0x03

/* DIP switch */
#define DIP_SWITCH_MATRIX_GRID  { {4,4} }

/* Disable DIP switch in matrix data */
#define MATRIX_MASKED

/* NKRO */
#define FORCE_NKRO

/* turn off effects when suspended */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

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

#define BOOTMAGIC_LITE_ROW 4
#define BOOTMAGIC_LITE_COLUMN 5
