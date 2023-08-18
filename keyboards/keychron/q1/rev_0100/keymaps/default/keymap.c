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
#include "alt_key.c"

enum layers{
    MAC_BASE,
    WIN_BASE,
    ALL_CK,  // Colemak
    ALL_FN,
    ALL_UC,  // UNICODE
    ALL_KP,  // Keepad
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_UE,
    KC_OE,
    KC_AE,
    KC_SZ,
    KC_EU
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

bool is_lsft_pressed = false;
bool is_rsft_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_INS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                               MO(ALL_UC),MO(ALL_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_INS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                               MO(ALL_UC),MO(ALL_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [ALL_CK] = LAYOUT_ansi_82(
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [ALL_FN] = LAYOUT_ansi_82(
        QK_RBT,             KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  EEP_RST,  QK_BOOT,
        KC_TRNS,  UC_M_MA,  UC_M_LN,  UC_M_WI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS, TG(ALL_CK),KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_MPLY,  KC_VOLU,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS, TG(ALL_KP),KC_MPRV,  KC_VOLD,  KC_MNXT),

    [ALL_UC] = LAYOUT_ansi_82(
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_EU,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UE,    KC_UE,    KC_OE,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_AE,    KC_SZ,    KC_SZ,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_OE,    KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [ALL_KP] = LAYOUT_ansi_82(
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NUM,   KC_PAST,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_PSLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_PPLS,  KC_TRNS,            KC_PENT,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_PMNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_KP_0,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};

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
        case KC_LSFT:      // Keep shift state in local variable
            if (record->event.pressed) {
                is_lsft_pressed = true;
            } else {
                is_lsft_pressed = false;
            }

            return !layer_state_is(ALL_UC);
        case KC_RSFT:
            if (record->event.pressed) {
                is_rsft_pressed = true;
            } else {
                is_rsft_pressed = false;
            }

            return !layer_state_is(ALL_UC);
        case KC_UE:
            if (record->event.pressed) {
                bool unicode_mode_win = get_unicode_input_mode() == UC_WIN;

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
                bool unicode_mode_win = get_unicode_input_mode() == UC_WIN;

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
                bool unicode_mode_win = get_unicode_input_mode() == UC_WIN;

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
                bool unicode_mode_win = get_unicode_input_mode() == UC_WIN;

                if (unicode_mode_win) {
                    send_alt_code(0, 2, 2, 3);
                } else {
                    send_unicode_string("ß");
                }
            }
            return false;
        case KC_EU:
            if (record->event.pressed) {
                bool unicode_mode_win = get_unicode_input_mode() == UC_WIN;

                if (unicode_mode_win) {
                    send_alt_code(0, 1, 2, 8);
                } else {
                    send_unicode_string("€");
                }
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}

// void keyboard_post_init_user(void) {
//     layer_on(ALL_CK);
// }

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // On some modes min and max are not correct
    const uint8_t min_led = 0;
    const uint8_t max_led = 81;

    // Caps lock
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = min_led; i <= max_led; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }

        rgb_matrix_set_color(45, RGB_BLUE);
    }

    // FN Layer
    if (layer_state_is(ALL_FN)) {
        // Turn off all used
        rgb_matrix_set_color(16, RGB_OFF);
        rgb_matrix_set_color(17, RGB_OFF);
        rgb_matrix_set_color(18, RGB_OFF);
        rgb_matrix_set_color(62, RGB_OFF);

        switch (get_unicode_input_mode()) {
            case UC_MAC:
                rgb_matrix_set_color(16, RGB_WHITE);
                break;
            case UC_LNX:
                rgb_matrix_set_color(17, RGB_WHITE);
                break;
            case UC_WIN:
                rgb_matrix_set_color(18, RGB_WHITE);
                break;
        }

        if (layer_state_is(ALL_CK)) {
            rgb_matrix_set_color(62, RGB_WHITE);
        }
    }

    // Keepad layer
    if (layer_state_is(ALL_KP)) {
        // Num lock off
        if (!host_keyboard_led_state().num_lock) {
            for (uint8_t i = min_led; i <= max_led; i++) {
                rgb_matrix_set_color(i, RGB_RED);
            }

            rgb_matrix_set_color(24, RGB_BLUE);
            return;
        }

        for (uint8_t i = min_led; i <= max_led; i++) {
            rgb_matrix_set_color(i, RGB_OFF);
        }

        // Numbers green
        rgb_matrix_set_color(37, RGB_GREEN);
        rgb_matrix_set_color(38, RGB_GREEN);
        rgb_matrix_set_color(39, RGB_GREEN);
        rgb_matrix_set_color(52, RGB_GREEN);
        rgb_matrix_set_color(53, RGB_GREEN);
        rgb_matrix_set_color(54, RGB_GREEN);
        rgb_matrix_set_color(66, RGB_GREEN);
        rgb_matrix_set_color(67, RGB_GREEN);
        rgb_matrix_set_color(68, RGB_GREEN);

        // Operators red
        rgb_matrix_set_color(25, RGB_RED);
        rgb_matrix_set_color(40, RGB_RED);
        rgb_matrix_set_color(55, RGB_RED);
        rgb_matrix_set_color(69, RGB_RED);

        // Numlock blue
        rgb_matrix_set_color(24, RGB_BLUE);
    }
}

