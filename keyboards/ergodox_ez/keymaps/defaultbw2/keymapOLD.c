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

#include "version.h"

enum layers {
    _Zero,  
    _One,   
    _Two,   
    _Three,   
    _Four,   
};

enum custom_keycodes {
//unique
  throwaway=SAFE_RANGE,
      //mod-tap
    mtAltEnter =  MT(MOD_LALT, KC_ENT),
    mtHyperF24 =  MT(MOD_LALT | MOD_LSFT|  MOD_LCTL,  KC_F24),
    mtAsterikF22 =  MT(KC_PAST,  KC_F22),
    mtHyperHome =  MT(MOD_LALT | MOD_LSFT| MOD_LCTL,  KC_HOME),
    mtAltShiftSpace =  MT(MOD_LALT | MOD_LSFT, KC_SPC),
    mtCtrlBksp=MT(MOD_LCTL, KC_BSPC),
      //HoldTap
      lt2Rename =LT(0,KC_2),
      lt7F7 =LT(0,KC_7),
      ltPASTF22 =LT(0,KC_PAST),
      ltPPLSF21 =LT(0,KC_PPLS), 
      ltBrLBrR =LT(0,KC_LBRC),
      ltF7PW =LT(0,KC_F7),    
      fRunCmdDate =LT(0,KC_F8),
      lt9Breakpoint =LT(0,KC_9),
ltF11StepOver =LT(0,KC_F11),
lt3RebuildVS=LT(0,KC_3),
lt4RemoveBreakpoint=LT(0,KC_4),
      lt5Comment =LT(0,KC_5),
      lt6Uncomment =LT(0,KC_6),
      ltKFormat =LT(0,KC_K),
      ltASelectAll =LT(0,KC_A),
      ltBBold=LT(0,KC_B),
      ltCSelectAllCopy =LT(0,KC_C),
      ltVSelectAllPaste =LT(0,KC_V),
      ltCommCtrlComm =LT(0,KC_COMM),
      ltF3CtrlF=LT(0,KC_F3),
      ltF5ShiftF5 =LT(0,KC_F5),
      ltLDeleteLine =LT(0,KC_L),
      ltNNew =LT(0,KC_N),
      //ltRReply =LT(0,KC_R),     
    ltSSave =LT(0,KC_S),
      ltF12CtrlMinus=LT(0,KC_F12),
      ltOneNotEqual=LT(0,KC_1),
      ltTabAltTab =LT(0,KC_TAB),
      ltZUndo =LT(0,KC_Z),
      //layer-tap  
    lt_OneEsc =LT(_One,KC_ESC),
    lt_OnePgDn =LT(_One,KC_PGDN),
    //lt_OneUnder =LT(_One,S(KC_MINS)),
      thCopyCut,
      thUnderscoreF5,
      thPlainPastePaste,
};


////Tap Dance Declarations!= 
enum {//the enums for the indices in the array of Tap Dance actions
  tapDefRef,

// tapDesktop,
// tapStepIntoOver,neioluy;78900
}; 
//
qk_tap_dance_action_t tap_dance_actions[] = {
//   //[manualArrayIndex] = TapDanceFunctionToCall()   
//   [tapSave_SaveAll] =   ACTION_TAP_DANCE_DOUBLE(LCTL(KC_S),RCS(KC_S)),  // TAP: ctrl s to save   DOUBLE:  ctrl-shift to save all 
//   //[tapStepIntoOver] =   ACTION_TAP_DANCE_DOUBLE(KC_F3,LCTL(KC_F)),
//   [tapFind] =   ACTION_TAP_DANCE_DOUBLE(KC_F3,LCTL(KC_F)),
  [tapDefRef] =   ACTION_TAP_DANCE_DOUBLE(KC_F12,KC_F11),    
//   [tapDesktop] =   ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_LEFT)),LCTL(LGUI(KC_RIGHT))),
//   [tapBreakpoint] =   ACTION_TAP_DANCE_DOUBLE(KC_F9,LCTL(LSFT(KC_F9))),
//   [tapLastPosGoToAll] =   ACTION_TAP_DANCE_DOUBLE(LCTL(KC_MINS),LCTL(KC_COMM)),
//   [tapEndHypEnd] =   ACTION_TAP_DANCE_DOUBLE(KC_END,HYPR(KC_END))


/*test test 1234
28016280162801628016&*JLHNm,nelu90tttttttttttttttttttttttttttttttttttttttttttttttttnnttttttttt

12341oneneooneoin
1
*/
////bbb test tesnt
};
// clang-format off *****222222222222222211111111111
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  
[_Zero] = LAYOUT_ergodox_pretty(  
    
  // left hand
        lt_OneEsc,    ltOneNotEqual,   lt2Rename,  lt3RebuildVS,    lt4RemoveBreakpoint, lt5Comment,  lt6Uncomment,                        lt7F7,    KC_8,    lt9Breakpoint,     KC_0,   KC_MINUS, KC_BSPC,   KC_DEL, 
        ltTabAltTab,   KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,   mtHyperF24,                                                         ltPASTF22,      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,   ltBrLBrR,
         KC_F23,  KC_A,   KC_R,   KC_S ,    KC_T,    KC_D,                                                                     KC_H,    ltNNew,    KC_E,    KC_I,    KC_O,  KC_QUOT,
        KC_LSFT,  ltZUndo, KC_X,   KC_C,    KC_V,    KC_B,   KC_EQUAL,                                                         ltPPLSF21,  ltKFormat,    KC_M,    ltCommCtrlComm, KC_DOT, KC_SLSH,   KC_BSLS,
        mtCtrlBksp,   KC_LGUI,    mtAltEnter, thCopyCut,  thPlainPastePaste,                                                     KC_LEFT, KC_UP, KC_RIGHT,  KC_DOWN,  thUnderscoreF5,
                                            ltF3CtrlF,   ltF5ShiftF5 ,                                                               mtHyperHome, KC_END,
                                                        ltF12CtrlMinus,                                                               KC_PGUP,
                                        KC_BTN1, LT(_Two,KC_BTN2), LT(_One,KC_F15),                                                  lt_OnePgDn, KC_ENT, KC_SPC
        ),     
 
 
            /* Keymap 1_______32wfpg54#@WFPG%$
            */

         [_One] = LAYOUT_ergodox_pretty(  
             
         // left hand
         TO(_Zero), C(KC_S),  C(S(KC_S)),          KC_1,  KC_1,  RESET,   KC_SLEP,                 ltF7PW,     fRunCmdDate,    KC_F9,       KC_F10,   KC_F11, KC_F12,   TO(_Three),     
         KC_1,   KC_1,      _______,  _______,    _______,    _______,    _______,             _______,      _______,    KC_MS_WH_UP,    _______,    _______,   _______,   TO(_Two),
         _______,  _______,  _______,  _______,    _______,    _______,                                    _______,    KC_MS_LEFT,  KC_MS_UP,   KC_MS_RIGHT,   KC_MS_DOWN, _______, 
         _______,  _______, _______,  _______,    _______,    _______,   _______,               TO(_Four),  _______,    KC_MS_WH_DOWN,    _______, _______, _______,   _______,
         _______,  _______,  _______, _______,  _______,                                                          KC_F11,  KC_F10,    S(KC_F11),    S(KC_F9), S(KC_F10), 
                              DM_PLY1,   C(S(KC_F5)) ,                        KC_MPRV, KC_MNXT,
                                        S(KC_F12),                                  KC_VOLU,
                       _______, _______, _______,                                  KC_VOLD, _______, KC_MPLY
         ),
         
         /* Keymap 2: Third
         *            
         *             
         */
         [_Two] = LAYOUT_ergodox_pretty(  
             
         // left hand
         TO(_Zero),      KC_F1,  KC_F2,   KC_F3, KC_F4,  KC_F5, KC_F6,              KC_F7,  KC_F8,    KC_F9,    KC_F10, KC_F13,   KC_F14, KC_F15, 
         KC_2,   KC_2,        _______,  _______,    _______,    _______, _______,                      _______,  _______,    _______,    _______, KC_F16,    KC_F17, KC_F18,
         _______,  _______,  _______,  _______,    _______,    _______,                                    _______,    _______,  _______,    KC_F19,    KC_F22, KC_F21, 
         _______,  _______, _______,  _______,    _______,    _______,   _______,               _______,  _______,    _______,    _______, KC_F22, KC_F23,   KC_F24,
         _______,  _______,  _______, _______,  _______,                                                          _______,  _______,    _______,    _______, _______, 
                                                             S(KC_F11),  KC_F10,                _______, _______,
                                                                        S(KC_F9),                 _______,
                                                      _______, _______, KC_F11,                 _______, _______, _______
         ),

           [_Three] = LAYOUT_ergodox_pretty(
    /* left hand */
    KC_ESC,   KC_1,     KC_2,         KC_3,     KC_4,     KC_5,    KC_LEFT,           KC_RIGHT,     KC_6,   KC_7,   KC_8,     KC_9,         KC_0,         TO(_Zero),
    KC_TAB,  KC_Q,     KC_W,         KC_E,     KC_R,     KC_T,    KC_Y,              KC_PGUP,     KC_Y,   KC_U,   KC_I,     KC_O,         KC_P,         KC_BSLASH,
    _______,    KC_A,     KC_S,         KC_D,     KC_F,     KC_G,                                     KC_H,   KC_J,   KC_K,     KC_L,         KC_SCLN,      KC_0,
    KC_LSFT,    KC_Z,     KC_X,         KC_C,     KC_V,     KC_B, ALT_T(KC_NO),         KC_PGDOWN, KC_N,   KC_M,   KC_COMMA, KC_DOT,       KC_SLASH,     KC_RSPC,
    KC_LCTL,   KC_LBRACKET,  KC_RBRACKET, KC_LEFT,  KC_RIGHT,                                                   KC_UP,  KC_DOWN,  KC_LBRACKET,  KC_RBRACKET,  TO(_Zero),
                                                  KC_HOME, KC_END,                          KC_MINUS, KC_ESCAPE,
                                                       KC_UP,                         KC_PGUP,
                                      KC_BSPACE, KC_TAB, KC_DOWN,                         KC_PGDOWN, KC_BSPACE, KC_SPACE
        ),


        /* Keymap 4 FOUR _Four FlightSim
         *             
         *             
         */

         [_Four] = LAYOUT_ergodox_pretty(  
             
         // left hand
         KC_ESCAPE, KC_1,  lt2Rename,  KC_3,    lt4RemoveBreakpoint, KC_F5, KC_F6,                                    lt7F7,   KC_F8,    KC_F9,    KC_F10, KC_F13,   KC_F14, KC_F15, 
         KC_TAB,  KC_Q,     KC_W,         KC_E,     KC_R,     KC_T,    KC_Y,                                        _______,  _______,    _______,    _______, KC_F16,    KC_F17, KC_F18,
         _______,  _______,  _______,  _______,    _______,    _______,                                                            _______,    _______,  _______,    KC_F19,    KC_F22, KC_F21, 
         _______,  _______, _______,  _______,    _______,    _______,   _______,                                       TO(_Zero),  _______,    _______,    _______, KC_F22, KC_F23,   KC_F24,
         _______,   KC_LGUI,  _______, _______,  _______,                                                                                  KC_LEFT, KC_UP, KC_RIGHT,  KC_DOWN,  thUnderscoreF5,
                                                             S(KC_F11),  KC_F10,                                        _______, _______,
                                                                        S(KC_F9),                                         _______,
                                                      _______, _______, KC_F11,                                         _______, _______, _______
         )

 };
 

bool isHeld(keyrecord_t *rec){
   return !rec->tap.count && rec->event.pressed; }
bool isTapped(keyrecord_t *rec){
   return rec->tap.count && rec->event.pressed;
 }
 
    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
     switch (keycode) {
     case KC_F23:   
       
            uint8_t layer = get_highest_layer(layer_state);
             ergodox_right_led_1_off();
             ergodox_right_led_2_off();
             ergodox_right_led_3_off();
            switch (layer) {
                case _Zero:
             ergodox_right_led_1_off();
             ergodox_right_led_2_off();
             ergodox_right_led_3_off();
                    break;
                case _One:
             ergodox_right_led_1_on();
                    break;
                case _Two:
             ergodox_right_led_1_on();
             ergodox_right_led_2_on();
                    break;
                case _Three:
             ergodox_right_led_1_on();
             ergodox_right_led_2_on();
             ergodox_right_led_3_on();
                case _Four:
             ergodox_right_led_1_off();
             ergodox_right_led_2_off();
             ergodox_right_led_3_on();
                    break;
            }
          return true;//return F23, after doing liths
           break;
   
     case thUnderscoreF5:   
         if (isHeld(record)) {
             tap_code16(KC_F5); // Intercept hold function to send ctrl-X
            }
         if (isTapped(record)) {
             tap_code16(S(KC_MINS)); // Intercept Tap  to send ctrl-C            
         }
          return false;             // Return nothing, all senarios handled above
           break;
     case thCopyCut:   
         if (isHeld(record)) {
             tap_code16(C(KC_X)); // Intercept hold function to send ctrl-X
             ergodox_right_led_1_on();
         }
         if (isTapped(record)) {
             tap_code16(C(KC_C)); // Intercept Tap  to send ctrl-C
             ergodox_right_led_1_off();
         }
          return false;             // Return nothing, all senarios handled above
           break;
     case thPlainPastePaste:   
         if (isTapped(record)) {
             tap_code16(C(KC_V));// Intercept Tap  to send plain-text paste shift-ctrl-V
         }
         if (isHeld(record)) {
             tap_code16(C(S(KC_V)));  // Intercept hold function to send ctrl-V
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
     case lt2Rename:
         if (isHeld(record)) {
             tap_code16(KC_F2); 
             return false;
         }
         return true;             
    break;
     case ltF3CtrlF:
         if (isHeld(record)) {
             tap_code16(C(KC_F)); 
             return false;
         }
    break;
    case ltF12CtrlMinus:
         if (isHeld(record)) {
             tap_code16(C(KC_MINUS)); 
             return false;  
               }
         return true;             
    break;
    case ltCommCtrlComm:
         if (isHeld(record)) {
             tap_code16(C(KC_COMM)); 
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
    case ltLDeleteLine:
         if (isHeld(record)) {
             tap_code16(C(KC_L)); 
             return false;
         }
         return true;             
    break;
case ltF11StepOver:
         if (isHeld(record)) {
             tap_code16(S(KC_F10)); 
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
    case ltOneNotEqual:
         if (isHeld(record)) {
             SEND_STRING("!= ");
             return false;
         }
         return true;             
    break;
    
    case lt7F7:
         if (isHeld(record)) {
             tap_code16(KC_F7);
             return false;
         }
         return true;             
    break;
    case ltPASTF22:
         if (isHeld(record)) {
             tap_code16(KC_F22);
             return false;
         }
         return true;             
    case ltPPLSF21:
         if (isHeld(record)) {
             tap_code16(KC_F21);
             return false;
         }
         return true;             
    break;
    case ltBrLBrR:
         if (isHeld(record)) {
             tap_code16(KC_RBRC);
             return false;
         }
         return true;             
    break;
    case ltF7PW:
         if (isHeld(record)) {
             SEND_STRING("32wfpg54#@WFPG%$");
             return false;
         }
         return true;             
    break;
   
    case fRunCmdDate:
            
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
            //  wait_ms(9400);
            //  tap_code16(KC_ENT); 
             return false;  
    break;


    case lt9Breakpoint:
         if (isHeld(record)) {
             tap_code16(KC_F9);
             return false;
         }
         return true;             
    break;
    case lt3RebuildVS:
         if (isHeld(record)) {
             tap_code16(C(S(KC_F5)));          
             return false;
         }
         return true;             
    break;
    case lt4RemoveBreakpoint:
         if (isHeld(record)) {
             tap_code16(KC_F9);          
             return false;
         }
         return true;             
    break;
    case lt5Comment:
         if (isHeld(record)) {
             tap_code16(C(KC_K));
             tap_code16(C(KC_C));
             return false;
         }
         return true;             
    break;
    case lt6Uncomment:
         if (isHeld(record)) {
             tap_code16(C(KC_K));
             tap_code16(C(KC_U));
             return false;
         }
         return true;             
    break;
    case ltKFormat:
         if (isHeld(record)) {
             tap_code16(C(KC_K));
             tap_code16(C(KC_D));
             return false;
         }
         return true;             
    break;
    case ltCSelectAllCopy:
         if (isHeld(record)) {
             tap_code16(C(KC_A));
             tap_code16(C(KC_C));
             return false;
         }
         return true;             
    break;
    case ltVSelectAllPaste:
         if (isHeld(record)) {
             tap_code16(C(KC_A));
             tap_code16(C(KC_V));
             return false;
         }
         return true;             
    break;

    case ltNNew:
         if (isHeld(record)) {
             tap_code16(KC_N);
             return false;
         }
         return true;             
    break;
    
   //   case LT(0,KC_X):ltNNew
   //       if (isHeld(record)) {
   //           tap_code16(S(KC_X)
   //           return false;
   //       }
   //       return true;          
    
      }
        return true;
        
    }



    const uint16_t PROGMEM cAltF4[] = {KC_6, KC_5, COMBO_END};
    const uint16_t PROGMEM cCtrlF4[] = {KC_3, KC_4, COMBO_END};

    combo_t key_combos[COMBO_COUNT] = {
        COMBO(cAltF4, A(KC_F4))   , 
        COMBO(cCtrlF4, C(KC_F4))
    };
    
     