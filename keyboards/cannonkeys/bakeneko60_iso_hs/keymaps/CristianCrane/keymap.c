/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN1
};

// custom keycodes: consider putting them in the above enum?
// window management
#define CC_KILW LALT(KC_F4)         // kill window
#define CC_OPNW LGUI(KC_S)          // open windows search -> rebound win+s to powerToys 'PowerRun', use to open apps, search, etc
#define CC_MAXW LGUI(KC_UP)         // maximize window
#define CC_MINW LGUI(KC_DOWN)       // minimize window
#define CC_SNPWL LGUI(KC_LEFT)      // snap window left, combine with shift to move window to left monitor
#define CC_SNPWR LGUI(KC_RIGHT)     // snap window right, combine with shift to move window to right monitor
#define CC_ATAB LALT(KC_TAB)        // instant switch between last used app
#define CC_HTAB LCTL(LALT(KC_TAB))  // brings up alt tab window view without having to hold it
// in-app commands
#define CC_BACK LALT(KC_LEFT)       // page back (chrome, windows)
#define CC_FWD  LALT(KC_RIGHT)      // page forward (chrome, windows)
#define CC_NTAB LCTL(KC_TAB)        // next tab
#define CC_PTAB RCS(KC_TAB)         // prev tab
#define CC_BPAG LALT(KC_LEFT)       // back page (chrome, windows)
#define CC_FPAG LALT(KC_RIGHT)      // forward page (chrome, windows)
#define CC_UNDO LCTL(KC_Z)          // standard undo command
#define CC_REDO LCTL(KC_Y)          // standard redo command
// text navigation
#define CC_PWORD LCTL(KC_LEFT)      // previous word
#define CC_NWORD LCTL(KC_RIGHT)     // next word
// shifted keys
#define CC_LPAR LSFT(KC_9)          // left parenthesis
#define CC_RPAR LSFT(KC_0)          // right parenthesis
#define CC_LBRK LSFT(KC_LBRC)       // left bracket
#define CC_RBRK LSFT(KC_RBRC)       // right bracket
#define CC_RARW LSFT(KC_DOT)        // right arrow
#define CC_PIPE LSFT(KC_BSLS)       // logical or (pipe)
#define CC_AMP  LFST(KC_7)          // logical and (ampersand)

// layer buttons
#define CC_SPCFN LT(_FN1, KC_SPC)   // space when tapped, layer 1 when held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_iso(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, QK_LEAD, KC_LALT,                            CC_SPCFN,                          KC_RALT, KC_RGUI, MO(_FN1),KC_RCTL
  ),

  [_FN1] = LAYOUT_60_iso(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLD, KC_VOLU,  KC_DEL,
    _______, CC_HTAB, CC_PTAB, CC_MAXW, CC_NTAB, _______, _______, CC_PWORD,KC_UP,   CC_NWORD,KC_PGUP, _______, _______,
    _______, CC_ATAB, CC_SNPWL,CC_MINW, CC_SNPWR,CC_AMP,  CC_PIPE, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, _______, _______, _______,
    _______, _______, CC_KILW, CC_BPAG, _______, CC_FPAG, _______, _______, KC_HOME, _______, KC_END,  CC_OPNW,          _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, QK_BOOT
  )
};

/* ------------- combos (remember to update combo count in config.h) ------------- */
// define combos
const uint16_t PROGMEM esc[] = {KC_Q, KC_W, COMBO_END}; // qw --> esc
const uint16_t PROGMEM bksp[] = {KC_L, KC_SCLN, COMBO_END}; // l; --> backspace
const uint16_t PROGMEM del[] = {KC_P, KC_LBRC, COMBO_END}; // p[ --> del
const uint16_t PROGMEM undo[] = {KC_Z, KC_X, COMBO_END}; // zx --> undo
const uint16_t PROGMEM redo[] = {KC_X, KC_C, COMBO_END}; // xc --> redo

// map them (comboName, keypress)
combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc, KC_ESC),
    COMBO(bksp, KC_BSPC),
    COMBO(del, KC_DEL),
    COMBO(undo, CC_UNDO),
    COMBO(redo, CC_REDO)
};
