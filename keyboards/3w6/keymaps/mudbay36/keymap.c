/* Copyright 2021 weteor
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers
{
    _ALPHA = 0,
    _NAV,
    _NUM,
	_FUN,
	_SYM
};

// TAPDANCE
 enum tapdances
 {
 	TD_ALTF4 = 0,
	TD_SFT_F11
};

 qk_tap_dance_action_t tap_dance_actions[] = {
 	[TD_ALTF4] 		= ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)),
 	[TD_SFT_F11] 	= ACTION_TAP_DANCE_DOUBLE(KC_F11, LSFT(KC_F11))
};

// COMBO
const uint16_t PROGMEM lbrc_combo[] = {KC_R, LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM grv_combo[]  = {LCTL_T(KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_U, RCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM quot_combo[] = {RCTL_T(KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_D), RSFT_T(KC_K), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(lbrc_combo, KC_LBRC),
	COMBO(grv_combo,  KC_GRV),
	COMBO(rbrc_combo, KC_RBRC),
	COMBO(quot_combo, KC_QUOT),
	COMBO(caps_combo, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT(
    KC_Q,           KC_W,           KC_E,           KC_R,           	KC_T,				/*|*/	KC_Y,   			KC_U,	        	KC_I,           KC_O,           KC_P,
    LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   	KC_G,    			/*|*/   KC_H,       		RCTL_T(KC_J),   	RSFT_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),
    KC_Z,           KC_X,           KC_C,           KC_V,           	KC_B,				/*|*/   KC_N,	    		KC_M,	        	KC_COMM,        KC_DOT,         KC_SLSH,
                                    LALT(KC_LSFT),	LT(_NAV, KC_SPC),  	LT(_SYM, KC_BSPC),	/*|*/	LT(_FUN, KC_DEL),	LT(_NUM, KC_ENT),	LALT(KC_LSFT)
	),
	[_NAV] = LAYOUT(
	TD(TD_ALTF4),   KC_PGUP,        KC_UP,          KC_HOME,        	KC_LBRC,			/*|*/	KC_RBRC,    		KC_TRNS,        	KC_TRNS,        KC_MINS,        KC_BSLS,
	KC_TAB,         KC_LEFT,        KC_DOWN,        KC_RGHT,        	KC_GRV,     		/*|*/   KC_EQL,     		KC_RCTL,        	KC_RSFT,        KC_RALT,        KC_RGUI,
	LALT(KC_LSFT),  KC_PGDN,        KC_TRNS,        KC_END,        		KC_LPRN,    		/*|*/   KC_RPRN,    		KC_TRNS,         	KC_TRNS,        KC_TRNS,        KC_QUOT,
	                                KC_TRNS,        KC_TRNS,        	KC_TRNS,    		/*|*/   KC_TRNS,    		KC_TRNS,        	KC_TRNS
		),
	[_NUM] = LAYOUT(
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        	KC_TRNS,   			/*|*/   KC_TRNS,   			KC_7,          		KC_8,          	KC_9,          KC_TRNS,
	KC_LGUI,        KC_LALT,        KC_LSFT,        KC_LCTL,        	KC_TRNS,    		/*|*/   KC_TRNS,    		KC_4,          		KC_5,          	KC_6,          KC_PDOT,
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        	KC_TRNS,    		/*|*/   KC_TRNS,    		KC_1,          		KC_2,          	KC_3,          KC_0,
	                                KC_TRNS,        KC_TRNS,        	KC_TRNS,    		/*|*/   KC_TRNS,			KC_TRNS,        	KC_TRNS
		),
	[_FUN] = LAYOUT(
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        	KC_TRNS,    		/*|*/   KC_TRNS,    		KC_F7,       		KC_F8,         	KC_F9,       	KC_F12,
	KC_LGUI,        KC_LALT,        KC_LSFT,        KC_LCTL,        	KC_VOLU,    		/*|*/   KC_TRNS,    		KC_F4,       		KC_F5,          KC_F6,       	TD(TD_SFT_F11),
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        	KC_VOLD,    		/*|*/   KC_TRNS,    		KC_F1,         		KC_F2,          KC_F3,       	KC_F10,
	                                KC_TRNS,        KC_TRNS,        	KC_MPLY,    		/*|*/   KC_TRNS,    		KC_TRNS,       		KC_TRNS
		),
	[_SYM] = LAYOUT(
	KC_QUES,        KC_AMPR,        KC_ASTR,        KC_PIPE,        	KC_LBRC,    		/*|*/   KC_RBRC,    		KC_TRNS,       		KC_TRNS,        KC_TRNS,       KC_TRNS,
	KC_DQUO,        KC_DLR,        	KC_PERC,        KC_CIRC,        	KC_GRV,    			/*|*/   KC_EQL,    			KC_RCTL,        	KC_RSFT,        KC_RALT,       KC_RGUI,
	KC_UNDS,        KC_EXLM,        KC_AT,        	KC_HASH,        	KC_LPRN,    		/*|*/   KC_RPRN,    		KC_TRNS,       		KC_TRNS,        KC_TRNS,       KC_TRNS,
	                                KC_TRNS,        KC_TRNS,        	KC_TRNS,    		/*|*/   KC_TRNS,    		KC_TRNS,       		KC_TRNS
		)
	// [_FN] = LAYOUT(
	// KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    /*|*/   KC_TRNS,    KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,
	// KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    /*|*/   KC_TRNS,    KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,
	// KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    /*|*/   KC_TRNS,    KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,
	//                                 KC_TRNS,        KC_TRNS,        KC_TRNS,    /*|*/   KC_TRNS,    KC_TRNS,       KC_TRNS
	// 	)
};