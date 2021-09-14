#pragma once

#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, RGB_MODE_REVERSE, RGB_MODE_FORWARD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
// default rotary encoder behavior

#define TAPPING_TOGGLE 2
// TT set to two taps

#define TAPPING_TERM 165

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_UP_DOWN
    #define RGB_MATRIX_STARTUP_SAT 255
    #define RGB_MATRIX_STARTUP_VAL 192
    #define RGB_MATRIX_STARTUP_SPD 30

    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 225
    #define RGB_DISABLE_TIMEOUT 0
#endif //RGB_MATRIX_ENABLE

#define VIA_CUSTOM_LIGHTING_ENABLE
#define VIA_QMK_RGBLIGHT_ENABLE