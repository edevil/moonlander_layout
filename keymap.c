#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  PT_LSPO,
  PT_RSPC,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TD(DANCE_0),                                    TD(DANCE_1),    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           PT_QUOT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           PT_LBRC,                                        PT_LCBR,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           PT_BSLS,
    KC_DELETE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           PT_RBRC,                                                                        PT_RCBR,        KC_H,           KC_J,           KC_K,           KC_L,           PT_ACUT,        PT_TILD,
    PT_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           PT_COMM,        PT_DOT,         KC_UP,          PT_RSPC,
    LT(1,PT_LABK),  ST_MACRO_0,     LGUI(KC_LALT),  PT_AMPR,        LCTL_T(KC_KP_ASTERISK),ST_MACRO_1,                                                                                                     RALT_T(KC_KP_SLASH),RCTL_T(PT_MINS),RALT_T(PT_PLUS),KC_LEFT,        KC_DOWN,        KC_RIGHT,
    KC_SPACE,       KC_BSPC,      KC_LGUI,                        MO(1),          MO(2),          KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PT_EURO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PT_MORD,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PT_CCED,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_HOME,        KC_END,         ST_MACRO_2,     KC_PGDN,      ST_MACRO_3,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    AU_TOGG,         KC_TRANSPARENT, KC_TRANSPARENT, TO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,    RESET,
    MU_TOGG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MU_NEXT,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     RGB_MODE_FORWARD,                                                                                                        RGB_TOG,        KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        KC_TRANSPARENT, RGB_HUI
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_BSPC,                                                                                                      TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_ALT,                    KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160}, {0,197,160} },

    [2] = { {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151}, {85,133,151} },

    [3] = { {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,0,255}, {0,251,241}, {0,251,241}, {0,251,241}, {0,0,255}, {0,0,255}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,0,255}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241}, {0,251,241} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
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

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_NUBS)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_RALT(SS_TAP(X_V))));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_E)));

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
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];


uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_A));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PAGE_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_A)); register_code16(LCTL(KC_A));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PAGE_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_E));
        tap_code16(LCTL(KC_E));
        tap_code16(LCTL(KC_E));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_E));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_E)); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_E)); register_code16(LCTL(KC_E));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_E)); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_E)); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
