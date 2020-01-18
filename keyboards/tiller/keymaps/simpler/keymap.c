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
  KC_STAB = SAFE_RANGE, KC_UNSFT_TAB, KC_MAYBE_STAB, KC_MAYBE_TAB,
  KC_OCT_0, KC_OCT_1, KC_OCT_2, KC_OCT_3, KC_OCT_4,
  KC_CH_0, KC_CH_1, KC_CH_2, KC_CH_3,
  KC_CH_4, KC_CH_5, KC_CH_6, KC_CH_7,
  KC_CC_FOLLOW_ON, KC_CC_FOLLOW_OFF, KC_PLAY, KC_REC,
  KC_ALL_OFF,
};

#define KC_SFT_BSPC SFT_T(KC_BSPC)
#define KC_CTL_DEL CTL_T(KC_DEL)

#define LAYER_BASE 0
#define LAYER_CM 1

#define LAYER_SYM 3
#define LAYER_NAV 4
#define LAYER_FN 5
#define LAYER_CTL 11
#define LAYER_ALT 12
#define LAYER_SFT 13
#define LAYER_GAME 14
#define LAYER_MUS 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
      KC_LALT, MO(LAYER_NAV), KC_ENT,

      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
      KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_BSPC,
      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT,
      KC_SPC, MO(LAYER_SYM), KC_LGUI
    ),

    //*
    [LAYER_SYM] = LAYOUT(
      KC_ESC, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, XXXXXXX,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX,
      _______, MO(LAYER_FN), _______,

      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_PLUS, KC_MINUS, _______,
      XXXXXXX, KC_DQUO, KC_UNDERSCORE, KC_EQUAL, KC_QUOTE, _______,
      XXXXXXX, KC_PIPE, XXXXXXX, XXXXXXX, KC_BSLASH, _______,
      _______, MO(LAYER_FN), _______
    ),

    /*[LAYER_NAV] = LAYOUT(
      KC_ESC, A(KC_F4), C(KC_LEFT), KC_UP, C(KC_RIGHT), XXXXXXX, 
      _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,
      _______, MO(LAYER_FN), _______,

      XXXXXXX, KC_7, KC_8, KC_9, KC_MINUS, _______,
      XXXXXXX, KC_4, KC_5, KC_6, KC_0, _______,
      XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, MO(LAYER_FN), _______
    ),*/

    [LAYER_NAV] = LAYOUT(
      KC_ESC, A(KC_F4), XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, 
      _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, MO(LAYER_FN), _______,

      XXXXXXX, KC_7, KC_8, KC_9, KC_MINUS, _______,
      XXXXXXX, KC_4, KC_5, KC_6, KC_0, _______,
      XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, MO(LAYER_FN), _______
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

    [LAYER_CTL] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_ALT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SFT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
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

#define RETRO_TERM 300
#define RETRO_ELAPSED TIMER_DIFF_16(record->event.time, retro_timer)
#define RETRO_SET retro_timer = record->event.time
#define RETRO_TAP(kc) \
  if (record->event.pressed) { RETRO_SET; } \
  else { if (!interrupted && RETRO_ELAPSED >= TAPPING_TERM && RETRO_ELAPSED < RETRO_TERM) { tap_code(kc); } }
#define ALSO_LAYER(layer) \
  if (record->event.pressed) { layer_on(layer); } else { layer_off(layer); }

static uint16_t last_keycode = -1;
static uint16_t retro_timer = 0;
static bool arm_maybe_tab = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!host_keyboard_led_state().num_lock) {
    tap_code(KC_NLCK);
  }

  bool interrupted = last_keycode != keycode;

  if (record->event.pressed) {
    if (interrupted && last_keycode == KC_UNSFT_TAB) {
      register_code(KC_LCTL);
    }
    last_keycode = keycode;
    if (arm_maybe_tab && keycode != KC_MAYBE_TAB && keycode != KC_MAYBE_STAB) {
      arm_maybe_tab = false;
    }
  } else if (keycode == last_keycode) {
    last_keycode = -1;
  }

  switch (keycode) {

    case LT(LAYER_NAV, KC_ENT):
      RETRO_TAP(KC_ENT);
      return true; // continue processing normally

    case LT(LAYER_SYM, KC_SPC):
      RETRO_TAP(KC_SPC);
      return true; // continue processing normally

    case KC_SFT_BSPC:
      RETRO_TAP(KC_BSPC);
      ALSO_LAYER(LAYER_SFT);
      arm_maybe_tab = true;
      return true; // continue processing normally

    case KC_CTL_DEL:
      RETRO_TAP(KC_DEL);
      ALSO_LAYER(LAYER_CTL);
      return true; // continue processing normally

    case KC_MAYBE_STAB:
      if (record->event.pressed) {
        tap_code16(arm_maybe_tab ? KC_TAB : KC_ENT);
      }
      return false;

    case KC_MAYBE_TAB:
      if (record->event.pressed) {
        if (arm_maybe_tab) {
          unregister_code(KC_LSFT);
          tap_code(KC_TAB);
          register_code(KC_LSFT);
        } else {
          tap_code(KC_SPC);
        }
      }
      return false;

    case KC_STAB:
      if (record->event.pressed) {
        RETRO_SET;
        register_code(KC_LSFT);
      } else {
        if (RETRO_ELAPSED < RETRO_TERM && !interrupted) {
          tap_code(KC_TAB);
        }
        unregister_code(KC_LSFT);
      }
      return false;

    case KC_UNSFT_TAB:
      if (record->event.pressed) {
        RETRO_SET;
        // will register control before the next keypress when interrupted
      } else {
        if (interrupted) {
          unregister_code(KC_LCTL);
        } else if (RETRO_ELAPSED < RETRO_TERM) {
          bool sfted = get_mods() & MOD_LSFT;
          if (sfted) {
            unregister_code(KC_LSFT);
          }
          tap_code(KC_TAB);
          if (sfted) {
            register_code(KC_LSFT);
          }       
        }
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