#include QMK_KEYBOARD_H
#include <stdio.h>


#define L_SHFT_HELD keyboard_report->mods & (MOD_BIT(KC_LSFT))
#define L_CTRL_HELD keyboard_report->mods & (MOD_BIT(KC_LCTL))
#define L_ALT_HELD keyboard_report->mods & (MOD_BIT(KC_LALT))
#define L_GUI_HELD keyboard_report->mods & (MOD_BIT(KC_LGUI))


enum {
    EN = 0,
    RU,
};
#define DEFAULT_LANG EN;
int CURRENT_LANG = DEFAULT_LANG;
int LANG_ON_CHANGE_TO_WILD_LAYER = DEFAULT_LANG;

enum {
    WILD_LAYER_ON = 0,
    WILD_LAYER_OFF,
};
#define DEFAULT_WILD_LAYER_STATE WILD_LAYER_OFF;
int CURRENT_WILD_LAYER_STATE = DEFAULT_WILD_LAYER_STATE;

enum {
    CAPS_SHIFT = 0,
    SHIFT_ALT,
    ALT_SPACE,
    CTRL_SHIFT,
};
#define DEFAULT_LAYOUT_HOTKEY CAPS_SHIFT;
int LAYOUT_HOTKEY = DEFAULT_LAYOUT_HOTKEY;


void set_layout_hotkey(int layout_hotkey_arg) {
    LAYOUT_HOTKEY = layout_hotkey_arg;
}

void switch_lang_to(int lang) {
    if (CURRENT_LANG == lang) return;

    bool is_ru = CURRENT_LANG == RU;

    bool is_ctrl_held = L_CTRL_HELD;
    bool is_shft_held = L_SHFT_HELD;
    bool is_alt_held = L_ALT_HELD;
    bool is_gui_held = L_GUI_HELD;

    if (is_shft_held) unregister_code(KC_LSFT);
    if (is_ctrl_held) unregister_code(KC_LCTL);
    if (is_alt_held) unregister_code(KC_LALT);
    if (is_gui_held) unregister_code(KC_LGUI);

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
    LANG_ON_CHANGE_TO_WILD_LAYER = lang;

    if (is_shft_held) register_code(KC_LSFT);
    if (is_ctrl_held) register_code(KC_LCTL);
    if (is_alt_held) register_code(KC_LALT);
    if (is_gui_held) register_code(KC_LGUI);
}

void send_key(char *one_tap_string, int lang) {
    int current_lang = CURRENT_LANG;
    bool is_required_lang = current_lang == lang;

    if (!is_required_lang) switch_lang_to(lang);
    send_string(one_tap_string);
    if (!is_required_lang) switch_lang_to(current_lang);
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
};

enum macros {
    MRS_TO_RU = SAFE_RANGE,
    MRS_TO_EN,
    MRS_LANG_SWITCH_VAR,
    MRS_LANG_CAPS_SHIFT,
    MRS_LANG_SHIFT_ALT,
    MRS_LANG_ALT_SPACE,
    MRS_LANG_CTRL_SHIFT,

    MRS_GRAVE,
    MRS_EXLM,
    MRS_QUES,
    MRS_AMPR,
    MRS_SLSH,
    MRS_BSLSH,
    MRS_PIPE,
    MRS_EQUAL,
    MRS_MINUS,
    MRS_AT,
    MRS_HASH,
    MRS_DLR,
    MRS_PRCNT,
    MRS_CIRC,
    MRS_ASTRX,
    MRS_QUOTE,
    MRS_COLON,
    MRS_LBRC,
    MRS_RBRC,
    MRS_LPRNT,
    MRS_RPRNT,
    MRS_LT,
    MRS_GT,

    MRS_RU_DOT,
    MRS_RU_NUM,
    MRS_RU_YO,
};

enum tap_dances {
    ESC_MAIN,

    CRBRKTS,
    PRNTS,
    BRKTS,
    LTGT,

    SLASHES,
    MARKS,
    QUOTES,
    COLONS,
    COMDOT,

    RU_SOFT_HARD,

    // SP_A_M,
};


// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_ru = CURRENT_LANG == RU;

    switch (keycode) {
    // Language's layout macros
    case MRS_TO_RU:
        if (record->event.pressed) switch_lang_to(RU);
        break;
    case MRS_TO_EN:
        if (record->event.pressed) switch_lang_to(EN);
        break;
    case MRS_LANG_SWITCH_VAR:
        if (record->event.pressed) {
            CURRENT_LANG = (CURRENT_LANG == EN) ? RU : EN;
        }
        break;
    case MRS_LANG_CAPS_SHIFT:
        if (record->event.pressed) set_layout_hotkey(CAPS_SHIFT);
        break;
    case MRS_LANG_SHIFT_ALT:
        if (record->event.pressed) set_layout_hotkey(SHIFT_ALT);
        break;
    case MRS_LANG_ALT_SPACE:
        if (record->event.pressed) set_layout_hotkey(ALT_SPACE);
        break;
    case MRS_LANG_CTRL_SHIFT:
        if (record->event.pressed) set_layout_hotkey(CTRL_SHIFT);
        break;

    // Wildcards macros
    case MRS_GRAVE: // `
        if (record->event.pressed) send_key("`", EN);
        break;
    case MRS_EXLM: // !
        if (record->event.pressed) send_key("!", EN);
        break;
    case MRS_QUES: // ?
        if (record->event.pressed) send_key("?", EN);
        break;
    case MRS_AMPR: // &
        if (record->event.pressed) send_key("&", EN);
        break;
    case MRS_SLSH: // /
        if (record->event.pressed) send_key("/", EN);
        break;
    case MRS_BSLSH: // '\'
        if (record->event.pressed) send_key("\\", EN);
        break;
    case MRS_PIPE: // |
        if (record->event.pressed) send_key("|", EN);
        break;
    case MRS_EQUAL: // =
        if (record->event.pressed) send_key("=", EN);
        break;
    case MRS_MINUS: // -
        if (record->event.pressed) send_key("-", EN);
        break;
    case MRS_AT: // @
        if (record->event.pressed) send_key("@", EN);
        break;
    case MRS_HASH: // #
        if (record->event.pressed) send_key("#", EN);
        break;
    case MRS_DLR: // $
        if (record->event.pressed) send_key("$", EN);
        break;
    case MRS_PRCNT: // %
        if (record->event.pressed) send_key("%", EN);
        break;
    case MRS_CIRC: // ^
        if (record->event.pressed) send_key("^", EN);
        break;
    case MRS_ASTRX: // *
        if (record->event.pressed) send_key("*", EN);
        break;
    case MRS_QUOTE: // '
        if (record->event.pressed) send_key("'", EN);
        break;
    case MRS_COLON: // ;
        if (record->event.pressed) send_key(";", EN);
        break;
    case MRS_LBRC: // [
        if (record->event.pressed) send_key("[", EN);
        break;
    case MRS_RBRC: // ]
        if (record->event.pressed) send_key("]", EN);
        break;
    case MRS_LPRNT: // (
        if (record->event.pressed) send_key("(", EN);
        break;
    case MRS_RPRNT: // )
        if (record->event.pressed) send_key(")", EN);
        break;
    case MRS_LT: // <
        if (record->event.pressed) send_key("<", EN);
        break;
    case MRS_GT: // >
        if (record->event.pressed) send_key(">", EN);
        break;
    // case MRS_LPRNT: // (
    //     if (record->event.pressed) {
    //         if (is_ru) switch_lang_to(EN);
    //         SEND_STRING(SS_LSFT(SS_TAP(X_9)));
    //         if (is_ru) switch_lang_to(RU);
    //     }
    //     break;
    // case MRS_RPRNT: // )
    //     if (record->event.pressed) {
    //         if (is_ru) switch_lang_to(EN);
    //         SEND_STRING(SS_LSFT(SS_TAP(X_0)));
    //         if (is_ru) switch_lang_to(RU);
    //     }
    //     break;
    // case MRS_LT: // <
    //     if (record->event.pressed) {
    //         if (is_ru) switch_lang_to(EN);
    //         SEND_STRING(SS_LSFT(SS_TAP(X_COMM)));
    //         if (is_ru) switch_lang_to(RU);
    //     }
    //     break;
    // case MRS_GT: // >
    //     if (record->event.pressed) {
    //         if (is_ru) switch_lang_to(EN);
    //         SEND_STRING(SS_LSFT(SS_TAP(X_DOT)));
    //         if (is_ru) switch_lang_to(RU);
    //     }
    //     break;

    // Wildcards RU macros
    case MRS_RU_DOT: // .
        if (record->event.pressed) send_key("/", RU);
        break;
    case MRS_RU_NUM: // №
        if (record->event.pressed) {
            if (!is_ru) switch_lang_to(RU);
            SEND_STRING(SS_LSFT(SS_TAP(X_3)));
            if (!is_ru) switch_lang_to(EN);
        }
        break;
    case MRS_RU_YO: // Ё
        if (record->event.pressed) {
            if (!is_ru) switch_lang_to(RU);
            SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)));
            if (!is_ru) switch_lang_to(EN);
        }
        break;
    }

    return true;
}

// < >
void ltgt_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_key("<", EN); break;
        case DOUBLE_TAP: send_key(">", EN); break;
    }
}
// [ ]
void brkts_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_key("[", EN); break;
        case DOUBLE_TAP: send_key("]", EN); break;
    }
}
// { }
void crbrkts_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_key("{", EN); break;
        case DOUBLE_TAP: send_key("}", EN); break;
    }
}
// ( )
void prnts_finished(qk_tap_dance_state_t *state, void *user_data) {
    int dance_state = get_tap_state(state);
    switch (dance_state) {
        case SINGLE_TAP: send_key("(", EN); break;
        case DOUBLE_TAP: send_key(")", EN); break;
    }
}

// // Space Arrows Mouse
// void spam_finished(qk_tap_dance_state_t *state, void *user_data) {
//     int dance_state = get_tap_state(state);

//     char *single_space = " ";
//     char *double_space = "  ";

//     switch (dance_state) {
//         case SINGLE_TAP: send_key(single_space); break;
//         case DOUBLE_TAP: send_key(double_space); break;
//         case DOUBLE_SINGLE_TAP: send_key(double_space);

//         case SINGLE_HOLD: layer_on(LR_ARROWS); break;
//         case DOUBLE_HOLD: layer_on(LR_MOUSE); break;
//     }
// }
// void spam_reset(qk_tap_dance_state_t *state, void *user_data) {
//     layer_off(LR_ARROWS);
//     layer_off(LR_MOUSE);
// }

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_MAIN] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, LR_MAIN),                          // Esc / LR_MAIN

    [RU_SOFT_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),                            // Ь / Ъ

    [CRBRKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, crbrkts_finished, NULL),             // { }
    [PRNTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, prnts_finished, NULL),                 // ( )
    [BRKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, brkts_finished, NULL),                 // [ ]
    [LTGT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ltgt_finished, NULL),                   // < >

    // [SP_A_M] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spam_finished, spam_reset),           // Space Arrows Mouse
};

// turn on EN layer on switch to LR_WILDS
layer_state_t layer_state_set_kb(layer_state_t state) {
    bool is_wild_layer_on = IS_LAYER_ON_STATE(state, LR_WILDS);
    bool is_wild_layer_off = IS_LAYER_OFF_STATE(state, LR_WILDS);
    bool prev_is_wild_layer_on = CURRENT_WILD_LAYER_STATE == WILD_LAYER_ON;

    bool is_en = CURRENT_LANG == EN;
    bool is_en_on_change_to_wild_layer = LANG_ON_CHANGE_TO_WILD_LAYER == EN;

    if (is_wild_layer_on && !prev_is_wild_layer_on) {
        CURRENT_WILD_LAYER_STATE = WILD_LAYER_ON;
        LANG_ON_CHANGE_TO_WILD_LAYER = CURRENT_LANG;

        if (!is_en) switch_lang_to(EN);
    }

    if (is_wild_layer_off && prev_is_wild_layer_on) {
        CURRENT_WILD_LAYER_STATE = WILD_LAYER_OFF;

        if (!is_en_on_change_to_wild_layer) switch_lang_to(LANG_ON_CHANGE_TO_WILD_LAYER);
    }

    return state;
}


// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LR_MAIN] = LAYOUT_split_3x6_3(
    // 1st row:
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    // 2nd row:
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSPC,
    // 3rd row:
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                                  KC_N, TD(RU_SOFT_HARD), KC_COMM, KC_DOT, MRS_RU_DOT, LT(LR_SERVICE, KC_QUOT),
    // 4th row:
    KC_LALT, LGUI_T(KC_TAB), LT(LR_MOUSE, KC_SPC),                          LT(LR_ARROWS, KC_SPC), LT(LR_NUMS, KC_ENT), OSL(LR_WILDS)
),
[LR_NUMS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,                       KC_PMNS, KC_7, KC_8, KC_9, KC_PSLS, KC_NLCK,
    // 2nd row:
    KC_LSFT, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11,                            KC_PPLS, KC_4, KC_5, KC_6, KC_PAST, KC_BSPC,
    // 3rd row:
    KC_LCTL, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                            KC_0, KC_1, KC_2, KC_3, MRS_RU_DOT, LT(LR_SERVICE, KC_ALGR),
    // 4th row:
    KC_LALT, LGUI_T(KC_TAB), LT(LR_MOUSE, KC_SPC),                          LT(LR_ARROWS, KC_SPC), KC_NO, OSL(LR_WILDS)
),
[LR_WILDS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), MRS_GRAVE, MRS_AT, MRS_HASH, MRS_DLR, MRS_PRCNT,          MRS_MINUS, MRS_EXLM, MRS_AMPR, MRS_PIPE, MRS_SLSH, MRS_BSLSH,
    // 2nd row:
    KC_LSFT, KC_NO, KC_NO, MRS_LBRC, MRS_RBRC, MRS_CIRC,                    MRS_EQUAL, MRS_QUES, MRS_COLON, MRS_QUOTE, MRS_ASTRX, KC_BSPC,
    // 3rd row:
    KC_LCTL, KC_NO, KC_NO, MRS_LPRNT, MRS_RPRNT, KC_NO,                     KC_NO, KC_NO, MRS_LT, MRS_GT, MRS_RU_DOT, MO(LR_SERVICE),
    // 4th row:
    KC_LALT, LGUI_T(KC_TAB), LT(LR_MOUSE, KC_SPC),                          LT(LR_ARROWS, KC_SPC), MRS_TO_RU, MRS_TO_EN
),
// [LR_WILDS] = LAYOUT_split_3x6_3(
//     // 1st row:
//     TD(ESC_MAIN), MRS_GRAVE, MRS_AT, MRS_HASH, MRS_DLR, MRS_PRCNT,          MRS_MINUS, KC_NO, MRS_AMPR, MRS_PIPE, MRS_SLSH, MRS_BSLSH,
//     // 2nd row:
//     KC_LSFT, TD(LTGT), TD(BRKTS), TD(CRBRKTS), TD(PRNTS), MRS_CIRC,         MRS_EQUAL, MRS_QUES, MRS_COLON, MRS_QUOTE, MRS_ASTRX, KC_BSPC,
//     // 3rd row:
//     KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, MRS_EXLM, KC_NO, KC_NO, MRS_RU_DOT, MO(LR_SERVICE),
//     // 4th row:
//     KC_LALT, LGUI_T(KC_TAB), LT(LR_MOUSE, KC_SPC),                          LT(LR_ARROWS, KC_SPC), MRS_TO_RU, MRS_TO_EN
// ),
[LR_ARROWS] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO,
    // 2nd row:
    KC_LSFT, KC_TRNS, KC_BTN2, KC_BTN3, KC_BTN1, KC_TRNS,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_BSPC,
    // 3rd row:
    KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_APP, MO(LR_SERVICE),
    // 4th row:
    KC_LALT, LGUI_T(KC_TAB), LT(LR_MOUSE, KC_SPC),                          KC_NO, LT(LR_NUMS, KC_ENT), OSL(LR_WILDS)
),
[LR_MOUSE] = LAYOUT_split_3x6_3(
    // 1st row:
    TD(ESC_MAIN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN5, KC_NO,
    // 2nd row:
    KC_LSFT, KC_TRNS, KC_BTN2, KC_BTN3, KC_BTN1, KC_TRNS,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_BSPC,
    // 3rd row:
    KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_BTN3, KC_NO, KC_APP, MO(LR_SERVICE),
    // 4th row:
    KC_LALT, LGUI_T(KC_TAB), KC_NO,                                         LT(LR_ARROWS, KC_SPC), LT(LR_NUMS, KC_ENT), OSL(LR_WILDS)
),
[LR_SERVICE] = LAYOUT_split_3x6_3(
    // 1st row:
    KC_ESC, KC_NO, KC_NO, MRS_RU_NUM, MRS_RU_NUM, MRS_RU_YO,                RESET, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO,
    // 2nd row:
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_DEL,
    // 3rd row:
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             MRS_LANG_SWITCH_VAR, MRS_LANG_CAPS_SHIFT, MRS_LANG_SHIFT_ALT, MRS_LANG_ALT_SPACE, MRS_LANG_CTRL_SHIFT, KC_NO,
    // 4th row:
    KC_VOLD, KC_VOLU, KC_MUTE,                                              KC_MPLY, KC_MPRV, KC_MNXT
),
};
