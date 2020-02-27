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
      _______, KC_TILDE, KC_GRAVE_US, KC_LBRACKET_US, KC_RBRACKET_US, XXXXXXX,
      _______, _______, _______,

      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_EQUAL_US, KC_PLUS, _______,
      XXXXXXX, KC_DQUO, KC_QUOTE_US, KC_MINUS_US, KC_UNDERSCORE, _______,
      XXXXXXX, KC_PIPE, KC_LT, KC_GT, KC_BSLASH_US, _______,
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      KC_BSPC, KC_DEL, C(KC_LEFT), KC_UP, C(KC_RIGHT), XXXXXXX,
      CTL_T(KC_ENT), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
      _______, KC_TAB, S(KC_TAB), KC_PGUP, KC_PGDN, XXXXXXX,
      _______, _______, _______,

      XXXXXXX, KC_7, KC_8, KC_9, KC_MINUS, _______,
      KC_TAB, KC_4, KC_5, KC_6, KC_0, CTL_T(KC_ENT),
      S(KC_TAB), KC_1, KC_2, KC_3, KC_DOT, _______,

      _______, SFT_T(KC_SPC), _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, CMB_TOG,
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
      _______, LT(LAYER_NAV, KC_SPC), _______
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

uint8_t combo_state = 0;
uint16_t combo_first = 0;
uint16_t combo_second = 0;

// df tab, sf bspc, sd del
// kj ent, kl esc
// COMBO_FIRST(KC_D);
// COMBO_FIRST(KC_S);
// COMBO_FIRST(KC_K);
// COMBO_SECOND(KC_S, KC_F, KC_BSPC);
// COMBO_SECOND(KC_S, KC_D, KC_DEL);
// COMBO_SECOND(KC_D, KC_F, KC_TAB);
// COMBO_SECOND(KC_K, KC_J, KC_ENT);
// COMBO_SECOND(KC_K, KC_L, KC_ESC);

// state 0
// A pressed, do nothing, enter state 1
bool handle_combo_zero(uint16_t keycode, bool pressed) {
  if (pressed && keycode == KC_S) {
    combo_state = 1;
    combo_first = keycode;
    return false;
  } else {
    return true;
  }
}

#define ISMOD(k) k == KC_LSFT || k == KC_RSFT || k == KC_LALT || k == KC_RALT || k == KC_LCTL || k == KC_RCTL

// state 1 (A)
// mod keys change, handle normally and remain in state 1
// B pressed, do nothing, enter state 2
// another unknown key pressed, register A and clear state
bool handle_combo_one(uint16_t keycode, bool pressed) {
  if (ISMOD(keycode)) return true;
  if (pressed && (keycode == KC_F || keycode == KC_D)) {
    combo_state = 2;
    combo_second = keycode;
    return false;
  } else {
    register_code(combo_first);
    combo_state = 0;
    return true;
  }
}

// state 2 (AB)
// mod keys change, handle normally and remain in state 2
// B released, tap combo code and enter state 3
// A released, tap A and register B and clear state
// another unknown key pressed, register A and B and clear state
bool handle_combo_two(uint16_t keycode, bool pressed) {
  if (ISMOD(keycode)) return true;
  if (!pressed && keycode == combo_second) {
    if (combo_second == KC_F) tap_code(KC_BSPC);
    if (combo_second == KC_D) tap_code(KC_DEL);
    combo_state = 3;
    return false;
  } else if (!pressed && keycode == combo_first) {
    tap_code(combo_first);
    register_code(combo_second);
    combo_state = 0;
    return false;
  } else {
    register_code(combo_first);
    register_code(combo_second);
    combo_state = 0;
    return true;
  }
}

// state 3 (A)
// mod keys change, handle normally and remain in state 3
// B pressed, tap combo code and remain in state 3
// A released, clear state
// another unknown key pressed, (clear state, ignore key, and/or handle normally)
bool handle_combo_three(uint16_t keycode, bool pressed) {
  if (ISMOD(keycode)) return true;
  if (keycode == KC_F || keycode == KC_D) {
    if (combo_second == KC_F) pressed ? register_code(KC_BSPC) : unregister_code(KC_BSPC);
    if (combo_second == KC_D) pressed ? register_code(KC_DEL) : unregister_code(KC_DEL);
    return false;
  } else if (!pressed && keycode == combo_first) {
    combo_state = 0;
    return false;
  } else {
    return true;
  }
}

bool handle_combo(uint16_t keycode, bool pressed) {
  switch (combo_state) {
    case 1: return handle_combo_one(keycode, pressed);
    case 2: return handle_combo_two(keycode, pressed);
    case 3: return handle_combo_three(keycode, pressed);
    default: return handle_combo_zero(keycode, pressed);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!handle_combo(keycode, record->event.pressed)) {
    return false;
  }

  switch (keycode) {
    UNSHIFT(KC_EQUAL_US, KC_EQUAL);
    UNSHIFT(KC_QUOTE_US, KC_QUOTE);
    UNSHIFT(KC_BSLASH_US, KC_BSLASH);
    UNSHIFT(KC_MINUS_US, KC_MINUS);
    UNSHIFT(KC_LBRACKET_US, KC_LBRACKET);
    UNSHIFT(KC_RBRACKET_US, KC_RBRACKET);
    UNSHIFT(KC_GRAVE_US, KC_GRAVE);
    default:
      return true;
  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}
