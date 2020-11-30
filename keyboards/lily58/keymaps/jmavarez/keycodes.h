#pragma once

// Unicode

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Tap Dance declarations
enum {
    TD_MENU_ADJS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Menu, twice to toggle adjust layer
    [TD_MENU_ADJS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_APP, _ADJUST),
};
