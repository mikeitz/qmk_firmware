#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_STAB = SAFE_RANGE, KC_UNSFT_TAB, KC_MAYBE_STAB, KC_MAYBE_TAB
};

#define KC_SFT_BSPC SFT_T(KC_BSPC)
#define KC_CTL_DEL CTL_T(KC_DEL)

#define LAYER_BASE 0
#define LAYER_CM 1

#define LAYER_SYM 3
#define LAYER_NAV 4
#define LAYER_FN 5
#define LAYER_ALT 11
#define LAYER_CTL 12
#define LAYER_SFT 13
#define LAYER_GUI 14

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
      LT(LAYER_NAV, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, KC_SCOLON, XXXXXXX,
      KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, XXXXXXX,
      LM(LAYER_ALT, MOD_LALT), KC_SFT_BSPC, KC_CTL_DEL,
      LT(LAYER_NAV, KC_ENT), LT(LAYER_SYM, KC_SPC), LT(LAYER_FN, KC_TAB)
    ),

    [LAYER_CM] = LAYOUT(
      _______, KC_Q, KC_W, KC_F, KC_P, KC_G,           KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, _______,
      _______, KC_A, KC_R, KC_S, KC_T, KC_D,           KC_H, KC_N, KC_E, KC_I, KC_O, _______,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_K, KC_M, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,           KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_TAB, KC_ESC, _______,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, _______,             _______, KC_DQUO, KC_QUOTE, KC_MINUS, KC_UNDERSCORE, _______,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, _______,     _______, KC_EQUAL, KC_PLUS, KC_PIPE, KC_BSLASH, _______,
      _______, C(KC_BSPC), C(KC_DEL),
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      KC_BSPC, KC_DEL, C(KC_LEFT), KC_UP, C(KC_RIGHT), A(KC_F4),     KC_PLUS, KC_7, KC_8, KC_9, KC_MINUS, _______,
      LCTL_T(KC_TAB), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,   KC_EQUAL, KC_4, KC_5, KC_6, KC_0, _______,
      KC_STAB, _______, _______, _______, _______, TG(LAYER_CM),     KC_SLASH, KC_1, KC_2, KC_3, KC_DOT, _______,
      _______, _______, _______,
      S(KC_TAB), KC_TAB, _______
    ),

    /*
    [LAYER_SYM] = LAYOUT(
      KC_GRAVE, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,              KC_CIRCUMFLEX, KC_7, KC_KP_8, KC_9, KC_ASTERISK, KC_MINUS,
      KC_TILDE, KC_HASH, KC_PIPE, KC_LPRN, KC_RPRN, KC_DOLLAR,                KC_EQUAL, KC_4, KC_5, KC_6, KC_0, KC_PLUS,
      _______, KC_BSLASH, KC_AMPERSAND, KC_LBRACKET, KC_RBRACKET, _______,    KC_SLASH, KC_1, KC_2, KC_3, KC_KP_DOT, KC_KP_ENTER,
      KC_SPC, C(KC_BSPC), C(KC_DEL),
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      KC_BSPC, KC_DEL, C(KC_LEFT), KC_UP, C(KC_RIGHT), A(KC_F4),                   KC_BSPC, C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_DEL, KC_DEL,
      LCTL_T(KC_TAB), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,           KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, S(KC_DEL),
      KC_STAB, _______, _______, _______, _______, TG(LAYER_CM),     _______, _______, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),
    */

    [LAYER_CTL] = LAYOUT(
      _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,
      KC_STAB, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_ALT] = LAYOUT(
      A(KC_F4), _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      KC_TAB, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,
      KC_STAB, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SFT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
      KC_UNSFT_TAB /*ctl_t tab*/, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      KC_TAB /*s tab*/, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,

      _______, _______, _______,
      KC_MAYBE_STAB, KC_MAYBE_TAB, _______
    ),

    [LAYER_GUI] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
      KC_L, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,

      KC_J, SFT_T(KC_M), KC_ENT,
      _______, _______, _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,      _______, KC_F7, KC_F8, KC_F9, KC_F11, _______,
      _______, _______, _______, _______, _______, _______,      _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
      _______, _______, _______, _______, _______, _______,      _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
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

    default:
      return true;

  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}