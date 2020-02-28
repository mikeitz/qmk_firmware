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
  KC_EQUAL_US, KC_QUOTE_US, KC_BSLASH_US, KC_MINUS_US, KC_LBRACKET_US, KC_RBRACKET_US, KC_GRAVE_US,
  KC_CMB
};

#define LAYER_BASE 0
#define LAYER_GAME 3
#define LAYER_NAV 4
#define LAYER_SYM 5
#define LAYER_FN 7
#define LAYER_MUS 15

#define CF(first, defs) \
  case first: switch(second) { \
    case 0: return first; \
    defs \
    default: return 0; \
  }
#define CS(second, combo) \
  case second: return combo;
#define CC(second) \
  case KC_##second: return C(KC_##second);

uint16_t get_combo(uint16_t first, uint16_t second) {
  switch (first) {
    CF(KC_F,
      CS(KC_D, KC_BSPC);
      CS(KC_S, KC_DEL);
      CS(KC_Z, C(KC_Z));

      CS(KC_M, KC_F1);
      CS(KC_COMMA, KC_F2);
      CS(KC_DOT, KC_F3);
      CS(KC_J, KC_F4);
      CS(KC_K, KC_F5);
      CS(KC_L, KC_F6);
      CS(KC_U, KC_F7);
      CS(KC_I, KC_F8);
      CS(KC_O, KC_F9);
      CS(KC_SCOLON, KC_F10);
      CS(KC_P, KC_F11);
      CS(KC_SLASH, KC_F12);

    );
    CF(KC_D,
      CS(KC_F, KC_TAB);
      CS(KC_S, S(KC_TAB));
    );
    CF(KC_K,
      CS(KC_J, KC_ENT);
    );
    CF(KC_J,
      CS(KC_K, KC_ESC);
    );
    default: return 0;
  }
}

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
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CMB,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(LAYER_GAME),
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

bool combos = false;

#define ISMOD(k) (k == KC_LSFT || k == KC_RSFT || k == KC_LALT || k == KC_RALT || k == KC_LCTL || k == KC_RCTL)

struct combo_t {
  uint8_t state;
  uint16_t first;
  uint16_t second;
};
struct combo_t combo_alpha = { 0, 0, 0 };
struct combo_t combo_rctl = { 0, 0, 0 };
struct combo_t combo_ralt = { 0, 0, 0 };
struct combo_t combo_lctl = { 0, 0, 0 };
struct combo_t combo_lalt = { 0, 0, 0 };

bool handle_combo(uint16_t keycode, bool pressed, struct combo_t* combo) {
  if (ISMOD(keycode)) return true;
  switch (combo->state) {
    case 1: {
      if (pressed && get_combo(combo->first, keycode) != 0) {
        combo->state = 2;
        combo->second = keycode;
        return false;
      } else {
        register_code(combo->first);
        combo->state = 0;
        return true;
      }
    }
    case 2: {
      if (!pressed && keycode == combo->second) {
        tap_code16(get_combo(combo->first, combo->second));
        combo->state = 3;
        return false;
      } else if (!pressed && keycode == combo->first) {
        tap_code(combo->first);
        register_code(combo->second);
        combo->state = 0;
        return false;
      } else {
        register_code(combo->first);
        register_code(combo->second);
        combo->state = 0;
        return true;
      }
    }
    case 3: {
      uint16_t code = get_combo(combo->first, keycode);
      if (code != 0) {
        pressed ? register_code16(code) : unregister_code16(code);
        return false;
      } else if (!pressed && keycode == combo->first) {
        combo->state = 0;
        return false;
      } else {
        return true;
      }
    }
    default: {
      if (pressed && get_combo(keycode, 0) != 0) {
        combo->state = 1;
        combo->first = keycode;
        return false;
      } else {
        return true;
      }
    }
  }
}

bool handle_combo_mod(uint16_t mod, uint16_t modkey, uint16_t keycode, bool pressed, struct combo_t* combo) {
  if (keycode >= 0xB0 || ISMOD(keycode)) return true;
  switch (combo->state) {
    case 1: {
      if (pressed) {
        combo->state = 2;
        combo->second = keycode;
        return false;
      } else if (!pressed && keycode == combo->first) {
        combo->state = 0;
        tap_code16(combo->first);
        return false;
      } else {
        return true;
      }
    }
    case 2: {
      if (!pressed && keycode == combo->second) {
        register_code16(mod);
        tap_code16(combo->second);
        combo->state = 3;
        return false;
      } else if (!pressed && keycode == combo->first) {
        tap_code16(combo->first);
        register_code16(combo->second);
        combo->state = 0;
        return false;
      } else {
        register_code16(combo->first);
        register_code16(combo->second);
        combo->state = 0;
        return true;
      }
    }
    case 3: {
      if (!pressed && keycode == combo->first) {
        combo->state = 0;
        unregister_code16(mod);
        return false;
      } else {
        return true;
      }
    }
    default: {
      if (pressed && modkey == keycode) {
        combo->state = 1;
        combo->first = keycode;
        return false;
      } else {
        return true;
      }
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (combos) {
    if (!handle_combo(keycode, record->event.pressed, &combo_alpha)) {
      return false;
    }
    /*if (!handle_combo_mod(KC_LCTL, KC_A, keycode, record->event.pressed, &combo_lctl)) {
      return false;
    }
    if (!handle_combo_mod(KC_LALT, KC_Z, keycode, record->event.pressed, &combo_lalt)) {
      return false;
    }
    if (!handle_combo_mod(KC_RCTL, KC_SCOLON, keycode, record->event.pressed, &combo_rctl)) {
      return false;
    }
    if (!handle_combo_mod(KC_RALT, KC_SLASH, keycode, record->event.pressed, &combo_ralt)) {
      return false;
    }*/
  }

  switch (keycode) {
    UNSHIFT(KC_EQUAL_US, KC_EQUAL);
    UNSHIFT(KC_QUOTE_US, KC_QUOTE);
    UNSHIFT(KC_BSLASH_US, KC_BSLASH);
    UNSHIFT(KC_MINUS_US, KC_MINUS);
    UNSHIFT(KC_LBRACKET_US, KC_LBRACKET);
    UNSHIFT(KC_RBRACKET_US, KC_RBRACKET);
    UNSHIFT(KC_GRAVE_US, KC_GRAVE);
    case KC_CMB:
      if (record->event.pressed) combos = !combos;
      return false;
    default:
      return true;
  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}