/* Copyright 2019 Mike Itz
 *
 * This program is free software: you can redistribute it and/or modify
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
#include "tiller.h"
#include "qmk_midi.h"

// -path:keyboards -path:users -path:layouts -path:docs

enum custom_keycodes {
  KC_OCT_0 = SAFE_RANGE, KC_OCT_1, KC_OCT_2, KC_OCT_3, KC_OCT_4,
  KC_CH_0, KC_CH_1, KC_CH_2, KC_CH_3,
  KC_CH_4, KC_CH_5, KC_CH_6, KC_CH_7,
  KC_CC_FOLLOW_ON, KC_CC_FOLLOW_OFF, KC_PLAY, KC_REC,
  KC_ALL_OFF,
};

#define LAYER_BASE 0
#define LAYER_GAME 3
#define LAYER_NAV 4
#define LAYER_SYM 5
#define LAYER_FN 7
#define LAYER_MUS 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
      CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,
      KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B,
      KC_LGUI, KC_LSFT, MO(LAYER_NAV),

      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENT,
      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_DEL,
      MO(LAYER_SYM), KC_SPC, MO(LAYER_FN)
    ),

    [LAYER_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, XXXXXXX,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX,
      _______, _______, _______,

      KC_ASTERISK, KC_7, KC_8, KC_9, KC_PLUS, _______,
      KC_MINUS, KC_4, KC_5, KC_6, KC_0, _______,
      KC_SLASH, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      _______, XXXXXXX, KC_HOME, KC_UP, KC_END, KC_PGUP,
      _______, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,
      _______, KC_LSFT, C(KC_X), C(KC_C), C(KC_V), XXXXXXX,
      _______, _______, _______,

      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_EQUAL, KC_PLUS, _______,
      XXXXXXX, KC_DQUO, KC_QUOTE, KC_MINUS, KC_UNDERSCORE, _______,
      XXXXXXX, KC_PIPE, KC_LT, KC_GT, KC_BSLASH, _______,
      _______, _______, _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, TG(LAYER_GAME),
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______,

      _______, KC_F7, KC_F8, KC_F9, KC_F11, _______,
      _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
      _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
      _______, _______, _______
    ),

    [LAYER_MUS] = LAYOUT(
      KC_ALL_OFF, KC_OCT_0, KC_OCT_1, KC_OCT_2, KC_OCT_3, KC_OCT_4,
      _______, KC_CH_0, KC_CH_1, KC_CH_2, KC_CH_3, KC_CC_FOLLOW_ON,
      _______, KC_CH_4, KC_CH_5, KC_CH_6, KC_CH_7, KC_CC_FOLLOW_OFF,
      KC_STOP, KC_LSFT, KC_REC,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_GAME] = LAYOUT(
      KC_ESC, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______,
      KC_LSFT, _______, _______, _______, _______, _______,
      KC_LALT, KC_SPC, KC_LCTL,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return true;
  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}
