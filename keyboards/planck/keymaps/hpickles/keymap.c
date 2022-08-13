/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _NAV,
  _SYM,
  //_FUNCTION,
  //_MOUSE,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  KC_TMUX,
};

#define NAV   MO(_NAV)
//#define FKEYS    MO(_FUNCTION)
//#define MOUSE    MO(_MOUSE)
#define SYM   MO(_SYM)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Homerow Mods
#define LGUI_A LGUI_T(KC_A)
#define LALT_R LALT_T(KC_R)
#define LCTL_S LCTL_T(KC_S)
#define LSHFT_T LSFT_T(KC_T)

#define RSFT_N RSFT_T(KC_N)
#define RCTL_E RCTL_T(KC_E)
#define RALT_I RALT_T(KC_I)
#define RGUI_O RGUI_T(KC_O)

enum combos {
  TM_TMUX,
  NE_ESC,
  MN_MENU,
  TN_ENT,
  PB_BSPC,
  TA_TAB,
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM tm_tmux[] = {LSHFT_T, KC_M, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {RSFT_N, RCTL_E, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, RSFT_N, COMBO_END};
const uint16_t PROGMEM tn_combo[] = {LSHFT_T, RSFT_N, COMBO_END};
const uint16_t PROGMEM pb_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM ta_combo[] = {LSHFT_T, LGUI_A, COMBO_END};

combo_t key_combos[] = {
  [TM_TMUX] = COMBO(tm_tmux, KC_TMUX),
  [NE_ESC] = COMBO(ne_combo, KC_ESC),
  [MN_MENU] = COMBO(mn_combo, KC_APP),
  [TN_ENT] = COMBO(tn_combo, KC_ENT),
  [PB_BSPC] = COMBO(pb_combo, KC_BSPC),
  [TA_TAB] = COMBO(ta_combo, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  |Lower |Leader|Space | SYM  | Nav  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
    _______, LGUI_A,  LALT_R,  LCTL_S,  LSHFT_T, KC_G,    KC_M,    RSFT_N,  RCTL_E,  RALT_I,  RGUI_O,  CTL_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    ADJUST,  KC_LCTL, KC_LALT, LOWER,   KC_LEAD, KC_SPC,  SYM,     NAV,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space | SYM  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    ADJUST, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,   SYM,     RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   ↓  |   →  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | GUI  | Alt  | Ctrl | Shift|      | PgUp | PgDn | Home | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ↑  |   ←  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_DOWN, KC_RGHT, KC_LBRC,  KC_RBRC, _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, KC_PGUP, KC_PGDN, KC_HOME,  KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, KC_UP,   KC_LEFT, KC_LCBR,  KC_RCBR, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* SYM
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   |  |   \  |  F1  |  F9  |   -  |  F11 |  F12 |   _  |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_EQL,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_PLUS,
    KC_PIPE, KC_BSLS, KC_F1,   KC_F9,   KC_MINS, KC_F11,  KC_F12,  KC_UNDS,  _______,  KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI,     RGB_SAD,       RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(_QWERTY), DF(_COLEMAK),  _______,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON,     TERM_OFF,      _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,      _______,      _______, _______, _______
)

};

const key_override_t delete_key_override = {
  .trigger_mods           = MOD_BIT(KC_LGUI),
  .layers                 = ~0,
  .suppressed_mods        = MOD_BIT(KC_LGUI),
  .options                = ko_option_no_unregister_on_other_key_down,
  //.negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LCTL)),
  //.custom_action          = momentary_layer,
  //.context                = (void *)LAYER_FN,
  .trigger                = KC_SPC,
  .replacement            = KC_DEL,
  .enabled                = NULL};

const key_override_t backspace_key_override = {
  .trigger_mods           = MOD_BIT(KC_LALT),
  .layers                 = ~0,
  .suppressed_mods        = MOD_BIT(KC_LALT),
  .options                = ko_option_no_unregister_on_other_key_down,
  //.negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LCTL)),
  //.custom_action          = momentary_layer,
  //.context                = (void *)LAYER_FN,
  .trigger                = KC_SPC,
  .replacement            = KC_BSPC,
  .enabled                = NULL};

const key_override_t tab_key_override = {
  .trigger_mods           = MOD_BIT(KC_LCTL),
  .layers                 = ~0,
  .suppressed_mods        = MOD_BIT(KC_LCTL),
  .options                = ko_option_no_unregister_on_other_key_down,
  //.negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LCTL)),
  //.custom_action          = momentary_layer,
  //.context                = (void *)LAYER_FN,
  .trigger                = KC_SPC,
  .replacement            = KC_TAB,
  .enabled                = NULL};

// const key_override_t enter_key_override = {
//   .trigger_mods           = MOD_BIT(KC_LSFT),
//   .layers                 = ~0,
//   .suppressed_mods        = MOD_BIT(KC_LSFT),
//   .options                = ko_option_no_unregister_on_other_key_down,
//   //.negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LGUI)),
//   //.custom_action          = momentary_layer,
//   //.context                = (void *)LAYER_FN,
//   .trigger                = KC_SPC,
//   .replacement            = KC_ENT,
//   .enabled                = NULL};

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &backspace_key_override,
    &tab_key_override,
    //&enter_key_override,
    NULL // Null terminate the array of overrides!
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return state;
}

bool tmux_flag = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        //set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        //set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case KC_TMUX:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a"));
        set_oneshot_layer(_SYM, ONESHOT_START);
        tmux_flag = true;
      } else {
      }
      return true;
    default:
      return true; // Process all other keycodes normally
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_TMUX:
      if (!record->event.pressed) {
      }
      break;
    default:
      if(tmux_flag){
        tmux_flag = false;
        clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
  }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

LEADER_EXTERNS();
void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Common phrases
    SEQ_TWO_KEYS(KC_D, KC_S) {
      SEND_STRING("Dog's sleeping");
    }

    SEQ_TWO_KEYS(KC_D, KC_W) { // doing well
      SEND_STRING("We are doing well.");
    }

    SEQ_TWO_KEYS(KC_H, KC_D) {
      SEND_STRING("How are you doing?");
    }

    SEQ_TWO_KEYS(KC_H, KC_W) { // hope well
      SEND_STRING("Hope you are doing well");
    }

    SEQ_TWO_KEYS(KC_J, KC_C) { // hope well
      SEND_STRING("Just chillin");
    }

    SEQ_ONE_KEY(KC_N) {
      SEND_STRING("Nice");
    }

    SEQ_TWO_KEYS(KC_S, KC_E) {
      SEND_STRING("Super excited!!!");
    }

    SEQ_TWO_KEYS(KC_S, KC_G) {
      SEND_STRING("Sounds good");
    }

    SEQ_ONE_KEY(KC_T) {
      SEND_STRING("Thanks");
    }

    SEQ_TWO_KEYS(KC_T, KC_G) {
      SEND_STRING("That's great");
    }

    SEQ_TWO_KEYS(KC_T, KC_S) {
      SEND_STRING("Thanks sweetie");
    }

    // Email
    SEQ_TWO_KEYS(KC_E, KC_M) { // email mort...
      SEND_STRING("mortifiedchaos01@gmail.com");
    }

    SEQ_TWO_KEYS(KC_E, KC_K) { // email kyler...
      SEND_STRING("kyler.johnson.01@gmail.com");
    }

    // Address
    SEQ_ONE_KEY(KC_A) { // address
      SEND_STRING("19525 73 Ave");
    }

    SEQ_TWO_KEYS(KC_A, KC_C) { // address city
      SEND_STRING("Surrey");
    }

    SEQ_TWO_KEYS(KC_A, KC_P) { // address postal
      SEND_STRING("V4N 6L7");
    }

    // SQL
    SEQ_TWO_KEYS(KC_M, KC_S) {
      SEND_STRING("SELECT * FROM ");
    }

    // Work
    SEQ_TWO_KEYS(KC_W, KC_E) { // work email
      SEND_STRING("kjohnson@schoolathome.ca");
    }

    SEQ_TWO_KEYS(KC_W, KC_U) { // work username
      SEND_STRING("kjohnson");
    }
  }

#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
