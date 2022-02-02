#include QMK_KEYBOARD_H
#include <stdio.h>


/*
    0: EN
    1: RU
*/
int CURRENT_LANG = 0;

/*
    0: Caps / Shift + Caps
    1: Shift + Alt
    2: Alt + Space
    3: Ctrl + Shift
*/
int LAYOUT_HOTKEY = 0;


void toggle_layout_hotkey(int layout_hotkey_number) {
    LAYOUT_HOTKEY = layout_hotkey_number;
}

void switch_to_lang(int lang) {
    if (CURRENT_LANG == lang) return;

    bool is_ru = CURRENT_LANG == 1;

    switch (LAYOUT_HOTKEY) {
        // Caps / Shift + Caps
        case 0:
            if (is_ru) send_string(SS_TAP(X_CAPSLOCK));
            if (!is_ru) send_string(SS_LSFT(SS_TAP(X_CAPSLOCK)));
            break;
        // Shift + Alt
        case 1:
            send_string(SS_LSFT(SS_TAP(X_LALT)));
            break;
        // Alt + Space
        case 2:
            send_string(SS_LALT(SS_TAP(X_SPC)));
            break;
        // Ctrl + Shift
        case 3:
            send_string(SS_LCTL(SS_TAP(X_LSFT)));
            break;
    }

    CURRENT_LANG = lang;
}

void send_one_string(char *one_tap_string) {
    bool is_ru = CURRENT_LANG == 1;

    if (is_ru) switch_to_lang(0); // to EN

    send_string(SS_DELAY(3));
    send_string(one_tap_string);

    if (is_ru) {
        send_string(SS_DELAY(3));
        switch_to_lang(1); // to RU
    }
}
void send_two_strings(qk_tap_dance_state_t *state, char *one_tap_string, char *dbl_tap_string) {
    bool is_ru = CURRENT_LANG == 1;

    if (is_ru) switch_to_lang(0); // to EN

    if (state->count == 1) {
        send_string(SS_DELAY(3));
        send_string(one_tap_string);
    } else {
        send_string(SS_DELAY(3));
        send_string(dbl_tap_string);
    }

    if (is_ru) {
        send_string(SS_DELAY(3));
        switch_to_lang(1); // to RU
    }
}

/*
    action: 0 - need to register
    action: 1 - need to unregister
*/
void toggle_mod_state(int key, int action) {
    if (action == 0) {
        register_code16(key);
        return;
    }
    if (action == 1) {
        unregister_code16(key);
    }
}

bool is_key_holded(qk_tap_dance_state_t *state) {
    if ((state->count == 1) && !(state->interrupted || !state->pressed)) return true;

    return false;
}


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

enum macros {
    MRS_RU = SAFE_RANGE,
    MRS_EN,
    MRS_SWITCH_LANG,
    MRS_LANG_HOTKEY_0,
    MRS_LANG_HOTKEY_1,
    MRS_LANG_HOTKEY_2,
    MRS_LANG_HOTKEY_3,

    MRS_GRAVE,
    // MRS_TILD,
    MRS_EXLM,
    MRS_QUES,
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
};


// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_ru = CURRENT_LANG == 1;

    switch (keycode) {
    // Language's layout macros
    case MRS_RU:
        if (record->event.pressed) switch_to_lang(1); // to EN
        break;
    case MRS_EN:
        if (record->event.pressed) switch_to_lang(0); // to RU
        break;
    // switch lang var to next
    case MRS_SWITCH_LANG:
        if (record->event.pressed) {
            CURRENT_LANG = (CURRENT_LANG == 0) ? 1 : 0;
        }
        break;
    case MRS_LANG_HOTKEY_0:
        if (record->event.pressed) toggle_layout_hotkey(0); // Caps / Shift + Caps
        break;
    case MRS_LANG_HOTKEY_1:
        if (record->event.pressed) toggle_layout_hotkey(1); // Shift + Alt
        break;
    case MRS_LANG_HOTKEY_2:
        if (record->event.pressed) toggle_layout_hotkey(2); // Alt + Space
        break;
    case MRS_LANG_HOTKEY_3:
        if (record->event.pressed) toggle_layout_hotkey(3); // Ctrl + Shift
        break;

    // Wildcards macros
    case MRS_GRAVE: // `
        if (record->event.pressed) send_one_string("`");
        break;
    // case MRS_TILD: // ~
    //     if (record->event.pressed) send_one_string("~");
    //     break;
    case MRS_EXLM: // !
        if (record->event.pressed) send_one_string("!");
        break;
    case MRS_QUES: // ?
        if (record->event.pressed) send_one_string("?");
        break;
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
            if (!is_ru) switch_to_lang(1); // to RU
            SEND_STRING(SS_LSFT(SS_TAP(X_3)));
            if (!is_ru) switch_to_lang(0); // to EN
        }
        break;
    case MRS_RU_YO: // Ё
        if (record->event.pressed) {
            if (!is_ru) switch_to_lang(1);
            SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)));
            if (!is_ru) switch_to_lang(0);
        }
        break;

    // open notifications and move cursor to 'clear notifications'
    case MRS_NOTIF:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_N)) SS_DELAY(3) SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_N)))));
        }
        break;
    }

    return true;
}

// , .
void comdot_finished(qk_tap_dance_state_t *state, void *user_data) {
    send_two_strings(state, ",", ".");
}
// ; :
void colons_finished(qk_tap_dance_state_t *state, void *user_data) {
    send_two_strings(state, ";", ":");
}
// "/ \"
void slashes_finished(qk_tap_dance_state_t *state, void *user_data) {
    send_two_strings(state, "/", "\\");
}
// left modifiers:
// { } / Shift
void crbrkts_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LSFT, 0);
        return;
    }
    send_two_strings(state, "{", "}");
}
void crbrkts_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LSFT, 1);
}
// [ ] / Ctrl
void brkts_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LCTL, 0);
        return;
    }
    send_two_strings(state, "[", "]");
}
void brkts_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LCTL, 1);
}
// ' " / Alt
void quotes_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LALT, 0);
        return;
    }
    send_two_strings(state, "'", "\"");
}
void quotes_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LALT, 1);
}
// ~ / Meta
void tild_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LGUI, 0);
        return;
    }
    send_one_string("~");
}
void tild_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LGUI, 1);
}
// right modifiers:
// ( ) / Shift
void prnts_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LSFT, 0);
        return;
    }
    send_two_strings(state, "(", ")");
}
void prnts_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LSFT, 1);
}
// < > / Ctrl
void ltgt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LCTL, 0);
        return;
    }
    send_two_strings(state, "<", ">");
}
void ltgt_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LCTL, 1);
}
// = / Alt
void equal_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LALT, 0);
        return;
    }
    send_one_string("=");
}
void equal_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LALT, 1);
}
// + / Meta
void plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (is_key_holded(state)) {
        toggle_mod_state(KC_LGUI, 0);
        return;
    }
    send_one_string("+");
}
void plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    toggle_mod_state(KC_LGUI, 1);
}


// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_MAIN] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, LR_MAIN),                          // Esc / LR_MAIN

    [RU_SOFT_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),                            // Ь / Ъ
    [RU_B_JU] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),                               // Б / Ю

    [COMDOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comdot_finished, NULL),               // , .
    [COLONS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, colons_finished, NULL),               // ; :
    [SLASHES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slashes_finished, NULL),             // '/ \'

    [CRBRKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, crbrkts_finished, crbrkts_reset),    // { } / Shift
    [BRKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, brkts_finished, brkts_reset),          // [ ] / Ctrl
    [QUOTES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quotes_finished, quotes_reset),       // ' " / Alt
    [TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tild_finished, tild_reset),             // ~   / Meta

    [PRNTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, prnts_finished, prnts_reset),          // ( ) / Shift
    [LTGT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ltgt_finished, NULL),                   // < > / Ctrl
    [EQUAL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, equal_finished, equal_reset),          // =   / Alt
    [PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, plus_finished, plus_reset),             // +   / Meta
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LR_MAIN] = LAYOUT_split_3x6_3(
    // 1st row:
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    // 2nd row:
    KC_TAB, GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,           KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), GUI_T(KC_SCLN), LT(LR_SERVICE, KC_ENT),
    // 3rd row:
    KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,                                        KC_N, TD(RU_SOFT_HARD), TD(RU_B_JU), TD(COLONS), TD(COMDOT), KC_QUOT,
    // 4th row:
    KC_DEL, MO(LR_MOUSE), LT(LR_ARROWS, KC_SPC),                                LT(LR_NUMS, KC_SPC), OSL(LR_WILDS), KC_BSPC
),
[LR_WILDS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_NO, MRS_HASH, MRS_DLR, KC_NO,                       TD(SLASHES), MRS_PRCNT, MRS_AT, MRS_LODASH, MRS_MINUS, KC_NO,
    // 2nd row:
    KC_TAB, TD(TILD), TD(QUOTES), TD(BRKTS), TD(CRBRKTS), MRS_GRAVE,            MRS_ASTRX, TD(PRNTS), TD(LTGT), TD(EQUAL), TD(PLUS), KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, MRS_EXLM, MRS_QUES, KC_NO,                             MRS_CIRC, MRS_AMPR, MRS_PIPE, TD(COLONS), TD(COMDOT), KC_NO,
    // 4th row:
    KC_DEL, MO(LR_MOUSE), LT(LR_ARROWS, KC_SPC),                                MRS_RU, MRS_EN, KC_BSPC
),
[LR_NUMS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,                           KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, KC_NLCK,
    // 2nd row:
    KC_TAB, KC_LGUI, ALT_T(KC_F4), CTL_T(KC_F5), SFT_T(KC_F6), KC_F11,          KC_PAST, SFT_T(KC_4), CTL_T(KC_5), ALT_T(KC_6), GUI_T(KC_PPLS), KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                                  KC_0, KC_1, KC_2, KC_3, TD(COMDOT), KC_ALGR,
    // 4th row:
    KC_DEL, MO(LR_MOUSE), LT(LR_ARROWS, KC_SPC),                                KC_NO, OSL(LR_WILDS), KC_BSPC
),
[LR_MOUSE] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_APP, KC_BTN4, KC_MS_U, KC_BTN5, KC_NO, KC_NO,
    // 2nd row:
    KC_TAB, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN1,                        KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_WH_U, KC_BTN1, KC_BTN3, KC_BTN2, KC_NO, KC_NO,
    // 4th row:
    KC_DEL, KC_NO, LT(LR_ARROWS, KC_SPC),                                       LT(LR_NUMS, KC_SPC), OSL(LR_WILDS), KC_BSPC
),
[LR_ARROWS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_APP, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
    // 2nd row:
    KC_TAB, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN1,                        KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_ENT,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_PGDN, KC_HOME, KC_NO, KC_END, KC_NO, KC_NO,
    // 4th row:
    KC_DEL, MO(LR_MOUSE), KC_NO,                                                LT(LR_NUMS, KC_SPC), OSL(LR_WILDS), KC_BSPC
),
[LR_SERVICE] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_NO, MRS_RU_NUM, KC_NO, MRS_RU_YO,                   RESET, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO,
    // 2nd row:
    KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                           MRS_SWITCH_LANG, TO(LR_GAME1), KC_NO, KC_NO, KC_NO, KC_NO,
    // 3rd row:
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, MRS_LANG_HOTKEY_0, MRS_LANG_HOTKEY_1, MRS_LANG_HOTKEY_2, MRS_LANG_HOTKEY_3, KC_NO,
    // 4th row:
    KC_MUTE, KC_VOLD, KC_VOLU,                                                  KC_MPLY, KC_MPRV, KC_MNXT
),
[LR_GAME1] = LAYOUT_split_3x6_3(
    // 1st row:
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ESC,
    // 2nd row:
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    // 3rd row:
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_SLSH, TD(COLONS), TD(COMDOT), TO(LR_MAIN),
    // 4th row:
    TO(LR_GAME2), KC_LALT, KC_SPC,                                              KC_SPC, KC_LALT, KC_BSPC
),
[LR_GAME2] = LAYOUT_split_3x6_3(
    // 1st row:
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC,                                       KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_ESC,
    // 2nd row:
    KC_CAPS, GUI_T(KC_F1), ALT_T(KC_F2), CTL_T(KC_F3), SFT_T(KC_F4), KC_ENT,    KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_ENT,
    // 3rd row:
    KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,                                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(LR_MAIN),
    // 4th row:
    KC_NO, KC_LALT, KC_SPC,                                                     KC_SPC, KC_LALT, KC_BSPC
)
};
