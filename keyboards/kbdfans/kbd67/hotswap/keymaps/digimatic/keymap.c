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

enum { _SV = 0, _SVD, _US, _DV = _US, _FL, _MAC, _FK };

// Tap Dance Declarations
enum {
    TD_SHIFT_LP = 0,
    TD_SHIFT_RP,
};

typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    SINGLE_TAP  = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP  = 3,
    DOUBLE_HOLD = 4,
    //  DOUBLE_SINGLE_TAP = 5, //send two single taps
    TRIPLE_TAP  = 6,
    TRIPLE_HOLD = 7
};

int cur_dance(qk_tap_dance_state_t *state);

// for the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted && state->pressed) return SINGLE_HOLD;
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        /*
         * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
         * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
         * keystrokes of the key, and not the 'double tap' action/macro.
         */
        if (state->interrupted)
            return DOUBLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 8;  // magic number. At some point this method will expand to work for more presses
}

// instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {.is_press_action = true, .state = 0};

void lp_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_8);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
            register_code(KC_RALT);
            register_code(KC_7);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LSFT);
            break;
        case TRIPLE_TAP:
            register_code(KC_RALT);
            register_code(KC_8);
            break;
    }
}

void lp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_8);
            unregister_code(KC_LSFT);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_RALT);
            unregister_code(KC_7);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_LSFT);
        case TRIPLE_TAP:
            unregister_code(KC_8);
            unregister_code(KC_RALT);
            break;
    }
    xtap_state.state = 0;
}

void rp_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            register_code(KC_RSFT);
            register_code(KC_9);
            break;
        case SINGLE_HOLD:
            register_code(KC_RSFT);
            break;
        case DOUBLE_TAP:
            register_code(KC_RALT);
            register_code(KC_0);
            break;
        case DOUBLE_HOLD:
            register_code(KC_RSFT);
            break;
        case TRIPLE_TAP:
            register_code(KC_RALT);
            register_code(KC_9);
            break;
    }
}

void rp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_9);
            unregister_code(KC_RSFT);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RSFT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_RALT);
            unregister_code(KC_0);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_RSFT);
        case TRIPLE_TAP:
            unregister_code(KC_9);
            unregister_code(KC_RALT);
            break;
    }
    xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {[TD_SHIFT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lp_finished, lp_reset), [TD_SHIFT_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rp_finished, rp_reset)};

#define FL_NUBS LT(_FL, KC_NUBS)
#define SVD_OE LT(_FL, KC_SCLN)
#define PW_PIPE RALT(KC_NUBS)
#define SHIFT_LP TD(TD_SHIFT_LP)  // Hold:L-Shift  Tap:(  Double-tap:{  Triple-tap:[
#define SHIFT_RP TD(TD_SHIFT_RP)  // Hold:R-Shift  Tap:)  Double-tap:}  Triple-tap:]
#define TOP RCTL(KC_HOME)
#define BOTTOM RCTL(KC_END)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_SV] = LAYOUT(
          KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PAUSE,KC_BSPC, KC_INS,  \
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,          KC_DEL,  \
  LT(_FL,KC_NUBS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP, \
         SHIFT_LP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SHIFT_RP,                   KC_UP,   KC_PGDN, \
          KC_LCTL, KC_LGUI, KC_LALT,                LT(_FL,KC_SPC),            KC_RALT,             MO(_FL),                   KC_LEFT, KC_DOWN, KC_RGHT),

[_SVD] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PAUSE,KC_BSPC, KC_INS,  \
  KC_TAB,  KC_LBRC, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NUHS, KC_RBRC, KC_NUBS,          KC_DEL,  \
  SVD_OE,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,          KC_ENT,           KC_PGUP, \
SHIFT_LP, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_SLSH, SHIFT_RP,                   KC_UP,   KC_PGDN, \
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
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,  \
  KC_LCTL, KC_LGUI, KC_LGUI,                   _______,                       KC_RALT, _______,                        _______, _______, _______),

[_FL] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,C(KC_PAUSE),_______,C(KC_INS), \
  TG(_FK), _______, _______, _______, RESET,   _______, _______, _______, TG(_MAC),KC_PAUSE, KC_PSCR,_______, _______, PW_PIPE,          _______, \
  KC_CAPS, DF(_US), DF(_SV), _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_HOME, \
  _______, DF(_DV), DF(_SVD),_______, _______, _______, KC_SLCK, KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE, _______,                   TOP,     KC_END,  \
  _______, _______, _______,                   _______,                       KC_LGUI, _______,                        KC_HOME, BOTTOM, KC_END),

[_FK] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,  \
  _______, _______, _______,                   _______,                       _______, _______,                        _______, _______, _______),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
