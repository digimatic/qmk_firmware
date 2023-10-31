#include "digimatic.h"

void register_unreg_code(uint64_t keycode, bool press) {
    if (press)
        register_code(keycode);
    else
        unregister_code(keycode);
}

bool process_digimatic_keycode(uint16_t keycode, bool pressed) {
    bool handled = false;
    switch (keycode) {
        case PW_LPAR:  // (
            register_unreg_code(KC_LSFT, pressed);
            register_unreg_code(KC_8, pressed);
            handled = true;
            break;
        case PW_RPAR:  // )
            register_unreg_code(KC_RSFT, pressed);
            register_unreg_code(KC_9, pressed);
            handled = true;
            break;

        case PW_LBRA:  // {
            if (isMac()) {
                register_unreg_code(KC_RALT, pressed);
                register_unreg_code(KC_RSFT, pressed);
                register_unreg_code(KC_8, pressed);
            } else {
                register_unreg_code(KC_RALT, pressed);
                register_unreg_code(KC_7, pressed);
            }
            handled = true;
            break;
        case PW_RBRA:  // }
            if (isMac()) {
                register_unreg_code(KC_RALT, pressed);
                register_unreg_code(KC_RSFT, pressed);
                register_unreg_code(KC_9, pressed);
            } else {
                register_unreg_code(KC_RALT, pressed);
                register_unreg_code(KC_0, pressed);
            }
            handled = true;
            break;

        case PW_LSQ:  // [
            register_unreg_code(KC_RALT, pressed);
            register_unreg_code(KC_8, pressed);
            handled = true;
            break;
        case PW_RSQ:  // ]
            register_unreg_code(KC_RALT, pressed);
            register_unreg_code(KC_9, pressed);
            handled = true;
            break;

        case PW_LT:  // <
            if (!isSvdvorak())
                register_unreg_code(SE_QUOT, pressed);
            else
                register_unreg_code(SE_LABK, pressed);
            handled = true;
            break;
        case PW_GT:  // >
            register_unreg_code(KC_LEFT_SHIFT, pressed);
            if (!isSvdvorak()) {
                register_unreg_code(SE_QUOT, pressed);
            } else {
                register_unreg_code(SE_LABK, pressed);
            }
            handled = true;
            break;

        case PW_PIPE:  // |
            if (isMac()) {
                register_unreg_code(KC_RALT, pressed);
                register_unreg_code(KC_7, pressed);
            } else {
                if (isSvdvorak())
                    register_unreg_code(SE_QUOT, pressed);
                else {
                    register_unreg_code(KC_RALT, pressed);
                    register_unreg_code(SE_LABK, pressed);
                }
            }
            handled = true;
            break;

        // case PW_TILD:  // ~
        //     if (pressed) {
        //         register_code(KC_RALT);
        //         register_code(SE_DIAE);
        //         register_code(KC_SPACE);
        //     } else {
        //         unregister_code(KC_SPACE);
        //         unregister_code(SE_DIAE);
        //         unregister_code(KC_RALT);
        //     }
        //     handled = true;
        //     break;
        case PW_BSLS:
            if (isMac()) {
                if (pressed) {
                    register_code(KC_RALT);
                    register_code(KC_RIGHT_SHIFT);
                    register_code(KC_7);
                } else {
                    unregister_code(KC_7);
                    unregister_code(KC_RIGHT_SHIFT);
                    unregister_code(KC_RALT);
                }
            } else {
                if (pressed) {
                    register_code(KC_RALT);
                    register_code(SE_PLUS);
                } else {
                    unregister_code(KC_RALT);
                    unregister_code(SE_PLUS);
                }
            }
            handled = true;
            break;

        default:
            break;
    }

    return handled;
}

#ifdef TAP_DANCE_ENABLE
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

int cur_dance(tap_dance_state_t *state);

// for the x tap dance. Put it here so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

int cur_dance(tap_dance_state_t *state) {
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

void lp_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_LPAR, true);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
            process_digimatic_keycode(PW_LBRA, true);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LSFT);
            break;
        case TRIPLE_TAP:
            process_digimatic_keycode(PW_LSQ, true);
            break;
    }
}

void lp_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_LPAR, false);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
            process_digimatic_keycode(PW_LBRA, false);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_LSFT);
        case TRIPLE_TAP:
            process_digimatic_keycode(PW_LSQ, false);
            break;
    }
    xtap_state.state = 0;
}

void rp_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_RPAR, true);
            break;
        case SINGLE_HOLD:
            register_code(KC_RSFT);
            break;
        case DOUBLE_TAP:
            process_digimatic_keycode(PW_RBRA, true);
            break;
        case DOUBLE_HOLD:
            register_code(KC_RSFT);
            break;
        case TRIPLE_TAP:
            process_digimatic_keycode(PW_RSQ, true);
            break;
    }
}

void rp_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_RPAR, false);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RSFT);
            break;
        case DOUBLE_TAP:
            process_digimatic_keycode(PW_RBRA, false);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_RSFT);
        case TRIPLE_TAP:
            process_digimatic_keycode(PW_RSQ, false);
            break;
    }
    xtap_state.state = 0;
}

void lp2_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_LT, true);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        default:
            break;
    }
}

void lp2_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_LT, false);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        default:
            break;
    }
    xtap_state.state = 0;
}

void rp2_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_GT, true);
            break;
        case SINGLE_HOLD:
            register_code(KC_RSFT);
            break;
        default:
            break;
    }
}

void rp2_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            process_digimatic_keycode(PW_GT, false);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RSFT);
            break;
        default:
            break;
    }
    xtap_state.state = 0;
    xtap_state.state = 0;
}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_SHIFT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lp_finished, lp_reset),
    [TD_SHIFT_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rp_finished, rp_reset),
    [TD_SHIFT_LPIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lp2_finished, lp2_reset),
    [TD_SHIFT_RPIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rp2_finished, rp2_reset)
};
// clang-format on
#endif
