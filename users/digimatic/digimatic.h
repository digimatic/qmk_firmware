#pragma once

#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

// Tap Dance Declarations
enum {
    TD_ESC,
    TD_SHIFT_LP,
    TD_SHIFT_RP,
    TD_SHIFT_LPIPE,
    TD_SHIFT_RPIPE,
};

enum digimatic_keycodes {
    PW_AT = SAFE_RANGE, // @

    PW_LPAR,    // (
    PW_RPAR,    // )

    PW_LBRA,    // {
    PW_RBRA,    // }

    PW_LSQ,     // [
    PW_RSQ,     // ]

    PW_LT,      // <
    PW_GT,      // >

    PW_PIPE
};

#define FL_NUBS LT(_FL, KC_NUBS)  // Hold:Function-layer Tap:Oo (< key)
#define SVD_OE LT(_FL, KC_SCLN)
#define PW_PIPE RALT(KC_NUBS)

#define TOP RCTL(KC_HOME)
#define BOTTOM RCTL(KC_END)
#define FL_SPACE LT(_FL,KC_SPC)    // Hold:Funtion-layer Tap:Space

#ifdef TAP_DANCE_ENABLE
#define SHIFT_LP TD(TD_SHIFT_LP)  // Hold:L-Shift  Tap:(  Double-tap:{  Triple-tap:[
#define SHIFT_RP TD(TD_SHIFT_RP)  // Hold:R-Shift  Tap:)  Double-tap:}  Triple-tap:]
#define ESC_GRV TD(TD_ESC)
#define SHIFT_LP2 TD(TD_SHIFT_LPIPE)
#define SHIFT_RP2 TD(TD_SHIFT_RPIPE)
#else
#define ESC_GRV KC_ESC
#endif
#define FL_ENT LT(_RAISE, KC_ENT)

bool process_digimatic_keycode(uint16_t keycode, bool pressed);

// forward declared, to be implemented by keymap
bool isMac(void);
bool isSvdvorak(void);

