#include QMK_KEYBOARD_H


enum macros {
    MRS_NOTIF = SAFE_RANGE,
    MRS_RU,
    MRS_EN,
    MRS_SWITCH_LANG,
    // Wildcards macros:
    MRS_GRAVE,
    MRS_EXLM,
    MRS_QUES,
    MRS_AT,
    MRS_LPRN,
    MRS_RPRN,
    MRS_AMPR,
    MRS_COMMA,
    MRS_DOT,
    MRS_SCOLON,
    MRS_COLON,
    MRS_TILD,
    MRS_CIRC,
    MRS_DLR,
    MRS_HASH,
    MRS_LCRVBRKT,
    MRS_RCRVBRKT,
    MRS_ASTRX,
    MRS_QUOTE,
    MRS_DQUOTE,
    MRS_EQUAL,
    MRS_PLUS,
    MRS_LT,
    MRS_GT,
    MRS_PRCNT,
    MRS_LBRKT,
    MRS_RBRKT,
    MRS_SLASH,
    MRS_PIPE,
    MRS_BSLASH,
    MRS_LODASH,
    MRS_MINUS,
    MRS_NUMBER,
    MRS_YO,
};

int lang = 0; // 0 === EN, 1 === RU

// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // open notifications and move cursor to 'clear notifications'
    case MRS_NOTIF:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_N)) SS_DELAY(5) SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_N)))));
        }
        break;
    // set lang var when lang changes to RU
    case MRS_RU:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            lang = 1;
        }
        break;

    // set lang var when lang changes to EN
    case MRS_EN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK));
            lang = 0;
        }
        break;

    // switch lang var to next
    case MRS_SWITCH_LANG:
        if (record->event.pressed) {
            SEND_STRING(SS_DELAY(5));
            lang = (lang == 0) ? 1 : 0;
        }
        break;

    // Wildcards_EN macros
    // en -> `
    case MRS_GRAVE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_GRAVE));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> !
    case MRS_EXLM:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_1)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ?
    case MRS_QUES:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_SLASH)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> @
    case MRS_AT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_2)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> (
    case MRS_LPRN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_9)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> )
    case MRS_RPRN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_0)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> &
    case MRS_AMPR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_7)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ,
    case MRS_COMMA:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_COMMA));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> .
    case MRS_DOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_DOT));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ;
    case MRS_SCOLON:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_SCOLON));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> :
    case MRS_COLON:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_SCOLON)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ~
    case MRS_TILD:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_GRAVE)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ^
    case MRS_CIRC:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_6)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> $
    case MRS_DLR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_4)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> #
    case MRS_HASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_3)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> {
    case MRS_LCRVBRKT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_LBRACKET)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> }
    case MRS_RCRVBRKT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_RBRACKET)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> *
    case MRS_ASTRX:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_8)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> '
    case MRS_QUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_QUOTE));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> "
    case MRS_DQUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_QUOTE)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> =
    case MRS_EQUAL:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_EQUAL));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> +
    case MRS_PLUS:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_EQUAL)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> <
    case MRS_LT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_COMMA)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> >
    case MRS_GT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_DOT)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> %
    case MRS_PRCNT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_5)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> [
    case MRS_LBRKT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_LBRACKET));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> ]
    case MRS_RBRKT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_RBRACKET));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> /
    case MRS_SLASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_SLASH));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> |
    case MRS_PIPE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_BSLASH)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> '\'
    case MRS_BSLASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_BSLASH));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> _
    case MRS_LODASH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_LSFT(SS_TAP(X_MINUS)));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> -
    case MRS_MINUS:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(5) SS_TAP(X_MINUS));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> №
    case MRS_NUMBER:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)) SS_DELAY(5) SS_LSFT(SS_TAP(X_3)) SS_DELAY(5) SS_TAP(X_CAPSLOCK));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;

    // en -> Ё
    case MRS_YO:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)) SS_DELAY(5) SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(5) SS_TAP(X_CAPSLOCK));

            if (lang == 1) {
                SEND_STRING(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            }
        }
        break;
    }

    return true;
}


enum tap_dances {
    TD_SOFT_HARD,
    TD_B_JU,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SOFT_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),                        // Ь / Ъ
    [TD_B_JU] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),                           // Б / Ю
};

enum layers {
    LR_MAIN,
    LR_WILDS,
    LR_NUMS,
    LR_MOUSE,
    LR_ARROWS,
    LR_SERVICE,
    LR_GAME1,
    LR_GAME2
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LR_MAIN] = LAYOUT(
    // 1st row:
    KC_NO,
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, LT(LR_SERVICE, KC_LBRC),
    KC_NO,
    // 2nd row:
    KC_TAB, GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,           KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), GUI_T(KC_SCLN), KC_ENT,
    // 3rd row:
    KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,                                        KC_N, TD(TD_SOFT_HARD), TD(TD_B_JU), MRS_COMMA, MRS_DOT, KC_QUOT,
    // 4th row:
    KC_DEL, LT(LR_ARROWS, KC_SPC), MO(LR_MOUSE),                                OSL(LR_WILDS), LT(LR_NUMS, KC_SPC), KC_BSPC
),
[LR_WILDS] = LAYOUT( // Wildcards
    // 1st row:
    KC_NO,
    TO(LR_MAIN), MRS_CIRC, MRS_EXLM, MRS_QUES, MRS_LBRKT, MRS_RBRKT,            MRS_SLASH, MRS_PIPE, MRS_BSLASH, MRS_LODASH, MRS_MINUS, KC_NO,
    KC_NO,
    // 2nd row:
    KC_TAB, MRS_PRCNT, MRS_LT, MRS_GT, MRS_LPRN, MRS_RPRN,                      MRS_ASTRX, MRS_QUOTE, MRS_DQUOTE, MRS_EQUAL, MRS_PLUS, KC_ENT,
    // 3rd row:
    MRS_GRAVE, MRS_TILD, MRS_AT, MRS_HASH, MRS_LCRVBRKT, MRS_RCRVBRKT,          MRS_AMPR, MRS_SCOLON, MRS_COLON, MRS_COMMA, MRS_DOT, MRS_DLR,
    // 4th row:
    KC_DEL, LT(LR_ARROWS, KC_SPC), MO(LR_MOUSE),                                MRS_EN, MRS_RU, KC_BSPC
),
[LR_NUMS] = LAYOUT(
    // 1st row:
    KC_NO,
    TO(LR_MAIN), KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,                            KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, KC_NLCK,
    KC_NO,
    // 2nd row:
    KC_TAB, KC_LGUI, ALT_T(KC_F4), CTL_T(KC_F5), SFT_T(KC_F6), KC_F11,          KC_PAST, SFT_T(KC_4), CTL_T(KC_5), ALT_T(KC_6), GUI_T(KC_PPLS), KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                                  KC_0, KC_1, KC_2, KC_3, KC_PDOT, KC_ALGR,
    // 4th row:
    KC_DEL, LT(LR_ARROWS, KC_SPC), MO(LR_MOUSE),                                OSL(LR_WILDS), KC_NO, KC_BSPC
),
[LR_MOUSE] = LAYOUT(
    // 1st row:
    KC_NO,
    TO(LR_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_BTN5, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO,
    KC_NO,
    // 2nd row:
    KC_TAB, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN1,                        KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_APP, KC_WH_D, KC_BTN3, KC_WH_U, KC_NO, KC_NO,
    // 4th row:
    KC_DEL, LT(LR_ARROWS, KC_SPC), KC_NO,                                       OSL(LR_WILDS), LT(LR_NUMS, KC_SPC), KC_BSPC
),
[LR_ARROWS] = LAYOUT(
    // 1st row:
    KC_NO,
    TO(LR_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO,
    KC_NO,
    // 2nd row:
    KC_TAB, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN1,                        KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_APP, KC_PGUP, KC_NO, KC_PGDN, KC_NO, KC_NO,
    // 4th row:
    KC_DEL, KC_NO, MO(LR_MOUSE),                                                OSL(LR_WILDS), LT(LR_NUMS, KC_SPC), KC_BSPC
),
[LR_SERVICE] = LAYOUT(
    // 1st row:
    KC_NO,
    TO(LR_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, MRS_YO,                            RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,
    // 2nd row:
    KC_NO, KC_NO, KC_NO, KC_NO, TO(LR_GAME1), KC_NO,                            MRS_SWITCH_LANG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, MRS_NUMBER, KC_NO, KC_NO,                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // 4th row:
    KC_MUTE, KC_VOLD, KC_VOLU,                                                  KC_MPLY, KC_MPRV, KC_MNXT
),
[LR_GAME1] = LAYOUT(
    // 1st row:
    KC_NO,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ESC,
    KC_NO,
    // 2nd row:
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    // 3rd row:
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_SLSH, KC_COMM, KC_DOT, TO(LR_MAIN),
    // 4th row:
    TO(LR_GAME2), KC_SPC, KC_LALT,                                              KC_LALT, KC_SPC, KC_BSPC
),
[LR_GAME2] = LAYOUT(
    // 1st row:
    KC_NO,
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC,                                       KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_ESC,
    KC_NO,
    // 2nd row:
    KC_CAPS, GUI_T(KC_F1), ALT_T(KC_F2), CTL_T(KC_F3), SFT_T(KC_F4), KC_ENT,    KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_ENT,
    // 3rd row:
    KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,                                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(LR_MAIN),
    // 4th row:
    KC_NO, KC_SPC, KC_LALT,                                                     KC_LALT, KC_SPC, KC_BSPC
)
};
