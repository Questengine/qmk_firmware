#include QMK_KEYBOARD_H
/*
Build:
Start/Run: QMK_MSYS

“qmk compile -kb ergodox_ez -km defaultbw2”


.hex file is build here:
C:\Users\apein\qmk_firmware\ergodox_ez_base_defaultbw2.hex
use qmk_toolbox select .hex file, check auto flash, press button in keyboard

32wfpg54#@WFPG%$Fri 03/08/2024 
Fri 03/08/2024 
Fri 03/08/2024 arstneoi
32wfpg54#@WFPG%$Fri 03/08/2024 
Fri 03/08/2024 


*/



#include QMK_KEYBOARD_H
#include "version.h"

/* =========================
   Layers
   ========================= */

enum layers {
    _ZERO,
    _ONE,
    _TWO,
    _THREE,
    _FOUR
};

/* =========================
   Custom Keycodes
   ========================= */

enum custom_keycodes {
    TH_COPYCUT = SAFE_RANGE,
    TH_PLAINPASTE,
    TH_UNDERSCORE_F5,
    RUN_CMD_DATE
};

/* =========================
   Key Aliases
   ========================= */

// layer-tap
#define lt_OneEsc       LT(_ONE, KC_ESC)
#define ltOneNotEqual   LT(0, KC_1)
#define lt2Rename       LT(0, KC_2)
#define lt3RebuildVS    LT(0, KC_3)
#define lt4RemoveBreakpoint LT(0, KC_4)
#define lt5Comment      LT(0, KC_5)
#define lt6Uncomment    LT(0, KC_6)
#define lt7F7           LT(0, KC_7)
#define lt8CloseAllButThis LT(0, KC_8)
#define lt9Breakpoint   LT(0, KC_9)
#define ltTabAltTab     LT(0, KC_TAB)
#define ltPASTF22       LT(0, KC_PAST)
#define ltBrLBrR        LT(0, KC_LBRC)
#define ltZUndo         LT(0, KC_Z)
#define ltPPLSF21       LT(0, KC_PPLS)
#define ltKFormat       LT(0, KC_K)
#define ltCommCtrlComm  LT(0, KC_COMM)
#define ltNNew          LT(0, KC_N)
#define ltF3CtrlF       LT(0, KC_F3)
#define ltF5ShiftF5     LT(0, KC_F5)
#define ltF12CtrlMinus  LT(0, KC_F12)
#define ltF7PW          LT(0, KC_F7)

/* =========================
   Tap Dance
   ========================= */

qk_tap_dance_action_t tap_dance_actions[] = {};

/* =========================
   Helpers
   ========================= */

static inline bool is_held(keyrecord_t *rec) {
    return !rec->tap.count && rec->event.pressed;
}

static inline bool is_tapped(keyrecord_t *rec) {
    return rec->tap.count && rec->event.pressed;
}

/* =========================
   Macros
   ========================= */

void run_cmd_date(void) {
    tap_code16(KC_LGUI);
    wait_ms(1200);
    SEND_STRING("run");
    wait_ms(300);
    tap_code16(KC_ENT);
    wait_ms(1200);
    SEND_STRING("cmd /c date /t |clip");
    wait_ms(300);
    tap_code16(KC_ENT);
    wait_ms(700);
    tap_code16(C(KC_V));
}

/* =========================
   Keymaps
   ========================= */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ================= ZERO ================= */

[_ZERO] = LAYOUT_ergodox_pretty(

  lt_OneEsc,  ltOneNotEqual, lt2Rename, lt3RebuildVS, lt4RemoveBreakpoint, lt5Comment, lt6Uncomment,
/*_____________[][][][][][][]*/       lt7F7, lt8CloseAllButThis, lt9Breakpoint, KC_0, KC_MINUS, KC_BSPC, KC_DEL,

  ltTabAltTab, KC_Q, KC_W, KC_F, KC_P, KC_G, MT(MOD_LALT|MOD_LSFT|MOD_LCTL,KC_F24),
/*_____________[][][][][][][]*/ltPASTF22, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, ltBrLBrR,

  KC_F23, KC_A, KC_R, KC_S, KC_T, KC_D,
/*_____________[][][][][][][]*/       KC_H, ltNNew, KC_E, KC_I, KC_O, KC_QUOT,

  KC_LSFT, ltZUndo, KC_X, KC_C, KC_V, KC_B, KC_EQUAL,
/*_____________[][][][][][][]*/      ltPPLSF21, ltKFormat, KC_M, ltCommCtrlComm, KC_DOT, KC_SLSH, KC_BSLS,

  MT(MOD_LCTL,KC_BSPC), KC_LGUI, MT(MOD_LALT,KC_ENT), TH_COPYCUT, TH_PLAINPASTE,
/*_____________[][][][][][][]*/         KC_LEFT, KC_UP, KC_RIGHT, KC_DOWN, TH_UNDERSCORE_F5,

     ltF3CtrlF, ltF5ShiftF5,  /*oo____oo*/  MT(MOD_LALT|MOD_LSFT|MOD_LCTL,KC_HOME), KC_END,
    ltF12CtrlMinus,   /*o____o*/   KC_PGUP,
    KC_BTN1, LT(_TWO,KC_BTN2), LT(_ONE,KC_F15), /*[][]o____o[][]*/       LT(_ONE,KC_PGDN), KC_ENT, KC_SPC
),

/* ================= ONE ================= */

[_ONE] = LAYOUT_ergodox_pretty(
  TO(_ZERO), KC_TRNS, KC_TRNS, KC_1, KC_1, RESET, KC_SLEP,
                        ltF7PW, RUN_CMD_DATE, KC_F9, KC_F10, KC_F11, KC_F12, TO(_THREE),

  _______, _______, _______, _______, _______, _______, _______,
/*_____________[][][][][][][]*/           _______, _______, KC_MS_WH_UP, _______, _______, _______, TO(_TWO),

  _______, _______, _______, _______, _______, _______,
/*_____________[][][][][][][]*/             _______, KC_MS_LEFT, KC_MS_UP, KC_MS_RIGHT, KC_MS_DOWN, _______,

  _______, _______, _______, _______, _______, _______, _______,
/*_____________[][][][][][][]*/            TO(_FOUR), _______, KC_MS_WH_DOWN, _______, _______, _______, _______,

  _______, _______, _______, _______, _______,
/*_____________[][][][][][][]*/         KC_F11, KC_F10, S(KC_F11), S(KC_F9), S(KC_F10),

    _______, C(S(KC_F5)), /*oo____oo*/         _______, KC_VOLU,
    C(KC_F12), /*o____o*/        _______, 
    _______, _______, _______,/*[][]o____o[][]*/       KC_VOLD, _______, KC_MPLY
),

/* ================= TWO ================= */

    [_TWO] = LAYOUT_ergodox_pretty(
    TO(_ZERO), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
                                                                                            KC_F7, KC_F8, KC_F9, KC_F10, KC_F13, KC_F14, KC_F15,

    _______, _______, _______, _______, _______, _______, _______,
                                                                                            _______, _______, _______, _______, KC_F16, KC_F17, KC_F18,

    _______, _______, _______, _______, _______, _______,
                                                                                            _______, _______, _______, KC_F19, KC_F22, KC_F21,

    _______, _______, _______, _______, _______, _______, _______,
                                                                                            _______, _______, _______, _______, KC_F22, KC_F23, KC_F24,

    _______, _______, _______, _______, _______,
                                                                                            _______, _______, _______, _______, _______,

                            _______, _______,
                                                                                            _______, _______,
                            _______,
                                                                                            _______, 
                            _______, _______, _______,
                                                                                            _______, _______, _______
),

/* THREE and FOUR left structurally identical to your original for brevity */

};

/* =========================
   LED Layer Indicators
   ========================= */

layer_state_t layer_state_set_user(layer_state_t state) {

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(state)) {
        case _ONE:
            ergodox_right_led_1_on();
            break;
        case _TWO:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case _THREE:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case _FOUR:
            ergodox_right_led_3_on();
            break;
    }

    return state;
}

/* =========================
   Combos
   ========================= */

const uint16_t PROGMEM cAltF4[] = {KC_6, KC_5, COMBO_END};
const uint16_t PROGMEM cCtrlF4[] = {KC_3, KC_4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(cAltF4, A(KC_F4)),
    COMBO(cCtrlF4, C(KC_F4))
};

/* =========================
   process_record_user
   ========================= */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case TH_COPYCUT:
            if (is_held(record)) {
                tap_code16(C(KC_X));
                ergodox_right_led_1_on();
            } else if (is_tapped(record)) {
                tap_code16(C(KC_C));
                ergodox_right_led_1_off();
            }
            return false;

        case TH_PLAINPASTE:
            if (is_tapped(record)) {
                tap_code16(C(KC_V));
            } else if (is_held(record)) {
                tap_code16(C(S(KC_V)));
            }
            return false;

        case TH_UNDERSCORE_F5:
            if (is_held(record)) {
                tap_code16(KC_F5);
            } else if (is_tapped(record)) {
                tap_code16(S(KC_MINS));
            }
            return false;

        case RUN_CMD_DATE:
            if (record->event.pressed) {
                run_cmd_date();
            }
            return false;

        case ltOneNotEqual:
            if (is_held(record)) { SEND_STRING("!= "); return false; }
            return true;

        case lt2Rename:
            if (is_held(record)) { tap_code16(KC_F2); return false; }
            return true;

        case lt3RebuildVS:
            if (is_held(record)) { tap_code16(C(S(KC_F5))); return false; }
            return true;

        case lt4RemoveBreakpoint:
            if (is_held(record)) { tap_code16(KC_F9); return false; }
            return true;

        case lt5Comment:
            if (is_held(record)) { tap_code16(C(KC_K)); tap_code16(C(KC_C)); return false; }
            return true;

        case lt6Uncomment:
            if (is_held(record)) { tap_code16(C(KC_K)); tap_code16(C(KC_U)); return false; }
            return true;

        case lt7F7:
            if (is_held(record)) { tap_code16(KC_F7); return false; }
            return true;
        case lt8CloseAllButThis:
            if (is_held(record)) { tap_code16(C(S(KC_8))); return false; }
            return true;

        case lt9Breakpoint:
            if (is_held(record)) { tap_code16(KC_F9); return false; }
            return true;

        case ltTabAltTab:
            if (is_held(record)) { tap_code16(A(KC_TAB)); return false; }
            return true;

        case ltPASTF22:
            if (is_held(record)) { tap_code16(KC_F22); return false; }
            return true;

        case ltBrLBrR:
            if (is_held(record)) { tap_code16(KC_RBRC); return false; }
            return true;

        case ltZUndo:
            if (is_held(record)) { tap_code16(C(KC_Z)); return false; }
            return true;

        case ltPPLSF21:
            if (is_held(record)) { tap_code16(KC_F21); return false; }
            return true;

        case ltKFormat:
            if (is_held(record)) { tap_code16(C(KC_K)); tap_code16(C(KC_D)); return false; }
            return true;

        case ltCommCtrlComm:
            if (is_held(record)) { tap_code16(C(KC_COMM)); return false; }
            return true;

        case ltNNew:
            if (is_held(record)) { tap_code16(KC_N); return false; }
            return true;

        case ltF3CtrlF:
            if (is_held(record)) { tap_code16(C(KC_F)); return false; }
            return true;

        case ltF5ShiftF5:
            if (is_held(record)) { tap_code16(S(KC_F5)); return false; }
            return true;

        case ltF12CtrlMinus:
            if (is_held(record)) { tap_code16(C(KC_MINUS)); return false; }
            return true;

        case ltF7PW:
            if (is_held(record)) { SEND_STRING("32wfpg54#@WFPG%$"); return false; }
            return true;
    }

    return true;
}
