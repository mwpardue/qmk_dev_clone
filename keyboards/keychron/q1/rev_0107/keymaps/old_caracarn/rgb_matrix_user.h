/* Copyright 2021 @ Mike Killewald
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

void rgb_matrix_init_user(void);

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue);

bool is_caps_lock_indicator(uint16_t keycode);
bool is_transparent(uint16_t keycode);
bool is_not_transparent(uint16_t keycode);

#    define NOLED \
        { 0, 0, 0 }

// clang-format off
#   define RGB_MATRIX_LAYOUT_LEDMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,      K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,      K3F, \
    K40,       K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4D, K4E,      \
    K50, K51, K52,                K56, K57, K58,      K5A, K5B, K5C, K5D, K5E, K5F  \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B,  K0C, K0D, NOLED, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B,  K1C, K1D, NOLED, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,  K2C, K2D, NOLED, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,  NOLED, K3D, NOLED, K3F }, \
    { K40, NOLED, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,  NOLED, K4D, K4E, NOLED }, \
    { K50, K51, K52, NOLED, NOLED, NOLED, K56, K57, K58, NOLED, K5A, K5B,  K5C, K5D, K5E, K5F }  \
  }
