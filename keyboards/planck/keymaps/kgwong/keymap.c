/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

// Func macro definitions.
#define ESC_CTRL FUNC(0) // Tap for Esc, hold for CTRL
#define SYM_1 FUNC(1) // !
#define SYM_2 FUNC(2) // @
#define SYM_3 FUNC(3) // #
#define SYM_4 FUNC(4) // $
#define SYM_5 FUNC(5) // %
#define SYM_6 FUNC(6) // ^
#define SYM_7 FUNC(7) // &
#define SYM_8 FUNC(8) // *
#define SYM_9 FUNC(9) // (
#define SYM_10 FUNC(10) // )

#define SYM_11 FUNC(11) // |
#define SYM_12 FUNC(12) // +
#define SYM_13 FUNC(13) // {
#define SYM_14 FUNC(14) // }
#define SYM_15 FUNC(15) // _

extern keymap_config_t keymap_config;

// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
	[2] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
	[3] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
	[4] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
	[5] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
	[6] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
	[7] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
	[8] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
	[9] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
	[10] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
	
	[11] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH),
	[12] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
	[13] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
	[14] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
	[15] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
	
 };

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _DVORAK,
  //_LOWER,
  //_RAISE,
  _PLOVER,
  //_ADJUST
  _FN,
  _NMPD,
  _SYM,
  _NAV,
  _MEDIA,
  _PLNCK
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  PLOVER,
  FN,
  NMPD,
  SYM,
  NAV,
  MEDIA,
  PLNCK,
  EXT_PLV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn	  |      | GUI  | Alt  |Space | Nmpd |  Sym |Bkspc | Nav  |      |Media |PLNCK |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB  ,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT},
  {ESC_CTRL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT},
  {KC_LSFT ,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  {FN      , _______, KC_LGUI, KC_LALT, KC_SPC,   NMPD,     SYM,  KC_BSPC,     NAV, _______,     MEDIA,   PLNCK}
}, 	

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {_______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______},
  {_______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______},
  {_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______ },
  {_______, _______, _______, _______, _______,   _______,  _______,  _______,   _______, _______, _______,   _______}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {_______,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______},
  {_______,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______},
  {_______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______ },
  {_______, _______, _______, _______, _______,   _______,  _______,  _______,   _______, _______, _______,   _______}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},


/* FN
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = {
  {	KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAPS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_NMPD] = {
  {_______, _______, _______, _______, _______, _______, KC_NLCK, KC_P7, KC_P8, KC_P9, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_P0, _______, _______, _______, _______}
},

[_SYM] = {
  {KC_GRV, SYM_1, SYM_2, SYM_3, SYM_4, SYM_5, SYM_6, SYM_7, SYM_8, SYM_9, SYM_10, KC_BSLASH},
  {_______, _______, _______, _______, _______, _______, _______, KC_EQL, SYM_12, KC_LBRC, KC_RBRC, SYM_11},
  {_______, _______, _______, _______, _______, _______, _______, KC_MINS, SYM_15, SYM_13, SYM_14, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_NAV] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_INS, KC_HOME, KC_PGUP, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_DELETE, KC_END, KC_PGDN, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_MEDIA] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLNCK] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) 
	  {
        print("mode just switched to qwerty and this is a huge string\n");
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
    case PLOVER:
      if (record->event.pressed) 
	  {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) 
		{
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
    case EXT_PLV:
      if (record->event.pressed) 
	  {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
	  return false;
	case FN:
      if (record->event.pressed) 
	  {
        layer_on(_FN);
      }
	  else
	  {
		  layer_off(_FN);
	  }
	  return false;
	case NMPD:
      if (record->event.pressed) 
	  {
        layer_on(_NMPD);
      }
	  else
	  {
		  layer_off(_NMPD);
	  }
	  return false;
	case SYM:
      if (record->event.pressed) 
	  {
        layer_on(_SYM);
      }
	  else
	  {
		  layer_off(_SYM);
	  }
	  return false;
	case NAV:
      if (record->event.pressed) 
	  {
        layer_on(_NAV);
      }
	  else
	  {
		  layer_off(_NAV);
	  }
      return false;
	case MEDIA:
      if (record->event.pressed) 
	  {
        layer_on(_MEDIA);
      }
	  else
	  {
		  layer_off(_MEDIA);
	  }
      return false;
	case PLNCK:
      if (record->event.pressed) 
	  {
        layer_on(_PLNCK);
      }
	  else
	  {
		  layer_off(_PLNCK);
	  }
      return false;
  }
  return true;
}