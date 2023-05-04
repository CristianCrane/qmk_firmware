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
#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
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
// layer buttons
#define CC_SPCFN LT(_FN1, KC_SPC)   // space when tapped, layer when held

/*
todo:
    1. ralt, rgui, fn, rctl buttons can be used for something else (4 buttons)
    2. 'c' on space layer is available. something with navigation?
    3. page up/down aren't used much, alternatives?
    4. ',' on space layer is available. something with text navigation? (its between home and end)
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
    KC_LCTL, QK_LEAD, KC_LALT,                         CC_SPCFN,                             KC_RALT, KC_RGUI, MO(_FN1), KC_RCTL
  ),

  [_FN1] = LAYOUT_60_ansi(
    _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, CC_HTAB, CC_PTAB,  CC_MAXW, CC_NTAB,  _______, _______, CC_PWORD, KC_UP,   CC_NWORD, KC_PGUP, _______, _______, _______,
    _______, CC_ATAB, CC_SNPWL, CC_MINW, CC_SNPWR, _______, _______, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_PGDN, _______,          _______,
    _______, CC_KILW, CC_BPAG,  _______, CC_FPAG,  _______, _______, KC_HOME,  _______, KC_END,   CC_OPNW,                   _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  )
};

/**
    Leader Key stuff.

    Basic commands:
    SEND_STRING() types the sequence of characters
    The following SS_* commands can be used INSIDE of the SEND_STRING argument
    KC_* keycodes are supported, but they are prefixed with X_* instead. eg KC_A -> X_A
    - SS_TAP() presses and releases a key.
    - SS_DOWN() presses (but does not release) a key.
    - SS_UP() releases a key.
    - SS_LCTL()
    - SS_LSFT()
    - SS_LALT()
    - SS_LGUI()

    To input raw chords (no string), use the tap_code16() command.
    This command uses the normal KC_* keycodes and modifiers. (NO SS_*)
    ex. tap_code16(LGUI(KC_S))

*/
void leader_start_user(void) {
    // do something when the leader key is pressed
}

void leader_end_user(void) {
    // quick actions
    // L: Login
//    if (leader_sequence_one_key(KC_L)) {
//        SEND_STRING("O697433" SS_TAP(X_TAB) "iamthe1whossecure" SS_TAP(X_TAB) SS_TAP(X_ENT));
//    }
//    // P: Pass
//    else if (leader_sequence_one_key(KC_P)) {
//       SEND_STRING("iamthe1whossecure");
//    }
}

/* ------------- combos (remember to update combo count in config.h) ------------- */
// define combos
const uint16_t PROGMEM esc[] = {KC_Q, KC_W, COMBO_END}; // qw --> esc

// map them (comboName, keypress)
combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc, KC_ESC)
};
