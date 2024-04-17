#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
    _IEON,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const key_override_t period_ko = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_AT);
const key_override_t ampersand_ko = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PIPE);
const key_override_t comma_ko = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t equal_ko = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, LSFT(KC_EQL));
const key_override_t quote_ko = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_DQUO);
const key_override_t semicolon_ko = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_COLN);

const key_override_t **key_overrides = (const key_override_t *[]){
	&period_ko,
	&ampersand_ko,
	&comma_ko,
	&equal_ko,
	&quote_ko,
	&semicolon_ko,
	NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_IEON] = LAYOUT_planck_grid(
            QK_GESC, KC_DOT,  KC_Y,    KC_A,    KC_AMPR,    _______,  KC_Q,  KC_F,       KC_L,    KC_G,    KC_K,  KC_J   ,
		    KC_BSPC, KC_I,    KC_E,    KC_O,    KC_N,       KC_COMM, KC_B,   KC_H,       KC_T,    KC_S,    KC_C,  KC_D   ,
			KC_LCTL, KC_UNDS, KC_MINS, KC_QUOT, KC_U,       KC_SCLN, KC_R,   KC_X,       KC_W,    KC_M,    KC_P,  KC_LSFT,
			KC_TAB,  LALT(KC_SYRQ), KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,  KC_ENT, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
                KC_GRV,  KC_BSLS, KC_PERC, KC_SLSH, _______, _______, _______, _______, KC_V,    KC_Z,    _______, _______,
		        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

    [_RAISE] = LAYOUT_planck_grid(
                  KC_DLR, _______, KC_LCBR, KC_LPRN, KC_LABK, _______, _______, KC_RABK, KC_RPRN, KC_RCBR, _______, _______,
		          KC_HASH, KC_7, KC_5, KC_3, KC_1, KC_9, KC_0, KC_2, KC_4, KC_6, KC_8, KC_PAST,
				  _______, KC_EXLM, KC_EQL, KC_DQUO, KC_LBRC, _______, _______, KC_RBRC, _______, _______, _______, _______,
				  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_ADJUST] = LAYOUT_planck_grid(
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		        KC_F11, KC_F7, KC_F5, KC_F3, KC_F1, KC_F9, KC_F10, KC_F2, KC_F4, KC_F6, KC_F8, KC_F12,
				LCA(KC_F11), LCA(KC_F7), LCA(KC_F5), LCA(KC_F3), LCA(KC_F1), LCA(KC_F9), LCA(KC_F10), LCA(KC_F2), LCA(KC_F4), LCA(KC_F6), LCA(KC_F8), LCA(KC_F12),
				_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
