#include QMK_KEYBOARD_H

#define _LEFT 0
#define _RIGHT 1
#define _NUM 2
#define _ARROWS 3
#define _FUNCTION 4
#define _BL 5

enum custom_keycodes {
  LEFT = SAFE_RANGE,
  RIGHT,
  NUM,
  ARROWS,
  FUNCTION,
  BL
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.
 * | tab  |   q  |   w  |   e  |   r  |   t  |
 * |------+------+------+------+------+------|
 * | rtrn |   a  |   s  |   d  |   f  |  g   |---,
 * |------+------+------+------+------+------|USB|
 * | shft |   z  |   x  |   c  |   v  |  v   |---'
 * |------+------+------+------+------+------|
 * | mode |  ctl | alt  |   +  |     sp      |
 * `-----------------------------------------'
 */
[_LEFT] = LAYOUT( \
  KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T, \
  KC_KP_ENTER, KC_A,     KC_S,    KC_D,    KC_F,    KC_G, \
  OSM(MOD_LSFT),KC_Z,     KC_X,    KC_C,    KC_V,    KC_B, \
  TO(_NUM),     KC_LCTRL, KC_LALT, LGUI_T(KC_SPACE),  LT(_RIGHT, KC_SPACE) ,LT(_RIGHT, KC_SPACE) \
),
/* Qwerty
 * ,-----------------------------------------.
 * | bs   |   p  |   o  |   i  |   u  |  y   |
 * |------+------+------+------+------+------|
 * |  '   |   ;  |   l  |   k  |   j  |  h   |---,
 * |------+------+------+------+------+------|USB|
 * | shft |   /  |   .  |   ,  |   m  |  n   |---'
 * |------+------+------+------+------+------|
 * | mode |  ctl | alt  |   +  |     sp      |
 * `-----------------------------------------'
 */
[_RIGHT] = LAYOUT( \
  KC_BSPACE, KC_P,     KC_O,    KC_I,    KC_U,    KC_Y, \
  KC_QUOTE, KC_SCOLON,     KC_L,    KC_K,    KC_J,    KC_H, \
  KC_RSHIFT, KC_SLASH,     KC_DOT,    KC_COMMA,    KC_M,    KC_N, \
  TO(_NUM),  _______,  _______, MO(_BL),  _______ , _______\
),
/* Numbers
 * ,-----------------------------------------.
 * | tab  |   -  |   9  |   8  |   7  |  *   |
 * |------+------+------+------+------+------|
 * | entr |   +  |   6  |   5  |   4  |  .   |---,
 * |------+------+------+------+------+------|USB|
 *        |   /  |   3  |   2  |   1  |  0   |---'
 * |------+------+------+------+------+------|
 * | mode |  ctl | alt  |   +  |     sp      |
 * `-----------------------------------------'
 */
[_NUM] = LAYOUT( \
  _______, KC_KP_MINUS, KC_KP_9, KC_KP_8, KC_KP_7, KC_KP_ASTERISK, \
  _______, KC_KP_PLUS,  KC_KP_6, KC_KP_5, KC_KP_4, KC_KP_DOT, \
  _______, KC_KP_SLASH, KC_KP_3, KC_KP_2, KC_KP_1, KC_KP_0, \
  TO(_ARROWS),     MO(_BL),  MO(_BL), _______,  LT(_RIGHT, KC_SPACE) ,LT(_RIGHT, KC_SPACE) \
),
/* Arrows
 * ,-----------------------------------------.
 * | tab  |      |      |   ^  |      |      |
 * |------+------+------+------+------+------|
 * |  '   |      |   <  |   v  |   >  |      |---,
 * |------+------+------+------+------+------|USB|
 * | shft |      |      |      |      |      |---'
 * |------+------+------+------+------+------|
 * | mode |  ctl | alt  |   +  |     sp      |
 * `-----------------------------------------'
 */
[_ARROWS] = LAYOUT( \
  KC_TAB,      _______,  KC_UP, _______,   _______, _______, \
  KC_KP_ENTER,  KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, \
  KC_RSHIFT,   _______,  _______, _______, _______,  _______, \
  TO(_FUNCTION),     MO(_BL),  MO(_BL), MO(_BL),  LT(_RIGHT, KC_SPACE) ,LT(_RIGHT, KC_SPACE) \
),
/* Function
 * ,-----------------------------------------.
 * | tab  |  f1  |  f2  |  f3  |  f4  | f13  |
 * |------+------+------+------+------+------|
 * | entr |  f5  |  f6  |  f7  |  f8  | f14  |---,
 * |------+------+------+------+------+------|USB|
 * | shft |  f9  | f10  | f11  | f12  | f15  |---'
 * |------+------+------+------+------+------|
 * | mode |  ctl | alt  |   +  |     sp      |
 * `-----------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  KC_TAB,      KC_F1,  KC_F2, KC_F3, KC_F4, KC_F13, \
  KC_KP_ENTER, KC_F5,  KC_F6, KC_F7, KC_F8, KC_F14, \
  KC_RSHIFT,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_F15, \
  TO(_LEFT),     MO(_BL),  MO(_BL), MO(_BL),  LT(_RIGHT, KC_SPACE) ,LT(_RIGHT, KC_SPACE) \
),
/* Qwerty
 * ,---------------------------------------------.
 * | BL_BRTG |        |         |        |   |   |
 * |---------+--------+---------+--------+---+---|
 * |         | BL_OFF | BL_TOGG | BL_ON  |   |   |---,
 * |---------+--------+---------+--------+---+---|USB|
 * |         |        |         |        |   |   |---'
 * |---------+--------+---------+--------+---+---|
 * | BL_DEC  | BL_DEC | BL_INC  | BL_INC |       |
 * `---------------------------------------------'
 */
[_BL] = LAYOUT( \
  BL_BRTG, _______, _______, _______, _______, _______, \
  _______, BL_OFF,  BL_TOGG, BL_ON,   _______, _______, \
  KC_CAPSLOCK, _______, KC_NUMLOCK, _______, _______, _______, \
  BL_DEC,  BL_DEC,  BL_INC,  MO(_BL),  _______ , _______ \
)
};
#ifdef SWAP_HANDS_ENABLE
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  { {3, 0}, {2, 0}, {1, 0}, {0, 0} },
  { {3, 1}, {2, 1}, {1, 1}, {0, 1} },
  { {3, 2}, {2, 2}, {1, 2}, {0, 2} },
  { {3, 3}, {2, 3}, {1, 3}, {0, 3} },
  { {3, 4}, {2, 4}, {1, 4}, {0, 4} },
  { {3, 5}, {2, 5}, {1, 5}, {0, 5} },
};
#endif
