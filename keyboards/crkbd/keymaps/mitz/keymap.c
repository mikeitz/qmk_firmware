#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_STAB = SAFE_RANGE, KC_UNSFT_TAB,
  KC_16, KC_27, KC_38, KC_49, KC_50
};

#define LAYER_BASE 0

#define LAYER_SYM 3
#define LAYER_NAV 4
#define LAYER_FN 5
#define LAYER_CTLALT 12
#define LAYER_SFT 13

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_BSPC, KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      LT(LAYER_NAV, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B,                        KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_EQUAL,

      LM(LAYER_CTLALT, MOD_LALT), LM(LAYER_SFT, MOD_LSFT), LM(LAYER_CTLALT, MOD_LCTL),  
      LT(LAYER_NAV, KC_ENT), LT(LAYER_SYM, KC_SPC), MO(LAYER_FN)
    ),

    [LAYER_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,                      KC_CIRCUMFLEX, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, KC_KP_MINUS,
      CTL_T(KC_GRAVE), KC_HASH, KC_PIPE, KC_LPRN, KC_RPRN, KC_DOLLAR,                       KC_EQUAL, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0, KC_KP_PLUS,
      KC_TILDE, KC_BSLASH, KC_AMPERSAND, KC_LBRACKET, KC_RBRACKET, _______,          KC_KP_SLASH, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, KC_KP_ENTER,

      _______, KC_BSPC, KC_DEL,
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      _______, KC_DEL, C(KC_LEFT), KC_UP, C(KC_RIGHT), A(KC_F4),             _______, _______, _______, _______, _______, _______,
      LCTL_T(KC_TAB), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,           KC_PGUP, KC_BSPC, KC_DEL, KC_HOME, KC_END, _______,
      KC_LGUI, KC_50, KC_49, KC_38, KC_27, KC_16,                            KC_PGDN, S(KC_TAB), KC_TAB, _______, _______, _______,
      
      ALT_T(KC_BSPC), SFT_T(KC_SPC), CTL_T(KC_ENT),
      RCTL_T(KC_ENT), RSFT_T(KC_SPC), KC_RALT
    ),

    [LAYER_CTLALT] = LAYOUT( // include zxcv so nav layer can easily copy/paste
      _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,
      KC_STAB, KC_Z, KC_X, KC_C, KC_V, KC_B,                          _______, _______, _______, _______, _______, _______,

      _______, _______, _______,
      _______, RSFT_T(KC_SPC), _______
    ),

    [LAYER_SFT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
      KC_UNSFT_TAB /*ctl_t tab*/, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      KC_TAB /*s tab*/, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
       

      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_FN] = LAYOUT(
      KC_PAUS, _______, _______, _______, _______, _______,           KC_F10, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_SLCK,
      KC_CLCK, KC_APP, KC_INS, _______, _______, _______,             KC_F11, KC_F4, KC_F5, KC_F6, KC_RCTL, KC_RALT,
      KC_NLCK, _______, _______, _______, _______, _______,           KC_F12, KC_F1, KC_F2, KC_F3, KC_RSFT, KC_RGUI,

      _______, _______, _______,
      _______, _______, _______
    )
};

static const uint8_t digits[] = {
  KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_6, KC_7, KC_8, KC_9, KC_0
};

#define RETRO_TERM 300
#define RETRO_ELAPSED TIMER_DIFF_16(record->event.time, retro_timer)
#define RETRO_SET retro_timer = record->event.time
static uint16_t last_keycode = -1;
static uint16_t retro_timer = 0;

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

    case LT(LAYER_SYM, KC_SPC):
      if (record->event.pressed) {
        RETRO_SET;
      } else {
        if (!interrupted && RETRO_ELAPSED >= TAPPING_TERM && RETRO_ELAPSED < RETRO_TERM) {
          tap_code(KC_SPC);
        }
      }
      return true; // continue processing normally

    case LT(LAYER_NAV, KC_ESC):
      if (record->event.pressed) {
        RETRO_SET;
      } else if (!interrupted && RETRO_ELAPSED >= TAPPING_TERM && RETRO_ELAPSED < RETRO_TERM) {
        tap_code(KC_ESC);
      }
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

    default:
      return true;

  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}