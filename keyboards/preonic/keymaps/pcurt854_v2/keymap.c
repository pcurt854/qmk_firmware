/* Copyright 2020 Pete Curt
 * Based on code by Jack Humbert
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
#include "muse.h"
#include "velocikey.h"

enum preonic_layers {
  _QWERTY,	// 0
  _COLEMAK,	// 1
  _DVORAK,	// 2
  _NUMPAD,	// 3
  _SYMBOL,	// 4
  _BRACKET,	// 5
  _ADJUST	// 6
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ABKPAIR,
  ARROW,
  AUDIOTG,
  BACKLIT,
  RBKPAIR,
  SBKPAIR,
  CBKPAIR,
  HBKPAIR,
  DBKPAIR,
  CCMT,
  CCMTLT,
  CCMTRT,
  DOTSLSH,
  NCBKTAB,
  NWMVMXW,
  TERMINAL,
  UTPSTLK,
  VLKTOGG,
  YIELDS
};



#ifdef AUDIO_ENABLE

#define AUDIO_ON_SONG H__NOTE(_C6), H__NOTE(_C7), H__NOTE(_C8),
float audio_on_song[][2] = SONG(AUDIO_ON_SONG);
float audio_off_song[][2] = SONG(GOODBYE_SOUND);

#define CAPS_LOCK_ON_SONG H__NOTE(_C6), H__NOTE(_C7), H__NOTE(_C8),
float caps_lock_on_song[][2] = SONG(CAPS_LOCK_ON_SONG);
float caps_lock_off_song[][2] = SONG(GOODBYE_SOUND);


// all same length, the next to last number in songs below
#define LAYER3_SONG H__NOTE(_C5),
#define LAYER4_SONG H__NOTE(_C6),
#define LAYER5_SONG H__NOTE(_C7),
// #define LAYER6_SONG S__NOTE(_C2),
#define LAYER6_SONG H__NOTE(_C8),
float higher_layer_on_songs[][1][2] = {
  SONG(LAYER3_SONG),
  SONG(LAYER4_SONG),
  SONG(LAYER5_SONG),
  SONG(LAYER6_SONG)
};
float higher_layer_off_song[][2] = SONG(GOODBYE_SOUND);
// float higher_layer_off_song[][2] = SONG(NO_SOUND);


#define LEADER_SUCCEED_SONG H__NOTE(_C5), H__NOTE(_C6), H__NOTE(_C5),
//float leader_start_song[][2] = SONG(CHROMATIC_SOUND);
float leader_start_song[][2] = SONG(NO_SOUND);
float leader_succeed_song[][2] = SONG(LEADER_SUCCEED_SONG);
float leader_fail_song[][2] = SONG(GOODBYE_SOUND);
//float leader_fail_song[][2] = SONG(NO_SOUND);


#define ONESHOT_SHIFT_ON_SONG H__NOTE(_C4), H__NOTE(_C6),
#define ONESHOT_SHIFT_OFF_SONG H__NOTE(_C6), H__NOTE(_C4),
float oneshot_shift_on_song[][2] = SONG(ONESHOT_SHIFT_ON_SONG);
float oneshot_off_song[][2] = SONG(GOODBYE_SOUND);


float velocikey_start_song[][2] = SONG(FANTASIE_IMPROMPTU);
float velocikey_stop_song[][2] = SONG(GOODBYE_SOUND);


#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty layer 0
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |   Del|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * | `~   |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   Dnc|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Lead |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |    {}|      |      |      |    <>|      |      |      |      |
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * | LCtl |      |      |      |      |      |      |      |      |      |      | RCtl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |    []|    ()|    ap|      |      |      |      |      |      |      | ? /  |
 * | mo(5)|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | mo(6)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | osm  | LCtl | Opt  | Cmd  | mo(4)| Entr | Spc  | tt(3)| Cmd  | Left | Down | Rght |
 * | LSft |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,
  LCTL_T(KC_ESC),
           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
  MO(_BRACKET),
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   LT(_ADJUST,KC_SLSH),
  OSM(MOD_LSFT),
           KC_LCTL, KC_LOPT, KC_LCMD, MO(_SYMBOL),
                                               KC_ENT,  KC_SPC,  TT(_NUMPAD),
                                                                          KC_RCMD, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Colemak layer 1
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |   Del|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * | `~   |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |    <>|      |      |      |      |   Dnc|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Lead |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |    {}|      |      |      |      |      |      |
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * | LCtl |      |      |      |      |      |      |      |      |      |      | RCtl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |    []|    ()|    ap|      |      |      |      |      |      |      | ? /  |
 * | mo(5)|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | mo(6)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | osm  | LCtl | Opt  | Cmd  | mo(4)| Entr | Spc  | tt(3)| Cmd  | Left | Down | Rght |
 * | LSft |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LEAD,
  LCTL_T(KC_ESC),
           KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    RCTL_T(KC_QUOT),
  MO(_BRACKET),
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   LT(_ADJUST, KC_SLSH),
  OSM(MOD_LSFT),
           KC_LCTL, KC_LOPT, KC_LCMD, MO(_SYMBOL),
                                               KC_ENT,  KC_SPC,  TT(_NUMPAD),
                                                                          KC_RCMD, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Dvorak layer 2
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |   Del|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * | `~   |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |    ap|      |      |   Dnc|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Lead |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |    {}|      |      |      |      |      |
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * | LCtl |      |      |      |      |      |      |      |      |      |      | RCtl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |    <>|      |    ()|      |      |      |      |    []|      | : ;  |
 * | mo(5)|   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  Up  | mo(6)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | osm  | LCtl | Opt  | Cmd  | mo(4)| Entr | Spc  | tt(3)| Cmd  | Left | Down | Rght |
 * | LSft |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_LEAD,
  LCTL_T(KC_ESC),
           KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    RCTL_T(KC_SLSH),
  MO(_BRACKET),
           KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_UP,   LT(_ADJUST, KC_COLN),
  OSM(MOD_LSFT),
           KC_LCTL, KC_LOPT, KC_LCMD, MO(_SYMBOL),
                                               KC_ENT,  KC_SPC,  TT(_NUMPAD),
                                                                          KC_RCMD, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Numpad layer 3
 * ,-----------------------------------------------------------------------------------.
 * | ____ |      |      |      |      |      |      |      |      |      |      | ____ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |   7  |   5  |   2  |      |      |   1  |      |      |   0  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |      |   4  |   0  |      |      |      |   9  |      |   6  |      | ____ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   8  |   3  |      |   ,  |   .  | ____ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | tg(3)| ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_7,    KC_5,    KC_2,    XXXXXXX, XXXXXXX, KC_1,    XXXXXXX, XXXXXXX, KC_0,    XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_4,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, KC_9,    XXXXXXX, KC_6,    XXXXXXX, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    KC_3,    XXXXXXX, KC_COMM, KC_DOT,  _______, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, TG(_NUMPAD),
                                                                          _______, _______, _______, _______
),

/* Symbol layer 4
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ |      |      |   !  |   $  |   ~  |      |   _  |   |  |/\**\/|   %  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ____ |   @  |   *  |  {}  |      |   `  |   #  |   -  |  ->  |   +  |   ;  | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  []  |  ()  |   ^  |SCO(V)|   \  |   &  |   =  |  <>  |  ./  | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |      | ____ | ____ |      | ____ | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, XXXXXXX, XXXXXXX, KC_EXLM, KC_DLR,  KC_TILD, XXXXXXX, KC_UNDS, KC_PIPE, CCMT,    KC_PERC, XXXXXXX,
  _______, KC_AT,   KC_ASTR, CBKPAIR, XXXXXXX, KC_GRV,  KC_HASH, KC_MINS, ARROW,   KC_PLUS, KC_SCLN, _______,
  XXXXXXX, SBKPAIR, RBKPAIR, KC_CIRC, SCMD(LOPT(KC_V)),
                                               KC_BSLS, KC_AMPR, KC_EQL,  ABKPAIR, DOTSLSH, KC_PGUP, XXXXXXX,
  _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, KC_HOME, KC_PGDN, KC_END
),

/* Bracket layer 5
 * ,-----------------------------------------------------------------------------------.
 * |      | test |gradnt|plain |      |      |   <|>  |  <  |  >  |      |      | del  |
 * |      |      |      |      |      |      |        |     |     |      | whup | brks |
 * |------+------+------+------+------+---------------+-----|-----+------+------|------|
 * |      |plain |plain |plain | Rgb  | saT+ |   (|)  |  (  |  )  | whlt | whdn | whrt |
 * |------+------+------+------+------+---------------+-----|-----+------+------|------|
 * |      |rAinbw|Swirl |breath| hue+ | mod+ |   [|]  |  [  |  ]  |      | [|)  |      |
 * |------+------+------+------+------+------|--------+-----|-----+------+------|------|
 * |      |Znake | Xmas |Cnight| vlk  | Brt+ |   {|}  |  {  |  }  | btn1 | msup | btn2 |
 * |------+------+------+------+------+------+--------+-----|-----+------+------+------|
 * | ____ | ____ | ____ | ____ |      |      | /\*|*\/| /\* | *\/ | mslt | msdn | msrt |
 * `-----------------------------------------------------------------------------------'
 */
[_BRACKET] = LAYOUT_preonic_grid(
  XXXXXXX, RGB_M_T,  RGB_M_G,  RGB_M_P, XXXXXXX, XXXXXXX, ABKPAIR, KC_LABK, KC_RABK, XXXXXXX, KC_WH_U, DBKPAIR,
  XXXXXXX, RGB_M_P,  RGB_M_P,  RGB_M_P, RGB_TOG, RGB_SAI, RBKPAIR, KC_LPRN, KC_RPRN, KC_WH_L, KC_WH_D, KC_WH_R,
  XXXXXXX, RGB_M_R,  RGB_M_SW, RGB_M_B, RGB_HUI, RGB_MOD, SBKPAIR, KC_LBRC, KC_RBRC, XXXXXXX, HBKPAIR, XXXXXXX,
  XXXXXXX, RGB_M_SN, RGB_M_X,  RGB_M_K, VLKTOGG, RGB_VAI, CBKPAIR, KC_LCBR, KC_RCBR, KC_BTN1, KC_MS_U, KC_BTN2,
  _______, _______,  _______,  _______, XXXXXXX, XXXXXXX, CCMT,    CCMTLT,  CCMTRT,  KC_MS_L, KC_MS_D, KC_MS_R
),

/* Adjust layer 6
 *
 * The control sequences are highly personal.  Please change to adapt to your own system.
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |play1 |play2 |      |      |      |      |      | rec2 | rec1 |rstop |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|Colemk|Dvorak| new  | new  |      |uTube |      |      |Print |      |
 * |      |      |      |      | teRm | Tab  |      |PaSTe |      |      |screen|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Audio |Sleep |show  |      |      |finder|mv win|mv win|Lock  |      |      |
 * |      |      |      |Dsktp |      |      |Hddn  |clkw  |c clkw|screen|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RESET |      | Caps |Virus |      |Nw mv | Mute | vol+ |      | dsp+ |      |
 * |      |RESET |      |      |scan  |      |mx win|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ |      |      |      |      | vol- |      | dsp- |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * dsp+-:              for QuickShade
 * mv win clkw:        for Rectangle
 * new tab:            for Google Chrome
 * uTube paste link    for Google Chrome
 * nw mv mx win:       for Rectangle
 * print screen:       for Mac Sys Pref/Keyboard/Shortcuts/Screenshots/Screenshot
 * show desktop:       for Mac Sys Pref/Keyboard/Shortcuts/Mission Control/Show Desktop
 * virus scan:         for Sophos Home
 */
[_ADJUST] = LAYOUT_preonic_grid(
  XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC2, DM_REC1, DM_RSTP,    XXXXXXX,
  XXXXXXX, QWERTY,  COLEMAK, DVORAK, TERMINAL, NCBKTAB, XXXXXXX, UTPSTLK, XXXXXXX, XXXXXXX, SCMD(KC_5), XXXXXXX,
  XXXXXXX, AUDIOTG,  C(LCMD(KC_PAUSE)),
                             HYPR(KC_D),
                                      XXXXXXX, XXXXXXX, SCMD(KC_DOT),
                                                                 LCA(KC_J), LCA(KC_K),  C(LCMD(KC_Q)), XXXXXXX, XXXXXXX,
  XXXXXXX, RESET,   XXXXXXX, KC_CAPS, SCMD(KC_V),
                                               XXXXXXX, NWMVMXW, KC__MUTE, KC__VOLUP,   XXXXXXX, LCAG(KC_UP), XXXXXXX,
  _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC__VOLDOWN, XXXXXXX, LCAG(KC_DOWN), XXXXXXX
)


};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    // rest are sorted alphabetically
    case ABKPAIR:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("<>");
          set_mods(mod_state);
        } else {
          SEND_STRING("<>" SS_DELAY(200) SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
      break;
    case AUDIOTG:
      if (record->event.pressed) {
        if (is_audio_on()) {
          PLAY_SONG(audio_off_song); // putting audio_off() right after seems to cut off the song
        }
      } else { // when released
        if (is_audio_on()) {
          audio_off();
        } else {
          audio_on();
          PLAY_SONG(audio_on_song);
        }
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef __AVR__
        writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef __AVR__
        writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case CBKPAIR:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("{}");
          set_mods(mod_state);
        } else {
          SEND_STRING("{}" SS_DELAY(200) SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case HBKPAIR: // Half close Half open
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("[)");
          set_mods(mod_state);
        } else {
          SEND_STRING("[)" SS_DELAY(200) SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case CCMT:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("/**/");
          set_mods(mod_state);
        } else {
          SEND_STRING_DELAY("/**/" SS_DELAY(30) SS_TAP(X_LEFT) SS_DELAY(30) SS_TAP(X_LEFT), 30);
        }
      }
      return false;
      break;
    case CCMTLT:
      if (record->event.pressed) {
        SEND_STRING("/*");
      }
      return false;
      break;
    case CCMTRT:
      if (record->event.pressed) {
        SEND_STRING("*/");
      }
      return false;
      break;
    case DOTSLSH:
      if (record->event.pressed) {
        SEND_STRING("./");
      }
      return false;
      break;
    case DBKPAIR: // right and 2 backspaces to delete a pair of brackets
      // with Shift: double the above, so can delete C style comment
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          SEND_STRING(SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) SS_DELAY(200) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE));
          set_mods(mod_state);
        } else {
          SEND_STRING(SS_TAP(X_RIGHT) SS_DELAY(200) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE));
        }
      }
      return false;
      break;
    case NCBKTAB: // close all other tabs, create New Chrome BlanK TAB, and close the current one
      if (record->event.pressed) {
        SEND_STRING(
          SS_LCMD("t") // create new tab
          SS_DELAY(100)
          SS_DOWN(X_LCMD) SS_TAP(X_F1) SS_DELAY(100) SS_UP(X_LCMD) // close all other tabs
        );
      }
      return false;
      break;
    case NWMVMXW: // New Window MoVe to next display MaX this new Window and move to lower-right corner
    // with Shift: move twice
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          SEND_STRING(SS_LCMD("n")
                      SS_DELAY(500) SS_DOWN(X_LCTL) SS_DOWN(X_LOPT) SS_TAP(X_K)
                      SS_DELAY(100) SS_TAP(X_X)
                      SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_DOWN) SS_UP(X_LOPT) SS_UP(X_LCTL));
          set_mods(mod_state);
        } else {
          SEND_STRING(SS_LCMD("n")
                      SS_DELAY(500) SS_DOWN(X_LCTL) SS_DOWN(X_LOPT) SS_TAP(X_J)
                      SS_DELAY(100) SS_TAP(X_X)
                      SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_DOWN) SS_UP(X_LOPT) SS_UP(X_LCTL));
        }
      }
      return false;
      break;
    case RBKPAIR:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("()");
          set_mods(mod_state);
        } else {
          SEND_STRING("()" SS_DELAY(200) SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case SBKPAIR:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("[]");
          set_mods(mod_state);
        } else {
          SEND_STRING("[]" SS_DELAY(200) SS_TAP(X_LEFT));
        }
      }
      return false;
      break;
    case TERMINAL: // new teRminal // with Shift: create 2
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          SEND_STRING(SS_LCMD(" ") SS_DELAY(200) "terminal.app" SS_DELAY(1000) SS_TAP(X_ENT)
                      SS_DELAY(300) SS_DOWN(X_LCTL) SS_DOWN(X_LOPT) SS_TAP(X_3) SS_UP(X_LCTL) SS_UP(X_LOPT)
                      SS_DELAY(100) SS_LCMD("n")
                      SS_DELAY(200) SS_DOWN(X_LCTL) SS_DOWN(X_LOPT) SS_TAP(X_1) SS_UP(X_LCTL) SS_UP(X_LOPT)
                      );
          set_mods(mod_state);
        } else {
          SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "terminal.app" SS_DELAY(500) SS_TAP(X_ENT)
                      SS_DELAY(300) SS_DOWN(X_LCTL) SS_DOWN(X_LOPT) SS_TAP(X_3) SS_UP(X_LCTL) SS_UP(X_LOPT)
                      );
        }
      }
      return false;
      break;
    case UTPSTLK: // right click utube video and select "copy URL with current time" then move mouse over a link in bookmark bar, run "Utube paste link" to update the bookmark to new URL
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_BTN2)       // right click to open drop down menu
          SS_DELAY(300) "e"              // Edit
          SS_TAP(X_ENT)                  // opens edit window
          SS_DELAY(1200) SS_TAP(X_TAB)   // go to second field
          SS_DELAY(100) SS_LCMD("v")     // Paste
        );
      }
      return false;
      break;
    case VLKTOGG:
      if (record->event.pressed) {
        #ifdef VELOCIKEY_ENABLE
        velocikey_toggle();
        #ifdef AUDIO_ENABLE
        if (velocikey_enabled()) {
          PLAY_SONG(velocikey_start_song);
        } else {
          PLAY_SONG(velocikey_stop_song);
        }
        #endif
        #endif
      }
      return false;
      break;
    case YIELDS:
      if (record->event.pressed) {
        SEND_STRING(". -> .");
      }
      return false;
      break;
  }
  return true; // process all other keys normally
};

/*
  Preonic LEDs visible from the top:
    6 5 4 3
    7 8 1 2

  The two numbers: starting LED number, number of LEDs
*/
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 2, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_ORANGE},
    {1, 1, HSV_ORANGE},
    {8, 1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, HSV_CHARTREUSE},
    {1, 1, HSV_CHARTREUSE},
    {8, 1, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM my_bracket_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, HSV_CYAN},
    {8, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_MAGENTA},
    {1, 1, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer, // 0
    my_shift_layer,    // 1
    my_numpad_layer,   // offset=2
    my_symbol_layer,
    my_bracket_layer,
    my_adjust_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
#ifdef AUDIO_ENABLE
//    if (led_state.caps_lock) {
//        PLAY_SONG(caps_lock_on_song);
//    }
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) { // caps lock state changed
        led_state.caps_lock ? PLAY_SONG(caps_lock_on_song) : PLAY_SONG(caps_lock_off_song);
        caps_state = led_state.caps_lock;
    }
#endif

    return true;
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_set_layer_state(1, true);
#ifdef AUDIO_ENABLE
    PLAY_SONG(oneshot_shift_on_song);
#endif
  }
  if (!mods) {
    rgblight_set_layer_state(1, false);
#ifdef AUDIO_ENABLE
    PLAY_SONG(oneshot_off_song);
#endif
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    int offset = 2;
    for (int i = 0; i <= _ADJUST - _NUMPAD; i++) {
#ifdef AUDIO_ENABLE
        if (rgblight_get_layer_state(i+offset)) {
            PLAY_SONG(higher_layer_off_song);
        }
#endif
        rgblight_set_layer_state(i+offset, false);
    }
    int highest_layer = get_highest_layer(state);
    if (highest_layer >= _NUMPAD && highest_layer <= _ADJUST) {
        rgblight_set_layer_state(highest_layer-_NUMPAD+offset, true);
#ifdef AUDIO_ENABLE
        PLAY_SONG(higher_layer_on_songs[highest_layer-_NUMPAD]);
#endif
    }

    return state;
}

bool did_leader_succeed;
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    // tap dance
    // sort by first key

    SEQ_ONE_KEY(KC_1) {
      SEND_STRING_DELAY(":15", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_1, KC_1) {
      SEND_STRING_DELAY(":15 PM", 50);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_2) {
      SEND_STRING_DELAY(":30", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_2, KC_2) {
      SEND_STRING_DELAY(":30 PM", 50);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_3) {
      SEND_STRING_DELAY(":45", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_3, KC_3) {
      SEND_STRING_DELAY(":45 PM", 50);
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_4) {
      SEND_STRING_DELAY(":00", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_4, KC_4) {
      SEND_STRING_DELAY(":00 PM", 50);
      did_leader_succeed = true;
    }

    SEQ_ONE_KEY(KC_BSPC) {
      SEND_STRING(SS_TAP(X_DEL));
      did_leader_succeed = true;
    }

    SEQ_ONE_KEY(KC_DOT) {
      SEND_STRING_DELAY(".00", 50);
      did_leader_succeed = true;
    }

    SEQ_ONE_KEY(KC_H) {
      SEND_STRING_DELAY("// HEREHERE", 50);
      did_leader_succeed = true;
    }

    SEQ_ONE_KEY(KC_K) {
      SEND_STRING_DELAY(",000", 50);
      did_leader_succeed = true;
    }

    SEQ_TWO_KEYS(KC_T, KC_A) {
      SEND_STRING_DELAY("Thanks a lot!", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_T, KC_S) {
      SEND_STRING_DELAY("Thanks!", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_T, KC_V) {
      SEND_STRING_DELAY("Thank you very much!", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_T, KC_Y) {
      SEND_STRING_DELAY("Thank you!", 50);
      did_leader_succeed = true;
    }

    SEQ_TWO_KEYS(KC_U, KC_K) {
      SEND_STRING_DELAY("United Kingdom", 50);
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_U, KC_S) {
      SEND_STRING_DELAY("United States", 50);
      did_leader_succeed = true;
    }

    leader_end();
  }
}

void leader_start(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

void leader_end(void) {
  if (did_leader_succeed) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed_song);
#endif
  } else {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail_song);
#endif
  }
}

