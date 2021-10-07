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
    _MO2,
    _MO3,
};

enum custom_keycodes {
  RGB_STA = SAFE_RANGE,
  RGB_GRA,
  RGB_CYC,
  KC_00,
  KC_WINLCK,
};

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
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP,          KC_PWR,
        _______, RGB_STA, RGB_GRA, RGB_CYC, RGB_M_P, RGB_M_B, RGB_M_R, _______, _______, _______, _______, _______, _______, _______,          _______,
        RGB_TOG, RGB_HUD, RGB_VAI, RGB_HUI, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_NLCK, _______, _______, RESET,            _______,
        KC_CAPS, RGB_SAD, RGB_VAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          RGB_SPD, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP, _______,
        _______, KC_WINLCK, _______,                            AG_TOGG,                            _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

    [_MO2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PMNS, KC_PPLS, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PDOT, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_PAST,          KC_PENT,          _______,
        _______,          KC_NO,   KC_DEL,  KC_INS,  KC_NO,   KC_NO,   KC_NO,   KC_P0,   KC_00,   KC_PDOT, KC_PSLS,          _______, RCTL(KC_PGUP), _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RCTL(KC_LEFT), RCTL(KC_PGDN), RCTL(KC_RIGHT)
    ),

    [_MO3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
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
        case KC_00:
            if (record->event.pressed) {
                // when keycode KC_00 is pressed
                SEND_STRING("00");
            } else {
                // when keycode KC_00 is released
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
            rgb_matrix_set_color(LED_L1, RGB_GREEN);
            rgb_matrix_set_color(LED_L2, RGB_GREEN);
        }
        if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
            rgb_matrix_set_color(LED_L3, RGB_MAGENTA);
            rgb_matrix_set_color(LED_L4, RGB_MAGENTA);
        }
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_L5, RGB_RED);
            rgb_matrix_set_color(LED_L6, RGB_RED);
            rgb_matrix_set_color(LED_L7, RGB_RED);
            rgb_matrix_set_color(LED_L8, RGB_RED);
        }
        if (_isWinKeyDisabled) {
            rgb_matrix_set_color(LED_LGUI, RGB_RED);  //light up Win key when disabled
        }

        // Layer indicators on right side lights.
        if (layer_state_is(_FN1)) {
            rgb_matrix_set_color(LED_R1, RGB_RED);
            rgb_matrix_set_color(LED_R2, RGB_RED);
            rgb_matrix_set_color(LED_R3, RGB_RED);
            rgb_matrix_set_color(LED_R4, RGB_RED);
            rgb_matrix_set_color(LED_FN, RGB_RED);
        }

        switch(get_highest_layer(layer_state)){  // special handling per layer
        case _FN1:  // on Fn layer select what the encoder does when pressed
            // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row;  larger numbers using 16bit code
            // if (timeout_threshold <= 10) rgb_matrix_set_color(LED_LIST_FUNCROW[timeout_threshold], RGB_RED);
            // else if (timeout_threshold < 140) {
            //     rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold / 10)], RGB_RED);
            //     rgb_matrix_set_color(LED_LIST_NUMROW[(timeout_threshold % 10)], RGB_RED);
            // } else { // >= 140 minutes, just show these 3 lights
            //     rgb_matrix_set_color(LED_LIST_NUMROW[10], RGB_RED);
            //     rgb_matrix_set_color(LED_LIST_NUMROW[11], RGB_RED);
            //     rgb_matrix_set_color(LED_LIST_NUMROW[12], RGB_RED);
            // }
            break;
        case _MO2: // Numpad layer
            for (uint8_t i=0; i<sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_MAGENTA);
            }
            rgb_matrix_set_color(LED_R5, RGB_MAGENTA);
            rgb_matrix_set_color(LED_R6, RGB_MAGENTA);
            rgb_matrix_set_color(LED_R7, RGB_MAGENTA);
            rgb_matrix_set_color(LED_R8, RGB_MAGENTA);
            break;
        case _MO3:
            rgb_matrix_set_color(LED_R5, RGB_GREEN);
            rgb_matrix_set_color(LED_R6, RGB_GREEN);
            rgb_matrix_set_color(LED_R7, RGB_GREEN);
            rgb_matrix_set_color(LED_R8, RGB_GREEN);
            break;
        default:
            break;
        }
    }

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif
