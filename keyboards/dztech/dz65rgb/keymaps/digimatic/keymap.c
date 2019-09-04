#include QMK_KEYBOARD_H
#include "digimatic.h"

enum { _SV = 0, _SVD, _US, _DV = _US, _FL, _MAC, _FK };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_SV] = LAYOUT_65_ansi( /* Base */
         ESC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,      KC_BSPC,      KC_INS,  \
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,          KC_DEL,  \
  LT(_FL,KC_NUBS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP, \
         SHIFT_LP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SHIFT_RP,                   KC_UP,   KC_PGDN, \
          KC_LCTL, KC_LGUI, KC_LALT,                LT(_FL,KC_SPC),            KC_RALT,             MO(_FL), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),

[_SVD] = LAYOUT_65_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,       KC_BSPC,     KC_INS,  \
  KC_TAB,  KC_LBRC, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NUHS, KC_RBRC, KC_NUBS,          KC_DEL,  \
  SVD_OE,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,          KC_ENT,           KC_PGUP, \
SHIFT_LP,  KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_SLSH,SHIFT_RP,                   KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                        KC_RALT, MO(_FL), KC_RCTL,               KC_LEFT, KC_DOWN, KC_RGHT),

[_US] = LAYOUT_65_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,        KC_DEL,     KC_HOME, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN, \
 SHIFT_LP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SHIFT_RP,                   KC_UP,   KC_END,  \
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                        KC_RALT, MO(_FL), KC_RCTL,               KC_LEFT, KC_DOWN, KC_RGHT),

// todo: _DV

[_MAC] = LAYOUT_65_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,  \
  KC_LCTL, KC_LALT, KC_LGUI,                   _______,                       KC_RALT, _______, _______,               _______, _______, _______),

[_FL] = LAYOUT_65_ansi(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,    _______,      C(KC_INS), \
  TG(_FK), KC_BTN1, KC_BTN2, KC_BTN3, RESET,   _______, _______, _______, TG(_MAC),RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD,BL_TOGG,_______, \
  KC_CAPS, DF(_US), DF(_SV), _______, EEP_RST, _______, _______, _______, KC_MPLY, KC_MSTP, KC_MPRV,  KC_MNXT,         _______,         KC_HOME, \
SHIFT_LP2, DF(_DV), DF(_SVD),_______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE,SHIFT_RP2,                  TOP,     KC_END,  \
  _______, _______, _______,                   _______,                       KC_LGUI, _______, _______,                KC_HOME, BOTTOM, KC_END),

[_FK] = LAYOUT_65_ansi(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       _______,     _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,  \
  _______, _______, _______,                   _______,                       _______, _______, _______,               _______, _______, _______),

};
// clang-format on


/*			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,\
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,\
			CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,\
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,\
		    KC_LCTL,       KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT, MO(_FL),  KC_RCTL,    KC_LEFT,           KC_DOWN,   KC_RIGHT),*/
/*		[_FL] = LAYOUT_65_ansi(
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,\
		    KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, RESET,    KC_PGUP,\
			CTL_T(KC_CAPS),RGB_SPI,  RGB_SPD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_PGDN,\
		    KC_LSFT,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_VOLU,  KC_MUTE,\
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),*/


void rgb_matrix_indicators_user(void)
{
	    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
	    {
	      rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
	    }
}

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	  return true;
}

bool isMac(void)
{
  return layer_state_is(_MAC);
}
