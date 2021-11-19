#include QMK_KEYBOARD_H


enum macros {
    MACRO_NOTIF = SAFE_RANGE,
    MACRO_RU,
    MACRO_EN,
    MACRO_SWITCH_LANG,
    // Wildcards macros:
    MACRO_GRAVE,
    MACRO_EXLM,
    MACRO_QUES,
    MACRO_AT,
    MACRO_LPRN,
    MACRO_RPRN,
    MACRO_AMPR,
    MACRO_COMMA,
    MACRO_DOT,
    MACRO_SCOLON,
    MACRO_COLON,
    MACRO_TILD,
    MACRO_CIRC,
    MACRO_DLR,
    MACRO_HASH,
    MACRO_LCRVBRACKET,
    MACRO_RCRVBRACKET,
    MACRO_ASTRX,
    MACRO_QUOTE,
    MACRO_DQUOTE,
    MACRO_EQUAL,
    MACRO_PLUS,
    MACRO_LT,
    MACRO_GT,
    MACRO_PRCNT,
    MACRO_LBRACKET,
    MACRO_RBRACKET,
    MACRO_SLASH,
    MACRO_PIPE,
    MACRO_BSLASH,
    MACRO_LODASH,
    MACRO_MINUS,
    MACRO_NUMBER,
};

int lang = 0; // 0 === EN, 1 === RU

// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // open notifications and move cursor to 'clear notifications'
    case MACRO_NOTIF:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_N)) SS_DELAY(5) SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_N)))));
        }
        break;
    // set lang var when lang changes to RU
    case MACRO_RU:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            lang = 1;
        }
        break;

    // set lang var when lang changes to EN
    case MACRO_EN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK));
            lang = 0;
        }
        break;

    // switch lang var to next
    case MACRO_SWITCH_LANG:
        if (record->event.pressed) {
            SEND_STRING(SS_DELAY(5));
            lang = (lang == 0) ? 1 : 0;
        }
        break;

    // Wildcards_EN macros
    // en -> `
    case MACRO_GRAVE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_GRAVE));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> !
    case MACRO_EXLM:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_1)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ?
    case MACRO_QUES:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_SLASH)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> @
    case MACRO_AT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_2)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> (
    case MACRO_LPRN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_9)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> )
    case MACRO_RPRN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_0)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> &
    case MACRO_AMPR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_7)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ,
    case MACRO_COMMA:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_COMMA));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> .
    case MACRO_DOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_DOT));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ;
    case MACRO_SCOLON:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_SCOLON));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> :
    case MACRO_COLON:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_SCOLON)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ~
    case MACRO_TILD:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_GRAVE)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ^
    case MACRO_CIRC:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_6)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> $
    case MACRO_DLR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_4)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> #
    case MACRO_HASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_3)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> {
    case MACRO_LCRVBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_LBRACKET)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> }
    case MACRO_RCRVBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_RBRACKET)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> *
    case MACRO_ASTRX:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_8)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> '
    case MACRO_QUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_QUOTE));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> "
    case MACRO_DQUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_QUOTE)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> =
    case MACRO_EQUAL:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_EQUAL));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> +
    case MACRO_PLUS:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_EQUAL)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> <
    case MACRO_LT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_COMMA)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> >
    case MACRO_GT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_DOT)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> %
    case MACRO_PRCNT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_5)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> [
    case MACRO_LBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_LBRACKET));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ]
    case MACRO_RBRACKET:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_RBRACKET));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> /
    case MACRO_SLASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_SLASH));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> |
    case MACRO_PIPE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_BSLASH)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> '\'
    case MACRO_BSLASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_BSLASH));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> _
    case MACRO_LODASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_MINUS)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> -
    case MACRO_MINUS:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_MINUS));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> №
    case MACRO_NUMBER:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)) SS_DELAY(5) SS_LSFT(SS_TAP(X_3)) SS_DELAY(5) SS_TAP(X_CAPSLOCK));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
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
    TD_SOFT_HARD,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LCTL(KC_F5)),              // F5 / Hard F5
    [TD_T] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_T), LALT(LGUI(KC_T))),     // Yakuake / Konsole
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_U), LALT(LGUI(KC_U))),     // Windows: Presentation / Greed
    [TD_H] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_H), LALT(LGUI(KC_H))),     // Krunner / Apps
    [TD_SOFT_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),            // Ь / Ъ
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layers:
    // 0 - Main
    // 1 - Digits
    // 2 - Wildcards
    // 3 - Cursor
    // 4 - OS
    // 5 - Service
    [0] = LAYOUT(
        // 1st row:
        KC_ESC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, MO(5),
        // 2nd row:
        KC_LALT, LT(3, KC_A), KC_S, KC_D, KC_F, KC_G,                                   KC_H, KC_J, KC_K, KC_L, LT(3, KC_SCLN), KC_QUOT,
        // 3rd row:
        KC_LCTL, LT(1, KC_Z), KC_X, KC_C, KC_V, KC_B,                                   KC_N, TD(TD_SOFT_HARD), KC_COMM, KC_DOT, MACRO_COMMA, MACRO_DOT,
        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, LT(4, KC_ENT),                                          KC_SPC, KC_DEL, OSL(2)
    ),
    // Digits, Fns
	[1] = LAYOUT(
        // 1st row:
        TO(0), KC_TAB, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,                              KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, KC_RALT, KC_NO,
        // 2nd row:
        KC_LALT, KC_NO, KC_F4, TD(TD_F5), KC_F6, KC_F11,                                KC_PAST, KC_4, KC_5, KC_6, KC_PPLS, KC_LGUI,
        // 3rd row:
        KC_LCTL, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                                    KC_0, KC_1, KC_2, KC_3, KC_PDOT, KC_NLCK,
        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, KC_ENT,                                                 KC_SPC, KC_DEL, KC_NO
    ),
    // Wildcards (all in one layer)
    [2] = LAYOUT(
        // 1st row:
        TO(0), MACRO_TILD, MACRO_NUMBER, MACRO_AT, MACRO_DLR, MACRO_LBRACKET, MACRO_RBRACKET,                   MACRO_SLASH, MACRO_PIPE, MACRO_BSLASH, MACRO_LODASH, MACRO_MINUS, KC_NO, MACRO_RU,
        // 2nd row:
        MACRO_GRAVE, MACRO_PRCNT, MACRO_QUES, MACRO_EXLM, MACRO_LPRN, MACRO_RPRN,                               MACRO_ASTRX, MACRO_QUOTE, MACRO_DQUOTE, MACRO_EQUAL, MACRO_PLUS, KC_NO,
        // 3rd row:
        KC_NO, MACRO_HASH, MACRO_LT, MACRO_GT, MACRO_LCRVBRACKET, MACRO_RCRVBRACKET,                            MACRO_AMPR, MACRO_SCOLON, MACRO_COLON, MACRO_CIRC, MACRO_COMMA, MACRO_DOT,
        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, KC_ENT,                                                                         KC_SPC, KC_NO, MACRO_EN
    ),
    // Cursor
    [3] = LAYOUT(
        // 1st row:
        TO(0), KC_TAB, KC_BTN1, KC_HOME, KC_UP, KC_END, KC_NO,                          KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_APP, KC_NO, KC_NO,
        // 2nd row:
        KC_LALT, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, MEH(KC_F),                           KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_LGUI,
        // 3rd row:
        KC_LCTL, KC_NO, KC_PGUP, KC_NO, KC_PGDN, MEH(KC_S),                             KC_NO, KC_BTN4, KC_BTN3, KC_BTN5, KC_ACL0, KC_NO,
        // 4th row:
        OSM(MOD_LSFT), KC_BSPC, KC_ENT,                                                 KC_NO, KC_DEL, KC_NO
    ),
    // OS
	[4] = LAYOUT(
        // 1st row:
        TO(0), KC_NO, LGUI(KC_Q), KC_NO, LGUI(KC_W), LGUI(KC_R), TD(TD_T),              LGUI(KC_Y), TD(TD_U), KC_NO, LGUI(KC_O), LGUI(KC_P), KC_PSCR, KC_NO,
        // 2nd row:
        KC_NO, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G),              TD(TD_H), KC_NO, KC_NO, KC_NO, LGUI(KC_SCLN), LALT(LGUI(KC_Q)),
        // 3rd row:
        KC_NO, LGUI(KC_Z), LGUI(KC_X), KC_NO, LGUI(KC_V), KC_MUTE,                      MACRO_NOTIF, LGUI(KC_M), LGUI(KC_COMM), KC_NO, LGUI(KC_SLSH), KC_NO,
        // 4th row:
        KC_VOLD, KC_VOLU, KC_NO,                                                        KC_MPLY, KC_MPRV, KC_MNXT
    ),
    // Service
	[5] = LAYOUT(
        // 1st row:
        TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // 2nd row:
        KC_NO, KC_NO, TO(4), KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // 3rd row:
        KC_NO, KC_NO, TO(1), TO(2), TO(3), KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // 4th row:
        KC_NO, KC_NO, KC_NO,                                                            KC_NO, KC_NO, MACRO_SWITCH_LANG
    )
};
