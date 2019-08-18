#include "digimatic.h"

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

// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_SHIFT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lp_finished, lp_reset),
    [TD_SHIFT_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rp_finished, rp_reset)};
// clang-format on
