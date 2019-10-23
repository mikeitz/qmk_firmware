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
enum custom_keycodes { BASE = SAFE_RANGE };

#define LAYER_BASE 0
#define LAYER_GAME 1

#define LAYER_NAV 3
#define LAYER_NUM 4
#define LAYER_ALPHA_TOP 14
#define LAYER_LAST 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(/* Base */
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX,
      KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, XXXXXXX,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, MO(LAYER_NAV), KC_LCTL,

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      XXXXXXX, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      XXXXXXX, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH,
      LT(LAYER_NUM, KC_ENT), KC_SPC, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [LAYER_GAME] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, KC_SPC, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, MO(LAYER_NAV), _______, _______, _______, _______, _______
    ),

    [LAYER_NUM] = LAYOUT(
      KC_TILDE, KC_1, KC_2, KC_3, KC_4, KC_5, _______,
      _______, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PLUS,
      _______, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LPRN, KC_RPRN, KC_EQUAL,
      _______, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, KC_LCBR, KC_RCBR, MO(LAYER_NAV),
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      KC_ESC, KC_HOME, C(KC_LEFT), KC_UP, C(KC_RIGHT), A(KC_F4), _______,
      KC_DEL, KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
      LM(LAYER_ALPHA_TOP, MOD_LGUI), KC_ENT, S(KC_TAB), KC_TAB, KC_SPC, G(KC_L), _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F12,
      TG(LAYER_GAME), _______, KC_LCTL, KC_LSFT, KC_LALT, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_ALPHA_TOP] = LAYOUT(
      _______, KC_Q, KC_W, KC_E, KC_R, KC_T, _______,
      _______, KC_A, KC_S, KC_D, KC_F, KC_G, _______,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      _______, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      _______, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH,
      KC_TAB, KC_SPC, KC_ENT, _______, _______, _______, _______
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
    )

    /*[LAYER_BASE] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_ESC,
      KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, LM(LAYER_WIN, MOD_LALT),
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LM(LAYER_WIN, MOD_LCTL),
      KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(LAYER_NUM), MO(LAYER_NAV), KC_LCTL,

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      MO(LAYER_NAV), KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      MO(LAYER_NUM), KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, SFT_T(KC_BSLASH),
      KC_ENT, KC_SPC, KC_TAB, KC_LGUI, XXXXXXX, XXXXXXX, MO(LAYER_NUM)
    ),*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_BASE);
      }
      return false;
      break;
    }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
