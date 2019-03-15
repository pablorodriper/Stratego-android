#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// System.String
struct String_t;
// System.String[]
struct StringU5BU5D_t4054002952;
// UnityEngine.LayerMask
struct LayerMask_t3236759763;
struct LayerMask_t3236759763_marshaled_pinvoke;
struct LayerMask_t3236759763_marshaled_com;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_String7231557.h"

// System.Int32 UnityEngine.LayerMask::NameToLayer(System.String)
extern "C"  int32_t LayerMask_NameToLayer_m170005213 (Il2CppObject * __this /* static, unused */, String_t* ___layerName0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.LayerMask::GetMask(System.String[])
extern "C"  int32_t LayerMask_GetMask_m500679236 (Il2CppObject * __this /* static, unused */, StringU5BU5D_t4054002952* ___layerNames0, const MethodInfo* method) IL2CPP_METHOD_ATTR;

// Methods for marshaling
struct LayerMask_t3236759763;
struct LayerMask_t3236759763_marshaled_pinvoke;

extern "C" void LayerMask_t3236759763_marshal_pinvoke(const LayerMask_t3236759763& unmarshaled, LayerMask_t3236759763_marshaled_pinvoke& marshaled);
extern "C" void LayerMask_t3236759763_marshal_pinvoke_back(const LayerMask_t3236759763_marshaled_pinvoke& marshaled, LayerMask_t3236759763& unmarshaled);
extern "C" void LayerMask_t3236759763_marshal_pinvoke_cleanup(LayerMask_t3236759763_marshaled_pinvoke& marshaled);

// Methods for marshaling
struct LayerMask_t3236759763;
struct LayerMask_t3236759763_marshaled_com;

extern "C" void LayerMask_t3236759763_marshal_com(const LayerMask_t3236759763& unmarshaled, LayerMask_t3236759763_marshaled_com& marshaled);
extern "C" void LayerMask_t3236759763_marshal_com_back(const LayerMask_t3236759763_marshaled_com& marshaled, LayerMask_t3236759763& unmarshaled);
extern "C" void LayerMask_t3236759763_marshal_com_cleanup(LayerMask_t3236759763_marshaled_com& marshaled);
