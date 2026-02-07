#include "shd/shd_type.h"
#include <shd/shd.h>

#include <shd/mem/shd_stack.h>

#include <stdlib.h>


shd_handler_t *g_handlers = 0;
u32 g_handlerCount = 0, g_handlerSize = 0;

shd_dfstack_t g_hndstatic_stack = {0};
shd_dfstack_t g_hndtemp_stack = {0};


/* #region Core # */
/* ############## */
shd_status_t shd_init() {
    // Handler array
    g_handlers = calloc(128, sizeof(shd_handler_t));
    if(!g_handlers)
        return SHD_STATUS_FAILED_EXTERN_ALLOC;

    g_handlerSize = 128;
    g_handlerCount = 0;
    
    // Stacks
    void *temp = calloc(1024 + 2, sizeof(u64));
    if(!temp)
        return SHD_STATUS_FAILED_EXTERN_ALLOC;
    
    shd_create_dfstack(&g_hndstatic_stack,
        temp, 4096);
    temp += 4096 + sizeof(u64);
    shd_create_dfstack(&g_hndtemp_stack,
        temp, 4096);

    return SHD_STATUS_SUCCESS;
}
shd_status_t shd_exit() {
    if(g_hndstatic_stack.pool) {
        free(g_hndstatic_stack.pool);
        shd_destroy_dfstack(&g_hndstatic_stack);
        shd_destroy_dfstack(&g_hndtemp_stack);
    }
    if(g_handlers) {
        free(g_handlers);
        g_handlers = 0;
        g_handlerSize = 0;
        g_handlerCount = 0;
    }

    return SHD_STATUS_SUCCESS;
}
/* #endregion   # */
/* ############## */

/* #region Handler# */
/* ################ */

// Find Current Index
/*
static inline u32 findci(shd_hid16_t hid) {
    u32 low = 0, high = itemCount, mid;

    while(low < high) {
        mid = low + (high - low) / 2;
        if(items[mid].id == hid)
            return mid;
        if(items[mid].id < hid)
            low = mid + 1;
        else
            high = mid;
    }

    return u32_MAX;
}
// Find Insert Index
static inline u16 findii(shd_hid16_t hid) {
    u32 low = 0, high = itemCount, mid;

    while(low < high) {
        mid = low + (high - low) / 2;
        // if(items[mid].id == hid)
        //     return mid;
        if(items[mid].id < hid)
            low = mid + 1;
        else
            high = mid;
    }
    return low;

}*/

shd_status_t shd_register_handler(shd_handler_t *hnd) {
    return SHD_STATUS_FAILED;
}

shd_status_t shd_check_dependencies(shd_handler_t *hnd) {
    return SHD_STATUS_FAILED;
}
shd_status_t shd_check_dependents(shd_handler_t *hnd) {
    return SHD_STATUS_FAILED;
}

shd_status_t shd_handler_initialize(shd_hid16_t hid, shd_headcrt_t *creator) {
    return SHD_STATUS_FAILED;
}
shd_status_t shd_handler_terminate(shd_hid16_t hid) {
    return SHD_STATUS_FAILED;
}
shd_headhnd_t *shd_handler_get(shd_hid16_t hid, shd_headgtr_t *getter) {

}
/* #endregion     # */
/* ################ */