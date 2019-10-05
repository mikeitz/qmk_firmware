/* Copyright 2019 Mike Itz
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QMKBEST = SAFE_RANGE, QMKURL };

#define LAYER_SYM 2
#define LAYER_NUM 1
#define LAYER_FN 3
#define LAYER_NUM2 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */

      LT(LAYER_NUM2, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, MO(LAYER_FN),
      LT(LAYER_SYM, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,
      KC_LCTRL, KC_LWIN, KC_LALT, KC_ENT, ALT_T(KC_SPC), CTL_T(KC_BSPC), LT(LAYER_NUM, KC_DEL),

      MO(LAYER_FN), KC_Y, KC_U, KC_I, KC_O, KC_P, LT(LAYER_NUM2, KC_MINUS),
      KC_NO, KC_H, KC_J, KC_K, KC_L, LT(LAYER_NUM, KC_SCOLON), LT(LAYER_SYM, KC_QUOTE),
      KC_NO, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, SFT_T(KC_BSLASH),
      LT(LAYER_NUM, KC_ENT), KC_SPC, KC_LWIN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),

    [LAYER_NUM] = LAYOUT(
      KC_ESC, C(KC_BSPC), C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_HOME, A(KC_F4),
      KC_TAB, KC_SPC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_F2,
      KC_LSFT, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_BSPC, KC_NO,
      KC_LCTRL, KC_LWIN, KC_LALT, KC_ENT, ALT_T(KC_SPC), CTL_T(KC_BSPC), SFT_T(KC_DEL),

      KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
      KC_NO, KC_0, KC_4, KC_5, KC_6, KC_0, KC_ENTER,
      KC_NO, KC_0, KC_1, KC_2, KC_3, KC_0, KC_RSFT,
      SFT_T(KC_ENT), CTL_T(KC_SPC), KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),

    [LAYER_SYM] = LAYOUT(
      KC_ESC, KC_EXCLAIM, KC_AT, KC_HASH, KC_LBRACKET, KC_RBRACKET, A(KC_F4),
      KC_TAB, KC_SPC, KC_DOLLAR, KC_PERCENT, KC_LPRN, KC_RPRN, KC_F2,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO,
      KC_LCTRL, KC_LWIN, KC_LALT, KC_ENT, ALT_T(KC_SPC), CTL_T(KC_BSPC), SFT_T(KC_DEL),

      KC_NO, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_PLUS, KC_EQUAL, KC_MINUS,
      KC_NO, KC_NO, KC_TILDE, KC_GRAVE, KC_NO, KC_NO, KC_QUOTE,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLASH,
      SFT_T(KC_ENT), CTL_T(KC_SPC), KC_LWIN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),


    [LAYER_FN] = LAYOUT(
      KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, A(KC_F4),
      KC_TAB, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F2,
      KC_LSFT, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_LCTRL, KC_LWIN, KC_LALT, KC_ENT, KC_LALT, KC_LCTRL, KC_LSFT,

      KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC,
      KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_ENTER,
      KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_RSFT,
      KC_LSFT, KC_LCTRL, KC_LWIN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),

    [LAYER_NUM2] = LAYOUT(
      KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
      KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

      KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
      KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [9] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
