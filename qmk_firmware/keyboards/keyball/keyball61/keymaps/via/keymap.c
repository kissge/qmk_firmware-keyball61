/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_GRAVE , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENTER ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_BTN3  ,            KC_BTN2  , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_QUOTE ,
    KC_ESC   , KC_LBRC  , KC_RBRC  , KC_LGUI  , MO(1)    , KC_LALT  , KC_BTN1  ,            KC_SPACE , KC_BTN1  , _______  , _______  , _______  , KC_EQUAL , KC_BSLS
  ),

  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    ,                                  KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    _______  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_DEL   ,
    _______  , NEW_TAB  , CLOSE_TAB, PREV_TAB , NEXT_TAB , CLOSE_WIN,                                  KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , BACK     , FORWARD  ,
    _______  ,REOPEN_TAB, _______  , KC_MUTE  , KC_VOLD  , KC_VOLU  , RESET    ,            EEP_RST  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , CHANGE_OS,            KC_BTN2  , IME      , _______  , _______  , _______  , _______  , RESET
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 1
    keyball_set_scroll_mode(get_highest_layer(state) == 1);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
