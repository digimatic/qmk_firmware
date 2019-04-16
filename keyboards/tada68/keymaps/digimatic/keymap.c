#include QMK_KEYBOARD_H

#define _SV 0   // Base layer: Swedish (default)
#define _SVD 1  // Base layer: Svdvorak
#define _US 2   // Base layer: US ANSI
#define _DV 3   // Base layer: Dvorak ANSI
#define _FL 4   // Function layer
#define _MAC 5  // Mac layer, switches win and alt
#define _FK 6   // Function keys (on 1-9, 0 ...)

// investigate later - use lctl / lsft as up/down.
// https://github.com/qmk/qmk_firmware/tree/master/keyboards/tada68/keymaps/fakb
#define LCTL_MA LCTL_T(KC_UP)
#define LSFT_MA LSFT_T(KC_DOWN)

//#define aa UC(0xC4)
//#define ae UC(0xC5)
//#define oe UC(0xD6)

/*const uint32_t PROGMEM unicode_map[] = {
  [aa] = 0xC4,
  [ae] = 0xC5,
  [oe] = 0xD6,
  [AA] = 0xE4,
  [AE] = 0xE5,
  [OE] = 0xF6
};*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _US: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |    |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|Fn |Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   *
   * Note: Shift + Esc = ~
   *       Win   + Esc = `
   */
[_US] = LAYOUT_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_GRV,  \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL , \
  KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,      KC_PGUP, \
  KC_LSPO,          KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,  KC_UP,  KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(_FL), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

/*
 Dvorak (ANSI)
,----------------------------------------------------------------.
|    | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|       |~ ` |
|----------------------------------------------------------------|
|     |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|  \  |    |
|----------------------------------------------------------------|
|       |  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|       |    |
|----------------------------------------------------------------|
|        |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|      |   |    |
|----------------------------------------------------------------|
|    |    |    |                       |   |   |    |   |   |    |
`----------------------------------------------------------------'
*/
[_DV] = LAYOUT_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_LBRC,  KC_RBRC, KC_BSPC, KC_GRV,  \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT ,KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_SLSH,  KC_EQL,  KC_BSLS, KC_DEL , \
  KC_LCTL, KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_MINS,       KC_ENT,      KC_PGUP, \
  KC_LSFT,          KC_SCLN, KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,     KC_RSFT, KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(_FL), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

[_SV] = LAYOUT_ansi( // This is the default layer
          KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_INS , \
          KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_NUHS, KC_DEL,  \
  LT(_FL,KC_NUBS), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,      KC_ENT,       KC_PGUP, \
          KC_LSFT      ,    KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,  KC_PGDN, \
          KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(_FL), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

[_SVD] = LAYOUT_ansi(
          KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_GRV , \
          KC_TAB,  KC_LBRC, KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_NUHS,  KC_RBRC, KC_NUBS, KC_DEL,  \
  LT(_FL,KC_SCLN), KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_SLSH,      KC_ENT,       KC_PGUP, \
          KC_LSFT      ,    KC_QUOT, KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,     KC_RSFT,  KC_UP,  KC_PGDN, \
          KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(_FL), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),




  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |Brk |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  Del |~ ` |
   * |----------------------------------------------------------------|
   * |Fkeys|BL |BL-|BL+|Brt|   |   |   |mac|Pau|PSc|BL-|BL+|BL   |Ins |
   * |----------------------------------------------------------------|
   * |CAPS  |us |sv |   |   |   |<- |Dn |Up | ->|   |Brt|        |Hme |
   * |----------------------------------------------------------------|
   * |        |dv |svd|   |   |Br-|Br+|V- |V+ |MUT|   |      |PUp|End |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hme|PDn|End |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12, KC_DEL, KC_GRV,  \
  TG(_FK), _______, _______, _______, _______, _______, _______, _______, TG(_MAC),KC_PAUSE, KC_PSCR, BL_DEC, BL_INC , BL_TOGG,  KC_INS,  \
  KC_CAPS, DF(_US), DF(_SV), _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, BL_BRTG,     _______,      KC_HOME, \
  _______, DF(_DV), DF(_SVD),_______, _______, _______, KC_SLCK, KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE,  _______,     KC_PGUP,      KC_END , \
  _______, _______, _______,                 _______,                     _______, _______,  _______, KC_HOME,     KC_PGDN,      KC_END ),

  /* Keymap _MAC: Mac Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Win |                       |Win |   |Alt|   |   |    |
   * `----------------------------------------------------------------'
   */
[_MAC] = LAYOUT_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_LCTL, KC_LALT, KC_LGUI,                        _______,                       KC_RGUI, _______, KC_RALT, _______, _______, _______),

[_FK] = LAYOUT_ansi(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,                        _______,                       _______, _______, _______, _______, _______, _______),

};


// Set unicode in Mac OS.
//void eeconfig_init_user(void) {
//  set_unicode_input_mode(UC_OSX);
//};
