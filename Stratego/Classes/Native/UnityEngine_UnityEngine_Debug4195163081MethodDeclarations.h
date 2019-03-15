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

// UnityEngine.ILogger
struct ILogger_t629411471;
// System.Object
struct Il2CppObject;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector34282066566.h"
#include "UnityEngine_UnityEngine_Color4194546905.h"
#include "mscorlib_System_Object4170816371.h"

// System.Void UnityEngine.Debug::.cctor()
extern "C"  void Debug__cctor_m37515655 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.ILogger UnityEngine.Debug::get_logger()
extern "C"  Il2CppObject * Debug_get_logger_m275693158 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Debug::DrawLine(UnityEngine.Vector3,UnityEngine.Vector3)
extern "C"  void Debug_DrawLine_m3405689270 (Il2CppObject * __this /* static, unused */, Vector3_t4282066566  ___start0, Vector3_t4282066566  ___end1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Debug::INTERNAL_CALL_DrawLine(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Color&,System.Single,System.Boolean)
extern "C"  void Debug_INTERNAL_CALL_DrawLine_m4247131229 (Il2CppObject * __this /* static, unused */, Vector3_t4282066566 * ___start0, Vector3_t4282066566 * ___end1, Color_t4194546905 * ___color2, float ___duration3, bool ___depthTest4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Debug::Log(System.Object)
extern "C"  void Debug_Log_m1731103628 (Il2CppObject * __this /* static, unused */, Il2CppObject * ___message0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Debug::LogError(System.Object)
extern "C"  void Debug_LogError_m4127342994 (Il2CppObject * __this /* static, unused */, Il2CppObject * ___message0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
