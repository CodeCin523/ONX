# shd_core.h

Core Shemodogan API for library life-cycle, handlers, actors, and creators.

Provides the main interface for initializing the library, registering handlers and actors, managing life-cycles, and subscribing or releasing actor instances.

⚠ **Low-level library core.** Misuse can break internal state or cause undefined behavior. Use higher-level wrappers or carefully follow API rules.

---

## Tables

### Types

| | | |
|---|---|---|
| [shd_result_t](#shd_result_t) | [shd_hndid_t](#shd_hndid_t) | [shd_actid_t](#shd_actid_t) |
| [shd_crttype_t](#shd_crttype_t) | [shd_crtflags_t](#shd_crtflags_t) | [shd_basecrt_t](#shd_basecrt_t) |
| [shd_baseact_t](#shd_baseact_t) | [shd_basehnd_t](#shd_basehnd_t) | [shd_actor_meta_t](#shd_actor_meta_t) |
| [shd_handler_meta_t](#shd_handler_meta_t) | | |

### Constants

| | | |
|---|---|---|
| [SHD_RESULT_OK](#shd_result_t) | [SHD_RESULT_FAILED](#shd_result_t) | [SHD_RESULT_FAILED_INTERNAL_ALLOC](#shd_result_t) |
| [SHD_RESULT_FAILED_EXTERNAL_ALLOC](#shd_result_t) | [SHD_PROVIDER_STD](#shd_provider_std) | [SHD_PROVIDER_EXT](#shd_provider_ext) |
| [SHD_HND_LOGGER_ID](#shd_hndid_t) | [SHD_HND_VLKCORE_ID](#shd_hndid_t) | [SHD_HND_VLKSWAPCHAIN_ID](#shd_hndid_t) |
| [SHD_HND_VLKSEQUENCER_ID](#shd_hndid_t) | [SHD_ACT_VLKDEVICE_ID](#shd_actid_t) | [SHD_CRTTYPE_LOGGER](#shd_crttype_t) |
| [SHD_CRTTYPE_VLKCORE](#shd_crttype_t) | [SHD_CRTTYPE_VLKSWAPCHAIN](#shd_crttype_t) | [SHD_CRTTYPE_VLKSEQUENCER](#shd_crttype_t) |
| [SHD_CRTFLAGS_DEFAULT_CREATOR](#shd_crtflags_t) | | |

### Macros / Functions

| | | |
|---|---|---|
| [shd_init_st](#shd_init_st) | [shd_term_st](#shd_term_st) | [shd_register_actor_st](#shd_register_actor_st) |
| [shd_register_handler_st](#shd_register_handler_st) | [shd_handler_init_st](#shd_handler_init_st) | [shd_handler_term_st](#shd_handler_term_st) |
| [shd_handler_get_mt](#shd_handler_get_mt) | [shd_actor_subscribe_mt](#shd_actor_subscribe_mt) | [shd_actor_release_mt](#shd_actor_release_mt) |
| [shd_init](#shd_init) | [shd_term](#shd_term) | [shd_register_actor](#shd_register_actor) |
| [shd_register_handler](#shd_register_handler) | [shd_handler_init](#shd_handler_init) | [shd_handler_term](#shd_handler_term) |
| [shd_handler_get](#shd_handler_get) | [shd_actor_subscribe](#shd_actor_subscribe) | [shd_actor_release](#shd_actor_release) |

---

## Reference

### shd_result_t

Function result type for Shemodogan APIs.  
Type: `u32`

#### SHD_RESULT_OK

Operation succeeded.  
Value: `0`

#### SHD_RESULT_FAILED

Generic failure.  
Value: `1`

#### SHD_RESULT_FAILED_INTERNAL_ALLOC

Internal allocation failure.  
Value: `2`

#### SHD_RESULT_FAILED_EXTERNAL_ALLOC

External allocation failure.  
Value: `3`

---

### SHD_PROVIDER_STD

Standard provider identifier.  
Value: `0`

### SHD_PROVIDER_EXT

External provider identifier.  
Value: `1`

---

### shd_hndid_t

Handler identifier type.  
Type: `u16`  

#### SHD_HND_LOGGER_ID

Logger handler ID.  

#### SHD_HND_VLKCORE_ID

Vulkan core handler ID.  

#### SHD_HND_VLKSWAPCHAIN_ID

Vulkan swapchain handler ID.  

#### SHD_HND_VLKSEQUENCER_ID

Vulkan sequencer handler ID.  

---

### shd_actid_t

Actor identifier type.  
Type: `u32`  

#### SHD_ACT_VLKDEVICE_ID

Vulkan device actor ID.  

---

### shd_crttype_t

Creator type identifier.  
Type: `u32`  

#### SHD_CRTTYPE_LOGGER

Logger creator type.  

#### SHD_CRTTYPE_VLKCORE

Vulkan core creator type.  

#### SHD_CRTTYPE_VLKSWAPCHAIN

Vulkan swapchain creator type.  

#### SHD_CRTTYPE_VLKSEQUENCER

Vulkan sequencer creator type.  

---

### shd_crtflags_t

Creator flags type.  
Type: `u32`  

#### SHD_CRTFLAGS_DEFAULT_CREATOR

Default creator flag (`1 << 0`)  

---

### shd_basecrt_t

Base creator structure.  
Holds creator type and flags. Can be passed to initialization functions.  
Type: `union`  

Fields:

- `ctype` – creator type (`shd_crttype_t`)  
- `flags` – creator flags (`shd_crtflags_t`)  
- `_raw` – raw 64-bit representation  

---

### shd_baseact_t

Base actor structure.  
Empty placeholder, reserved for actor instance data.  
Type: `union`  

- `_raw` – raw 64-bit representation  

---

### shd_basehnd_t

Base handler structure.  
Empty placeholder, reserved for handler instance data.  
Type: `union`  

- `_raw` – raw 64-bit representation  

---

### shd_actor_meta_t

Actor meta structure.  
Holds lifecycle function pointers and metadata.  

Fields:

- `fInit` – function pointer for actor initialization (`shd_result_t (*)(shd_basecrt_t*)`)  
- `fTerm` – function pointer for actor termination (`shd_result_t (*)()`)  
- `datalen` – size of actor instance struct in bytes (`u16`)  

---

### shd_handler_meta_t

Handler meta structure.  
Holds lifecycle function pointers, optional instance, dependencies, and metadata.  

Fields:

- `fInit` – function pointer for handler initialization (`shd_result_t (*)(shd_basecrt_t*)`)  
- `fTerm` – function pointer for handler termination (`shd_result_t (*)()`)  
- `pInst` – optional pointer to handler instance. If `NULL`, core creates it.  
- `pName` – handler name string  
- `pDeps` – array of dependency handler IDs  
- `depCount` – number of dependencies (`u16`)  
- `instlen` – size of handler struct in bytes (`u16`)  

---

### shd_init_st

Initialize the Shemodogan library.  

`shd_result_t shd_init_st(void)`

Returns: `shd_result_t`

---

### shd_term_st

Terminate the Shemodogan library.  

`shd_result_t shd_term_st(void)`

Returns: `shd_result_t`

---

### shd_register_actor_st

Register an actor with the library.  

`shd_result_t shd_register_actor_st(shd_actid_t actid, shd_actor_meta_t *meta)`

- `actid` – actor ID  
- `meta` – pointer to actor meta structure  

Returns: `shd_result_t`

---

### shd_register_handler_st

Register a handler with the library.  

`shd_result_t shd_register_handler_st(shd_hndid_t hndid, shd_handler_meta_t *meta)`

- `hndid` – handler ID  
- `meta` – pointer to handler meta structure  

Returns: `shd_result_t`

---

### shd_handler_init_st

Initialize a handler.  

`shd_result_t shd_handler_init_st(shd_hndid_t hndid, shd_basecrt_t *creator)`

- `hndid` – handler ID  
- `creator` – pointer to creator structure  

Returns: `shd_result_t`

---

### shd_handler_term_st

Terminate a handler.  

`shd_result_t shd_handler_term_st(shd_hndid_t hndid)`

- `hndid` – handler ID  

Returns: `shd_result_t`

---

### shd_handler_get_mt

Get a handler instance (thread-safe).  

`shd_result_t shd_handler_get_mt(shd_hndid_t hndid, shd_basehnd_t *out_handler)`

- `hndid` – handler ID  
- `out_handler` – pointer to store handler instance  

Returns: `shd_result_t`

---

### shd_actor_subscribe_mt

Subscribe (create/get) an actor instance (thread-safe).  

`shd_result_t shd_actor_subscribe_mt(shd_actid_t actid, shd_basecrt_t *creator, shd_baseact_t **out_actor)`

- `actid` – actor ID  
- `creator` – pointer to creator structure  
- `out_actor` – pointer to store actor instance  

Returns: `shd_result_t`

---

### shd_actor_release_mt

Release an actor instance (thread-safe).  

`shd_result_t shd_actor_release_mt(shd_actid_t actid, shd_baseact_t *actor)`

- `actid` – actor ID  
- `actor` – pointer to actor instance to release  

Returns: `shd_result_t`

---

### Interface Aliases

All aliases simply redirect to the `_st` or `_mt` version of the function.

- `shd_init(...)` → `shd_init_st(...)`  
- `shd_term(...)` → `shd_term_st(...)`  
- `shd_register_actor(...)` → `shd_register_actor_st(...)`  
- `shd_register_handler(...)` → `shd_register_handler_st(...)`  
- `shd_handler_init(...)` → `shd_handler_init_st(...)`  
- `shd_handler_term(...)` → `shd_handler_term_st(...)`  
- `shd_handler_get(...)` → `shd_handler_get_mt(...)`  
- `shd_actor_subscribe(...)` → `shd_actor_subscribe_mt(...)`  
- `shd_actor_release(...)` → `shd_actor_release_mt(...)`  

---

### Notes

- `_st` functions are **single-thread only**, `_mt` functions are **thread-safe**.  
- `shd_basecrt_t`, `shd_baseact_t`, and `shd_basehnd_t` are **lightweight union wrappers** used for generic handling.  
- Use **creator structs** to provide context during handler or actor initialization.  
- Actors are **subordinate to their handler**, and multiple instances can exist; handlers are **singleton**.  
- Constants and IDs follow the **Shemodogan packed ID system**.