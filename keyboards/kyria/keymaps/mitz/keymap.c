/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum custom_keycodes {
  KC_UNUSED = SAFE_RANGE,
};

#define LAYER_BASE 0
#define LAYER_NAV 3
#define LAYER_SYM 4
#define LAYER_FN 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [LAYER_BASE] = LAYOUT(
       KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
       CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,                               KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENT,
       KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_DEL, S(KC_TAB), KC_TAB, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, LT(LAYER_FN, KC_DEL),
       KC_ENT, KC_LALT, KC_LGUI, KC_LSFT, MO(LAYER_NAV), MO(LAYER_SYM), KC_SPC, KC_LGUI, KC_LALT, KC_ENT
     ),
     [LAYER_NAV] = LAYOUT(
       _______, XXXXXXX, KC_HOME, KC_UP, KC_END, KC_PGUP,                                        KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_EQUAL, KC_PLUS, _______,
       _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                                    XXXXXXX, KC_DQUO, KC_QUOTE, KC_MINUS, KC_UNDERSCORE, _______,
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, KC_PIPE, KC_LT, KC_GT, KC_BSLASH, _______,
                                  _______, _______, _______, _______, KC_BSPC, KC_TAB, _______, _______, _______, _______
     ),
     [LAYER_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,                                           KC_ASTERISK, KC_7, KC_8, KC_9, KC_PLUS, _______,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, XXXXXXX,                                             KC_MINUS, KC_4, KC_5, KC_6, KC_0, _______,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX, _______, _______, _______, _______, KC_SLASH, KC_1, KC_2, KC_3, KC_DOT, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
     [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7, KC_F8, KC_F9, KC_F11, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
}
#endif


#define RETRO_TERM 200
#define RETRO_ELAPSED TIMER_DIFF_16(record->event.time, retro_timer)
#define RETRO_SET retro_timer = record->event.time
#define RETRO_TAP(kc) \
  if (record->event.pressed) { RETRO_SET; } \
  else { if (!interrupted && RETRO_ELAPSED >= TAPPING_TERM && RETRO_ELAPSED < RETRO_TERM) { tap_code(kc); } }
#define RETRO_TAP_MOD(kc, mod) \
  if (record->event.pressed) { RETRO_SET; } \
  else { if (!interrupted && RETRO_ELAPSED >= TAPPING_TERM && RETRO_ELAPSED < RETRO_TERM) { unregister_code(mod); tap_code(kc); } }

static uint16_t last_keycode = -1;
static uint16_t retro_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!host_keyboard_led_state().num_lock) {
    tap_code(KC_NLCK);
  }

  bool interrupted = last_keycode != keycode;
  if (record->event.pressed) {
    last_keycode = keycode;
  } else if (keycode == last_keycode) {
    last_keycode = -1;
  }

  switch (keycode) {

    case LT(LAYER_SYM, KC_SPC):
      RETRO_TAP(KC_SPC);
      return true;

    case LT(LAYER_NAV, KC_ENT):
      RETRO_TAP(KC_ENT);
      return true;

    case LT(LAYER_NAV, KC_DEL):
      RETRO_TAP(KC_DEL);
      return true;

    case LT(LAYER_FN, KC_BSLASH):
      RETRO_TAP(KC_BSLASH);
      return true;

    case SFT_T(KC_BSPC):
      RETRO_TAP_MOD(KC_BSPC, KC_LSFT);
      return true;

    case CTL_T(KC_ESC):
      RETRO_TAP_MOD(KC_ESC, KC_LCTL);
      return true;

    default:
      return true;

  }
}