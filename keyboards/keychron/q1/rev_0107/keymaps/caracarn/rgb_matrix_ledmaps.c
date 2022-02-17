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
#include "rgb_matrix_ledmaps.h"

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) { return; }
__attribute__((weak)) void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return;
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

static bool enabled = true;

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_user(void) { rgb_matrix_indicators_keymap(); }
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef RGB_MATRIX_LEDMAPS_ENABLED
    if (rgb_matrix_is_enabled() && enabled) {
        set_layer_rgb(led_min, led_max, get_highest_layer(layer_state | default_layer_state));
    }

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
    rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer) {
    const ledmap *l = &(ledmaps[layer]);

    uint8_t val = rgb_matrix_get_val();

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = (*l)[i][0],
            .s = (*l)[i][1],
            .v = val,
        };

        if (hsv.h || hsv.s) {
            RGB rgb = hsv_to_rgb(hsv);
            //RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

/* void set_layer_color(int layer) {
    if (layer == 0) { return; }
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmaps[layer][i][0]),
            .s = pgm_read_byte(&ledmaps[layer][i][1]),
            .v = pgm_read_byte(&ledmaps[layer][i][2]),
        };
        if (hsv.h || hsv.s || hsv.v) {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        } else if (layer != 1) {
            // Only deactivate non-defined key LEDs at layers other than FN. Because at FN we have RGB adjustments and need to see them live.
            // If the values are all false then it's a transparent key and deactivate LED at this layer
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
} */

void rgb_matrix_layers_enable() {
    dprintf("ledmaps are enabled\n");
    enabled = true;
}

void rgb_matrix_layers_disable() {
    dprintf("ledmaps are disabled\n");
    enabled = false;
}

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
