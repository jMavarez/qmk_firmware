#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "oled.c"

// #ifdef PROTOCOL_LUFA
//   #include "lufa.h"
//   #include "split_util.h"
// #endif
// #ifdef SSD1306OLED
//   #include "ssd1306.h"
// #endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |  1!  |  2@  |  3#  |  4$  |  5%  |                    |  6^  |  7&  |  8*  |  9(  |  0)  |  `~  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -_  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;:  |  '"  |
  * |------+------+------+------+------+------|       |    |BckSpce|------+------+------+------+------+------|
  * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  /?  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | MENU | LAlt |LOWER | / Space /       \Enter \  |RAISE | META | Caps |
  *                   |  TD  |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV,  \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS, \
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
    KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,  KC_BSPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                          TD(TD_MENU_ADJS), KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_LGUI, KC_CAPS \
  ),

  /* LOWER
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  \/  |   !  |   @  |   #  |   $  |   %  |                    |  =+  |  -_  |  (   |   )  |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  \/  |   ^  |   &  |   *  |      |      |-------.    ,-------|      |  \|  |  {   |   }  |      |      |
  * |------+------+------+------+------+------|       |    |  DEL  |------+------+------+------+------+------|
  * |  \/  |      |      |      |      |      |-------|    |-------|      |      |  [   |   ]  |      |  \/  |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE |KC_APP| Caps |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_LOWER] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,\
    KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BSLS, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |  \/  |      |      | Stop | Mute | Vol+ |                    | P Up |   7  |   8  |   9  |   *  |   /  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  \/  |      | Prev | Play | Next | Vol- |                    | P Dwn|   4  |   5  |   6  |   +  |   -  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  \/  | Left | Down |  Up  |Right |      |-------.    ,-------| Home |   1  |   2  |   3  |      |   =  |
  * |------+------+------+------+------+------|       |    |  \/   |------+------+------+------+------+------|
  * |  \/  |      |      |      |      |      |-------|    |-------| End  |   ,  |   0  |   .  |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE |KC_APP| Caps |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_RAISE] = LAYOUT( \
    KC_TRNS, XXXXXXX, XXXXXXX, KC_MSTP, KC_MUTE, KC_VOLU,                   KC_PGUP, KC_P7,   KC_P8,  KC_P9,   KC_PAST, KC_PSLS, \
    KC_TRNS, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD,                   KC_PGDN, KC_P4,   KC_P5,  KC_P6,   KC_PPLS, KC_PMNS, \
    KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,                   KC_HOME, KC_P1,   KC_P2,  KC_P3,   XXXXXXX, KC_PEQL, \
    KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX, KC_TRNS, KC_END,  KC_PCMM, KC_P0,  KC_PDOT, XXXXXXX, XXXXXXX, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  /* ADJUST - Extra stuff
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | Pwer | Sleep| Wake |      |      | Bri+ |                    |      |      |      |      |      |GUI_OF|
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  \/  |      |      |      |      | Bri- |                    |      |      |      |      |      |GUI_ON|
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  \/  |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
  * |------+------+------+------+------+------|       |    |  \/   |------+------+------+------+------+------|
  * |  \/  |      |      |      |      |      |-------|    |-------|      |      |      |      |      |  \/  |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE |KC_APP| Caps |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_ADJUST] = LAYOUT( \
    KC_PWR,  KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, KC_BRIU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GUI_OFF, \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GUI_ON,  \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),
};
