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
enum custom_keycodes { QWERTY = SAFE_RANGE, COLEMAK };

#define LAYER_QWERTY 0
#define LAYER_COLEMAK 2

#define LAYER_NAV 3
#define LAYER_NUM 4
#define LAYER_WIN 5
#define LAYER_LAST 9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_QWERTY] = LAYOUT(/* Base */
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_ESC,
      KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, LM(LAYER_WIN, MOD_LALT),
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LM(LAYER_WIN, MOD_LCTL),
      KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(LAYER_NUM), MO(LAYER_NAV), KC_LCTL,

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      MO(LAYER_NAV), KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      MO(LAYER_NUM), KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, SFT_T(KC_BSLASH),
      KC_ENT, KC_SPC, KC_TAB, KC_LGUI, XXXXXXX, XXXXXXX, MO(LAYER_NUM)
    ),

    [LAYER_NUM] = LAYOUT(
      KC_TILDE, KC_1, KC_2, KC_3, KC_4, KC_5, _______,
      _______, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, _______,
      _______, KC_ENT, S(KC_TAB), KC_TAB, KC_SPC, KC_LALT, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PLUS,
      _______, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LPRN, KC_RPRN, KC_EQUAL,
      _______, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, KC_LCBR, KC_RCBR, KC_PIPE,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      KC_ESC, _______, C(KC_LEFT), KC_UP, C(KC_RIGHT), _______, A(KC_F4), 
      KC_DEL, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
      _______, KC_ENT, S(KC_TAB), KC_TAB, KC_SPC, KC_LALT, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
      _______, KC_F11, KC_F12, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_WIN] = LAYOUT(
      _______, _______, _______, _______, S(KC_TAB), KC_TAB, _______,
      _______, _______, _______, _______, S(KC_TAB), KC_TAB, _______,
      _______, _______, _______, _______, S(KC_TAB), KC_TAB, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_LAST] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_COLEMAK);
      }
      return false;
      break;
    }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
