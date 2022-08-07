/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum custom_keycodes {
  KC_TMUX = SAFE_RANGE,
};

enum layers {
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _MOUSE,
    // _ADJUST,
};

// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)

#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define MOUSE    MO(_MOUSE)
//#define ADJUST   MO(_ADJUST)
#define SYM_RBRC LT(_SYM, KC_RBRC)

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
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM tm_tmux[] = {LSHFT_T, KC_M, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {RSFT_N, RCTL_E, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, RSFT_N, COMBO_END};

combo_t key_combos[] = {
  [TM_TMUX] = COMBO(tm_tmux, KC_TMUX),
  [NE_ESC] = COMBO(ne_combo, KC_ESC),
  [MN_MENU] = COMBO(mn_combo, KC_APP),
};



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space|  [{  |  |Sym/]}| Nav  | Mouse| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     CTL_ESC ,LGUI_A, LALT_R  , LCTL_S , LSHFT_T,   KC_G ,                                        KC_M, RSFT_N , RCTL_E,  RALT_I,RGUI_O ,CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                _______, KC_LGUI, KC_LEAD, KC_SPC ,KC_LBRC,    SYM_RBRC,   NAV   ,MOUSE,KC_RGUI, KC_APP
    ),
/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |  ↓   |  →   |      |      | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgUp | PgDn | Home | End  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      |  ↑   |  ←   |M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_DOWN, KC_RGHT, _______, _______,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGUP, KC_PGDN, KC_HOME, KC_END , KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SLCK, _______, _______, KC_UP  , KC_LEFT, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | KC_TILD|  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   | KC_PLUS|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | KC_PIPE|   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   | KC_QUES|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
      KC_TILD, KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
      KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Mouse Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |   ↑  |      |      |        |
 * |--------+------+------+------+------+------|                              |-------+-----+------+------+------+--------|
 * |        | ACL0 | ACL1 | ACL2 |  M1  |  M2  |                              |      |   ←  |   ↓  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+-------+-----+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, KC_MS_U, _______, _______, _______,
      _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, KC_BTN2,                                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |DT_PRT|DT_UP |DT_DWN|      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    //
    // [_ADJUST] = LAYOUT(
    //   _______, _______, _______, _______, _______, _______,                                    DT_PRNT,DT_UP  , DT_DOWN, _______,  _______, _______,
    //   _______, _______, _______, COLEMAK, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
    //   _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
    //                              _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    // ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
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

const key_override_t enter_key_override = {
  .trigger_mods           = MOD_BIT(KC_LSFT),
  .layers                 = ~0,
  .suppressed_mods        = MOD_BIT(KC_LSFT),
  .options                = ko_option_no_unregister_on_other_key_down,
  //.negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LGUI)),
  //.custom_action          = momentary_layer,
  //.context                = (void *)LAYER_FN,
  .trigger                = KC_SPC,
  .replacement            = KC_ENT,
  .enabled                = NULL};

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &backspace_key_override,
    &tab_key_override,
    &enter_key_override,
    NULL // Null terminate the array of overrides!
};

bool tmux_flag = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Common phrases
    SEQ_TWO_KEYS(KC_D, KC_W) { // doing well
      SEND_STRING("We are doing well.");
    }

    SEQ_TWO_KEYS(KC_H, KC_G) { // how's going
      SEND_STRING("How are you doing?");
    }

    SEQ_TWO_KEYS(KC_H, KC_W) { // hope well
      SEND_STRING("Hope you are doing well");
    }

    SEQ_TWO_KEYS(KC_S, KC_G) {
      SEND_STRING("Sounds good");
    }

    SEQ_ONE_KEY(KC_T) {
      SEND_STRING("Thanks");
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

    // Work
    SEQ_TWO_KEYS(KC_W, KC_E) { // work email
      SEND_STRING("kjohnson@schoolathome.ca");
    }

    SEQ_TWO_KEYS(KC_W, KC_U) { // work username
      SEND_STRING("kjohnson@schoolathome.ca");
    }

    // SEQ_ONE_KEY(KC_F) {
    //   // Anything you can do in a macro.
    //   SEND_STRING("QMK is awesome.");
    // }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }
}
