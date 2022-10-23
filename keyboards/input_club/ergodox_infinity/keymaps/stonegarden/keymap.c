#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"

enum custom_keycodes {
    BASE = SAFE_RANGE,
    MEDIA,
    NUMPAD,
    FUNC,
    EPRM,
    VRSN,
    RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_ergodox(
            /* LEFT */
            KC_BSLS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_ESC,
            KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       MEDIA,
            KC_GRV,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
            KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LBRC,
            KC_LCTL,    KC_LALT,    KC_LGUI,    KC_TILD,    KC_DLR,
                                                                        LCA_T(KC_MENU), KC_PSCR,
                                                                                        KC_HOME,
                                                            KC_BSPC,    KC_DEL,         KC_END,
            /* RIGHT */
            KC_ESC,     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,   KC_SLSH,
            NUMPAD,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,   KC_QUOT,
                        KC_H,       KC_J,       KC_K,       KC_L,       LT(1,KC_SCLN),  KC_EQL,
            KC_RBRC,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     LSFT(KC_SCLN),  KC_MINS,
            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_RALT,
            FUNC,       KC_INS,
            KC_PGUP,
            KC_PGDN,    KC_ENT,     KC_SPC),


    [_MEDIA] = LAYOUT_ergodox(
            /* LEFT */
            RESET,      RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_RMOD,   RGB_MOD,
            EEP_RST,    RGB_M_P,    RGB_M_B,    RGB_M_R,    RGB_M_SW,   RGB_M_SN,   BASE,
            _______,    RGB_M_K,    RGB_M_X,    RGB_M_G,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,    _______,
            RGB_TOG,    RGB_SPD,    RGB_SPI,    RGB_VAD,    RGB_VAI,
                                                                        _______,    _______,
                                                                                    _______,
                                                            _______,     _______,   _______,
            /* RIGHT */
            _______,    _______,    _______,    _______,    _______,    _______,    RESET,
            BASE,       KC_MPRV,    KC_MUTE,    _______,    KC_MNXT,    _______,    _______,
                        KC_MRWD,    KC_VOLD,    KC_VOLU,    KC_MFFD,    _______,    KC_MPLY,
            _______,    _______,    _______,    _______,    _______,    _______,    KC_MSTP,
            BL_BRTG,    BL_TOGG,    BL_DEC,     BL_INC,     _______,
            _______,    _______,
            _______,
            _______,    _______,    _______),


	[_NUMPAD] = LAYOUT_ergodox(
            /* LEFT */
            RESET,      _______,    _______,    KC_BTN4,    KC_BTN5,    _______,    _______,
            _______,    KC_ACL0,    KC_WBAK,    KC_BTN1,    KC_BTN2,    KC_WFWD,    BASE,
            _______,    KC_ACL1,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,
            _______,    KC_ACL2,    KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    KC_BTN3,
            _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,
                                                                                    _______,
                                                            _______,    _______,    _______,
            /* RIGHT */
            _______,    _______,    KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS,    RESET,
            BASE,       KC_LPRN,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS,    EEP_RST,
                        KC_RPRN,    KC_P4,      KC_P5,      KC_P6,      KC_PDOT,    _______,
            _______,    KC_P0,      KC_P1,      KC_P2,      KC_P3,      KC_PCMM,    _______,
            _______,    _______,    _______,    _______,    _______,
            FUNC,       _______,
            _______,
            _______,    _______,    KC_P0),


	[_FUNC] = LAYOUT_ergodox(
            /* LEFT */
            RESET,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,
            EPRM,       _______,    _______,    _______,    _______,    _______,    BASE,
            _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,     LSFT(KC_INS), _______,
            _______,    _______,    _______,    _______,    _______,
                                                                        MAGIC_TOGGLE_NKRO,   _______,
                                                                                    _______,
                                                                        _______,    _______, _______,
            /* RIGHT */

            RESET,        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,   KC_F11,
            BASE,       _______,    _______,    _______,    _______,    _______,    KC_F12,
                        _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    KC_RGUI,    KC_RSFT,
            _______,    _______,    _______,    _______,    KC_RCTL,
            BASE,       _______,
            _______,
            _______, _______, _______)
};

//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//  // MACRODOWN only works in this function
//  switch(id) {
//    case 0:
//      if (record->event.pressed) {
//        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//      }
//      break;
//    case 1:
//      if (record->event.pressed) { // For resetting EEPROM
//        eeconfig_init();
//      }
//      break;
//  }
//  return MACRO_NONE;
//}

//void matrix_init_user() {
//  backlight_enable();
//  backlight_level(BACKLIGHT_LEVELS);
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BASE:
      if (record->event.pressed) {
          layer_on(_BASE);
          layer_off(_MEDIA);
          layer_off(_NUMPAD);
          layer_off(_FUNC);
          //set_single_persistent_default_layer(_BASE);
      }
      return false;
    case MEDIA:
      if (record->event.pressed) {
          layer_on(_MEDIA);
      }
      return false;
    case NUMPAD:
      if (record->event.pressed) {
          layer_on(_NUMPAD);
      }
      return false;
    case FUNC:
      if (record->event.pressed) {
          layer_on(_FUNC);
      }
      return false;
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
        #endif
      }
      return false;
  }
  return true;
}