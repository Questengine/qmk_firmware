#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

/*

Build:
Start/Run: QMK_MSYS
“qmk compile -kb ergodox_ez -km defaultbw”
Hex:
C:\Users\apein\qmk_firmware\ergodox_ez_defaultbw.hex

*/


//constants for indices to the array of layers
#define _LayerZero 0 // default layer
#define _LayerOne 1
#define _LayerTwo 2

enum custom_keycodes {//aliases for keycodes that are long/complicated
  COLEMAK = SAFE_RANGE,
//tap-hold  
  ltBBold=LT(0,KC_B),
  lt2Rename =LT(0,KC_2),
  ltASelectAll =LT(0,KC_A),
  ltF3CtrlF=LT(0,KC_F3),
  ltF5ShiftF5 =LT(0,KC_F5),
  ltRReply =LT(0,KC_R),
  ltSSave =LT(0,KC_S),
  ltF12ShiftF12=LT(0,KC_F12),
  ltTabAltTab =LT(0,KC_TAB),
  ltZUndo =LT(0,KC_Z),
//layer-tap  
  lt_OneEsc =LT(_LayerOne,KC_ESC),
//unique
  thCopyCut

};

//Tap Dance Declarations
enum {//the enums for the indices in the array of Tap Dance actions
   tapSave_SaveAll=0,
   tapBreakpoint,
   tapDefRef,
   tapDesktop,
   tapFind,
   tapLastPosGoToAll,
   tapStepIntoOver,
   tapEndHypEnd
};

qk_tap_dance_action_t tap_dance_actions[] = {
//[manualArrayIndex] = TapDanceFunctionToCall()   
[tapSave_SaveAll] =   ACTION_TAP_DANCE_DOUBLE(LCTL(KC_S),RCS(KC_S)),  // TAP: ctrl s to save   DOUBLE:  ctrl-shift to save all 
//[tapStepIntoOver] =   ACTION_TAP_DANCE_DOUBLE(KC_F3,LCTL(KC_F)),
[tapFind] =   ACTION_TAP_DANCE_DOUBLE(KC_F3,LCTL(KC_F)),
[tapDefRef] =   ACTION_TAP_DANCE_DOUBLE(KC_F12,KC_F11),
[tapDesktop] =   ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_LEFT)),LCTL(LGUI(KC_RIGHT))),
[tapBreakpoint] =   ACTION_TAP_DANCE_DOUBLE(KC_F9,LCTL(LSFT(KC_F9))),
[tapLastPosGoToAll] =   ACTION_TAP_DANCE_DOUBLE(LCTL(KC_MINS),LCTL(KC_COMM)),
[tapEndHypEnd] =   ACTION_TAP_DANCE_DOUBLE(KC_END,HYPR(KC_END))

};
//11223344jk                dsdsdsdsdsdsdsrrsrsddsbaba 
enum combos {
  KM_ESC,
  JK_TAB,
  QW_SFT,
  TD_LAYER,
};
const uint16_t PROGMEM km_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM td_combo[] = {KC_T, KC_D, COMBO_END};

//combo_t key_combos[COMBO_COUNT] = {
combo_t key_combos[COMBO_COUNT] = {
  [KM_ESC] = COMBO(km_combo, KC_ESC),
  [JK_TAB] = COMBO(jk_combo, KC_TAB),
  [QW_SFT] = COMBO(qw_combo,  MO(_LayerTwo)),
  [TD_LAYER] = COMBO(td_combo, MO(_LayerOne)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_LayerZero] = LAYOUT_ergodox_pretty(  // layer 0 : default
        // left hand
        lt_OneEsc,         KC_1,         lt2Rename,   KC_0,   KC_4,   KC_5,   KC_6,
        ltTabAltTab,    KC_Q,    KC_W,   KC_F,   KC_P,   KC_G,   KC_LCBR,
        MT(MOD_LALT | MOD_LSFT, KC_SPC),      ltASelectAll, ltRReply, ltSSave,   KC_T,   KC_D,
         KC_LSFT,   ltZUndo,  KC_X,   KC_C,   KC_V,   ltBBold,   KC_EQUAL,
        MT(MOD_LCTL , KC_BSPC),       KC_LGUI,    KC_LALT,  thCopyCut   ,C(KC_V),
                                                     ltF3CtrlF, ltF5ShiftF5,
                                                          KC_BTN2,
                                               KC_BTN1,TO(_LayerTwo),ltF12ShiftF12,
//
//
//             
//                                               
        // right hand
                 KC_7,    KC_8,   KC_9,  KC_0,  KC_MINS,   KC_BSPC,   KC_DEL,           
              KC_PAST,    KC_J,   KC_L,  KC_U,   KC_Y,   KC_SCLN,   KC_LBRC,
                          KC_H,   KC_N,  KC_E,   KC_I,   KC_O ,     KC_QUOT,
             KC_PPLS,    KC_K,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,   KC_BSLS,
             KC_LEFT,    KC_UP,     KC_RGHT,    KC_DOWN,   S(KC_MINS),
             KC_HOME,        KC_END,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_SPC
    ),///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    [_LayerOne] = LAYOUT_ergodox_pretty(  // layer 1 : 
        // left hand
        TO(_LayerZero),KC_1,  KC_1,   _______,   _______,   RESET,   KC_SLEP,
        KC_1,         _______,   _______,   _______,   _______,   _______,   KC_1,
        KC_1,      _______,     _______,   _______,   _______,   KC_D,
        _______,        _______,  _______,   _______,   _______,   KC_B,   _______,
        _______,       _______,      _______,        C(KC_C), C(KC_V),
                                                     KC_F3, KC_F5,
                                                              KC_BTN2,
                                               KC_BTN1,KC_BSPC,KC_DEL,
//
//222222111121212311231233331           
//                                               
        // right hand
              TO(_LayerZero),   _______,     _______,        _______,         HYPR(KC_F13),        HYPR(KC_F14),  HYPR(KC_F15),
              _______,   _______,     _______,        _______,                HYPR(KC_F16),        HYPR(KC_F17),  HYPR(KC_F18),
                         _______,     _______,        _______,                 HYPR(KC_F19),        HYPR(KC_F20),   HYPR(KC_F21),
              _______,   _______,     _______,        _______,                HYPR(KC_F22),        HYPR(KC_F23),     HYPR(KC_F24), 
                                     _______,        _______,         _______,        _______,        _______,
             _______, _______,
             _______,
             _______,_______, _______
    ),///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    [_LayerTwo] = LAYOUT_ergodox_pretty(  // layer 1 : 
        // left hand
        TO(_LayerZero),KC_2,  KC_2,   _______,   _______,   _______,   _______,
        KC_2,         KC_2,   _______,   _______,   _______,   _______,   _______,
        KC_2,      _______,     _______,   _______,   _______,   _______,
        _______,        _______,  _______,   _______,   _______,   _______,   _______,
        _______,       _______,      _______,        _______, _______,
                                                     _______, _______,
                                                              _______,
                                               _______,_______,_______,
//
//
//                                               
        // right hand
              _______,   _______,     _______,        _______,       _______,        _______,        _______,
              _______,   _______,     _______,        _______,       _______,        _______,        _______,
                         _______,     _______,        _______,       _______,        _______,        _______,
              _______,   _______,     _______,        _______,       _______,        _______,        _______,
                                     _______,        _______,         _______,        _______,        _______,
             _______, _______,
             _______,
             _______,_______, _______
    ),
};


bool isHeld(keyrecord_t *rec){
   return !rec->tap.count && rec->event.pressed;
 }
bool isTapped(keyrecord_t *rec){
   return rec->tap.count && rec->event.pressed;
 }


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
   switch (keycode) {
        case thCopyCut:   
            if (isHeld(record)) {
                tap_code16(C(KC_X)); // Intercept hold function to send ctrl-X
            }
            if (isTapped(record)) {
                tap_code16(C(KC_C)); // Intercept hold function to send ctrl-C
            }
            return false;             // Return nothing, all senarios handled above
       break;
       case ltSSave:
            if (isHeld(record)) {
                tap_code16(C(KC_S)); 
                return false;
            }
            return true;             
       break;   
        case ltZUndo:
            if (isHeld(record)) {
                tap_code16(C(KC_Z)); 
                return false;
            }
            return true;             
       break;
        case ltF5ShiftF5:
            if (isHeld(record)) {
                tap_code16(S(KC_F5)); 
                return false;
            }
            return true;             
       break;
        case ltF3CtrlF:
            if (isHeld(record)) {
                tap_code16(C(KC_F)); 
                return false;
            }
            return true;             
       break;
        case lt2Rename:
            if (isHeld(record)) {
                tap_code16(KC_F2); 
                return false;
            }
            return true;             
       break;
       case ltASelectAll:
            if (isHeld(record)) {
                tap_code16(C(KC_A)); 
                return false;
            }
            return true;             
       break;
       case ltF12ShiftF12:
            if (isHeld(record)) {
                tap_code16(S(KC_F12)); 
                return false;
            }
            return true;             
       break;
       case ltBBold:
            if (isHeld(record)) {
                tap_code16(C(KC_B)); 
                return false;
            }
            return true;             
       break;
       case ltTabAltTab:
            if (isHeld(record)) {
                tap_code16(A(KC_TAB)); 
                return false;
            }
            return true;             
       break;
      //   case LT(0,KC_X):ltTabAltTab
      //       if (isHeld(record)) {
      //           tap_code16(S(KC_X)
      //           return false;
      //       }
      //       return true;          
      
       
    }
    return true;
    
 }
 
    