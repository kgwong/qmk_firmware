/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum cajal_layers {
  _COLEMAK = 0,
  _QWERTY = 1,
  _DVORAK = 2,

  _FN = 3,
  _NMPD = 4,
  _SYM = 5,
  _NAV = 6,
  _MEDIA = 7,
  _RGB = 8
};

enum cajal_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = {
    {KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_QUOT, KC_BSPC, _______},
    {CTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT, MO(_RGB)},
    {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP},
    {MO(_FN), _______, KC_LGUI, KC_LALT, KC_SPC, MO(_NMPD), MO(_SYM), KC_BSPC, MO(_NAV), KC_RCTL, MO(_MEDIA), KC_LEFT, KC_DOWN, KC_RGHT}
}, 	
[_QWERTY] = {
  {_______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,    _______,    _______},
  {_______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,    _______},
  {_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,    _______ },
  {_______, _______, _______, _______, _______,   _______,  _______,  _______,   _______, _______, _______,   _______,    _______,    _______}
},
[_DVORAK] = {
  {_______,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,    _______,    _______},
  {_______,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______,    _______},
  {_______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,    _______ },
  {_______, _______, _______, _______, _______,   _______,  _______,  _______,   _______, _______, _______,   _______,    _______,    _______}
},
[_FN] = {
  {	KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,    XXXXXXX,    XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX,    XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,    XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX}
},
[_NMPD] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_P7, KC_P8, KC_P9, KC_PAST, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PSLS, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PENT, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_P0, KC_COMM, KC_PDOT, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX}
},
[_SYM] = {
  {KC_GRV, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_BSLASH, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL, S(KC_EQL), KC_LBRC, KC_RBRC, S(KC_BSLASH), XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, S(KC_MINS), S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},
[_NAV] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DELETE, XXXXXXX, KC_INS, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},
[_MEDIA] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT}
},
[_RGB] = {
  {COLEMAK, QWERTY, DVORAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAD, RGB_SAI, XXXXXXX, RGB_VAI},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_VAD, RGB_HUI}
}
};


layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) 
	  {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) 
	  {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) 
	  {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}