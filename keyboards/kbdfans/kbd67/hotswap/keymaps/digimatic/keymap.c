/* Copyright 2019 MechMerlin
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
#include "digimatic.h"

enum { _SV = 0, _SVD, _US, _DV = _US, _FL, _MAC, _FK };

// clang-format off
// 16
// 15
// 14
// 14
// 9
// Sum 68

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_SV] = LAYOUT(
         ESC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PAUSE,KC_BSPC, KC_INS,  \
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,          KC_DEL,  \
  LT(_FL,KC_NUBS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP, \
         SHIFT_LP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SHIFT_RP,                   KC_UP,   KC_PGDN, \
          KC_LCTL, KC_LGUI, KC_LALT,                LT(_FL,KC_SPC),            KC_RALT,             MO(_FL),                   KC_LEFT, KC_DOWN, KC_RGHT),

[_SVD] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PAUSE,KC_BSPC, KC_INS,  \
  KC_TAB,  KC_LBRC, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NUHS, KC_RBRC, KC_NUBS,          KC_DEL,  \
  SVD_OE,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,          KC_ENT,           KC_PGUP, \
SHIFT_LP,  KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_SLSH,SHIFT_RP,                   KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                        KC_RALT, MO(_FL),                        KC_LEFT, KC_DOWN, KC_RGHT),

[_US] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_HOME, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN, \
 SHIFT_LP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SHIFT_RP,                   KC_UP,   KC_END,  \
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                        KC_RALT, MO(_FL),                        KC_LEFT, KC_DOWN, KC_RGHT),

// todo: _DV

[_MAC] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, \
  KC_LCTL, KC_LALT, KC_LGUI,                   _______,                       KC_RALT, _______,                        _______, _______, _______),

[_FL] = LAYOUT(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,C(KC_PAUSE),_______, C(KC_INS),\
  TG(_FK), KC_BTN1, KC_BTN2, KC_BTN3, C(KC_R), _______, QK_BOOT, _______, TG(_MAC),KC_PAUSE,KC_PSCR, _______, _______, PW_PIPE           , _______,  \
  KC_CAPS, PW_BSLS, PW_LT  , PW_LSQ , PW_LBRA, PW_LPAR, PW_RPAR, PW_RBRA, PW_RSQ , PW_GT  , PW_PIPE, SE_LABK,        C(KC_F5)            , KC_HOME,  \
SHIFT_LP2, DF(_SV),DF(_SVD), DF(_US), _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE,SHIFT_RP2,                  TOP      , KC_END ,  \
  _______, _______, _______,                   _______,                       KC_LGUI, _______,                        KC_HOME, BOTTOM   , KC_END ),

[_FK] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, \
  _______, _______, _______,                   _______,                       _______, _______,                        _______, _______, _______),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (process_digimatic_keycode(keycode, record->event.pressed)) {
        return false;
    } else {
        if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
            set_keylog(keycode, record);
#endif
            // set_timelog();
        }
        return true;
    }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

bool isMac(void)
{
  return layer_state_is(_MAC);
}

bool isSvdvorak(void) { return layer_state_is(_SVD); }
