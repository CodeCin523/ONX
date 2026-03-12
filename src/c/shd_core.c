#include <shemodogan/mem/shd_block.h>
#include <shemodogan/mem/shd_mem.h>
#include <shemodogan/shd_core.h>

#include <stdlib.h>


struct shd_dataact {
    shd_sbblock_t       instdt_alloc;
    shd_actor_meta_t   *meta;
};
struct shd_datahnd {
    shd_handler_meta_t *meta;
    shd_basehnd_t      *instdt;
    shd_hndid_t         id;
};


static struct shd_dataact *dataact;         // all registered actors
static u32 dataact_count = 0, dataact_size = 0;
static struct shd_datahnd *datahnd;         // all registered handler
static u32 datahnd_count = 0, datahnd_size = 0;

static shd_sbblock_t actpool_alloc = {0};   // main allocator for all instdt_alloc of the actors.


/* ================================================================================ */
/*  CORE                                                                            */
/* ================================================================================ */

// Library Life-Cycle and Registers
shd_result_t shd_init_st(void) {
    // Actor & Handler arrays
    dataact = calloc(SHD_KB(2), sizeof(struct shd_dataact));
    if(!dataact) return SHD_RESULT_FAILED_EXTERNAL_ALLOC;

    dataact_size = SHD_KB(2);
    dataact_count = 0;

    datahnd = calloc(256, sizeof(struct shd_datahnd));
    if(!datahnd) return SHD_RESULT_FAILED_EXTERNAL_ALLOC;

    datahnd_size = 256;
    datahnd_count = 0;

    // Block & Stack allocs
    void *pool = malloc(SHD_MB(1));
    if(!pool) return SHD_RESULT_FAILED_EXTERNAL_ALLOC;
    shd_setup_sbblock_st(&actpool_alloc, pool, SHD_MB(1), SHD_KB(1));

    return SHD_RESULT_OK;
}
shd_result_t shd_term_st(void) {
    // Should check current status of handlers and actors

    if(actpool_alloc.pool) {
        free(actpool_alloc.pool);
        shd_teardown_sbblock_st(&actpool_alloc);
    }
    if(datahnd) {
        free(datahnd);
        datahnd = 0;
        datahnd_size = 0;
        datahnd_count = 0;
    }
    if(dataact) {
        free(dataact);
        dataact = 0;
        dataact_size = 0;
        dataact_count = 0;
    }

    return SHD_RESULT_OK;
}

shd_result_t shd_register_actor_st(shd_actid_t actid, shd_actor_meta_t *meta) {

}
shd_result_t shd_register_handler_st(shd_hndid_t hndid, shd_handler_meta_t *meta) {

}

// Handler Life-Cycle
static shd_result_t shd_handler_check_dependencies_st(
    shd_hndid_t hndid, shd_handler_meta_t *meta
) {
    
}
static shd_result_t shd_handler_check_dependents_st(
    shd_hndid_t hndid, shd_handler_meta_t *meta
) {

}

shd_result_t shd_handler_init_st(shd_hndid_t hndid, shd_basecrt_t *creator) {

}
shd_result_t shd_handler_term_st(shd_hndid_t hndid) {

}

shd_result_t shd_handler_get_mt(shd_hndid_t hndid, shd_basehnd_t *out_handler) {

}

// Actor Life-Cycle
shd_result_t shd_actor_subscribe_mt(shd_actid_t actid, shd_basecrt_t *creator, shd_baseact_t **out_actor) {

}
shd_result_t shd_actor_release_mt(shd_actid_t actid, shd_baseact_t *actor) {

}