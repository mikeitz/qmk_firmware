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
  KC_EQUAL_US, KC_QUOTE_US, KC_BSLASH_US, KC_MINUS_US, KC_LBRACKET_US, KC_RBRACKET_US, KC_GRAVE_US
};

#define LAYER_BASE 0
#define LAYER_TAB 1
#define LAYER_GAME 3
#define LAYER_GAME2 4
#define LAYER_GAME3 5
#define LAYER_NAV 12
#define LAYER_SYM 13
#define LAYER_FN 14
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
      _______, KC_TILDE, KC_GRAVE_US, KC_LBRACKET_US, KC_RBRACKET_US, XXXXXXX,
      _______, _______, _______,

      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_EQUAL_US, KC_PLUS, _______,
      XXXXXXX, KC_DQUO, KC_QUOTE_US, KC_MINUS_US, KC_UNDERSCORE, _______,
      XXXXXXX, KC_PIPE, KC_LT, KC_GT, KC_BSLASH_US, _______,
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      _______, A(KC_F4), C(KC_LEFT), KC_UP, C(KC_RIGHT), XXXXXXX,
      CTL_T(KC_ENT), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
      _______, KC_LSFT, KC_SPC, KC_PGUP, KC_PGDN, XXXXXXX,
      _______, _______, _______,  

      XXXXXXX, KC_7, KC_8, KC_9, KC_MINUS, _______,
      XXXXXXX, KC_4, KC_5, KC_6, KC_0, CTL_T(KC_ENT),
      XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, SFT_T(KC_SPC), _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(LAYER_GAME2),
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(LAYER_GAME),
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(LAYER_GAME3),
      _______, _______, _______,

      XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F11, _______,
      XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F10, _______,
      XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, _______,
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

    [LAYER_TAB] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, SFT_T(KC_TAB), S(KC_TAB),

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
      _______, LT(LAYER_NAV, KC_SPC), _______
    ),

    [LAYER_GAME2] = LAYOUT(
      KC_ESC, KC_T, KC_Q, KC_W, KC_E, KC_R,
      KC_TAB, KC_LSFT, KC_A, KC_S, KC_D, KC_F,
      KC_G, KC_Z, KC_X, KC_C, KC_V, KC_B,
      KC_LALT, KC_SPC, KC_LCTL,
      
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, LT(LAYER_NAV, KC_SPC), _______
    ),

    [LAYER_GAME3] = LAYOUT(
      KC_ESC, KC_TAB, KC_Q, KC_W, KC_E, XXXXXXX,
      KC_1, KC_LSFT, KC_A, KC_S, KC_D, KC_F,
      KC_V, KC_2, KC_Z, KC_LCTL, KC_X, XXXXXXX,
      XXXXXXX, KC_SPC, KC_T,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______
    )
};

#define UNSHIFT(x, y) case x: \
  if (record->event.pressed) { \
    if (get_mods() & MOD_LSFT) { \
      unregister_code(KC_LSFT); \
      register_code(y); \
      register_code(KC_LSFT); \
    } else { \
      register_code(y); \
    } \
  } else { \
    unregister_code(y); \
  } return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    UNSHIFT(KC_EQUAL_US, KC_EQUAL);
    UNSHIFT(KC_QUOTE_US, KC_QUOTE);
    UNSHIFT(KC_BSLASH_US, KC_BSLASH);
    UNSHIFT(KC_MINUS_US, KC_MINUS);
    UNSHIFT(KC_LBRACKET_US, KC_LBRACKET);
    UNSHIFT(KC_RBRACKET_US, KC_RBRACKET);
    UNSHIFT(KC_GRAVE_US, KC_GRAVE);

    case CTL_T(KC_TAB):
    case CTL_T(KC_ESC):
    case KC_LALT:
      record->event.pressed ? layer_on(LAYER_TAB) : layer_off(LAYER_TAB);
      return true;

    case KC_OCT_0 ... KC_OCT_4:
      if (record->event.pressed) tiller_set_octave(keycode - KC_OCT_0);
      return false;

    case KC_CH_0 ... KC_CH_7:
      if (record->event.pressed) {
        uint8_t ch = keycode - KC_CH_0 + ((get_mods() & MOD_LSFT) ? 8 : 0);
        tiller_set_channel(ch);
        midi_send_cc(&midi_device, 15, 101 + ch, 127);
      }
      return false;

    case KC_STOP:
      if (record->event.pressed) midi_send_cc(&midi_device, 14, 102, 127);
      return false;

    case KC_REC:
      if (record->event.pressed) midi_send_cc(&midi_device, 14, 101, 127);
      return false;

    case KC_ALL_OFF:
      if (record->event.pressed) tiller_all_notes_off();
      return false;

    case KC_CC_FOLLOW_OFF:
      if (record->event.pressed) tiller_set_cc_follows_channel(false);
      return false;

    case KC_CC_FOLLOW_ON:
      if (record->event.pressed) tiller_set_cc_follows_channel(true);
      return false;
      
    default:
      return true;
  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}