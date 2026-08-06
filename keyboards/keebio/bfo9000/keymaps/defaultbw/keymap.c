#include QMK_KEYBOARD_H
/*
Build:
Start/Run: QMK_MSYS
"qmk compile -kb keebio/bfo9000 -km defaultbw"

flash from qmk msys with:
qmk flash -kb keebio/bfo9000 -km defaultbw
(press reset button when prompted)
*/

// Edit keymaps below as a 9-wide grid (left half only).
// LAYOUT_HALF expands to the full 18-wide LAYOUT at compile time,
// duplicating your 9 keys into the right-half slots.
#define LAYOUT_HALF( \
    k00,k01,k02,k03,k04,k05,k06,k07,k08, \
    k10,k11,k12,k13,k14,k15,k16,k17,k18, \
    k20,k21,k22,k23,k24,k25,k26,k27,k28, \
    k30,k31,k32,k33,k34,k35,k36,k37,k38, \
    k40,k41,k42,k43,k44,k45,k46,k47,k48, \
    k50,k51,k52,k53,k54,k55,k56,k57,k58  \
) LAYOUT( \
    k00,k01,k02,k03,k04,k05,k06,k07,k08,  k00,k01,k02,k03,k04,k05,k06,k07,k08, \
    k10,k11,k12,k13,k14,k15,k16,k17,k18,  k10,k11,k12,k13,k14,k15,k16,k17,k18, \
    k20,k21,k22,k23,k24,k25,k26,k27,k28,  k20,k21,k22,k23,k24,k25,k26,k27,k28, \
    k30,k31,k32,k33,k34,k35,k36,k37,k38,  k30,k31,k32,k33,k34,k35,k36,k37,k38, \
    k40,k41,k42,k43,k44,k45,k46,k47,k48,  k40,k41,k42,k43,k44,k45,k46,k47,k48, \
    k50,k51,k52,k53,k54,k55,k56,k57,k58,  k50,k51,k52,k53,k54,k55,k56,k57,k58  \
)

#define _LayerZero 0
#define _LayerOne  1

enum custom_keycodes {
    throwaway = SAFE_RANGE,
    mtHyperF24,
    lt2Rename,
    lt7F7,
    ltBrLBrR,
    ltF7PW,
    ltF8PW,
    lt9Breakpoint,
    ltF11StepOver,
    lt5Comment,
    lt6Uncomment,
    ltKFormat,
    ltASelectAll,
    ltBBold,
    ltCSelectAllCopy,
    ltVSelectAllPaste,
    ltCommCtrlComm,
    ltF3CtrlF,
    ltF5ShiftF5,
    ltLDeleteLine,
    ltNNew,
    ltSSave,
    ltF12CtrlMinus,
    ltOneNotEqual,
    ltTabAltTab,
    ltZUndo,
    lt_OneEsc,
    thCopyCut,
    thPlainPastePaste,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LayerZero] = LAYOUT_HALF(
//	x0                    x1          x2          x3        x4       x5         x6          x7             x8
	KC_DEL,           KC_END,      KC_PGUP,  KC_PGDN,  KC_BTN2,    KC_VOLU,    KC_VOLD,       KC_MNXT,       KC_MPLY,  //y 0
	KC_BSPC,           KC_HOME,       KC_6,      KC_MINS,   KC_PPLS,     KC_MS_DOWN,    KC_RGHT,       KC_RGHT,          KC_SPC,  //y 1
	KC_F5,            KC_9,       KC_6,      KC_3,     KC_EQL,      KC_MS_RIGHT,    KC_UP,        KC_DOWN,           KC_ENT, //y 2
	KC_F2,            KC_8,       KC_5,      KC_2,     KC_PDOT,      KC_MS_UP,    KC_LEFT,     KC_LEFT,         KC_LALT, //y 3
	 C(S(KC_S)),       KC_7,       KC_4,      KC_1,    KC_0    ,   KC_MS_LEFT,    KC_BTN1,      KC_F5,          KC_LGUI,  //y 4
	KC_ESC,          KC_TAB,    KC_F22,    KC_F23,     KC_F24,   KC_APP,   KC_APP,     SFT_T(KC_BSPC),        MT(MOD_LCTL,KC_BSPC)   //y 5
),
// [_LayerZero] = LAYOUT_HALF(
// //	x0                    x1          x2          x3        x4       x5         x6          x7             x8
// 	KC_ESC,               C(S(KC_S)), KC_F2,      KC_MINS,  KC_PPLS, KC_EQL,    lt5Comment, KC_BSPC,       KC_DEL,  //y 0
// 	KC_TAB,               KC_1,       KC_1,      KC_7,       KC_8,     KC_9,    KC_6,       KC_7,          KC_APP,  //y 1
// 	KC_TAB,               KC_Q,       KC_1,      KC_4,       KC_5,     KC_6,    KC_APP,     mtHyperF24,    KC_VOLU, //y 2
// 	KC_F23,               KC_A,       KC_1,      KC_1,       KC_2,     KC_3,    KC_F10,     KC_F11,        KC_VOLD, //y 3
// 	SFT_T(KC_BSPC),       KC_Z,       KC_X ,     KC_0,    KC_UP,   KC_PDOT,   KC_F3,      KC_F5,         KC_MNXT,  //y 4
// 	MT(MOD_LCTL,KC_BSPC), KC_LGUI,    KC_LALT,    KC_LEFT, KC_DOWN, KC_RGHT,   KC_ENT,     KC_SPC,        KC_MPLY   //y 5
// ),

[_LayerOne] = LAYOUT_HALF(
   C(KC_S), C(S(KC_S)), KC_F2,       KC_F3,    KC_F4,   KC_F5,    KC_6,           KC_APP,          mtHyperF24,
   lt_OneEsc, KC_1,     KC_2,        KC_3,     KC_4,    KC_5,     KC_6,           KC_6,            KC_APP,
   KC_TAB,    KC_Q,     KC_W,        KC_F,     KC_P,    KC_G,     KC_PMNS,        mtHyperF24,      KC_TRNS,
   OSL(_LayerOne), ltASelectAll, KC_R, ltSSave, KC_T,  KC_D,     ltF3CtrlF,      ltF5ShiftF5,     KC_TRNS,
   SFT_T(KC_BSPC), KC_Z, LT(0,KC_X), KC_C,   KC_V,    KC_B,     KC_EQUAL,       KC_F12,          KC_TRNS,
   MT(MOD_LCTL,KC_BSPC), KC_LGUI, KC_LALT, C(KC_X), C(KC_C), C(KC_V), KC_BTN1, KC_BTN2,         KC_F5
),

};

// ---------------------------------------------------------------------------

bool isHeld(keyrecord_t *rec) {
    return !rec->tap.count && rec->event.pressed;
}
bool isTapped(keyrecord_t *rec) {
    return rec->tap.count && rec->event.pressed;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case thCopyCut:
        if (isTapped(record)) tap_code16(C(KC_C));
        if (isHeld(record))   tap_code16(C(KC_X));
        return false;

    case thPlainPastePaste:
        if (isTapped(record)) tap_code16(C(KC_V));
        if (isHeld(record))   tap_code16(C(S(KC_V)));
        return false;

    case ltSSave:
        if (isHeld(record)) { tap_code16(C(KC_S)); return false; }
        return true;

    case ltZUndo:
        if (isHeld(record)) { tap_code16(C(KC_Z)); return false; }
        return true;

    case ltF5ShiftF5:
        if (isHeld(record)) { tap_code16(S(KC_F5)); return false; }
        return true;

    case lt2Rename:
        if (isHeld(record)) { tap_code16(KC_F2); return false; }
        return true;

    case ltF3CtrlF:
        if (isHeld(record)) { tap_code16(C(KC_F)); return false; }
        return true;

    case ltF12CtrlMinus:
        if (isHeld(record)) { tap_code16(C(KC_MINUS)); return false; }
        return true;

    case ltCommCtrlComm:
        if (isHeld(record)) { tap_code16(C(KC_COMM)); return false; }
        return true;

    case ltBBold:
        if (isHeld(record)) { tap_code16(C(KC_B)); return false; }
        return true;

    case ltLDeleteLine:
        if (isHeld(record)) { tap_code16(C(KC_L)); return false; }
        return true;

    case ltF11StepOver:
        if (isHeld(record)) { tap_code16(S(KC_F10)); return false; }
        return true;

    case ltTabAltTab:
        if (isHeld(record)) { tap_code16(A(KC_TAB)); return false; }
        return true;

    case ltOneNotEqual:
        if (isHeld(record)) { SEND_STRING("!= "); return false; }
        return true;

    case lt7F7:
        if (isHeld(record)) { tap_code16(KC_F7); return false; }
        return true;

    case ltBrLBrR:
        if (isHeld(record)) { tap_code16(KC_RBRC); return false; }
        return true;

    case ltF7PW:
        if (isHeld(record)) { SEND_STRING("32wfpg54#@WFPG%$"); return false; }
        return true;

    case ltF8PW:
        tap_code16(KC_LGUI);
        wait_ms(1400);
        SEND_STRING("run");
        wait_ms(400);
        tap_code16(KC_ENT);
        wait_ms(1400);
        SEND_STRING("cmd /c date /t |clip");
        wait_ms(400);
        tap_code16(KC_ENT);
        wait_ms(900);
        tap_code16(C(KC_V));
        return false;

    case lt9Breakpoint:
        if (isHeld(record)) { tap_code16(KC_F9); return false; }
        return true;

    case lt5Comment:
        if (isHeld(record)) { tap_code16(C(KC_K)); tap_code16(C(KC_C)); return false; }
        return true;

    case lt6Uncomment:
        if (isHeld(record)) { tap_code16(C(KC_K)); tap_code16(C(KC_U)); return false; }
        return true;

    case ltKFormat:
        if (isHeld(record)) { tap_code16(C(KC_K)); tap_code16(C(KC_D)); return false; }
        return true;

    case ltCSelectAllCopy:
        if (isHeld(record)) { tap_code16(C(KC_A)); tap_code16(C(KC_C)); return false; }
        return true;

    case ltVSelectAllPaste:
        if (isHeld(record)) { tap_code16(C(KC_A)); tap_code16(C(KC_V)); return false; }
        return true;

    case ltNNew:
        if (isHeld(record)) { tap_code16(KC_N); return false; }
        return true;

    case ltASelectAll:
        if (isHeld(record)) { tap_code16(C(KC_A)); return false; }
        return true;

    }
    return true;
}
