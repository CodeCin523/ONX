#include <shd/handler/shd_logger.h>
#include <shd/shd.h>

void shd_flush() {

}
void shd_log(const char *msg, u8 level) {

}
void shd_logh(const char *hnd_name, const char *msg, u8 level) {

}

static shd_status_t logger_init(shd_basecrt_t *_creator) {
    if(_creator == 0)
        return SHD_STATUS_HANDLER_MISSING_CREATOR;
    if(_creator->type != SHD_CRTTYPE_LOGGER)
        return SHD_STATUS_HANDLER_INVALID_CREATOR;
    
    shd_crt_logger_t creator = {
        {0, 0}, 8192
    };
    if((_creator->flags & SHD_CRTFLAG_DEFAULT_CREATOR) == 0) {
        shd_crt_logger_t *_crt = (shd_crt_logger_t *) _creator;
        creator = *_crt;
    }



    return SHD_STATUS_FAILED;
}
static shd_status_t logger_term() {
    return SHD_STATUS_FAILED;
}
static shd_basehnd_t *logger_get(shd_basegtr_t *_getter) {
    return 0;
}

shd_handler_meta_t shd_handler_logger_meta = {
    logger_init,
    logger_term,
    logger_get,
    "shd_hndlogger",
    0,
    0,
    sizeof(shd_hnd_logger_t)
};
