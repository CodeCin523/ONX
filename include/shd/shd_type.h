#ifndef __SHD_TYPE_H__
#define __SHD_TYPE_H__

#include "shd_id.h"
#include "shd_num.h"

typedef u32 shd_status_t;
enum {  // NEED TO FIND CORRECT VALUES FOR THOSE
    SHD_STATUS_SUCCESS                      = 0,
    SHD_STATUS_FAILED                       = 1,
    SHD_STATUS_FAILED_INTERN_ALLOC          = 2,
    SHD_STATUS_FAILED_EXTERN_ALLOC          = 3,
    SHD_STATUS_HANDLER_ID_EXISTS            = 4,
    SHD_STATUS_HANDLER_ID_NOT_FOUND         = 5,
    SHD_STATUS_HANDLER_INVALID_STATE        = 6,
    SHD_STATUS_HANDLER_MISSING_DEPENDENCIES = 7,
    SHD_STATUS_HANDLER_EXISTENT_DEPENDENTS  = 8,
    SHD_STATUS_HANDLER_INITIALIZED          = 100,
    SHD_STATUS_HANDLER_TERMINATED           = 101,
    SHD_STATUS_HANDLER_INVALID_CREATOR      = -1,
    SHD_STATUS_HANDLER_INVALID_DEPENDENCIES = -1,
    SHD_STATUS_HANDLER_INVALID_DEPENDENTS   = -1,
};

typedef u32 shd_crttype_t;
#define SHD_CRTTYPE_LOGGER          (SHD_HID32_LOGGER | 0)
#define SHD_CRTTYPE_VULKAN_INSTANCE (SHD_HID32_VULKAN_INSTANCE | 0)
typedef u32 shd_crtflags_t;
#define SHD_CRTFLAG_DEFAULT_CREATOR (1)

typedef u32 shd_gtrtype_t;
#define SHD_GTRTYPE_LOGGER          (SHD_HID32_LOGGER | 0)
#define SHD_GTRTYPE_VULKAN_INSTANCE (SHD_HID32_VULKAN_INSTANCE | 0)
typedef u32 shd_gtrflags_t;
#define SHD_GTRFLAG_DIRECT_INSTANCE (1)

typedef struct shd_headcrt {
    shd_crttype_t  type;
    shd_crtflags_t flags;
} shd_headcrt_t;
typedef struct shd_headgtr {
    shd_gtrtype_t  type;
    shd_gtrflags_t flags;
} shd_headgtr_t;
typedef struct shd_headhnd {

} shd_headhnd_t;

typedef u64 shd_token_t;

typedef struct shd_actor {
    shd_token_t tkn;
} shd_actor_t;

typedef struct shd_handler {
    // Handler function pointers.
    shd_status_t (*fInitialize)(shd_headcrt_t *);
    shd_status_t (*fTerminate)();

    shd_headhnd_t *(*fGet)(shd_headgtr_t *);

    const char *pName;          // Name of handler.
    const shd_hid16_t *pDeps;   // Dependencies of handler.
    const u16 depCount;         // Count of dependencies.
    const u16 datalen;          // Size of handler's struct.
} shd_handler_t;

#endif /* __SHD_TYPE_H__ */