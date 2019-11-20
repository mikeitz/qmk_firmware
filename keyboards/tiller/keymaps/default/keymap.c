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

enum custom_keycodes { ESC_STAB = SAFE_RANGE, };

enum {
  TD_ALT_GUI = 0,
};

#define ACTION_TAP_DANCE_DOUBLE_SLOW(kc1, kc2) \
  { .fn = {qk_tap_dance_pair_on_each_tap, qk_tap_dance_pair_finished, qk_tap_dance_pair_reset}, \
    .user_data = (void *)&((qk_tap_dance_pair_t){kc1, kc2}), \
    .custom_tapping_term = 500, }

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ALT_GUI] = ACTION_TAP_DANCE_DOUBLE_SLOW(KC_LALT, KC_LGUI),
};

#define LAYER_BASE 0
#define LAYER_COLEMAK 1

#define LAYER_NAV 3
#define LAYER_SYM 4
#define LAYER_FN 5
#define LAYER_GAME 12

#define LAYER_LAST 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_EQUAL, KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXXXX,
      CTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, XXXXXXX,
      ESC_STAB, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_ALT_GUI), LT(LAYER_NAV, KC_BSPC), CTL_T(KC_DEL),

      XXXXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      XXXXXXX, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      XXXXXXX, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_UNDERSCORE,
      SFT_T(KC_ENT), LT(LAYER_SYM, KC_SPC), MO(LAYER_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX 
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
      _______, KC_HASH, KC_AT, KC_LCBR, KC_RCBR, KC_CIRCUMFLEX, _______,
      _______, KC_AMPERSAND, KC_PIPE, KC_LPRN, KC_RPRN, KC_EXCLAIM, _______,
      _______, KC_PERCENT, KC_DOLLAR, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, _______,
      _______, _______, _______, _______, _______, KC_BSPC, KC_SPC,

      _______, KC_EQUAL, KC_7, KC_8, KC_9, KC_ASTERISK, _______,
      _______, KC_MINUS, KC_4, KC_5, KC_6, KC_0, _______,
      _______, KC_PLUS, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      KC_ESC, KC_ESC, KC_HOME, KC_UP, KC_END, _______, _______,
      _______, C(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, C(KC_RIGHT), _______,
      _______, KC_ENT, _______, _______, KC_SPC, _______, _______,
      _______, _______, _______, _______, _______, _______,  _______,


      _______, _______, KC_EQUAL, KC_ASTERISK, KC_GRAVE, KC_TILDE, _______,
      _______, KC_BSPC, KC_MINUS, KC_UNDERSCORE, KC_DQUO, KC_QUOTE, _______,
      _______, KC_DEL, KC_PLUS, KC_RSFT, KC_RALT, KC_RCTL, KC_RSFT,
      _______, CTL_T(KC_SPC), KC_LALT, _______, _______, _______, _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, TG(LAYER_COLEMAK), _______,
      _______, _______, _______, _______, _______, TG(LAYER_GAME), _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,


      _______, KC_F10, KC_F7, KC_F8, KC_F9, _______, _______,
      _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_LALT, _______,
      _______, KC_F12, KC_F1, KC_F2, KC_F3, _______, _______,
      _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_GAME] = LAYOUT(
      KC_ESC, _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______, _______,
      KC_LSFT, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, KC_LALT, KC_SPC, KC_LCTL,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
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

static uint16_t last_keycode = -1;
static uint16_t esc_stab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool interrupted = last_keycode != keycode;
  last_keycode = keycode;
  switch (keycode) {
    case ESC_STAB:
      if (record->event.pressed) {
        esc_stab_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        bool ctl_alt = get_mods() & (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT)|MOD_BIT(KC_RCTL)|MOD_BIT(KC_LCTL));
        ctl_alt |= layer_state_is(LAYER_NAV);
        bool timed_out = timer_elapsed(esc_stab_timer) > TAPPING_TERM;
        if (!timed_out && !interrupted && ctl_alt) {
          tap_code(KC_TAB);
        }
        unregister_code(KC_LSFT);
        if (!timed_out && !interrupted && !ctl_alt) {
          tap_code(KC_ESC);
        }
      }
      break;
    }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}