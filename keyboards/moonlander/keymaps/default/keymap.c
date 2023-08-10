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

enum layers {
    BASE,         // default layer
    BASE_QUERTY,  // querty
    BASE_MAC,     // mac
    SEC,          // symbols and media
    MOUSE,        // mouse control
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    WIN_MGR
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_CAPS,          KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
        KC_BSLS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_DEL,           KC_PGDN, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_EQL,           KC_MINS, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, WIN_MGR,                  MO(MOUSE),KC_UP,   KC_DOWN, KC_RALT, KC_RGUI, KC_RCTL,
                                            KC_SPC,  KC_BSPC, MO(SEC),          MO(SEC), KC_ESC,  KC_ENT
    ),

    [BASE_QUERTY] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    _______,
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
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EE_CLR,  _______, _______, KC_WBAK, KC_WFWD,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MOUSE] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        KC_MUTE, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_VOLU, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_VOLD, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, TG(BASE_MAC),
        KC_MPRV, KC_MNXT, KC_MPLY, KC_BTN1, KC_BTN2,         _______,            _______,          _______, _______, _______, _______, TG(BASE_QUERTY),
                                            KC_BTN1, KC_BTN2, _______,           _______, _______, _______
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
    }
    return true;
}
