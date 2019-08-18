#pragma once

#include QMK_KEYBOARD_H

// Tap Dance Declarations
enum {
    TD_ESC,
    TD_SHIFT_LP,
    TD_SHIFT_RP,
};

#define FL_NUBS LT(_FL, KC_NUBS)  // Hold:Function-layer Tap:Oo
#define SVD_OE LT(_FL, KC_SCLN)
#define PW_PIPE RALT(KC_NUBS)
#define SHIFT_LP TD(TD_SHIFT_LP)  // Hold:L-Shift  Tap:(  Double-tap:{  Triple-tap:[
#define SHIFT_RP TD(TD_SHIFT_RP)  // Hold:R-Shift  Tap:)  Double-tap:}  Triple-tap:]
#define TOP RCTL(KC_HOME)
#define BOTTOM RCTL(KC_END)
#define FL_SPACE LT(_FL,KC_SPC)    // Hold:Funtion-layer Tap:Space
