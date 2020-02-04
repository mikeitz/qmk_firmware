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
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENT,
      KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,             KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, MO(LAYER_FN),
      KC_LGUI, MO(LAYER_NAV), KC_LSFT,
      KC_SPC, MO(LAYER_SYM), KC_LALT
    ),

    [LAYER_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_LCBR, KC_RCBR, KC_PERCENT,           KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_EQUAL, KC_PLUS, KC_DEL,
      _______, KC_HASH, KC_DOLLAR, KC_LPRN, KC_RPRN, KC_PIPE,             XXXXXXX, KC_DQUO, KC_QUOTE, KC_UNDERSCORE, KC_MINUS, _______,
      _______, KC_TILDE, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_BSLASH, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_NAV] = LAYOUT(
      _______, XXXXXXX, KC_HOME, KC_UP, KC_END, KC_PGUP,            XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, _______,
      _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,        XXXXXXX, KC_4, KC_5, KC_6, KC_0, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, _______,
      _______, _______, _______,
      _______, _______, _______
    ),

    [LAYER_FN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,         _______, KC_F7, KC_F8, KC_F9, KC_F11, _______,
      _______, _______, _______, _______, _______, _______,         _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
      _______, _______, _______, _______, _______, _______,         _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
      _______, _______, _______,
      _______, _______, _______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}