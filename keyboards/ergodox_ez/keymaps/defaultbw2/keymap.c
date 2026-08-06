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
    _ONE
};

/* =========================
   Custom Keycodes
   ========================= */

enum custom_keycodes {
    TH_COPYCUT = SAFE_RANGE,
    TH_PLAINPASTE,
    TH_UNDERSCORE_F5,
    TH_TILDE_F23,
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
   Layout Helpers
   ========================= */

// Each half is defined separately then joined at build time.
// Row 2 has 6 keys per side (no inner column key).
// Row 4 has 5 keys per side (no outer two keys).
// Thumb cluster: 2 outer + 1 mid + 3 inner per side.

// ERGODOX_LAYER takes all 76 args: 38 left half first, then 38 right half.
// Use the "// --- RIGHT ---" comment in the keymap to find the divider.
// Row 2 has 6 keys per side (no inner column). Row 4 has 5 keys per side.
// Thumb cluster: 2 outer, 1 mid, 3 inner per side.
#define ERGODOX_LAYER(                                          \
    L00,L01,L02,L03,L04,L05,L06,                               \
    L10,L11,L12,L13,L14,L15,L16,                               \
    L20,L21,L22,L23,L24,L25,                                   \
    L30,L31,L32,L33,L34,L35,L36,                               \
    L40,L41,L42,L43,L44,                                       \
    L55,L56,                                                    \
    L54,                                                        \
    L53,L52,L51,                                                \
    R00,R01,R02,R03,R04,R05,R06,                               \
    R10,R11,R12,R13,R14,R15,R16,                               \
    R21,R22,R23,R24,R25,R26,                                   \
    R30,R31,R32,R33,R34,R35,R36,                               \
    R42,R43,R44,R45,R46,                                       \
    R50,R51,                                                    \
    R52,                                                        \
    R55,R54,R53                                                 \
) LAYOUT_ergodox_pretty(                                        \
    L00,L01,L02,L03,L04,L05,L06, R00,R01,R02,R03,R04,R05,R06, \
    L10,L11,L12,L13,L14,L15,L16, R10,R11,R12,R13,R14,R15,R16, \
    L20,L21,L22,L23,L24,L25,         R21,R22,R23,R24,R25,R26, \
    L30,L31,L32,L33,L34,L35,L36, R30,R31,R32,R33,R34,R35,R36, \
    L40,L41,L42,L43,L44,                 R42,R43,R44,R45,R46, \
                        L55,L56, R50,R51,                      \
                            L54, R52,                          \
                    L53,L52,L51, R55,R54,R53                   \
)

/* =========================
   Keymaps
   ========================= */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ================= ZERO ================= */

[_ZERO] = ERGODOX_LAYER(
    // --- LEFT ---
    lt_OneEsc,            ltOneNotEqual, lt2Rename, lt3RebuildVS,        lt4RemoveBreakpoint, lt5Comment, lt6Uncomment,
    ltTabAltTab,          KC_Q,          KC_W,      KC_F,                KC_P,                KC_G,       MT(MOD_LALT|MOD_LSFT|MOD_LCTL,KC_F24),
    TH_TILDE_F23,         KC_A,          KC_R,      KC_S,                KC_T,                KC_D,
    KC_LSFT,  ltZUndo,       KC_X,      KC_C,                KC_V,                KC_B,       KC_EQUAL,
    MT(MOD_LCTL,KC_BSPC), KC_LGUI,       MT(MOD_LALT,KC_ENT),           TH_COPYCUT,          TH_PLAINPASTE,
    ltF3CtrlF,            ltF5ShiftF5,
    ltF12CtrlMinus,
    KC_BTN1,              KC_BTN2,       LT(_ONE,KC_F15),
    // --- RIGHT ---
    lt7F7,                lt8CloseAllButThis, lt9Breakpoint, KC_0,       KC_MINUS,            KC_BSPC,    KC_DEL,
    ltPASTF22,            KC_J,          KC_L,      KC_U,                KC_Y,                KC_SCLN,    ltBrLBrR,
    KC_H,                 ltNNew,        KC_E,      KC_I,                KC_O,                KC_QUOT,
    ltPPLSF21,            ltKFormat,     KC_M,      ltCommCtrlComm,      KC_DOT,              KC_SLSH,    KC_BSLS,
    KC_LEFT,              KC_UP,         KC_RIGHT,  KC_DOWN,             TH_UNDERSCORE_F5,
    MT(MOD_LALT|MOD_LSFT|MOD_LCTL,KC_HOME), KC_END,
    KC_PGUP,
    LT(_ONE,KC_PGDN),     KC_ENT,        KC_SPC
),

/* =================== ONE =================== */

[_ONE] = ERGODOX_LAYER(
    // --- LEFT ---
    TO(_ZERO),  C(KC_S),    KC_TRNS,    KC_1,          KC_1,       RESET,      KC_SLEP,
    _______,    _______,    _______,    _______,        _______,    _______,    _______,
    _______,    _______,    _______,    _______,        _______,    _______,
    _______,    _______,    _______,    _______,        _______,    _______,    _______,
    _______,    _______,    _______,    _______,        _______,
    _______,    C(S(KC_F5)),
    C(KC_F12),
    _______,    _______,    _______,
    // --- RIGHT ---
    ltF7PW,     RUN_CMD_DATE, KC_F9,    KC_F10,         KC_F11,     KC_F12,     _______,
    _______,    _______,    KC_MS_WH_UP, _______,        _______,    _______,    _______,
    _______,    KC_MS_LEFT, KC_MS_UP,   KC_MS_RIGHT,    KC_MS_DOWN, _______,
    _______,    _______,    KC_MS_WH_DOWN, _______,      _______,   _______,    _______,
    KC_F11,     KC_F10,     S(KC_F11),  S(KC_F9),       S(KC_F10),
    _______,    KC_VOLU,
    _______,
    KC_VOLD,    _______,    KC_MPLY
)

};

/* =========================
   LED Layer Indicators
   ========================= */

layer_state_t layer_state_set_user(layer_state_t state) {

    if (get_highest_layer(state) == _ONE) {
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
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

        case TH_COPYCUT: {
            static uint16_t timer;
            if (record->event.pressed) {
                timer = timer_read();
            } else {
                if (timer_elapsed(timer) < TAPPING_TERM) {
                    tap_code16(C(KC_C));
                    ergodox_right_led_1_off();
                } else {
                    tap_code16(C(KC_X));
                    ergodox_right_led_1_on();
                }
            }
            return false;
        }

        case TH_PLAINPASTE: {
            static uint16_t timer;
            if (record->event.pressed) {
                timer = timer_read();
            } else {
                if (timer_elapsed(timer) < TAPPING_TERM) {
                    tap_code16(C(KC_V));
                } else {
                    tap_code16(C(S(KC_V)));
                }
            }
            return false;
        }

        case TH_UNDERSCORE_F5: {
            static uint16_t timer;
            if (record->event.pressed) {
                timer = timer_read();
            } else {
                if (timer_elapsed(timer) < TAPPING_TERM) {
                    tap_code16(S(KC_MINS));
                } else {
                    tap_code16(KC_F5);
                }
            }
            return false;
        }

        case TH_TILDE_F23: {
            static uint16_t timer;
            if (record->event.pressed) {
                timer = timer_read();
            } else {
                if (timer_elapsed(timer) < TAPPING_TERM) {
                    tap_code16(S(KC_GRV));
                } else {
                    tap_code16(KC_F23);
                }
            }
            return false;
        }

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
