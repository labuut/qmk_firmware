#include QMK_KEYBOARD_H


enum macros {
    ST_MACRO_NOTIF = SAFE_RANGE,
    // Wildcards_EN macros:
    ST_MACRO_EN_GRAVE,
    ST_MACRO_EN_EXLM,
    ST_MACRO_EN_QUES,
    ST_MACRO_EN_AT,
    ST_MACRO_EN_LPRN,
    ST_MACRO_EN_RPRN,
    ST_MACRO_EN_AMPR,
    ST_MACRO_EN_COMMA,
    ST_MACRO_EN_DOT,
    ST_MACRO_EN_SCOLON,
    ST_MACRO_EN_COLON,
    ST_MACRO_EN_TILD,
    ST_MACRO_EN_CIRC,
    ST_MACRO_EN_DLR,
    ST_MACRO_EN_HASH,
    ST_MACRO_EN_LCRVBRACKET,
    ST_MACRO_EN_RCRVBRACKET,
    ST_MACRO_EN_ASTRX,
    ST_MACRO_EN_QUOTE,
    ST_MACRO_EN_DQUOTE,
    ST_MACRO_EN_EQUAL,
    ST_MACRO_EN_PLUS,
    ST_MACRO_EN_LT,
    ST_MACRO_EN_GT,
    ST_MACRO_EN_PRCNT,
    ST_MACRO_EN_LBRACKET,
    ST_MACRO_EN_RBRACKET,
    ST_MACRO_EN_SLASH,
    ST_MACRO_EN_PIPE,
    ST_MACRO_EN_BSLASH,
    ST_MACRO_EN_LODASH,
    ST_MACRO_EN_MINUS,
    ST_MACRO_EN_NUMBER,
};

// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // open notifications and move cursor to 'clear notifications'
    case ST_MACRO_NOTIF:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_N)) SS_DELAY(10) SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_N)))));
        }
        break;

    // Wildcards_EN macros
    // en -> `
    case ST_MACRO_EN_GRAVE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_GRAVE));
        }
        break;

    // en -> !
    case ST_MACRO_EN_EXLM:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_1)));
        }
        break;

    // en -> ?
    case ST_MACRO_EN_QUES:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_SLASH)));
        }
        break;

    // en -> @
    case ST_MACRO_EN_AT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_2)));
        }
        break;

    // en -> (
    case ST_MACRO_EN_LPRN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_9)));
        }
        break;

    // en -> )
    case ST_MACRO_EN_RPRN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_0)));
        }
        break;

    // en -> &
    case ST_MACRO_EN_AMPR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_7)));
        }
        break;

    // en -> ,
    case ST_MACRO_EN_COMMA:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_COMMA));
        }
        break;

    // en -> .
    case ST_MACRO_EN_DOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_DOT));
        }
        break;

    // en -> ;
    case ST_MACRO_EN_SCOLON:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_SCOLON));
        }
        break;

    // en -> :
    case ST_MACRO_EN_COLON:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_SCOLON)));
        }
        break;

    // en -> ~
    case ST_MACRO_EN_TILD:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_GRAVE)));
        }
        break;

    // en -> ^
    case ST_MACRO_EN_CIRC:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_6)));
        }
        break;

    // en -> $
    case ST_MACRO_EN_DLR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_4)));
        }
        break;

    // en -> #
    case ST_MACRO_EN_HASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_3)));
        }
        break;

    // en -> {
    case ST_MACRO_EN_LCRVBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_LBRACKET)));
        }
        break;

    // en -> }
    case ST_MACRO_EN_RCRVBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_RBRACKET)));
        }
        break;

    // en -> *
    case ST_MACRO_EN_ASTRX:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_8)));
        }
        break;

    // en -> '
    case ST_MACRO_EN_QUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_QUOTE));
        }
        break;

    // en -> "
    case ST_MACRO_EN_DQUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_QUOTE)));
        }
        break;

    // en -> =
    case ST_MACRO_EN_EQUAL:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_EQUAL));
        }
        break;

    // en -> +
    case ST_MACRO_EN_PLUS:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_EQUAL)));
        }
        break;

    // en -> <
    case ST_MACRO_EN_LT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_COMMA)));
        }
        break;

    // en -> >
    case ST_MACRO_EN_GT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_DOT)));
        }
        break;

    // en -> %
    case ST_MACRO_EN_PRCNT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_5)));
        }
        break;

    // en -> [
    case ST_MACRO_EN_LBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_LBRACKET));
        }
        break;

    // en -> ]
    case ST_MACRO_EN_RBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_RBRACKET));
        }
        break;

    // en -> /
    case ST_MACRO_EN_SLASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_SLASH));
        }
        break;

    // en -> |
    case ST_MACRO_EN_PIPE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_BSLASH)));
        }
        break;

    // en -> '\'
    case ST_MACRO_EN_BSLASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_BSLASH));
        }
        break;

    // en -> _
    case ST_MACRO_EN_LODASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_LSFT(SS_TAP(X_MINUS)));
        }
        break;

    // en -> -
    case ST_MACRO_EN_MINUS:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(10) SS_TAP(X_MINUS));
        }
        break;

    // en -> №
    case ST_MACRO_EN_NUMBER:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)) SS_DELAY(10) SS_LSFT(SS_TAP(X_3)) SS_DELAY(10) SS_TAP(X_CAPSLOCK));
        }
        break;
    }

    return true;
}


enum tap_dances {
    TD_F5,
    TD_H,
    TD_T,
    TD_U,
    TD_PLAY,
    TD_LANG,
    TD_BSPC,
};

// this code is a copy from moonlander to support tap dance with TAP/DOUBLE-TAP/HOLD
// [BEGINING]
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

// dance tap TD_LANG
void on_dance_lang(qk_tap_dance_state_t *state, void *user_data);
void dance_lang_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_lang_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_lang(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_CAPSLOCK);
        tap_code16(KC_CAPSLOCK);
        tap_code16(KC_CAPSLOCK);
    }
    if(state->count > 3) {
        tap_code16(KC_CAPSLOCK);
    }
}

void dance_lang_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_CAPSLOCK); break;
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_CAPSLOCK)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_CAPSLOCK); register_code16(KC_CAPSLOCK);
    }
}

void dance_lang_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_CAPSLOCK); break;
        case SINGLE_HOLD: layer_off(2); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_CAPSLOCK)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_CAPSLOCK); break;
    }
    dance_state[0].step = 0;
}

// dance tap TD_BSPC
void on_dance_bspc(qk_tap_dance_state_t *state, void *user_data);
void dance_bspc_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_bspc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_bspc(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_bspc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_BSPC)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_bspc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: layer_off(5); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_BSPC)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[0].step = 0;
}
// [END]

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LCTL(KC_F5)),              // F5 / Hard F5
    [TD_T] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_T), LALT(LGUI(KC_T))),     // Yakuake / Konsole
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_U), LALT(LGUI(KC_U))),     // Windows: Presentation / Greed
    [TD_H] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_H), LALT(LGUI(KC_H))),     // Krunner / Apps
    [TD_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, LALT(LSFT(KC_B))),     // Play / Like (Spotify)
    [TD_LANG] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_lang, dance_lang_finished, dance_lang_reset),  // ENG / RU / MO2 (Wildcards)
    [TD_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_bspc, dance_bspc_finished, dance_bspc_reset),  // bspace / ctrl+bspace / MO5 (OS)
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layers:
    // 0 - Main
    // 1 - Digits
    // 2 - Wildcards
    // 3 - Arrows
    // 4 - Mouse
    // 5 - OS
    // 6 - Service
    [0] = LAYOUT(
        // 1st row:
        LT(5, KC_ESC), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, TO(6),
        // 2nd row:
        KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        // 3rd row:
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
        // 4th row:
        OSM(MOD_LSFT), TD(TD_BSPC), LT(1, KC_ENT),                                  LT(3, KC_SPC), LT(4, KC_DEL), TD(TD_LANG)
    ),
    // Digits, Fns
	[1] = LAYOUT(
        // 1st row:
        TO(0), KC_TAB, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,                          KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, KC_RALT, KC_NLCK,
        // 2nd row:
        KC_LALT, KC_NO, KC_F4, TD(TD_F5), KC_F6, KC_F11,                            KC_PAST, KC_4, KC_5, KC_6, KC_PPLS, KC_LGUI,
        // 3rd row:
        KC_LCTL, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                                KC_0, KC_1, KC_2, KC_3, KC_PDOT, KC_NO,
        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, KC_NO,                                              KC_SPC, KC_DEL, KC_NO

    ),
    // Wildcards EN
    [2] = LAYOUT(
        // 1st row:
        // left (7)
        TO(0), ST_MACRO_EN_GRAVE, ST_MACRO_EN_EXLM, ST_MACRO_EN_QUES, ST_MACRO_EN_AT, ST_MACRO_EN_LPRN, ST_MACRO_EN_RPRN,
        // right (7)
        ST_MACRO_EN_SLASH, ST_MACRO_EN_PIPE, ST_MACRO_EN_BSLASH, ST_MACRO_EN_LODASH, ST_MACRO_EN_MINUS, KC_NO, KC_NO,

        // 2nd row:
        // left (6)
        ST_MACRO_EN_TILD, ST_MACRO_EN_CIRC, ST_MACRO_EN_DLR, ST_MACRO_EN_HASH, ST_MACRO_EN_LCRVBRACKET, ST_MACRO_EN_RCRVBRACKET,
        // right (6)
        ST_MACRO_EN_ASTRX, ST_MACRO_EN_QUOTE, ST_MACRO_EN_DQUOTE, ST_MACRO_EN_EQUAL, ST_MACRO_EN_PLUS, KC_NO,

        // 3rd row:
        // left (6)
        KC_LCTL, ST_MACRO_EN_LT, ST_MACRO_EN_GT, ST_MACRO_EN_PRCNT, ST_MACRO_EN_LBRACKET, ST_MACRO_EN_RBRACKET,
        // right (6)
        ST_MACRO_EN_AMPR, ST_MACRO_EN_SCOLON, ST_MACRO_EN_COLON, ST_MACRO_EN_COMMA, ST_MACRO_EN_DOT, ST_MACRO_EN_NUMBER,

        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, KC_ENT,                                             KC_SPC, KC_DEL, KC_NO
    ),
    // Arrows
    [3] = LAYOUT(
        // 1st row:
        TO(0), KC_TAB, KC_NO, KC_HOME, KC_UP, KC_END, KC_NO,                        KC_NO, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, KC_NO,
        // 2nd row:
        KC_LALT, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                           KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_LGUI,
        // 3rd row:
        KC_LCTL, KC_NO, KC_PGUP, KC_NO, KC_PGDN, KC_NO,                             KC_NO, KC_PGUP, KC_NO, KC_PGDN, KC_NO, KC_NO,
        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, KC_ENT,                                             KC_NO, KC_DEL, KC_NO
    ),
    // Mouse
	[4] = LAYOUT(
        // 1st row:
        TO(0), KC_TAB, KC_NO, KC_HOME, KC_UP, KC_END, KC_NO,                        KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_APP, KC_NO, KC_NO,
        // 2nd row:
        KC_LALT, MEH(KC_S), KC_LEFT, KC_DOWN, KC_RGHT, MEH(KC_F),                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_LGUI,
        // 3rd row:
        KC_LCTL, KC_NO, KC_PGUP, KC_NO, KC_PGDN, KC_NO,                             KC_NO, KC_BTN4, KC_BTN3, KC_BTN5, KC_ACL0, KC_NO,
        // 4th row:b
        OSM(MOD_LSFT), KC_BSPC, KC_ENT,                                             KC_SPC, KC_NO, KC_NO
    ),
    // OS
	[5] = LAYOUT(
        // 1st row:
        KC_MUTE, KC_NO, LGUI(KC_Q), LGUI(KC_W), KC_NO, LGUI(KC_R), TD(TD_T),        LGUI(KC_Y), TD(TD_U), LGUI(KC_I), LGUI(KC_O), LGUI(KC_P), KC_PSCR, LALT(LGUI(KC_Q)),
        // 2nd row:
        KC_NO, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G),          TD(TD_H), LGUI(KC_J), LGUI(KC_K), LGUI(KC_L), LGUI(KC_SCLN), KC_NO,
        // 3rd row:
        KC_NO, LGUI(KC_Z), LGUI(KC_X), KC_NO, LGUI(KC_V), KC_NO,                    ST_MACRO_NOTIF, LGUI(KC_M), LGUI(KC_COMM), LGUI(KC_DOT), LGUI(KC_SLSH), TO(0),
        // 4th row:
        KC_VOLD, KC_NO, KC_VOLU,                                                    TD(TD_PLAY), KC_MPRV, KC_MNXT
    ),
    // Service
	[6] = LAYOUT(
        // 1st row:
        TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // 2nd row:
        KC_NO, KC_NO, TO(4), TO(5), KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // 3rd row:
        KC_NO, KC_NO, TO(1), TO(2), TO(3), KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // 4th row:
        KC_NO, KC_NO, KC_NO,                                                        KC_NO, KC_NO, KC_NO
    )
};
