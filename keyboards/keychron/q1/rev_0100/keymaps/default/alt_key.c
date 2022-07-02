
void send_keypad_number(uint8_t number) {
    switch (number) {
        case 0:
            register_code(KC_KP_0);
            unregister_code(KC_KP_0);
            break;
        case 1:
            register_code(KC_KP_1);
            unregister_code(KC_KP_1);
            break;
        case 2:
            register_code(KC_KP_2);
            unregister_code(KC_KP_2);
            break;
        case 3:
            register_code(KC_KP_3);
            unregister_code(KC_KP_3);
            break;
        case 4:
            register_code(KC_KP_4);
            unregister_code(KC_KP_4);
            break;
        case 5:
            register_code(KC_KP_5);
            unregister_code(KC_KP_5);
            break;
        case 6:
            register_code(KC_KP_6);
            unregister_code(KC_KP_6);
            break;
        case 7:
            register_code(KC_KP_7);
            unregister_code(KC_KP_7);
            break;
        case 8:
            register_code(KC_KP_8);
            unregister_code(KC_KP_8);
            break;
        case 9:
            register_code(KC_KP_9);
            unregister_code(KC_KP_9);
            break;
    }
}

void send_alt_code(uint8_t code1, uint8_t code2, uint8_t code3, uint8_t code4) {
    register_code(KC_LALT);

    send_keypad_number(code1);
    send_keypad_number(code2);
    send_keypad_number(code3);
    send_keypad_number(code4);

    unregister_code(KC_LALT);
}
