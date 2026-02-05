#ifndef __ONX_TYPE_H__
#define __ONX_TYPE_H__

#include "onx_id.h"
#include "onx_num.h"

typedef u32 onx_status_t;
enum {
    ONX_STATUS_SUCCESS = (ONX_ID32_GEN | 0),
    ONX_STATUS_FAILED  = (ONX_ID32_GEN | 1),
    ONX_STATUS_TOKEN_INVALID    = (ONX_ID32_TKN | 0),
    ONX_STATUS_HANDLER_INVALID_ID           = (ONX_ID32_HND | 0),
    ONX_STATUS_HANDLER_INVALID_CREATOR      = (ONX_ID32_HND | 1),
    ONX_STATUS_HANDLER_INVALID_DEPENDENCIES = (ONX_ID32_HND | 2),
    ONX_STATUS_HANDLER_INVALID_DEPENDENTS   = (ONX_ID32_HND | 3),
};

typedef u32 onx_crttype_t;
#define ONX_CRTTYPE_LOGGER          (ONX_HID32_LOGGER | 0)
#define ONX_CRTTYPE_VULKAN_INSTANCE (ONX_HID32_VULKAN_INSTANCE | 0)
typedef u32 onx_crtflags_t;
#define ONX_CRTFLAG_DEFAULT_CREATOR (1)

typedef u32 onx_gtrtype_t;
#define ONX_GTRTYPE_LOGGER          (ONX_HID32_LOGGER | 0)
#define ONX_GTRTYPE_VULKAN_INSTANCE (ONX_HID32_VULKAN_INSTANCE | 0)
typedef u32 onx_gtrflags_t;
#define ONX_GTRFLAG_DIRECT_INSTANCE (1)

typedef struct onx_headcrt {
    onx_crttype_t  type;
    onx_crtflags_t flags;
} onx_headcrt_t;
typedef struct onx_headgtr {
    onx_gtrtype_t  type;
    onx_gtrflags_t flags;
} onx_headgtr_t;
typedef struct onx_headhnd {

} onx_headhnd_t;

typedef u64 onx_token_t;

typedef struct onx_actor {
    onx_token_t tkn;
} onx_actor_t;

typedef struct onx_handler {
    // Handler function pointers.
    onx_status_t (*fInitialize)(onx_headcrt_t *);
    onx_status_t (*fTerminate)();

    onx_headhnd_t *(*fGet)(onx_headgtr_t *);

    const char *pName;          // Name of handler.
    const onx_hid16_t *pDeps;   // Dependencies of handler.
    const onx_hid16_t depCount; // Count of dependencies.
    const onx_hid16_t len;      // Size of handler's struct.
    const onx_hid16_t id;       // Id of handler.
} onx_handler_t;

#endif /* __ONX_TYPE_H__ */