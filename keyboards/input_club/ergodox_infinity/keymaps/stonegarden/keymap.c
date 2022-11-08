#include QMK_KEYBOARD_H
#include "version.h"

enum custom_layers {
    _BASE,
    _MEDIA,
    _NUMPAD,
    _FUNC,
};

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
        BASE,       VRSN,
        _______,
        _______, _______, _______)
};

// https://docs.qmk.fm/#/feature_st7565?id=st7565-lcd-driver
#ifdef ST7565_ENABLE
void st7565_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            if (is_keyboard_master()) {
                st7565_write_ln_P(PSTR("\n     Ergodox    \n        Infinity\n"), false);
            } else {
                static const char PROGMEM qmk_logo[] = {
                    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
                    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
                    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
                };

                st7565_write_P(qmk_logo, false);
            }
            // Takes values between 0 and UINT16_MAX (65 535)
            ergodox_infinity_lcd_color(25000, 25000, 25000);
            break;
        case _MEDIA:
            st7565_write_ln_P(PSTR("\n        MEDIA\n\n"), false);
            ergodox_infinity_lcd_color(10000, 10000, 40000);
            break;
        case _NUMPAD:
            if (is_keyboard_master()) {
                st7565_write_ln_P(PSTR("\n        MOUSE\n\n"), false);
                ergodox_infinity_lcd_color(25000, 25000, 0);
            } else {
                st7565_write_ln_P(PSTR("\n        NUMPAD\n\n"), false);
                ergodox_infinity_lcd_color(0, 32768, 0);
            }
            break;
        case _FUNC:
            st7565_write_ln_P(PSTR("\n       FUNCTION\n\n"), false);
            ergodox_infinity_lcd_color(UINT16_MAX >> 1, 0, UINT16_MAX >> 1);
            break;
        default:
            st7565_write_ln_P(PSTR("\n       UNDEFINED\n\n"), false);
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                layer_on(_BASE);
                layer_off(_MEDIA);
                layer_off(_NUMPAD);
                layer_off(_FUNC);
                // set_single_persistent_default_layer(_BASE);
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
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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