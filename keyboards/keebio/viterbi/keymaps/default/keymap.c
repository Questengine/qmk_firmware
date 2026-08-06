#include QMK_KEYBOARD_H
/*

qmk msys
"qmk compile -kb keebio/viterbi -km default"

 */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _Zero,
    _One,
    _RAISE,
    _ADJUST
};
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
      thCopyCut, 
      thPlainPastePaste,
      ltF5ShiftF5 =LT(0,KC_F5),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  ESC |   `  |   A  |   S  |   T  | BKSP | DEL  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  TAB  | SFT | CTL  |  WIN |  ALT |  (   |  )   |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   UP |   X  | HOME | PGUP | END  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn| LEFT | DOWN | RGT  | SPC  | PGDN |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_Zero] = LAYOUT_ortho_5x14( 
     KC_SLSH,  KC_PAST ,KC_MINS,KC_F9,       KC_VOLU,KC_VOLD,KC_ENT ,                   
                                                                                                             KC_SLSH,  KC_PAST ,KC_MINS,KC_F9,       KC_VOLU,KC_VOLD,KC_ENT ,           
     KC_BSPC, KC_9 , KC_6   , KC_3        , KC_MNXT, KC_MNXT , KC_RGHT,         
                                                                                                             KC_BSPC, KC_9 , KC_6   , KC_3        , thPlainPastePaste, KC_MNXT , KC_RGHT,                          
     KC_PRINT_SCREEN, KC_8 ,  KC_5, KC_2,               KC_MPLY, KC_UP , KC_DOWN  ,         
                                                                                                             KC_PRINT_SCREEN, KC_8 ,  KC_5, KC_2,               KC_MPLY, KC_UP , KC_DOWN  ,                     
     A(KC_PRINT_SCREEN), KC_7, KC_4   , KC_1             , KC_0  , KC_MPRV , KC_LEFT ,           
                                                                                                             A(KC_PRINT_SCREEN), KC_7, KC_4   , KC_1             , KC_0  , KC_MPRV , KC_LEFT ,                     
     KC_ESC, KC_TAB , KC_F, KC_S,           KC_DOT, KC_LSFT, KC_LCTL ,          
                                                                                                            KC_ESC, KC_TAB , KC_F, KC_S,          KC_DOT, KC_LSFT, KC_LCTL                  
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 
 
 
 
 */   
  [_One] = LAYOUT_ortho_5x14(
    TO(_Zero), KC_PAST, KC_PAST  , KC_MINS  ,      KC_T   , KC_BSPC, KC_DEL ,                     TO(_Zero), KC_PAST, KC_PAST  , KC_MINS  ,      KC_T   , KC_BSPC, KC_DEL ,                   
    _______, _______, _______, _______      ,     KC_LALT   , KC_LPRN   , KC_RPRN   ,             _______, _______, _______, _______      ,     KC_LALT   , KC_LPRN   , KC_RPRN   ,           
    _______, _______, _______, _______      ,       KC_F4   , thCopyCut   , thPlainPastePaste,    _______, _______, _______, _______      ,       KC_F4   , thCopyCut   , thPlainPastePaste,  
    _______, _______, _______, _______      ,      KC_HOME   , KC_PGUP   , KC_END   ,             _______, _______, _______, _______      ,      KC_HOME   , KC_PGUP   , KC_END   ,           
    _______, _______, _______, _______      ,      KC_SPC, KC_PGDN  , KC_ENT,                     _______, _______, _______, _______      ,      KC_SPC, KC_PGDN  , KC_ENT                   
  )
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
             tap_code16(C(KC_C)); // Intercept Tap  to send ctrl-C
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

     case ltF5ShiftF5:
         if (isHeld(record)) {
             tap_code16(S(KC_F5)); 
             return false;
         }
         return true;             
    break;






  }
  return true;
}
