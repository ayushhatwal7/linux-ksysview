# DEBUG_LOG

Running log of real bugs hit during development.

[ 5248.707221] ksysview_core: ksysview_core_module_init: 25: Init
[ 5248.771667] ksysview_proc: ksysview_proc_module_init: 16: Init
[ 5248.771691] ksysview_proc: ksysview_proc_module_init: 19: System Info: Test system info
[ 5256.407465] ksysview_proc: ksysview_proc_module_exit: 25: Exit
[ 5256.472748] ksysview_core: ksysview_core_module_exit: 31: Exit

---

## Bug 1 — Kbuild "No rule to make target" (Phase 1)

**Symptom:**
No rule to make target 'ksysview_core.ko', needed by '__build'
**Cause:**
Top-level Makefile used `obj-m := ksysview_core.ko` with `M=$(PWD)`.
Kbuild looked for `ksysview_core.c` in the top-level directory — it was in a subdirectory.

**Fix:**
Added per-subdirectory Makefiles with `obj-m := ksysview_core.o`.
Top-level Makefile now invokes kbuild twice with separate `M=` paths.

---

## Bug 2 — Unknown symbol at insmod (Phase 1)

**Symptom:**
ERROR: "ksysview_core_sysinfo" [ksysview_proc.ko] undefined!
**Cause:**
Two separate kbuild invocations are independent — `ksysview_proc` build had no
knowledge of symbols exported by `ksysview_core`.

**Fix:**
Used `KBUILD_EXTRA_SYMBOLS=$(PWD)/ksysview_core/Module.symvers` in the
`ksysview_proc` build invocation so kbuild resolves cross-module symbols correctly.
