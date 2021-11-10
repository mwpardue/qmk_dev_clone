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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const ckled2001_led __flash g_ckled2001_leds[DRIVER_LED_TOTAL] = {
/* Refer to ckled2001 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, D_1,    F_1,    E_1},
    {0, D_2,    F_2,    E_2},
    {0, D_3,    F_3,    E_3},
    {0, D_4,    F_4,    E_4},
    {0, D_5,    F_5,    E_5},
    {0, D_6,    F_6,    E_6},
    {0, D_7,    F_7,    E_7},
    {0, D_8,    F_8,    E_8},
    {0, D_9,    F_9,    E_9},
    {0, D_10,   F_10,   E_10},
    {0, D_11,   F_11,   E_11},
    {0, D_12,   F_12,   E_12},
    {0, D_13,   F_13,   E_13},
    {0, D_14,   F_14,   E_14},
    {0, D_16,   F_16,   E_16},

    {0, G_1,    I_1,    H_1},
    {0, G_2,    I_2,    H_2},
    {0, G_3,    I_3,    H_3},
    {0, G_4,    I_4,    H_4},
    {0, G_5,    I_5,    H_5},
    {0, G_6,    I_6,    H_6},
    {0, G_7,    I_7,    H_7},
    {0, G_8,    I_8,    H_8},
    {0, G_9,    I_9,    H_9},
    {0, G_10,   I_10,   H_10},
    {0, G_11,   I_11,   H_11},
    {0, G_12,   I_12,   H_12},
    {0, G_13,   I_13,   H_13},
    {0, G_14,   I_14,   H_14},
    {0, G_16,   I_16,   H_16},

    {0, J_1,    L_1,    K_1},
    {0, J_2,    L_2,    K_2},
    {0, J_3,    L_3,    K_3},
    {0, J_4,    L_4,    K_4},
    {0, J_5,    L_5,    K_5},
    {0, J_6,    L_6,    K_6},
    {0, J_7,    L_7,    K_7},
    {0, J_8,    L_8,    K_8},
    {0, J_9,    L_9,    K_9},
    {0, J_10,   L_10,   K_10},
    {0, J_11,   L_11,   K_11},
    {0, J_12,   L_12,   K_12},
    {0, J_14,   L_14,   K_14},
    {0, J_16,   L_16,   K_16},

    {1, A_1,    C_1,    B_1},
    {1, A_3,    C_3,    B_3},
    {1, A_4,    C_4,    B_4},
    {1, A_5,    C_5,    B_5},
    {1, A_6,    C_6,    B_6},
    {1, A_7,    C_7,    B_7},
    {1, A_8,    C_8,    B_8},
    {1, A_9,    C_9,    B_9},
    {1, A_10,   C_10,   B_10},
    {1, A_11,   C_11,   B_11},
    {1, A_12,   C_12,   B_12},
    {1, A_14,   C_14,   B_14},
    {1, A_15,   C_15,   B_15},

    {1, D_1,    F_1,    E_1},
    {1, D_2,    F_2,    E_2},
    {1, D_3,    F_3,    E_3},
    {1, D_7,    F_7,    E_7},
    {1, D_11,   F_11,   E_11},
    {1, D_12,   F_12,   E_12},
    {1, D_13,   F_13,   E_13},
    {1, D_14,   F_14,   E_14},
    {1, D_15,   F_15,   E_15},
    {1, D_16,   F_16,   E_16}
};

led_config_t g_led_config = {
    {
        {   0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,    13, NO_LED,     14  },
        {  15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,    28, NO_LED,     29  },
        {  30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41, NO_LED,    42, NO_LED,     43  },
        {  44,     NO_LED, 45,     46,     47,     48,     49,     50,     51,     52,     53,     54, NO_LED,    55,     56,         },
        {  57,     58,     59,     NO_LED, NO_LED, NO_LED, 60,     NO_LED, NO_LED, NO_LED, 61,     62,     63,    64,     65,     66  },
    },
    {
        {0, 0}, {15, 0}, {30, 0}, {45, 0}, {60, 0}, {75, 0}, {90, 0}, {105, 0}, {120, 0}, {135, 0}, {150, 0}, {165, 0}, {180, 0}, {195, 0},           {224, 0},
        {0,16}, {15,16}, {30,16}, {45,16}, {60,16}, {75,16}, {90,16}, {105,16}, {120,16}, {135,16}, {150,16}, {165,16}, {180,16}, {195,16},           {224,16},
        {0,32}, {15,32}, {30,32}, {45,32}, {60,32}, {75,32}, {90,32}, {105,32}, {120,32}, {135,32}, {150,32}, {165,32},           {195,32},           {224,32},
        {0,48},          {30,48}, {45,48}, {60,48}, {75,48}, {90,48}, {105,48}, {120,48}, {135,48}, {150,48}, {165,48},           {180,48}, {210,48},
        {0,64}, {15,64}, {30,64},                            {90,64},                               {150,64}, {165,64}, {180,64}, {195,64}, {210,64}, {224,64},
    },
    {
        4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,            4,
        4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,            4,
        4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,            4,            4,
        4,            4,     4,     4,     4,     4,     4,     4,     4,     4,     4,            4,     4,
        4,     4,     4,                          4,                          4,     4,     4,     4,     4,     4,
    }
};
#endif
