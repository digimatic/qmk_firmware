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

    PW_LOWER,
    PW_LOWR=PW_LOWER,

    PW_RAISE,
    PW_RAIS=PW_RAISE,

    PW_ADJUST,
    PW_ADJ=PW_ADJUST,

    PW_LPAR,    // (
    PW_RPAR,    // )

    PW_LBRA,    // {
    PW_RBRA,    // }

    PW_LSQ,     // [
    PW_RSQ,     // ]

    PW_LT,      // <
    PW_GT,      // >

    PW_PIPE,    // /
    PW_BSLS     // backslash
  //  PW_TILD
};

#define FL_NUBS LT(_FL, SE_LABK)  // Hold:Function-layer Tap:Oo (< key)
#define FL_LABK LT(_FL, SE_LABK)  // Hold:Function-layer Tap:Oo (< key)
#define CTL_LT MT(MOD_LCTL,SE_LABK)
#define BREAK MT(MOD_LCTL,KC_PAUS)

#define SVD_OE LT(_FL, KC_SCLN)
//#define PW_PIPE RALT(SE_LABK)   // On windows, not mac

#define TOP RCTL(KC_HOME)
#define BOTTOM RCTL(KC_END)
#define FL_SPACE LT(_FL,KC_SPC)    // Hold:Funtion-layer Tap:Space
#define FL_SPC FL_SPACE

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

#define RALT_1 RALT(KC_1)
#define RALT_2 RALT(KC_2)
#define RALT_3 RALT(KC_3)
#define RALT_4 RALT(KC_4)
#define RALT_5 RALT(KC_5)
#define RALT_6 RALT(KC_6)
#define RALT_7 RALT(KC_7)
#define RALT_8 RALT(KC_8)
#define RALT_9 RALT(KC_9)
#define RALT_0 RALT(KC_0)
#define PW_TILD RALT(SE_DIAE)

bool process_digimatic_keycode(uint16_t keycode, bool pressed);

// forward declared, to be implemented by keymap
bool isMac(void);
bool isSvdvorak(void);

