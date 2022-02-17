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

#include QMK_KEYBOARD_H
#include "keymap_user.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

typedef union {
  uint32_t raw;
   struct {
    bool caps_lock_light_tab :1;
    bool caps_lock_light_alphas :1;
    // bool fn_layer_transparent_keys_off :1;
    // bool fn_layer_color_enable :1;
  };
} user_config_t;

user_config_t user_config;


#ifdef VIA_ENABLE
    #define USER_START USER00
#else
    #define USER_START SAFE_RANGE
#endif

// // Tap Dance declarations
// enum {
//     TD_LCMD_CAPS,
// };

// // Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_LCMD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCMD, KC_CAPS),
// };


enum custom_keycodes {
    KC_MISSION_CONTROL = USER_START,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
     KC_LIGHT_TAB_TOGGLE,
     KC_LIGHT_ALPHAS_TOGGLE
    // KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE,
    // KC_FN_LAYER_COLOR_TOGGLE
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
 #define KC_LTTOG KC_LIGHT_TAB_TOGGLE
 #define KC_LATOG KC_LIGHT_ALPHAS_TOGGLE
// #define KC_TKTOG KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE
// #define KC_FCTOG KC_FN_LAYER_COLOR_TOGGLE
#define CAPSFN LT(MAC_FN, KC_CAPS)
#define TTMACFN TT(MAC_FN)
#define TGMACFN TG(MAC_FN)
#define TTWINFN TT(WIN_FN)
#define TGWINFN TG(WIN_FN)
#define SPACNAV LT(NAV, KC_SPC)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_SLEP,                  KC_MUTE,
        KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,                  KC_PGUP,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,                  KC_PGDN,
        CAPSFN,    HOME_A,    HOME_S,    HOME_D,    HOME_F,    KC_G,      KC_H,      HOME_J,    HOME_K,    HOME_L,    HOME_SCLN, KC_QUOT,              KC_ENT,                   KC_DEL,
        KC_LSPO,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSPC,       KC_UP,
        KC_LCTL,   KC_LOPTN,  KC_LCMMD,                                   SPACNAV,   KC_VOLD,   KC_VOLU,              KC_RCMMD,  TTMACFN,   KC_RCTL,       KC_LEFT,   KC_DOWN,   KC_RGHT),

    [MAC_FN] = LAYOUT_all(
        KC_TRNS,   KC_BRID,   KC_BRIU,   KC_MCTL,   KC_LPAD,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   RESET,                    RGB_TOG,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        RGB_TOG,   RGB_MOD,   RGB_VAI,   RGB_HUI,   RGB_SAI,   RGB_SPI,   KC_TRNS,   KC_7,      KC_8,      KC_9,      KC_PLUS,   KC_MINS,   KC_ASTR,   KC_TRNS,                  KC_TRNS,
        TGMACFN,   RGB_RMOD,  RGB_VAD,   RGB_HUD,   RGB_SAD,   RGB_SPD,   KC_TRNS,   KC_4,      KC_5,      KC_6,      KC_DOT,    KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_1,      KC_2,      KC_3,      KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_0,      RGB_VAD,   RGB_VAI,              KC_TRNS,   TGMACFN,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),

    [WIN_BASE] = LAYOUT_all(
        KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_SLEP,                  KC_MUTE,
        KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,                  KC_PGUP,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,                  KC_PGDN,
        KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,              KC_ENT,                   KC_DEL,
        KC_LSFT,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSFT,       KC_UP,
        KC_LCTL,   KC_LGUI,   KC_LALT,                                    KC_SPC,    KC_VOLD,   KC_VOLU,              KC_RALT,   TTWINFN,   KC_RCTL,       KC_LEFT,   KC_DOWN,   KC_RGHT),

    [WIN_FN] = LAYOUT_all(
        KC_TRNS,   KC_BRID,   KC_BRIU,   KC_TASK,   KC_FLXP,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_TRNS,                  RGB_TOG,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        RGB_TOG,   RGB_MOD,   RGB_VAI,   RGB_HUI,   RGB_SAI,   RGB_SPI,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   RGB_RMOD,  RGB_VAD,   RGB_HUD,   RGB_SAD,   RGB_SPD,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_TRNS,   RGB_VAD,   RGB_VAI,              KC_TRNS,   TGWINFN,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),

    [NAV] = LAYOUT_all(
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_UP,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_BTN1,   KC_WH_U,   KC_BTN2,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_TRNS,   KC_TRNS,   KC_WH_R,   KC_WH_D,   KC_WH_L,   KC_TRNS,   KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),


/*
    [X] = LAYOUT_all(
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),
 */
};

#ifdef _______
#undef _______
#define _______ {0, 0, 0}
#endif
#ifdef NOLED
#undef NOLED
#define NOLED {0,0,0}
#endif

const uint8_t PROGMEM ledmaps[][DRIVER_LED_TOTAL][3] = {
   [MAC_FN] = RGB_MATRIX_LAYOUT_LEDMAP{
        _______,   MAGENT,    MAGENT,    BLUE,    MAGENT,    GREEN,     GREEN,     PINK,      PINK,      PINK,      PINK,      _______,   _______,   RED,                        _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   ORANGE,    ORANGE,    ORANGE,    ORANGE,    ORANGE,    ORANGE,    _______,                  _______,
        BLUE,      GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   ORANGE,    ORANGE,    ORANGE,    ORANGE,    _______,              _______,                  _______,
        _______,              YELLOW,    YELLOW,    _______,   _______,   _______,   _______,   ORANGE,    ORANGE,    ORANGE,    _______,              _______,       _______,
        _______,   _______,   _______,                                    ORANGE,    _______,   _______,              _______,   BLUE,      _______,       _______,   _______,   _______
     },
    [WIN_FN] = RGB_MATRIX_LAYOUT_LEDMAP{
        _______,   MAGENT,    MAGENT,    MAGENT,    MAGENT,    GREEN,     GREEN,     PINK,      PINK,      PINK,      PINK,      _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   _______,   _______,   _______,   _______,   _______,              _______,                  _______,
        _______,              YELLOW,    YELLOW,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,   _______,   _______,             _______,   BLUE,      _______,       _______,   _______,   _______
    },
    [NAV] = RGB_MATRIX_LAYOUT_LEDMAP{
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   CORAL,     _______,   _______,   _______,   TEAL,      TEAL,      TEAL,      _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   CORAL,     CORAL,     CORAL,     _______,   _______,   TEAL,      TEAL,      TEAL,      _______,   _______,              _______,                  _______,
        _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,   _______,   _______,              _______,   _______,   _______,       _______,   _______,   _______
     },
/*     [X] = {
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,                  _______,
        _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,   _______,   _______,              _______,   _______,   _______,       _______,   _______,   _______
     }, */
};

#undef _______
#define _______ KC_TRNS


#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 8, 5 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 5 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

 void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.caps_lock_light_tab = false;
    user_config.caps_lock_light_alphas = false;
/*     user_config.fn_layer_transparent_keys_off = true;
    user_config.fn_layer_color_enable = false; */
    eeconfig_update_user(user_config.raw);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;
        case KC_MCTL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        case KC_LIGHT_TAB_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_tab ^= 1; // bitwise xor to toggle status bit
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        case KC_LIGHT_ALPHAS_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_alphas ^= 1;
                eeconfig_update_user(user_config.raw);
            }
/*             return false;  // Skip all further processing of this key
        case KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE:
            if (record->event.pressed) {
                user_config.fn_layer_transparent_keys_off ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                user_config.fn_layer_color_enable ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key */

        default:
            return true;  // Process all other keycodes normally
    }
}

 bool get_caps_lock_light_tab(void) {
    return user_config.caps_lock_light_tab;
}

bool get_caps_lock_light_alphas(void) {
    return user_config.caps_lock_light_alphas;
}

/* bool get_fn_layer_transparent_keys_off(void) {
    return user_config.fn_layer_transparent_keys_off;
}

bool get_fn_layer_color_enable(void) {
    return user_config.fn_layer_color_enable;
} */

 void set_layer_color(int layer) {
    if (layer == 0) { return; }
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
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
}

void rgb_matrix_indicators_user(void) {
    if (disable_layer_color ||
        rgb_matrix_get_flags() == LED_FLAG_NONE ||
        rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW) {
            return;
        }
    set_layer_color(get_highest_layer(layer_state));
}
