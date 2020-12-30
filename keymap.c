#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_portuguese_osx_iso.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  ST_MACRO_0,
  PT_LSPO,
  PT_RSPC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,                                        KC_RIGHT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           PT_QUOT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TG(1),                                          TG(1),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_DELETE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_HYPR,                                                                        KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           LT(2,PT_CCED),  LGUI_T(PT_TILD),
    PT_LSPO,        LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(PT_MINS),PT_RSPC,
    LT(1,PT_LABK),  ST_MACRO_0,     LGUI(KC_LALT),  KC_LEFT,        KC_RIGHT,       PT_SLSH,                                                                                                        LCTL_T(KC_ESCAPE),KC_UP,          KC_DOWN,        PT_PLUS,        PT_ACUT,        MO(1),
    KC_SPACE,       KC_BSPACE,      KC_LGUI,                        KC_LALT,        KC_TAB,         KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    PT_ASTR,        KC_EXLM,        PT_AT,          PT_LCBR,        PT_RCBR,        PT_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    PT_BSLS,        KC_HASH,        KC_DLR,         PT_LPRN,        PT_RPRN,        PT_GRV,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_TRANSPARENT, KC_PGUP,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        PT_CIRC,        PT_LBRC,        PT_RBRC,        PT_TILD,                                        KC_TRANSPARENT, KC_END,         KC_UP,          KC_PGDOWN,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_COMMA,       PT_DOT,         PT_EQL,         PT_AMPR,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,    RESET,
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     RGB_MOD,                                                                                                        RGB_TOG,        KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160} },

    [2] = { {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(SS_TAP(X_GRAVE)));
    }
    break;
    case PT_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case PT_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}
