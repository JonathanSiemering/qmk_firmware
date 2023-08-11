/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"
#include "alt_key.c"

enum layers {
    BASE,         // default layer
    BASE_QUERTY,  // querty
    BASE_MAC,     // mac
    SEC,          // symbols and media
    MOUSE,        // mouse control
    SETTING,      // Settings
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    WIN_MGR,
    KC_UE,
    KC_OE,
    KC_AE,
    KC_SZ,
    KC_EU
};

bool is_lsft_pressed = false;
bool is_rsft_pressed = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    MO(SETTING),     KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
        KC_BSLS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_DEL,           KC_PGDN, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_EQL,           KC_MINS, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, WIN_MGR,                  MO(MOUSE),KC_UP,   KC_DOWN, KC_RALT, KC_RGUI, KC_RCTL,
                                            KC_SPC,  KC_BSPC, MO(SEC),          MO(SEC), KC_ESC,  KC_ENT
    ),

    [BASE_QUERTY] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [BASE_MAC] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, KC_LALT, KC_LGUI, _______, _______,          _______,           _______,          _______, KC_RGUI, KC_RALT, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [SEC] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_MINS, KC_EQL,  _______, _______, _______, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_AE,   KC_UE,   KC_OE,   KC_SZ,   KC_EU,   _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, _______,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EE_CLR,  _______, _______, KC_WBAK, KC_WFWD,          _______,           _______,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [MOUSE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_MUTE, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_VOLU, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_VOLD, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_MPRV, KC_MNXT, KC_MPLY, KC_BTN1, KC_BTN2,         _______,            _______,          _______, _______, _______, _______, _______,
                                            KC_BTN1, KC_BTN2, _______,           _______, _______, _______
    ),

    [SETTING] = LAYOUT_moonlander(
       LED_LEVEL, UC_MAC, UC_LINX, UC_WIN,  _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        KC_CAPS, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, TG(BASE_MAC),
        _______, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, _______, _______, _______, TG(BASE_QUERTY),
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    case WIN_MGR:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LSFT);
        }
        else {
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
        }
    case KC_LSFT:
        if (record->event.pressed) {
            is_lsft_pressed = true;
        } else {
            is_lsft_pressed = false;
        }

        return !layer_state_is(SEC);
    case KC_RSFT:
        if (record->event.pressed) {
            is_rsft_pressed = true;
        } else {
            is_rsft_pressed = false;
        }

        return !layer_state_is(SEC);
    case KC_UE:
        if (record->event.pressed) {
            bool unicode_mode_win = get_unicode_input_mode() == UNICODE_MODE_WINDOWS;

            if (is_lsft_pressed | is_rsft_pressed) {
                if (unicode_mode_win) {
                    send_alt_code(0, 2, 2, 0);
                } else {
                    send_unicode_string("Ü");
                }
            } else {
                if (unicode_mode_win) {
                    send_alt_code(0, 2, 5, 2);
                } else {
                    send_unicode_string("ü");
                }
            }
        }
        return false;
    case KC_OE:
        if (record->event.pressed) {
            bool unicode_mode_win = get_unicode_input_mode() == UNICODE_MODE_WINDOWS;

            if (is_lsft_pressed | is_rsft_pressed) {
                if (unicode_mode_win) {
                    send_alt_code(0, 2, 1, 4);
                } else {
                    send_unicode_string("Ö");
                }
            } else {
                if (unicode_mode_win) {
                    send_alt_code(0, 2, 4, 6);
                } else {
                    send_unicode_string("ö");
                }
            }
        }
        return false;
    case KC_AE:
        if (record->event.pressed) {
            bool unicode_mode_win = get_unicode_input_mode() == UNICODE_MODE_WINDOWS;

            if (is_lsft_pressed | is_rsft_pressed) {
                if (unicode_mode_win) {
                    send_alt_code(0, 1, 9, 6);
                } else {
                    send_unicode_string("Ä");
                }
            } else {
                if (unicode_mode_win) {
                    send_alt_code(0, 2, 2, 8);
                } else {
                    send_unicode_string("ä");
                }
            }
        }
        return false;
    case KC_SZ:
        if (record->event.pressed) {
            bool unicode_mode_win = get_unicode_input_mode() == UNICODE_MODE_WINDOWS;

            if (unicode_mode_win) {
                send_alt_code(0, 2, 2, 3);
            } else {
                send_unicode_string("ß");
            }
        }
        return false;
    case KC_EU:
        if (record->event.pressed) {
            bool unicode_mode_win = get_unicode_input_mode() == UNICODE_MODE_WINDOWS;

            if (unicode_mode_win) {
                send_alt_code(0, 1, 2, 8);
            } else {
                send_unicode_string("€");
            }
        }
        return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Caps lock
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    }

    // Set Layer
    if (layer_state_is(SETTING)) {
        // Set all off
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, RGB_OFF);
        }

        // MAC Layer
        if (layer_state_is(BASE_MAC)) {
            rgb_matrix_set_color(39, RGB_WHITE);
        }

        // QUERTY Layer
        if (layer_state_is(BASE_QUERTY)) {
            rgb_matrix_set_color(40, RGB_WHITE);
        }

        // Unicode Mode
        switch (get_unicode_input_mode()) {
            case UNICODE_MODE_MACOS:
                rgb_matrix_set_color(5, RGB_WHITE);
                break;
            case UNICODE_MODE_LINUX:
                rgb_matrix_set_color(10, RGB_WHITE);
                break;
            case UNICODE_MODE_WINDOWS:
                rgb_matrix_set_color(15, RGB_WHITE);
                break;
        }
    }

    return false;
}

