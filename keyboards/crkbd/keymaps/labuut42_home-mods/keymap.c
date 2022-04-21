#include QMK_KEYBOARD_H
#include <stdio.h>


enum {
    EN = 0,
    RU,
};
int CURRENT_LANG =RU;

enum {
    CAPS_SHIFT = 0,
    SHIFT_ALT,
    ALT_SPACE,
    CTRL_SHIFT,
};
int LAYOUT_HOTKEY = CAPS_SHIFT;


void toggle_layout_hotkey(int layout_hotkey_arg) {
    LAYOUT_HOTKEY = layout_hotkey_arg;
}

void switch_lang(int lang) {
    if (CURRENT_LANG == lang) return;

    bool is_ru = CURRENT_LANG == RU;

    switch (LAYOUT_HOTKEY) {
        case CAPS_SHIFT:
            if (is_ru) send_string(SS_TAP(X_CAPSLOCK));
            if (!is_ru) send_string(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            break;
        case SHIFT_ALT:
            send_string(SS_LSFT(SS_TAP(X_LALT)));
            break;
        case ALT_SPACE:
            send_string(SS_LALT(SS_TAP(X_SPC)));
            break;
        case CTRL_SHIFT:
            send_string(SS_LCTL(SS_TAP(X_LSFT)));
            break;
    }

    CURRENT_LANG = lang;
}

void send_one_string(char *one_tap_string) {
    bool is_ru = CURRENT_LANG == RU;

    if (is_ru) switch_lang(EN);

    // send_string(SS_DELAY(3));
    send_string(one_tap_string);

    if (is_ru) {
        // send_string(SS_DELAY(3));
        switch_lang(RU);
    }
}

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

int get_tap_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        return SINGLE_HOLD;
    }

    if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        if (state->pressed) return DOUBLE_HOLD;
        return DOUBLE_TAP;
    }

    return MORE_TAPS;
}


enum layers {
    LR_MAIN,
    LR_WILDS,
    LR_NUMS,
    LR_MOUSE,
    LR_ARROWS,
    LR_SERVICE,
    // LR_GAME1,
    // LR_GAME2
};

enum macros {
    MRS_RU = SAFE_RANGE,
    MRS_EN,
    MRS_LANG_SWITCH_VAR,
    MRS_LANG_CAPS_SHIFT,
    MRS_LANG_SHIFT_ALT,
    MRS_LANG_ALT_SPACE,
    MRS_LANG_CTRL_SHIFT,

    MRS_GRAVE,
    // MRS_TILD,
    // MRS_EXLM,
    // MRS_QUES,
    MRS_AMPR,
    MRS_PIPE,
    // MRS_EQUAL,
    // MRS_PLUS,
    MRS_MINUS,
    MRS_LODASH,
    // MRS_COMMA,
    // MRS_DOT,
    MRS_AT,
    MRS_HASH,
    MRS_DLR,
    MRS_PRCNT,
    MRS_CIRC,
    MRS_ASTRX,

    MRS_RU_NUM,
    MRS_RU_YO,

    MRS_NOTIF,
};

enum tap_dances {
    ESC_MAIN,

    RU_SOFT_HARD,
    RU_B_JU,

    COMDOT,
    COLONS,
    SLASHES,
    CRBRKTS,
    BRKTS,
    QUOTES,
    TILD,
    PRNTS,
    LTGT,
    EQUAL,
    PLUS,
    MARKS,
};


// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_ru = CURRENT_LANG == 1;

    switch (keycode) {
    // Language's layout macros
    case MRS_RU:
        if (record->event.pressed) switch_lang(RU);
        break;
    case MRS_EN:
        if (record->event.pressed) switch_lang(EN);
        break;
    case MRS_LANG_SWITCH_VAR:
        if (record->event.pressed) {
            CURRENT_LANG = (CURRENT_LANG == EN) ? RU : EN;
        }
        break;
    case MRS_LANG_CAPS_SHIFT:
        if (record->event.pressed) toggle_layout_hotkey(CAPS_SHIFT);
        break;
    case MRS_LANG_SHIFT_ALT:
        if (record->event.pressed) toggle_layout_hotkey(SHIFT_ALT);
        break;
    case MRS_LANG_ALT_SPACE:
        if (record->event.pressed) toggle_layout_hotkey(ALT_SPACE);
        break;
    case MRS_LANG_CTRL_SHIFT:
        if (record->event.pressed) toggle_layout_hotkey(CTRL_SHIFT);
        break;

    // Wildcards macros
    case MRS_GRAVE: // `
        if (record->event.pressed) send_one_string("`");
        break;
    // case MRS_TILD: // ~
    //     if (record->event.pressed) send_one_string("~");
    //     break;
    // case MRS_EXLM: // !
    //     if (record->event.pressed) send_one_string("!");
    //     break;
    // case MRS_QUES: // ?
    //     if (record->event.pressed) send_one_string("?");
    //     break;
    case MRS_AMPR: // &
        if (record->event.pressed) send_one_string("&");
        break;
    case MRS_PIPE: // |
        if (record->event.pressed) send_one_string("|");
        break;
    // case MRS_EQUAL: // =
    //     if (record->event.pressed) send_one_string("=");
    //     break;
    // case MRS_PLUS: // +
    //     if (record->event.pressed) send_one_string("+");
    //     break;
    case MRS_MINUS: // -
        if (record->event.pressed) send_one_string("-");
        break;
    case MRS_LODASH: // _
        if (record->event.pressed) send_one_string("_");
        break;
    // case MRS_COMMA: // ,
    //     if (record->event.pressed) send_one_string(",");
    //     break;
    // case MRS_DOT: // .
    //     if (record->event.pressed) send_one_string(".");
    //     break;
    case MRS_AT: // @
        if (record->event.pressed) send_one_string("@");
        break;
    case MRS_HASH: // #
        if (record->event.pressed) send_one_string("#");
        break;
    case MRS_DLR: // $
        if (record->event.pressed) send_one_string("$");
        break;
    case MRS_PRCNT: // %
        if (record->event.pressed) send_one_string("%");
        break;
    case MRS_CIRC: // ^
        if (record->event.pressed) send_one_string("^");
        break;
    case MRS_ASTRX: // *
        if (record->event.pressed) send_one_string("*");
        break;

    // RU macros
    case MRS_RU_NUM: // №
        if (record->event.pressed) {
            if (!is_ru) switch_lang(RU);
            SEND_STRING(SS_LSFT(SS_TAP(X_3)));
            if (!is_ru) switch_lang(EN);
        }
        break;
    case MRS_RU_YO: // Ё
        if (record->event.pressed) {
            if (!is_ru) switch_lang(RU);
            SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)));
            if (!is_ru) switch_lang(EN);
        }
        break;

    // // open notifications and move cursor to 'clear notifications'
    // case MRS_NOTIF:
    //     if (record->event.pressed) {
    //         SEND_STRING(SS_LGUI(SS_TAP(X_N)) SS_DELAY(3) SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_N)))));
    //     }
    //     break;

    }

    return true;
}

// , .
void comdot_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string(","); break;
        case DOUBLE_TAP: send_one_string("."); break;
    }
}
// ; :
void colons_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string(";"); break;
        case DOUBLE_TAP: send_one_string(":"); break;
    }
}
// "/ \"
void slashes_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("/"); break;
        case DOUBLE_TAP: send_one_string("\\"); break;
    }
}
// { }
void crbrkts_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("{"); break;
        case DOUBLE_TAP: send_one_string("}"); break;
    }
}

// left modifiers:
// ~ / Ctrl
void tild_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("~"); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
        case DOUBLE_TAP: send_one_string("~~"); break;
    }
}
void tild_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LCTL);
}
// < > / Shift
void ltgt_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("<"); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: send_one_string(">"); break;
    }
}
void ltgt_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LSFT);
}
// [ ] / Meta
void brkts_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("["); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: send_one_string("]"); break;
    }
}
void brkts_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LGUI);
}
// ( ) / Alt
void prnts_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("("); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: send_one_string(")"); break;
    }
}
void prnts_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LALT);
}

// right modifiers:
// + / Ctrl
void plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("+"); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
    }
}
void plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LCTL);
}
// = / Shift
void equal_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("="); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
    }
}
void equal_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LSFT);
}
// ' " / Meta
void quotes_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("'"); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: send_one_string("\""); break;
    }
}
void quotes_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LGUI);
}
// ? ! / Alt
void marks_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_one_string("?"); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: send_one_string("!"); break;
    }
}
void marks_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_LALT);
}


// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_MAIN] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, LR_MAIN),                          // Esc / LR_MAIN

    [RU_SOFT_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),                            // Ь / Ъ
    [RU_B_JU] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),                               // Б / Ю

    [COMDOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comdot_finished, NULL),               // , .
    [COLONS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, colons_finished, NULL),               // ; :
    [SLASHES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slashes_finished, NULL),             // '/ \'
    [CRBRKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, crbrkts_finished, NULL),             // { }

    [TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tild_finished, tild_reset),             // ~   / Ctrl
    [LTGT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ltgt_finished, NULL),                   // < > / Shift
    [BRKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, brkts_finished, brkts_reset),          // [ ] / Meta
    [PRNTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, prnts_finished, prnts_reset),          // ( ) / Alt

    [PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, plus_finished, plus_reset),             // +   / Ctrl
    [EQUAL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, equal_finished, equal_reset),          // =   / Shift
    [QUOTES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quotes_finished, quotes_reset),       // ' " / Meta
    [MARKS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, marks_finished, marks_reset),          // ? ! / Alt
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LR_MAIN] = LAYOUT_split_3x6_3(
    // 1st row:
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    // 2nd row:
    KC_ENT, CTL_T(KC_A), SFT_T(KC_S), GUI_T(KC_D), ALT_T(KC_F), KC_G,           KC_H, ALT_T(KC_J), GUI_T(KC_K), SFT_T(KC_L), CTL_T(KC_SCLN), KC_BSPC,
    // 3rd row:
    MO(LR_SERVICE), KC_Z, KC_X, KC_C, KC_V, KC_B,                               KC_N, TD(RU_SOFT_HARD), TD(RU_B_JU), TD(COLONS), TD(COMDOT), KC_QUOT,
    // 4th row:
    KC_NO, LT(LR_MOUSE, KC_TAB), LT(LR_NUMS, KC_SPC),                           LT(LR_ARROWS, KC_SPC), LT(LR_WILDS, KC_ENT), OSL(LR_WILDS)
),
[LR_NUMS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,                           KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, KC_NLCK,
    // 2nd row:
    KC_ENT, KC_LCTL, SFT_T(KC_F4), GUI_T(KC_F5),  ALT_T(KC_F6), KC_F11,         KC_PAST, ALT_T(KC_4), GUI_T(KC_5), SFT_T(KC_6), CTL_T(KC_PPLS), KC_BSPC,
    // 3rd row:
    MO(LR_SERVICE), KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                         KC_0, KC_1, KC_2, KC_3, TD(COMDOT), KC_ALGR,
    // 4th row:
    KC_NO, LT(LR_MOUSE, KC_TAB), KC_NO,                                         LT(LR_ARROWS, KC_SPC), LT(LR_WILDS, KC_ENT), OSL(LR_WILDS)
),
[LR_WILDS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_NO, MRS_AT, MRS_HASH, KC_NO,                        TD(SLASHES), MRS_PIPE, MRS_AMPR, MRS_LODASH, MRS_MINUS, KC_NO,
    // 2nd row:
    KC_ENT, TD(TILD), TD(LTGT), TD(BRKTS), TD(PRNTS), TD(CRBRKTS),              MRS_ASTRX, TD(MARKS), TD(QUOTES), TD(EQUAL), TD(PLUS), KC_BSPC,
    // 3rd row:
    MO(LR_SERVICE), KC_NO, KC_NO, MRS_DLR, MRS_PRCNT, KC_NO,                    KC_NO, MRS_GRAVE, MRS_CIRC, TD(COLONS), TD(COMDOT), KC_NO,
    // 4th row:
    KC_NO, LT(LR_MOUSE, KC_TAB), LT(LR_NUMS, KC_SPC),                           LT(LR_ARROWS, KC_SPC), MRS_EN, MRS_RU
),
[LR_MOUSE] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN5, KC_NO,
    // 2nd row:
    KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1,                        KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_BSPC,
    // 3rd row:
    MO(LR_SERVICE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_NO, KC_NO, KC_BTN3, KC_NO, KC_APP, KC_NO,
    // 4th row:
    KC_NO, KC_NO, LT(LR_NUMS, KC_SPC),                                          LT(LR_ARROWS, KC_SPC), LT(LR_WILDS, KC_ENT), OSL(LR_WILDS)
),
[LR_ARROWS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO,
    // 2nd row:
    KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_BSPC,
    // 3rd row:
    MO(LR_SERVICE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_NO, KC_NO, KC_NO, KC_NO, KC_APP, KC_NO,
    // 4th row:
    KC_NO, LT(LR_MOUSE, KC_TAB), LT(LR_NUMS, KC_SPC),                           KC_NO, LT(LR_WILDS, KC_ENT), OSL(LR_WILDS)
),
[LR_SERVICE] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_NO, KC_NO, MRS_RU_NUM, MRS_RU_YO,                   RESET, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO,
    // 2nd row:
    KC_NO, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,
    // 3rd row:
    MO(LR_SERVICE), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                          MRS_LANG_SWITCH_VAR, MRS_LANG_CAPS_SHIFT, MRS_LANG_SHIFT_ALT, MRS_LANG_ALT_SPACE, MRS_LANG_CTRL_SHIFT, KC_NO,
    // 4th row:
    KC_VOLD, KC_VOLU, KC_MUTE,                                                  KC_MPLY, KC_MPRV, KC_MNXT
),
// [LR_GAME1] = LAYOUT_split_3x6_3(
//     // 1st row:
//     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ESC,
//     // 2nd row:
//     KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSPC,
//     // 3rd row:
//     KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_SLSH, TD(COLONS), TD(COMDOT), TO(LR_MAIN),
//     // 4th row:
//     TO(LR_GAME2), KC_LALT, KC_SPC,                                              KC_SPC, KC_ENT, KC_LALT
// ),
// [LR_GAME2] = LAYOUT_split_3x6_3(
//     // 1st row:
//     KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC,                                       KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_ESC,
//     // 2nd row:
//     KC_CAPS, GUI_T(KC_F1), ALT_T(KC_F2), CTL_T(KC_F3), SFT_T(KC_F4), KC_ENT,    KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_BSPC,
//     // 3rd row:
//     KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,                                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(LR_MAIN),
//     // 4th row:
//     KC_NO, KC_LALT, KC_SPC,                                                     KC_SPC, KC_LALT, KC_ENT
// )
};
