// @sdk66, @iamdanielv & @irfanjmdn

#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

void keyboard_post_init_user(void) {
    debug_enable = false;
    debug_matrix = false;
}

enum layer_names {
    BASE = 0,
    CAPS,
    FN,
    RSFT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    MO(CAPS),KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, MO(RSFT), KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(FN),KC_LEFT, KC_DOWN, KC_RGHT
),

[CAPS] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_PSCR,
    _______, _______, _______, KC_END,  KC_F5,   _______, _______, KC_PGUP, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_MPRV, KC_MNXT, KC_MPLY, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______,
    _______, KC_CALC, KC_WHOM, _______, _______, _______, KC_PGDN, KC_MUTE, _______, _______, _______, KC_CAPS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[FN] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[RSFT] = LAYOUT(
    KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, MS_WHLU, MS_UP,   MS_WHLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MS_BTN3, _______, _______, _______,
    _______, _______, _______, _______, MS_BTN2, MS_BTN1, _______, _______, _______
),

/*
[_EMPTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
),
*/
};

#ifdef CONSOLE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  return true;
}
#endif
