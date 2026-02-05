#include <onx/onx.h>

/* #region Core # */
/* ############## */
onx_status_t onx_init() {
    return ONX_STATUS_SUCCESS;
}
onx_status_t onx_exit() {
    return ONX_STATUS_SUCCESS;
}
/* #endregion   # */
/* ############## */

/* #region Handler# */
/* ################ */

// Find Current Index
/*
static inline u32 findci(onx_hid16_t hid) {
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
static inline u16 findii(onx_hid16_t hid) {
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

onx_status_t onx_register_handler(onx_handler_t *hnd) {
    return ONX_STATUS_SUCCESS;
}

onx_status_t onx_check_dependencies(onx_handler_t *hnd) {

}
onx_status_t onx_check_dependents(onx_handler_t *hnd) {

}

onx_status_t onx_handler_initialize(onx_hid16_t hid, onx_headcrt_t *creator) {
    
}
onx_status_t onx_handler_terminate(onx_hid16_t hid) {

}
onx_headhnd_t *onx_handler_get(onx_hid16_t hid, onx_headgtr_t *getter) {

}
/* #endregion     # */
/* ################ */