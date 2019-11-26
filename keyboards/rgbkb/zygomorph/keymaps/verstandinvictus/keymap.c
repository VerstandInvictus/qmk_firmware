#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN 1

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
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_5x12( \
/* ,----------------------------------------------------.         ---------------------------------------------------.*/
    KC_F1,   KC_F2,    RGB_TOG,  XXXXX,  KC_PAST,  KC_PSLS,         KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, \
/* |--------+--------+--------+--------+---------+-------+-       ------+---------+--------+-------+--------+--------|*/
    KC_F3,   KC_F4,    KC_P7,   KC_P8,   KC_P9,    KC_PMNS,         KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_SLSH, \
/* |--------+--------+--------+--------+---------+-------+-       ------+---------+--------+-------+--------+--------|*/
    KC_F7,   KC_F6,    KC_P4,   KC_P5,  KC_P6,    KC_PPLS,         KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
/* |--------+--------+--------+--------+--;-------+-------+       -------+---------+--------+-------+--------+--------|*/
    KC_F7,   KC_F9,    KC_P1,   KC_P2,  KC_P3,    KC_PEQL,          KC_N,    KC_M,     KC_COMM, KC_DOT, KC_UP,   KC_ENT,  \
/* |--------+--------+--------+--------+---------+-------+-       ------+---------+--------+-------+--------+--------|*/
    KC_F9,   KC_F10,   KC_P0,   KC_PCMM, KC_PDOT,  TAB_FN,        KC_SPC, KC_PGDN,  KC_END, KC_LEFT, KC_DOWN, KC_RGHT \
/* ,-------------------------------------------------------       ---------------------------------------------------.*/
),

[_FN] = LAYOUT_5x12( \
 /* ,----------------------------------------------------.         .-----------------------------------------------------.*/
    XXXXX,   XXXXX,   XXXXX,   XXXXX,   RGB_M_P,  RGB_M_SN,           KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11, KC_F12,  \
/* |--------+--------+--------+--------+---------+-------+-       +--------+---------+--------+-------+--------+--------|*/
    XXXXX,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_B, RGB_M_SW,           RGB_M_P, RGB_M_B,  RGB_M_R, RGB_M_SW, XXXXX, XXXXX,   \
/* |--------+--------+--------+--------+---------+-------+-       +--------+---------+--------+-------+--------+--------|*/
    XXXXX,   RGB_HUI, RGB_SAI, RGB_VAI,  RGB_M_G, RGB_M_X,           RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, XXXXX,  RESET,   \
/* |--------+--------+--------+--------+---------+-------+-       +--------+---------+--------+-------+--------+--------|*/
    XXXXX,   RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_K, RGB_M_R,           XXXXX,   XXXXX,    XXXXX,   XXXXX,  XXXXX,   XXXXX,   \
/* |--------+--------+--------+--------+---------+-------+-       +--------+---------+--------+-------+--------+--------|*/
    XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   TAB_FN,            XXXXX,   XXXXX,    XXXXX,   XXXXX,  XXXXX,   XXXXX   \
),

};

// SSD1306 OLED driver logic
#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
  static const char PROGMEM rgbkb_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(rgbkb_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM mode_logo[4][4] = {
    {0x95,0x96,0},
    {0xb5,0xb6,0},
    {0x97,0x98,0},
    {0xb7,0xb8,0} };

  if (keymap_config.swap_lalt_lgui != false) {
    oled_write_ln_P(mode_logo[0], false);
    oled_write_ln_P(mode_logo[1], false);
  } else {
    oled_write_ln_P(mode_logo[2], false);
    oled_write_ln_P(mode_logo[3], false);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _QWERTY:
      oled_write_ln_P(PSTR("Base Layer"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("Function"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_ln_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif
