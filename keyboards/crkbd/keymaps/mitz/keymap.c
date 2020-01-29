#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_UNUSED = SAFE_RANGE, KC_UNSFT_TAB
};

#define LAYER_BASE 0
#define LAYER_CM 1

#define LAYER_SYM 3
#define LAYER_SYM_THUMB 4
#define LAYER_NAV 5
#define LAYER_FN 6
#define LAYER_SFT_THUMB 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_BASE] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
      CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
      KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,             KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH,
      KC_LGUI, SFT_T(KC_BSPC), LT(LAYER_NAV, KC_DEL),
      LT(LAYER_NAV, KC_ENT), LT(LAYER_SYM, KC_SPC), KC_LALT
    ),

    [LAYER_CM] = LAYOUT(
      _______, KC_Q, KC_W, KC_F, KC_P, KC_G,           KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, _______,
      _______, KC_A, KC_R, KC_S, KC_T, KC_D,           KC_H, KC_N, KC_E, KC_I, KC_O, _______,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_K, KC_M, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SYM] = LAYOUT(
      KC_ESC, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,            KC_CIRCUMFLEX, KC_7, KC_8, KC_9, KC_PLUS, KC_EQUAL,
      KC_LCTL, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, KC_PIPE,             KC_AMPERSAND, KC_4, KC_5, KC_6, KC_0, KC_ASTERISK,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX,     XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, MO(LAYER_FN),
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SYM_THUMB] = LAYOUT(
      _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_SFT_THUMB] = LAYOUT(
      _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      A(KC_F4), KC_BSPC, C(KC_LEFT), KC_UP, C(KC_RIGHT), KC_DEL,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_BSPC), KC_BSPC,
      CTL_T(KC_ENT), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,   XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, S(KC_DEL), KC_DEL,
      SFT_T(KC_SPC), KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, S(KC_TAB), KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______,
      KC_BSPC, KC_SPC, _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,         _______, KC_F7, KC_F8, KC_F9, KC_F11, _______,
      _______, _______, _______, _______, _______, _______,         _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
      _______, _______, _______, _______, _______, TG(LAYER_CM),    _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
      _______, _______, _______,
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

    default:
      return true;

  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}