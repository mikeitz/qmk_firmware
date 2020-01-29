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
#include "tiller.h"
#include "qmk_midi.h"

// -path:keyboards -path:users -path:layouts -path:docs

enum custom_keycodes {
  KC_OCT_0 = SAFE_RANGE, KC_OCT_1, KC_OCT_2, KC_OCT_3, KC_OCT_4,
  KC_CH_0, KC_CH_1, KC_CH_2, KC_CH_3,
  KC_CH_4, KC_CH_5, KC_CH_6, KC_CH_7,
  KC_CC_FOLLOW_ON, KC_CC_FOLLOW_OFF, KC_PLAY, KC_REC,
  KC_ALL_OFF,
  KC_UNSFT_TAB,
};

#define LAYER_BASE 0
#define LAYER_CM 1
#define LAYER_GAME 3

#define LAYER_SYM 4
#define LAYER_SYM_THUMB 5
#define LAYER_NAV 6
#define LAYER_FN 7
#define LAYER_SFT_THUMB 8

#define LAYER_MUS 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
      CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,
      KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
      KC_LALT, SFT_T(KC_BSPC), LT(LAYER_NAV, KC_DEL),

      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, LT(LAYER_FN, KC_BSLASH),
      LT(LAYER_NAV, KC_ENT), LT(LAYER_SYM, KC_SPC), KC_LGUI
    ),

    [LAYER_SYM] = LAYOUT(
      KC_ESC, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, KC_PIPE,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX,
      _______, C(KC_BSPC), C(KC_DEL),

      KC_CIRCUMFLEX, KC_7, KC_8, KC_9, KC_PLUS, KC_EQUAL,
      KC_AMPERSAND, KC_4, KC_5, KC_6, KC_0, KC_ASTERISK,
      XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, MO(LAYER_FN),
      _______, _______, _______
    ),

    [LAYER_SYM_THUMB] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, SFT_T(KC_BSPC), LT(LAYER_NAV, KC_DEL),

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SFT_THUMB] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      KC_TAB, KC_UNSFT_TAB, _______
    ),

    [LAYER_NAV] = LAYOUT(
      A(KC_F4), KC_BSPC, C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_DEL,
      CTL_T(KC_ENT), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______,

      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_BSPC), KC_BSPC,
      XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, S(KC_DEL), KC_DEL,
      XXXXXXX, S(KC_TAB), KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,
      S(KC_ENT), S(KC_SPC), _______
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

  if (layer_state_is(LAYER_SYM) && keycode != C(KC_BSPC) && keycode != C(KC_DEL)) {
    layer_on(LAYER_SYM_THUMB);
  }
  if (keycode != KC_TAB && keycode != KC_UNSFT_TAB) {
    layer_off(LAYER_SFT_THUMB);
  }

  bool interrupted = last_keycode != keycode;
  if (record->event.pressed) {
    last_keycode = keycode;
  } else if (keycode == last_keycode) {
    last_keycode = -1;
  }

  switch (keycode) {

    case LT(LAYER_SYM, KC_SPC):
      if (!record->event.pressed) layer_off(LAYER_SYM_THUMB);
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
      if (record->event.pressed) layer_on(LAYER_SFT_THUMB);
      RETRO_TAP_MOD(KC_BSPC, KC_LSFT);
      return true;

    case CTL_T(KC_ESC):
      RETRO_TAP_MOD(KC_ESC, KC_LCTL);
      return true;

    case KC_UNSFT_TAB:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        tap_code(KC_TAB);
        register_code(KC_LSFT);
      }
      return false;

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

/*
inline bool layer_is_on(layer_state_t  state, uint8_t layer) {
  return state & (1UL << layer);
}

inline bool layer_has_turned_on(layer_state_t  before, layer_state_t after, uint8_t layer) {
  return !layer_is_on(before, layer) && layer_is_on(after, layer);
}

layer_state_t  last_layer_state = 0;
layer_state_t  layer_state_set_user(layer_state_t  state) {
  layer_state_t before = last_layer_state;
  last_layer_state = state;
  if (!layer_is_on(state, LAYER_SYM) && layer_is_on(state, LAYER_SYM_THUMB)) {
    layer_off(LAYER_SYM_THUMB);
  } else if (layer_has_turned_on(before, state, LAYER_SYM) && !layer_is_on(state, LAYER_SYM_THUMB)) {
    layer_on(LAYER_SYM_THUMB);
  }
  return last_layer_state;
}
*/

/*
    [LAYER_SYM_ALL] = LAYOUT(
      // Layout that moves right outermost columns into the middle
      // by depending on the number keys on the nav layer.
      KC_ESC, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, XXXXXXX,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX,
      _______, C(KC_BSPC), C(KC_DEL),

      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_PLUS, KC_MINUS, _______,
      XXXXXXX, KC_DQUO, KC_UNDERSCORE, KC_EQUAL, KC_QUOTE, _______,
      XXXXXXX, KC_PIPE, KC_LT, KC_GT, KC_BSLASH, MO(LAYER_FN),
      _______, _______, _______
    ),

    [LAYER_NAV_ALL] = LAYOUT(
      A(KC_F4), KC_BSPC, C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_DEL,
      CTL_T(KC_ENT), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
      _______, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______,

      XXXXXXX, KC_7, KC_8, KC_9, KC_MINUS, _______,
      XXXXXXX, KC_4, KC_5, KC_6, KC_0, KC_PGUP,
      XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, KC_PGDN,
      S(KC_TAB), KC_TAB, _______
    ),
*/