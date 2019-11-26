#include QMK_KEYBOARD_H
#include "secret_macros.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
//    _ETCH,
//    _PROG,
    _HY,
    _FN,
};

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
    SCP_STRONG,
    SCP_NXTPW,
    LI_HALF,
    RGBRST
};

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
extern void eeconfig_update_rgb_matrix_default(void);
#endif


#define FN_ESC   LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)
#define C_A_D LCTL(LALT(KC_DEL))
#define C_S_E LCTL(LSFT(KC_ESC))
#define TAB_FN LT(_FN, KC_TAB)
#define ALT_F5 MT(MOD_LALT, KC_F5)
#define FLT_TB LALT(KC_TAB)
#define BLT_TB LSFT(LALT(KC_TAB))
#define FWN_TB LGUI(KC_TAB)
#define BWN_TB LSFT(LGUI(KC_TAB))

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
            case SCP_NXTPW:
                SEND_STRING(NXTPW);
                return false;
            case LI_HALF:
                SEND_STRING("Not to worry, we are still operating half a datacenter.");
                return false;
            case RGBRST:
                #if defined(RGBLIGHT_ENABLE)
                    if (record->event.pressed) {
                      eeconfig_update_rgblight_default();
                      rgblight_enable();
                    }
                #elif defined(RGB_MATRIX_ENABLE)
                    if (record->event.pressed) {
                      eeconfig_update_rgb_matrix_default();
                    }
                #endif
            return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_PSCR,  KC_BRK,   KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS, \
    TAB_FN,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_INS,   KC_SLCK,  KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_SLSH, \
    MO(_HY),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_BSLS,  KC_EQL,   KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     C_S_E,    KC_MPLY,  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_UP,    KC_ENT, \
    KC_RCTL,    KC_LGUI, ALT_F5,  KC_HOME, KC_PGUP, KC_LBRC,  KC_TAB,   KC_SPC,   KC_RBRC, KC_PGDN, KC_END,   KC_LEFT, KC_DOWN,  KC_RIGHT, \
                                                    KC_DEL,   KC_TAB,   KC_SPC,   KC_BSPC \
  ),


  [_HY] = LAYOUT( \
     KC_GRV, KC_TILD,   _______,  _______, _______, _______, C_A_D,   KC_CALC, _______,  _______,   _______,    KC_LPRN,   KC_PLUS,  KC_EQL, \
    _______, _______,   _______,  _______, _______, _______, _______, LI_HALF, _______,  _______,   _______,    _______,   KC_PIPE,  KC_BSLS, \
    MO(_HY), _______,   _______,  _______, _______, _______, _______, _______, _______,  _______,   _______,    C_A_D,     _______,  _______, \
    _______, _______,   _______,  _______, _______, _______, _______, _______, SCP_WEAK, SCP_LONG,  SCP_STRONG, SCP_ANT,   SCP_MDWY, SCP_NXTPW, \
    _______, _______,   _______,  _______, KC_VOLD, KC_VOLU, KC_MPLY, KC_MPLY, _______,  _______,   _______,    _______,   _______,  _______, \
                                                    KC_MPRV, KC_MPLY, KC_MPLY, KC_MNXT \
  ),

  [_FN] =  LAYOUT( \
    KC_F12,   KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,  KC_F13,  KC_F14,  KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11, \
    TAB_FN,  RGB_TOG, RGB_MOD, RGB_RMOD, RGBRST,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_HUI, RGB_SAI, RGB_VAI,  RGB_SPI,  _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
    _______, RGB_HUD, RGB_SAD, RGB_VAD,  RGB_SPD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,  _______,  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, \
                                                   _______, RESET,   _______, _______ \
  )
};

#ifdef ENCODER_ENABLE
const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS * 2][2]  = {
    [_QWERTY] = EXTRA_ENCODER_LAYOUT( \
        KC_WH_D, KC_WH_U,
        KC_WH_D, KC_WH_U,
        KC_WH_D, KC_WH_U,
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD
    ),
    [_HY] = EXTRA_ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_FN] = EXTRA_ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t layer = biton32(layer_state);
  uint16_t keycode = pgm_read_word(&encoders[layer][index][clockwise]);
  while (keycode == KC_TRANSPARENT && layer > 0)
  {
    layer--;
    if ((layer_state & (1 << layer)) != 0)
        keycode = pgm_read_word(&encoders[layer][index][clockwise]);
  }
  if (keycode != KC_TRANSPARENT)
    tap_code16(keycode);
}
#endif
