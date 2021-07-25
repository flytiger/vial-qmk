/* Copyright 2021 Jonavin Eng
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



#ifdef RGB_MATRIX_ENABLE

    // RGB LED locations
    enum led_location_map {
        LED_LSFT, // 0, Sh_L, k13
        LED_LEFT, // 1, Left, k16
        LEB_RCTL, // 2, Ct_R, k11
        LED_RIGHT, // 3, Right, k21
        LED_LCTL, // 4, Ct_L, k00
        LED_F5, // 5, F5, k06
        LED_Q, // 6, Q, k26
        LED_TAB, // 7, Tab, k17
        LED_A, // 8, A, k10
        LED_ESC, // 9, Esc, k12
        LED_Z, // 10, Z, k14
        LED_PGUP, // 11, PgUp, k90
        LED_GRV, // 12, ~, k36
        LED_1, // 13, 1, k27
        LED_W, // 14, W, k20
        LED_CAPS, // 15, Caps, k22
        LED_S, // 16, S, k24
        LED_X, // 17, X, k93
        LED_PGDN, // 18, PgDn, k31
        LED_F1, // 19, F1, k37
        LED_2, // 20, 2, k30
        LED_E, // 21, E, k32
        LED_F3, // 22, F3, k34
        LED_D, // 23, D, k33
        LED_F4, // 24, F4, k47
        LED_C, // 25, C, k40
        LED_UP, // 26, Up, k42
        LED_F2, // 27, F2, k44
        LED_3, // 28, 3, k07
        LED_R, // 29, R, k46
        LED_T, // 30, T, k41
        LED_F, // 31, F, k43
        LED_G, // 32, G, k45
        LED_V, // 33, V, k94
        LED_B, // 34, B, k63
        LED_5, // 35, 5, k56
        LED_4, // 36, 4, k51
        LED_U, // 37, U, k53
        LED_Y, // 38, Y, k55
        LED_J, // 39, J, k71
        LED_H, // 40, H, k57
        LED_M, // 41, M, k50
        LED_N, // 42, N, k52
        LED_6, // 43, 6, k54
        LED_7, // 44, 7, k76
        LED_I, // 45, I, k67
        LED_RBRC, // 46, ], k60
        LED_K, // 47, K, k62
        LED_F6, // 48, F6, k64
        LED_COMM, // 49, ,, k95
        LED_HOME, // 50, Home, ka6
        LED_EQL, // 51, =, k77
        LED_8, // 52, 8, k70
        LED_O, // 53, O, k72
        LED_F7, // 54, F7, k74
        LED_L, // 55, L, k92
        LED_DOWN, // 56, Down, ka7
        LED_DOT, // 57, ., k87
        LED_END, // 58, End, k80
        LED_F8, // 59, F8, k82
        LED_9, // 60, 9, k85
        LED_P, // 61, P, ka3
        LED_LBRC, // 62, [, k86
        LED_SCLN, // 63, ;, k81
        LED_QUOT, // 64, ", k83
        LED_SLSH, // 65, /, k04
        LED_MINS, // 66, -, ka5
        LED_0, // 67, 0, l01
        LED_LGUI, // 68, Gui_L, l11
        LED_RSFT, // 69, Sft_R, k97
        LED_FN, // 70, MO(1), l02
        LED_LALT, // 71, LED_LALT, l12
        LED_SPC, // 72, Space, k65
        LED_RALT, // 73, Alt_R, l03
        LED_DEL, // 74, Del, l13
        LED_BSPC, // 75, BSpc, k15
        LED_BSLS, // 76, \, l04
        LED_F11, // 77, F11, l14
        LED_ENT, // 78, Enter, k66
        LED_F12, // 79, F12, k05
        LED_F9, // 80, F9, l05
        LED_F10, // 81, F10, l15
        LED_L1, // 82, LED_L1, k75
        LED_L2, // 83, LED_L2, l06
        LED_L3, // 84, LED_L3, l16
        LED_L4, // 85, LED_L4, ka1
        LED_L5, // 86, LED_L5, k25
        LED_L6, // 87, LED_L6, l07
        LED_L7, // 88, LED_L7, l17
        LED_L8, // 89, LED_L8, k61
        LED_R1, // 90, LED_R1, k91
        LED_R2, // 91, LED_R2, l08
        LED_R3, // 92, LED_R3, l18
        LED_R4, // 93, LED_R4, ka2
        LED_R5, // 94, LED_R5, k35
        LED_R6, // 95, LED_R6, k03
        LED_R7, // 96, LED_R7, ka4
        LED_R8 // 97, LED_R8, k73
    };

    const uint8_t LED_LIST_WASD[] = { LED_W, LED_A, LED_S, LED_D };

    const uint8_t LED_LIST_ARROWS[] = { LED_LEFT, LED_RIGHT, LED_UP, LED_DOWN };

    const uint8_t LED_LIST_FUNCROW[] = { LED_ESC, LED_F1, LED_F2, LED_F3, LED_F4, LED_F5, LED_F6, LED_F7, LED_F8, LED_F9, LED_F10, LED_F11, LED_F12, LED_DEL};

    const uint8_t LED_LIST_NUMROW[] = { LED_GRV, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0, LED_MINS, LED_EQL, LED_BSPC, LED_DEL};

    const uint8_t LED_LIST_NUMPAD[] = {
        LED_7, LED_8, LED_9,
        LED_U, LED_I, LED_O,
        LED_J, LED_K, LED_L,
        LED_M, LED_COMM, LED_DOT
        };

    const uint8_t LED_SIDE_LEFT[] = { LED_L1, LED_L2, LED_L3, LED_L4, LED_L5, LED_L6, LED_L7, LED_L8};

    const uint8_t LED_SIDE_RIGHT[] = { LED_R1, LED_R2, LED_R3, LED_R4, LED_R5, LED_R6, LED_R7, LED_R8};

#endif
