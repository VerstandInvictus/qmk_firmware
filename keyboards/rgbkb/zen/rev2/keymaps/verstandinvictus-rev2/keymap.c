#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "secret_macros.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _HY 1
#define _FN 2


// Fillers to make layering more clear
#define _____ KC_TRNS
#define XXXXX KC_NO
#define C_A_D LCTL(LALT(KC_DEL))
#define TAB_FN LT(_FN, KC_TAB)
#define ALT_F5 MT(MOD_LALT, KC_F5)

enum custom_keycodes {
    SH_MNXT = SAFE_RANGE,
    SH_MPRV,
    SH_MPLY,
    SH_VOLD,
    SH_VOLU,
    SH_SH,
    SCP_ANT,
    SCP_MDWY,
    SCP_WEAK,
    SCP_LONG,
    SCP_STRONG
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case SH_MNXT:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                  _delay_ms(150);
                SEND_STRING(SS_TAP(X_MEDIA_NEXT_TRACK));
                SEND_STRING(SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                return false;
            case SH_MPRV:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                  _delay_ms(150);
                SEND_STRING(SS_TAP(X_MEDIA_PREV_TRACK));
                SEND_STRING(SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                return false;
            case SH_MPLY:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                  _delay_ms(150);
                SEND_STRING(SS_TAP(X_MEDIA_PLAY_PAUSE));
                SEND_STRING(SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                return false;
            case SH_VOLD:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                  _delay_ms(150);
                SEND_STRING(SS_TAP(X_AUDIO_VOL_DOWN));
                SEND_STRING(SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                return false;
            case SH_VOLU:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                  _delay_ms(150);
                SEND_STRING(SS_TAP(X_AUDIO_VOL_UP));
                SEND_STRING(SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                return false;
            case SH_SH:
                SEND_STRING(
                  SS_DOWN(X_LSHIFT)
                  SS_TAP(X_RSHIFT)
                  SS_UP(X_LSHIFT));
                return false;
            case SCP_ANT:
                SEND_STRING(ANTPW);
                return false;
            case SCP_MDWY:
                SEND_STRING(MDWPW);
                return false;
            case SCP_WEAK:
                SEND_STRING(WEAKPW);
                return false;
            case SCP_LONG:
                SEND_STRING(LONGPW);
                return false;
            case SCP_STRONG:
                SEND_STRING(STRONGPW);
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
/* ,----------------------------------------------------.                 .-----------------------------------------------------.*/
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    TAB_FN,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_SLSH, \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    MO(_HY), KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   SH_SH,  SH_MPLY,  KC_N,    KC_M,     KC_COMM, KC_DOT, KC_UP,   KC_ENT,  \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    KC_LCTL, KC_LGUI, ALT_F5,  KC_HOME, KC_PGUP,  KC_LBRC,KC_TAB,  KC_SPC, KC_RBRC, KC_PGDN,  KC_END, KC_LEFT, KC_DOWN, KC_RGHT, \
/* ,----------------------------------------------------------------------------------------------------------------------------.*/
                                                  KC_DEL, KC_TAB,  KC_SPC, KC_BSPC \
),

[_HY] = LAYOUT( \
 /* ,----------------------------------------------------.                 .-----------------------------------------------------.*/
    KC_GRV,  KC_TILD, _____,   _____,   KC_DLR,   KC_PERC,                 KC_CALC, _____,    _____,   KC_LPRN, KC_PLUS, KC_EQL, \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    _____,   _____,   _____,   _____,   _____,    KC_LCBR,                 KC_RCBR, _____,    _____,   _____,  KC_PIPE, KC_BSLS, \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    MO(_HY), _____,   _____,   _____,   _____,    KC_LBRC,                 KC_RBRC, _____,    _____,   C_A_D,  KC_PIPE, _____,   \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    _____,   _____,   _____,   _____,   KC_VOLD,  KC_VOLU, _____,   _____, SCP_WEAK,SCP_LONG,SCP_STRONG,SCP_ANT,SCP_MDWY,_____,   \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    _____,   _____,   _____,   _____,   SH_VOLD,  SH_MPRV, _____,  _____,  SH_MNXT, SH_VOLU,   _____,   _____,   _____,  _____,   \
/* ,----------------------------------------------------------------------------------------------------------------------------.*/
                                                  SH_MPLY, SH_MPRV, SH_MNXT, SH_MPLY \
),

[_FN] = LAYOUT( \
 /* ,----------------------------------------------------.                 .-----------------------------------------------------.*/
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                   KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11, KC_F12,  \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    TAB_FN,  RGB_TOG, RGB_MOD, RGB_RMOD, XXXXX,   XXXXX,                   RGB_M_P, RGB_M_B,  RGB_M_R, RGB_M_SW, XXXXX, XXXXX,   \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    XXXXX,   RGB_HUI, RGB_SAI, RGB_VAI,  XXXXX,   XXXXX,                   RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, XXXXX,  RESET,   \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    XXXXX,   RGB_HUD, RGB_SAD, RGB_VAD, XXXXX,    XXXXX,  XXXXX,   XXXXX,  XXXXX,   XXXXX,    XXXXX,   XXXXX,  XXXXX,   XXXXX,   \
/* |--------+--------+--------+--------+---------+-------+-------..-------+--------+---------+--------+-------+--------+--------|*/
    _____,   _____,   _____,   XXXXX,   XXXXX,    XXXXX,  XXXXX,   XXXXX,  XXXXX,   XXXXX,    XXXXX,   XXXXX,  XXXXX,   XXXXX,   \
/* ,----------------------------------------------------------------------------------------------------------------------------.*/
                                                 XXXXX,   XXXXX,   XXXXX, XXXXX \
),

};

const uint16_t PROGMEM fn_actions[] = {
};

#if OLED_DRIVER_ENABLE
const char* layer_name_user(uint32_t layer) {
  switch (layer) {
    case _QWERTY:
      return PSTR("QWRTY");
    case _NAV:
      return PSTR("NAV\n");
    default:
      return PSTR("UNDEF");
  }
}
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { /* Second encoder from slave */
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}
