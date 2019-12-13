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

// -path:keyboards -path:users -path:layouts -path:docs

enum custom_keycodes { KC_STAB = SAFE_RANGE };


#define LAYER_BASE 0

#define LAYER_NAV 3
#define LAYER_SYM 4
#define LAYER_FN 5
#define LAYER_TAB 13
#define LAYER_SFT 14
#define LAYER_GAME 15
#define LAYER_LAST 16

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_BSPC, KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX,
      LT(LAYER_NAV, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, XXXXXXX,
      LT(LAYER_SYM, KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LM(LAYER_TAB, MOD_LALT), LM(LAYER_SFT, MOD_LSFT), LM(LAYER_TAB, MOD_LCTL),

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      XXXXXXX, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, LT(LAYER_NAV, KC_QUOTE),
      XXXXXXX, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, LT(LAYER_SYM, KC_DEL),
      KC_ENT, KC_SPC, MO(LAYER_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [LAYER_SYM] = LAYOUT(
      KC_DEL, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT, _______,
      KC_LGUI, KC_CIRCUMFLEX, KC_PIPE, KC_LPRN, KC_RPRN, KC_DOLLAR, _______,
      _______, KC_BSLASH, KC_AMPERSAND, KC_LBRACKET, KC_RBRACKET, KC_HASH, _______,
      _______, _______, _______, _______, _______, KC_SPC, _______,

      _______, KC_TILDE, KC_KP_7, KC_KP_8, KC_KP_9, KC_PLUS, KC_EQUAL,
      _______, KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_GRAVE,
      _______, KC_KP_PLUS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, KC_COMMA,
      KC_KP_ENTER, KC_KP_0, KC_KP_DOT, _______, _______, _______, _______
      ),

    [LAYER_NAV] = LAYOUT(
      _______, _______, C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_DEL, _______,
      _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
      _______, _______, _______, _______, KC_ENT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, KC_HOME, KC_BSPC, KC_DEL, KC_END, KC_RWIN, _______,
      _______, _______, _______, KC_RCTL, KC_RALT, KC_RSFT, _______,
      _______, _______, KC_TAB, _______, _______, _______, _______
    ),

    [LAYER_TAB] = LAYOUT( // include zxcv so nav layer can easily copy/paste
      _______, _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, ALT_T(KC_DEL),
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_SFT] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      CTL_T(KC_TAB), _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, ALT_T(KC_DEL),
      _______, _______, _______, _______, _______, _______, _______
    ),


    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, TG(LAYER_GAME), _______,
      _______, _______, _______, _______, _______, KC_NLCK, _______,
      _______, _______, _______, _______, _______, _______, _______,


      _______, KC_F10, KC_F7, KC_F8, KC_F9, _______, _______,
      _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_LALT, KC_LGUI,
      _______, KC_F12, KC_F1, KC_F2, KC_F3, KC_LCTL, KC_LSFT,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_GAME] = LAYOUT(
      KC_ESC, _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______, _______,
      KC_LSFT, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, KC_LALT, KC_SPC, KC_LCTL,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, MO(LAYER_SYM),
      _______, MO(LAYER_NAV), _______, _______, _______, _______, _______
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
  if (!host_keyboard_led_state().num_lock) {
    tap_code(KC_NLCK);
  }
  switch (keycode) {
    // case KC_STAB:
    //  return false;
  }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}