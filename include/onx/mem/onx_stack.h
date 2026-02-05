#ifndef __ONX_STACK_H__
#define __ONX_STACK_H__

#include "../onx_num.h"

struct onx_stkspace {
    // Could be change to two 32 bits, and the flag is the most-important-bit of lcount. We would go from 0.5MB max to 16GB max.
    u32 flags;  // if flags is 1 and is foot, remove before.
    u16 lcount; // last count
    u16 ncount; // next count
};

typedef struct onx_vstack {
    u64 *pool;
    struct onx_stkspace *last;
    u32 count;
} onx_vstack_t;

static inline u64 *onx_vstack_push(onx_vstack_t *vstack, u32 size) {
    if(vstack == nullptr)
        return nullptr;

    // The len logics works, but if size is a multiple of u64, it gives 8 bytes (64bits) bonus.
    u32 len = (size / sizeof(u64)) + 2;
    u32 used = (u64 *)vstack->last - vstack->pool;
    if(len >= vstack->count - used)
        return nullptr;

    struct onx_stkspace *head = vstack->last;
    struct onx_stkspace *foot = vstack->last + len;

    head->ncount = len;
    head->flags = 0;
    foot->lcount = len;
    foot->ncount = 0;
    foot->flags = 0;
    vstack->last = foot;

    return (u64*)head + 1;
}
static inline void onx_vstack_pop(onx_vstack_t *vstack, u64 *addr) {
    if(vstack == nullptr)
        return;
    if(vstack->pool == (u64 *)vstack->last /*vstack->last->lcount == 0*/)
        return;
    
    struct onx_stkspace *head = vstack->last - vstack->last->lcount;
    if(addr != nullptr) { // Should also check to see if addr is out of bound.
        head = (struct onx_stkspace *) (addr - 1);
    }
    struct onx_stkspace *foot = head + head->ncount;

    if(addr != nullptr && foot != vstack->last) {
        foot->flags = 1;
    } else {
        // Really only there for sanity, since they will get overwritten if pushed on.
        // foot->lcount = 0;
        // foot->flags = 0;
        // head->ncount = 0;
        vstack->last = head;
        if(head->flags == 1)
            onx_vstack_pop(vstack, nullptr);
    }
}
static inline void onx_vstack_clear(onx_vstack_t *vstack) {
    vstack->last = (struct onx_stkspace *) vstack->pool;
    vstack->last->flags = 0;
    vstack->last->lcount = 0;
    vstack->last->ncount = 0;
}

#endif /* __ONX_STACK_H__ */