/* Copyright 2021 Mikael Manukyan <arm.localhost@gmail.com>
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

#include "quantum.h"

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

// no association keycode
#    define NOLED \
        { 0, 0, 0 }

// clang-format off
#   define RGB_MATRIX_LAYOUT_LEDMAP( \
    K00, K01,  K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,      K0F, \
    K10, K11,  K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K1F, \
    K20, K21,  K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F, \
    K30, K31,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,      K3F, \
    K40,       K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4D, K4E,      \
    K50, K51,  K52,                K56,                K5A, K5B, K5C, K5D, K5E, K5F  \
) \
 { \
    K00, K01,  K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B,  K0C, K0D, NOLED, K0F, \
    K10, K11,  K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B,  K1C, K1D, NOLED, K1F, \
    K20, K21,  K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,  K2C, K2D, NOLED, K2F, \
    K30, K31,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,  NOLED, K3D, NOLED, K3F, \
    K40, NOLED,  K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,  NOLED, K4D, K4E, NOLED, \
    K50, K51,  K52, NOLED, NOLED, NOLED, K56, NOLED, NOLED, NOLED, K5A, K5B,  K5C, K5D, K5E, K5F  \
}
// clang-format on
typedef uint8_t ledmap[DRIVER_LED_TOTAL][3];
extern const ledmap ledmaps[];

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer);

void rgb_matrix_layers_enable(void);
void rgb_matrix_layers_disable(void);

// Just a handy defines to make our ledmaps look better
#define RED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_keymap(void);
void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
