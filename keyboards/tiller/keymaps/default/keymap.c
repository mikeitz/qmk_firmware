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
  KC_STAB = SAFE_RANGE, KC_UNSFT_TAB,
  KC_16, KC_27, KC_38, KC_49, KC_50,
  KC_OCT_0, KC_OCT_1, KC_OCT_2, KC_OCT_3, KC_OCT_4,
  KC_CH_0, KC_CH_1, KC_CH_2, KC_CH_3,
  KC_CH_4, KC_CH_5, KC_CH_6, KC_CH_7,
  KC_CC_FOLLOW_ON, KC_CC_FOLLOW_OFF, KC_PLAY, KC_REC,
  KC_ALL_OFF,
};

#define KC_NAV_ENT LT(LAYER_NAV, KC_ENT)
#define KC_NAV_ESC LT(LAYER_NAV, KC_ESC)
#define KC_SYM_SPC LT(LAYER_SYM, KC_SPC)
//#define KC_SFT_BSPC SFT_T(KC_BSPC)
//#define KC_CTL_DEL CTL_T(KC_DEL)
#define KC_ALT_TAB LM(LAYER_CTLALT, MOD_LALT)

#define LAYER_BASE 0
#define LAYER_CM 1

#define LAYER_SYM 3
#define LAYER_NAV 4
#define LAYER_FN 5
#define LAYER_CTLALT 12
#define LAYER_SFT 13
#define LAYER_GAME 14
#define LAYER_MUS 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_BSPC, KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX,
      LT(LAYER_MUS, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, XXXXXXX,
      KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ALT_TAB, LM(LAYER_SFT, MOD_LSFT), LM(LAYER_CTLALT, MOD_LCTL),

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      XXXXXXX, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      XXXXXXX, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_EQUAL,
      KC_NAV_ENT, KC_SYM_SPC, MO(LAYER_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [LAYER_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT, _______,
      KC_TILDE, KC_HASH, KC_PIPE, KC_LPRN, KC_RPRN, KC_DOLLAR, _______,
      KC_GRAVE, KC_BSLASH, KC_AMPERSAND, KC_LBRACKET, KC_RBRACKET, KC_KP_SLASH, _______,
      _______, _______, _______, _______, KC_SPC, C(KC_BSPC), C(KC_DEL),

      _______, KC_CIRCUMFLEX, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, KC_KP_MINUS,
      _______, KC_EQUAL, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0, KC_KP_PLUS,
      _______, KC_KP_SLASH, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, KC_KP_ENTER,
      _______, _______, _______, _______, _______, _______,
    ),
    
    [LAYER_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      LCTL_T(KC_TAB), _______, _______, _______, _______, _______, _______,
      S(KC_TAB), _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, KC_LALT, KC_LSFT, KC_LCTL,

      _______, KC_BSPC, C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_DEL, KC_DEL,
      _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, S(KC_DEL),
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_CTLALT] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______, _______,
      KC_STAB, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_SFT] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,
      KC_UNSFT_TAB /*ctl_t tab*/, _______, _______, _______, _______, _______, _______,
      KC_TAB /*s tab*/, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_MUS] = LAYOUT(
      KC_ALL_OFF, KC_OCT_0, KC_OCT_1, KC_OCT_2, KC_OCT_3, KC_OCT_4, _______,
      _______, KC_CH_0, KC_CH_1, KC_CH_2, KC_CH_3, KC_CC_FOLLOW_ON, _______,
      _______, KC_CH_4, KC_CH_5, KC_CH_6, KC_CH_7, KC_CC_FOLLOW_OFF, _______,

      _______, _______, _______, _______, KC_STOP, KC_LSFT, KC_REC,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_FN] = LAYOUT(
      KC_PAUS, KC_INS, _______, _______, _______, _______, _______,
      KC_CLCK, KC_APP, _______, _______, _______, TG(LAYER_GAME), _______,
      KC_NLCK, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,

      _______, KC_F10, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_SLCK,
      _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_RCTL, KC_RALT,
      _______, KC_F12, KC_F1, KC_F2, KC_F3, KC_RSFT, KC_RGUI,
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

static const uint8_t digits[] = {
  KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_6, KC_7, KC_8, KC_9, KC_0
};

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
  } else if (keycode == last_keycode) {
    last_keycode = -1;
  }

  switch (keycode) {

    /*case KC_SFT_BSPC:
      RETRO_TAP(KC_BSPC);
      ALSO_LAYER(LAYER_SFT);
      return true; // continue processing normally

    case KC_CTL_DEL:
      RETRO_TAP(KC_DEL);
      ALSO_LAYER(LAYER_CTLALT);
      return true; // continue processing normally

    case KC_NAV_ESC:
      RETRO_TAP(KC_ESC);
      return true; // continue processing normally*/

    case KC_NAV_ENT:
      RETRO_TAP(KC_ENT);
      return true; // continue processing normally

    case KC_SYM_SPC:
      RETRO_TAP(KC_SPC);
      return true; // continue processing normally

    case KC_STAB:
      if (record->event.pressed) {
        RETRO_SET;
        register_code(KC_LSFT);
      } else {
        if (RETRO_ELAPSED < TAPPING_TERM && !interrupted) {
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
        } else if (RETRO_ELAPSED < TAPPING_TERM) {
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

    case KC_16 ... KC_50:
      if (record->event.pressed) {
        if (get_mods() & MOD_LSFT) {
          unregister_code(KC_LSFT);
          tap_code(digits[keycode - KC_16 + 5]);
          register_code(KC_LSFT);
        } else {
          tap_code(digits[keycode - KC_16]);
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