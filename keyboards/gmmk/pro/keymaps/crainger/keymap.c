/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "rgb_matrix_map.h"

enum custom_layers {
    _BASE,
    _FN1,
    _MO1,
    _MO2,
};

enum custom_keycodes {
  RGB_STA = SAFE_RANGE,
  RGB_GRA,
  RGB_CYC,
  KC_WINLCK,
};

// Tap Dance Definitions
enum custom_tapdance {
  TD_CAPSLOCK_MO,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for shift, twice for Caps Lock
  [TD_CAPSLOCK_MO] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_CAPS, _MO2),
};

#define TD_CAPS TD(TD_CAPSLOCK_MO)

bool _isWinKeyDisabled = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN1),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_SLCK,           KC_PWR,
        _______, RGB_STA, RGB_GRA, RGB_CYC, RGB_M_P, RGB_M_B, RGB_M_R, _______, _______, _______, _______, RGB_RMOD, RGB_MOD, RGB_TOG,           RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_PSCR, _______,  _______, RESET,             RGB_HUD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,           RGB_SAI,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,  RGB_VAI, RGB_SAD,
        _______, KC_WINLCK, _______,                            _______,                           _______, _______, _______, RGB_SPD,  RGB_VAD, RGB_SPI
    ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_STA:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_indicator_static);
            }
            return false; // Skip all further processing of this key
        case RGB_GRA:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_indicator_gradient);
            }
            return false; // Skip all further processing of this key
        case RGB_CYC:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_indicator_cycle_all);
            }
            return false; // Skip all further processing of this key
        case KC_WINLCK:
            if (record->event.pressed) {
                _isWinKeyDisabled = !_isWinKeyDisabled; //toggle status
                if(_isWinKeyDisabled) {
                    process_magic(GUI_OFF, record);
                } else {
                    process_magic(GUI_ON, record);
                }
            } else  unregister_code16(keycode);
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}

#ifdef RGB_MATRIX_ENABLE
    // Capslock, Scroll lock and Numlock  indicator on Left side lights.
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
            rgb_matrix_set_color(LED_DEL, RGB_RED);
        }
        if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
            rgb_matrix_set_color(LED_ESC, RGB_RED);
        }
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_CAPS, RGB_RED);
        }
        if (_isWinKeyDisabled) {
            rgb_matrix_set_color(LED_LGUI, RGB_RED);  //light up Win key when disabled
        }
    }

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (clockwise) {
      tap_code(KC_WH_R);
    } else {
      tap_code(KC_WH_L);
    }
    return true;
}
