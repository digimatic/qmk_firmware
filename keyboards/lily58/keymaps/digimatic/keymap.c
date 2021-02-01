#include QMK_KEYBOARD_H
#include "digimatic.h"
#include <stdio.h>
#include "lily58.h"
#include <keymap_swedish.h>

#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#ifdef SSD1306OLED
#    include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
    _SV = 0,
    _SVD,
    _MAC,
    _LOWER,
    _FL = _LOWER,  // 1 Lower
    _RAISE,        // 2
    _RAISESVD,     // 3
    _ADJUST,       // 4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off

/* QWERTY / SV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ESC/§ |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LOWER/< | A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|  Del  |    |BackSP |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtl | LGUI | LAlt | /Space/ /       \Enter/\  | RAlt |RAISE | RCtl |
 *                   |      |      |      |/ LOWER /         \LOWER \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_SV] = LAYOUT( \
 ESC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, \
 KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG, \
 FL_NUBS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA, \
 KC_LSHIFT,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_DEL,   KC_BSPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_MINS, KC_SFTENT,\
                        KC_LCTL, KC_LGUI, KC_LALT, FL_SPACE,           FL_ENT,   KC_RALT,MO(_RAISE),KC_RCTL \
),

 [_SVD] = LAYOUT( \
 _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, \
 _______,  SE_ARNG, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    SE_QUOT, \
 SVD_OE ,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    SE_MINS, \
 _______,  SE_ADIA, KC_Q,    KC_J,    KC_K,    KC_X, KC_DEL,   KC_BSPC,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, \
                        _______, _______, _______, FL_SPACE,           FL_ENT,   _______,MO(_RAISESVD),_______ \
),

 [_MAC] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                        _______, KC_LALT, KC_LGUI, _______,           _______,  _______, _______, _______ \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  §   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |PnScn |ScLock|Pause |                    |      |      |      |      | ^    | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  <   |  [   |  {   |  (   |-------.    ,-------|  )   |  }   |  ]   |  >   | |    |  Ä   |
 * |------+------+------+------+------+------|       |    | Del   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  SE_SECT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_F12,  \
  _______, _______, PW_LT,   PW_LSQ,  PW_LBRA, PW_LPAR,                   PW_RPAR, PW_RBRA, PW_RSQ,  PW_GT,   PW_PIPE, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, \
                        _______, _______, _______, _______,          _______,  _______, _______, _______\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |   ´  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   ¨  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down | Up   | Rght |   '  |
 * |------+------+------+------+------+------|       |    |ADJUST |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
 _______,    ALGR(KC_1), ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), ALGR(KC_5),                    ALGR(KC_6), ALGR(KC_7), ALGR(KC_8), ALGR(KC_9), ALGR(KC_0), SE_ACUT, \
 _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                          KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       SE_DIAE, \
 KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                         KC_INS,     KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT,    SE_QUOT, \
 _______,    _______,    _______,    _______,    _______,    _______, _______, TG(_ADJUST), _______,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     _______,\
                           _______, _______, _______, _______,          _______, _______, _______, _______ \
),

[_RAISESVD] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, SE_ACUT, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_DIAE, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     _______, _______, _______, _______, _______, SE_LABK, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,_______,TG(_ADJUST),_______, _______, _______, _______, _______, _______, \
                        _______, _______, _______, _______,          _______,  _______, _______, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |SV/SVD|      |      |      |      |                    | VOL+ |  7   |   8  |   9  |RGB ON| HUE+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | MUTE |  4   |   5  |   6  | MODE | HUE- |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| VOL- |  1   |   2  |   3  | SAT+ | VAL+ |
 * |------+------+------+------+------+------|MAC/WIN|    |DEFAULT|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  0   |   0  |   .  | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX,TG(_SVD), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_VOLU,  KC_7  ,  KC_8  ,  KC_9  , RGB_TOG, RGB_HUI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MUTE,  KC_4  ,  KC_5  ,  KC_6  , RGB_MOD, RGB_HUD, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_VOLD,  KC_1  ,  KC_2  ,  KC_3  , RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_MAC),TG(_ADJUST),XXXXXXX, KC_0 ,  KC_0  ,  KC_DOT, RGB_SAD, RGB_VAD,\
                        _______, _______, _______, _______,          _______,  _______, _______, _______\
  )
};
// clang-format on

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
}
#endif  // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_LOWER) && (IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_RAISESVD))) {
        layer_on(_ADJUST);
    } else {
        layer_off(_ADJUST);
    }

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

bool isMac(void) { return layer_state_is(_MAC); }
bool isSvdvorak(void) { return layer_state_is(_SVD); }

char layer_state_str[24];

void set_layer_state_str(const char *str) { snprintf(layer_state_str, sizeof(layer_state_str), str); }

const char *read_layer_state(void) {
    if (layer_state_is(_LOWER)) {
        set_layer_state_str("Layer: Lower");
    } else if (layer_state_is(_RAISE)) {
        set_layer_state_str("Layer: Raise");
    } else if (layer_state_is(_RAISESVD)) {
        set_layer_state_str("Layer: Raise (SVD)");
    } else if (layer_state_is(_ADJUST)) {
        set_layer_state_str("Layer: Adjust");
    } else if (layer_state_is(_MAC) && layer_state_is(_SVD)) {
        set_layer_state_str("Layer: Svdorak (Mac)");
    } else if (layer_state_is(_MAC)) {
        set_layer_state_str("Layer: Default (Mac)");
    } else if (layer_state_is(_SV)) {
        set_layer_state_str("Layer: Default (Win)");
    } else if (layer_state_is(_SVD)) {
        set_layer_state_str("Layer: Svdvorak (Win)");
    } else {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
    }
    return layer_state_str;
}
