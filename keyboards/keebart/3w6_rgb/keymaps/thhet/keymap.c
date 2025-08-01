#include QMK_KEYBOARD_H

enum layers {
    _BASE, // default layer
    _NAV,  // navigation keys
};

// Key definitions for layer switching and one-shot modifiers
#pragma region Custom Key Definitions
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

#pragma region Colors
#define LED_HIGH_INTENSITY 0x48
#define LED_LOW_INTENSITY 0x8

#define RGB_DARK_BLUE 0x00, 0x00, LED_LOW_INTENSITY
#define RGB_DARK_CYAN 0x00, LED_LOW_INTENSITY, LED_LOW_INTENSITY
#define RGB_DARK_GREEN 0x00, LED_LOW_INTENSITY, 0x00
#define RGB_DARK_MAGENTA LED_LOW_INTENSITY, 0x00, LED_LOW_INTENSITY
#define RGB_DARK_RED LED_LOW_INTENSITY, 0x00, 0x00
#define RGB_DARK_WHITE LED_LOW_INTENSITY, LED_LOW_INTENSITY, LED_LOW_INTENSITY
#define RGB_DARK_YELLOW LED_LOW_INTENSITY, LED_LOW_INTENSITY, 0x00

#define RGB_LIGHT_BLUE 0x00, 0x00, LED_HIGH_INTENSITY
#define RGB_LIGHT_CYAN 0x00, LED_HIGH_INTENSITY, LED_HIGH_INTENSITY
#define RGB_LIGHT_GREEN 0x00, LED_HIGH_INTENSITY, 0x00
#define RGB_LIGHT_MAGENTA LED_HIGH_INTENSITY, 0x00, LED_HIGH_INTENSITY
#define RGB_LIGHT_RED LED_HIGH_INTENSITY, 0x00, 0x00
#define RGB_LIGHT_WHITE LED_HIGH_INTENSITY, LED_HIGH_INTENSITY, LED_HIGH_INTENSITY
#define RGB_LIGHT_YELLOW LED_HIGH_INTENSITY, LED_HIGH_INTENSITY, 0x00
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

#pragma region Variables
bool active_right_shift_osm = false;
bool active_left_shift_osm = false;
bool active_right_ctrl_osm = false;
bool active_left_ctrl_osm = false;
bool active_right_alt_osm = false;
bool active_left_alt_osm = false;
bool active_right_gui_osm = false;
bool active_left_gui_osm = false;
#pragma endregion Variables

#pragma region Helper functions
void light_up_left_mods(
    uint8_t r_off, uint8_t g_off, uint8_t b_off,
    uint8_t r_on, uint8_t g_on, uint8_t b_on
) {
    if (active_left_shift_osm) {
        rgb_matrix_set_color(6, r_on, g_on, b_on); // F
    } else {
         rgb_matrix_set_color(6, r_off, g_off, b_off);
    }
    if (active_left_ctrl_osm) {
        rgb_matrix_set_color(7, r_on, g_on, b_on); // D
    } else {
        rgb_matrix_set_color(7, r_off, g_off, b_off);
    }
    if (active_left_alt_osm) {
        rgb_matrix_set_color(8, r_on, g_on, b_on); // S
    } else {
        rgb_matrix_set_color(8, r_off, g_off, b_off);
    }
    if (active_left_gui_osm) {
        rgb_matrix_set_color(9, r_on, g_on, b_on); // A
    } else {
        rgb_matrix_set_color(9, r_off, g_off, b_off);
    }
}

void light_up_right_mods(
    uint8_t r_off, uint8_t g_off, uint8_t b_off,
    uint8_t r_on, uint8_t g_on, uint8_t b_on
) {
    if (active_right_shift_osm) {
        rgb_matrix_set_color(29, r_on, g_on, b_on); // J
    } else {
         rgb_matrix_set_color(29, r_off, g_off, b_off);
    }
    if (active_right_ctrl_osm) {
        rgb_matrix_set_color(28, r_on, g_on, b_on); // K
    } else {
        rgb_matrix_set_color(28, r_off, g_off, b_off);
    }
    if (active_right_alt_osm) {
        rgb_matrix_set_color(27, r_on, g_on, b_on); // L
    } else {
        rgb_matrix_set_color(27, r_off, g_off, b_off);
    }
    if (active_right_gui_osm) {
        rgb_matrix_set_color(26, r_on, g_on, b_on); // Ö
    } else {
        rgb_matrix_set_color(26, r_off, g_off, b_off);
    }
}

void reset_all_osm(void) {
    active_right_shift_osm = false;
    active_left_shift_osm = false;
    active_right_ctrl_osm = false;
    active_left_ctrl_osm = false;
    active_right_alt_osm = false;
    active_left_alt_osm = false;
    active_right_gui_osm = false;
    active_left_gui_osm = false;
}
#pragma endregion

#pragma region System Callbacks
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

// Keyboard-level callback, invoked after current animation frame is rendered but before it is flushed to
// the LEDs. Returns true to continue running the keyboard-level callback.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:

            rgb_matrix_set_color(15, RGB_LIGHT_WHITE);     // LH thumb key 1
            // rgb_matrix_set_color(16, RGB_DARK_MAGENTA); // LH thumb key 2
            rgb_matrix_set_color(17, RGB_LIGHT_GREEN);     // LH thumb key 3

            // rgb_matrix_set_color(18, RGB_DARK_BLUE);   // RH thumb key 1
            rgb_matrix_set_color(19, RGB_LIGHT_MAGENTA);  // RH thumb key 2
            rgb_matrix_set_color(20, RGB_LIGHT_BLUE);     // RH thumb key 3

            light_up_left_mods(RGB_OFF, RGB_LIGHT_WHITE);
            light_up_right_mods(RGB_OFF, RGB_LIGHT_WHITE);
            break;

        case _NAV:
            // Mods on the left hand side
            light_up_left_mods(RGB_DARK_WHITE, RGB_LIGHT_WHITE);

            // Color the arrow keys
            rgb_matrix_set_color(33, RGB_DARK_MAGENTA);     // Up
            rgb_matrix_set_color(29, RGB_DARK_MAGENTA);     // Left
            rgb_matrix_set_color(28, RGB_DARK_MAGENTA);     // Down
            rgb_matrix_set_color(27, RGB_DARK_MAGENTA);     // Right

            rgb_matrix_set_color(34, RGB_DARK_WHITE);       // ESC
            break;
    }
    return false;
}

// This is a callback for OSM(mod). It is called whenever the state of any one shot modifier key is changed:
// when it toggles on, but also when it is toggled off.
// thet: This function is not called reliable when the oneshot mods are changed. We can only use it to
// reset the OSM state when the mods are cleared.
void oneshot_mods_changed_user(uint8_t mods) {
    if (mods == 0) {
        reset_all_osm();
    }
}

// This function is called by QMK during key processing before the actual key event is handled. If this
// functions return true QMK will process the keycodes as usual.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case OS_RSFT:
                active_right_shift_osm = true;
                break;
            case OS_LSFT:
                active_left_shift_osm = true;
                break;
            case OS_RCTL:
                active_right_ctrl_osm = true;
                break;
            case OS_LCTL:
                active_left_ctrl_osm = true;
                break;
            case OS_RALT:
                active_right_alt_osm = true;
                break;
            case OS_LALT:
                active_left_alt_osm = true;
                break;
            case OS_RGUI:
                active_right_gui_osm = true;
                break;
            case OS_LGUI:
                active_left_gui_osm = true;
                break;
            default:
                if (keycode != LT_NAV_SPACE &&
                    keycode != MO_NAV /* &&
                    keycode != MO_SYMB &&
                    keycode != MO_NUM &&
                    keycode != MO_FUN*/) {
                    // Reset the OSM state when any other key is pressed.
                    reset_all_osm();
                }
                break;
        }
    }
    return true;
}
#pragma endregion
