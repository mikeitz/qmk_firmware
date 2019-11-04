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

enum {
  TD_ALT_GUI = 0,
  TD_SFT_CTL = 1,
};

#define ACTION_TAP_DANCE_DOUBLE_SLOW(kc1, kc2) \
  { .fn = {qk_tap_dance_pair_on_each_tap, qk_tap_dance_pair_finished, qk_tap_dance_pair_reset}, \
    .user_data = (void *)&((qk_tap_dance_pair_t){kc1, kc2}), \
    .custom_tapping_term = 500, }

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ALT_GUI] = ACTION_TAP_DANCE_DOUBLE_SLOW(KC_LALT, KC_LGUI),
  [TD_SFT_CTL] = ACTION_TAP_DANCE_DOUBLE_SLOW(KC_LSFT, KC_LCTL),
};

#define LAYER_BASE 0
#define LAYER_COLEMAK 1

#define LAYER_NAV 3
#define LAYER_SYM 4
#define LAYER_GAME 12

#define LAYER_LAST 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      ALT_T(KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX,
      CTL_T(KC_DEL), KC_A, KC_S, KC_D, KC_F, KC_G, XXXXXXX,
      SFT_T(KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, SFT_T(KC_BSPC), CTL_T(KC_TAB),

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      XXXXXXX, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      XXXXXXX, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, XXXXXXX,
      LT(LAYER_NAV, KC_ENT), LT(LAYER_SYM, KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [LAYER_COLEMAK] = LAYOUT(
      _______, KC_Q, KC_W, KC_F, KC_P, KC_B, _______,
      _______, KC_A, KC_R, KC_S, KC_T, KC_G, _______,
      _______, KC_Z, KC_X, KC_C, KC_D, KC_V, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, _______,
      _______, KC_M, KC_N, KC_E, KC_I, KC_O, _______,
      _______, KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLASH, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_SYM] = LAYOUT(
      KC_TILDE, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_BSLASH, _______,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, KC_PIPE, _______,
      _______, KC_PERCENT, KC_CIRCUMFLEX, KC_LBRACKET, KC_RBRACKET, KC_AMPERSAND, _______,
      _______, _______, _______, _______, _______, KC_BSPC, KC_SPC,

      _______, KC_ASTERISK, KC_7, KC_8, KC_9, KC_EQUAL, _______,
      _______, KC_PLUS, KC_4, KC_5, KC_6, KC_0, KC_GRAVE,
      _______, KC_MINUS, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      _______, KC_HOME, C(KC_LEFT), KC_UP, C(KC_RIGHT), A(KC_F4), _______,
      _______, KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
      _______, S(KC_TAB), KC_TAB, KC_ENT, KC_SPC, _______, _______,
      _______, _______, _______, _______, _______, _______,  _______,


      _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F12,
      _______, TG(LAYER_GAME), TG(LAYER_COLEMAK), KC_LSFT, KC_LALT, KC_LCTL, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_GAME] = LAYOUT(
      KC_ESC, _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______, _______,
      KC_LSFT, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, KC_SPC, KC_LCTL, MO(LAYER_NAV),

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
    )
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
