#include QMK_KEYBOARD_H

enum layers {
    _BASE, // default layer
    _NAV,  // navigation keys
};

// Key definitions for layer switching and one-shot modifiers
#pragma region A
#define LT_NAV_SPACE LT(_NAV, KC_SPC)
#define MO_NAV MO(_NAV)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#pragma endregion

#pragma region Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_E,    KC_R,         KC_T,             KC_Z,    KC_U,   KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D,    KC_F,         KC_G,             KC_H,    KC_J,   KC_K, KC_L, KC_SCLN,
        KC_Y, KC_X, KC_C,    KC_V,         KC_B,             KC_N,    KC_M,   KC_COMM, KC_DOT, KC_MINS,
                    _______, LT_NAV_SPACE, OS_LSFT,          OS_RSFT, MO_NAV, _______),

    [_NAV] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,         KC_PGUP, KC_HOME, KC_UP, KC_END, _______,
        OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, _______,         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,
        _______, _______, _______, _______, _______,         KC_ESC, KC_BSPC, KC_ENT, KC_TAB, KC_DEL,
                          _______, _______, _______,         KC_ENT, KC_BSPC, _______),
};
#pragma endregion


#pragma region System Hooks
// This is ran as the very last task in the keyboard initialization process. This is useful if you want to
// make changes to certain features, as they should be initialized by this point.
void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(0, 0, 0);

    // This is good in case I screw anything up with bad code; it's REALLY hard
    // to fix it when mods get messed up since it can mess up the whole OS.
    //
    // Ctrl+alt+del can help on Windows, as can osk.exe sometimes.
    clear_mods();
}
#pragma endregion
