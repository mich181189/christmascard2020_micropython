/*
 * WS2812 control
 * Micropython Interface
*/

#include "mod_ws2812.h"
#include "ws2812.h"

#include "py/mphal.h"
#include "py/runtime.h"
#include "py/mperrno.h"

// only currently developed/tested on F401
#if defined(STM32F4)

STATIC mp_obj_t mp_ws2812_init(const mp_obj_t count) {
	if(!mp_obj_is_small_int(count)) {
		mp_raise_TypeError(MP_ERROR_TEXT("Argument must be an integer"));
		return mp_const_none; 
	}

	ws2812_init(mp_obj_get_int(count));

	// start displaying stuff
	ws2812_display();

	return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(ws2812_init_obj, mp_ws2812_init);

STATIC mp_obj_t mp_ws2812_setLed(size_t n_args, const mp_obj_t *arg) {
	//all arguments should be integers
	for(size_t i = 0; i < n_args; ++i) {
		if(!mp_obj_is_small_int(arg[i])) {
			mp_raise_TypeError(MP_ERROR_TEXT("Argument must be an integer"));
			return mp_const_none; 
		}
	}

	ws2812_set_led(mp_obj_get_int(arg[0]),
		mp_obj_get_int(arg[1]), mp_obj_get_int(arg[2]), mp_obj_get_int(arg[3]));

	return mp_const_none;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(ws2812_setLed_obj, 4, 4, mp_ws2812_setLed);

STATIC const mp_rom_map_elem_t ws2812_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ws2812) },
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&ws2812_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_set_led), MP_ROM_PTR(&ws2812_setLed_obj) },
};
STATIC MP_DEFINE_CONST_DICT(ws2812_module_globals, ws2812_module_globals_table);

// Define module object.
const mp_obj_module_t ws2812_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&ws2812_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_ws2812, ws2812_module, MICROPY_ENABLE_WS2812);

#endif // defined(STM32F4)
