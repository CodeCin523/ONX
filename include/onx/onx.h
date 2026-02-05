/* ONX Naming Rules - Simplified
 * ├─ CMake modules
 * |  ├─ onxl => ONX Library (main target)
 * |  ├─ onxt => ONX Tests
 * |  └─ onxe => ONX Examples
 * ├─ Module abbreviations (optional, when useful)
 * |  ├─ gen  => general
 * |  ├─ tkn  => token
 * |  ├─ evt  => event
 * |  ├─ act  => actor
 * |  └─ hnd  => handler
 * ├─ Other abbreviations
 * |  ├─ crt => creator
 * |  ├─ gtr => getter
 * |
 * ├─ Case
 * |  ├─ snake_case           => functions, types, variables
 * |  └─ SCREAMING_SNAKE_CASE => only constants, macros, enum values
 * ├─ Prefix
 * |  ├─ onx_  => functions, types (struct, enum, typedef), variables
 * |  └─ ONX_  => constants, macros, enum values
 * |
 * ├─ Function
 * |  └─ onx_do_something()
 * ├─ Type (struct / enum / typedef)
 * |  └─ onx_something_t
 */

#ifndef __ONX_H__
#define __ONX_H__

#include "onx_type.h"

onx_status_t onx_init();
onx_status_t onx_exit();

onx_status_t onx_register_handler(onx_handler_t *hnd);

onx_status_t onx_check_dependencies(onx_handler_t *hnd);
onx_status_t onx_check_dependents(onx_handler_t *hnd);

onx_status_t onx_handler_initialize(onx_hid16_t hid, onx_headcrt_t *creator);
onx_status_t onx_handler_terminate(onx_hid16_t hid);
onx_headhnd_t *onx_handler_get(onx_hid16_t hid, onx_headgtr_t *getter);

#endif /* __ONX_H__ */