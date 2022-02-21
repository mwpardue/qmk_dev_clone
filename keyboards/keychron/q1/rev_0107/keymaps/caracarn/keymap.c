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

#include "caracarn.h"

#ifdef VIA_ENABLE
    #define USER_START USER00
#else
    #define USER_START SAFE_RANGE
#endif

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

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
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
/* #define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LGUI_T(KC_F) */

// Right-hand home row mods
/* #define HOME_J RGUI_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN) */

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_SLEP,         KC_VOLD, KC_MUTE, KC_VOLU,
        KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,                  KC_PGUP,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,                  KC_PGDN,
        CAPSFN,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,              KC_ENT,                   KC_DEL,
        KC_LSPO,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSPC,       KC_UP,
        KC_LCTL,   KC_LOPTN,  KC_LCMMD,                                   SPACNAV,                                    KC_RCMMD,  TTMACFN,   KC_RCTL,       KC_LEFT,   KC_DOWN,   KC_RGHT),

    [MAC_FN] = LAYOUT_all(
        KC_TRNS,   KC_BRID,   KC_BRIU,   KC_MCTL,   KC_LPAD,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   RESET,           RGB_VAD, RGB_TOG, RGB_VAI,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        RGB_TOG,   RGB_MOD,   RGB_VAI,   RGB_HUI,   RGB_SAI,   RGB_SPI,   KC_TRNS,   KC_7,      KC_8,      KC_9,      KC_PLUS,   KC_MINS,   KC_ASTR,   KC_TRNS,                  KC_TRNS,
        TGMACFN,   RGB_RMOD,  RGB_VAD,   RGB_HUD,   RGB_SAD,   RGB_SPD,   KC_TRNS,   KC_4,      KC_5,      KC_6,      KC_DOT,    KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_1,      KC_2,      KC_3,      KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_0,                                     KC_TRNS,   TGMACFN,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),

    [WIN_BASE] = LAYOUT_all(
        KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_SLEP,         KC_VOLD, KC_MUTE, KC_VOLU,
        KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,                  KC_PGUP,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,                  KC_PGDN,
        KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,              KC_ENT,                   KC_DEL,
        KC_LSFT,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSFT,       KC_UP,
        KC_LCTL,   KC_LGUI,   KC_LALT,                                    KC_SPC,                                     KC_RALT,   TTWINFN,   KC_RCTL,       KC_LEFT,   KC_DOWN,   KC_RGHT),

    [WIN_FN] = LAYOUT_all(
        KC_TRNS,   KC_BRID,   KC_BRIU,   KC_TASK,   KC_FLXP,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_TRNS,         RGB_VAD, RGB_TOG, RGB_VAI,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        RGB_TOG,   RGB_MOD,   RGB_VAI,   RGB_HUI,   RGB_SAI,   RGB_SPI,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   RGB_RMOD,  RGB_VAD,   RGB_HUD,   RGB_SAD,   RGB_SPD,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_TRNS,                                  KC_TRNS,   TGWINFN,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),

    [NAV] = LAYOUT_all(
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_UP,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_BTN1,   KC_WH_U,   KC_BTN2,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_TRNS,   KC_TRNS,   KC_WH_R,   KC_WH_D,   KC_WH_L,   KC_TRNS,   KC_TRNS,              KC_TRNS,                  KC_TRNS,
        KC_TRNS,              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,       KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                                    KC_TRNS,                                    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS),

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

#ifdef RGB_MATRIX_LEDMAPS_ENABLED
    #ifdef _______
    #undef _______
    #define _______ {0, 0, 0}
    #endif

const ledmap PROGMEM ledmaps[] = {
     [MAC_BASE] = {
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,                  _______,
        _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,       _______,   _______,   _______
     },
    [MAC_FN] = {
        _______,   MAGENT,    MAGENT,    MAGENT,    MAGENT,    GREEN,     GREEN,     PINK,      PINK,      PINK,      PINK,      PINK,        PINK,      RED,               _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   ORANGE,    ORANGE,    ORANGE,    ORANGE,    ORANGE,    ORANGE,    _______,                  _______,
        BLUE,      GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   ORANGE,    ORANGE,    ORANGE,    ORANGE,    _______,              _______,                  _______,
        _______,              YELLOW,    YELLOW,    _______,   _______,   _______,   _______,   ORANGE,    ORANGE,    ORANGE,    _______,              _______,       _______,
        _______,   _______,   _______,                                    ORANGE,                                     _______,   BLUE,      _______,       _______,   _______,   _______
    },
[WIN_BASE] = {
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,                  _______,
        _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,       _______,   _______,   _______
    },
    [WIN_FN] = {
        _______,   MAGENT,    MAGENT,    MAGENT,    MAGENT,    GREEN,     GREEN,     PINK,      PINK,      PINK,      PINK,      _______,   _______,   _______,         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   GREEN,     GREEN,     GREEN,     GREEN,     GREEN,     _______,   _______,   _______,   _______,   _______,   _______,              _______,                  _______,
        _______,              YELLOW,    YELLOW,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,                                    _______,   BLUE,      _______,       _______,   _______,   _______
    },
    [NAV] = {
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,         _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   _______,   CORAL,     _______,   _______,   _______,   TEAL,      TEAL,      TEAL,      _______,   _______,   _______,   _______,                  _______,
        _______,   _______,   CORAL,     CORAL,     CORAL,     _______,   _______,   TEAL,      TEAL,      TEAL,      _______,   _______,              _______,                  _______,
        _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,       _______,
        _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,       _______,   _______,   _______
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
#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
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
        default:
            return true;   // Process all other keycodes normally
    }
}


/* bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
        case LCTL_T(KC_A):
        case LALT_T(KC_S):
        case LSFT_T(KC_D):
        case LGUI_T(KC_F):
        case RGUI_T(KC_J):
        case RSFT_T(KC_K):
        case LALT_T(KC_L):
        case RCTL_T(KC_SCLN):
            return true;
        default:
            return false;
    }
} */
