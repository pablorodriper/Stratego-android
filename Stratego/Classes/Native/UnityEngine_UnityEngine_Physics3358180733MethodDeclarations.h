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


#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector34282066566.h"
#include "UnityEngine_UnityEngine_RaycastHit4003175726.h"
#include "UnityEngine_UnityEngine_QueryTriggerInteraction577895768.h"
#include "UnityEngine_UnityEngine_Ray3134616544.h"

// System.Boolean UnityEngine.Physics::Raycast(UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.RaycastHit&,System.Single,System.Int32,UnityEngine.QueryTriggerInteraction)
extern "C"  bool Physics_Raycast_m1758069759 (Il2CppObject * __this /* static, unused */, Vector3_t4282066566  ___origin0, Vector3_t4282066566  ___direction1, RaycastHit_t4003175726 * ___hitInfo2, float ___maxDistance3, int32_t ___layerMask4, int32_t ___queryTriggerInteraction5, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Physics::Raycast(UnityEngine.Ray,UnityEngine.RaycastHit&,System.Single,System.Int32)
extern "C"  bool Physics_Raycast_m1600345803 (Il2CppObject * __this /* static, unused */, Ray_t3134616544  ___ray0, RaycastHit_t4003175726 * ___hitInfo1, float ___maxDistance2, int32_t ___layerMask3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Physics::Raycast(UnityEngine.Ray,UnityEngine.RaycastHit&,System.Single,System.Int32,UnityEngine.QueryTriggerInteraction)
extern "C"  bool Physics_Raycast_m165875788 (Il2CppObject * __this /* static, unused */, Ray_t3134616544  ___ray0, RaycastHit_t4003175726 * ___hitInfo1, float ___maxDistance2, int32_t ___layerMask3, int32_t ___queryTriggerInteraction4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Physics::Internal_Raycast(UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.RaycastHit&,System.Single,System.Int32,UnityEngine.QueryTriggerInteraction)
extern "C"  bool Physics_Internal_Raycast_m3365413907 (Il2CppObject * __this /* static, unused */, Vector3_t4282066566  ___origin0, Vector3_t4282066566  ___direction1, RaycastHit_t4003175726 * ___hitInfo2, float ___maxDistance3, int32_t ___layermask4, int32_t ___queryTriggerInteraction5, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Physics::INTERNAL_CALL_Internal_Raycast(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.RaycastHit&,System.Single,System.Int32,UnityEngine.QueryTriggerInteraction)
extern "C"  bool Physics_INTERNAL_CALL_Internal_Raycast_m1291554392 (Il2CppObject * __this /* static, unused */, Vector3_t4282066566 * ___origin0, Vector3_t4282066566 * ___direction1, RaycastHit_t4003175726 * ___hitInfo2, float ___maxDistance3, int32_t ___layermask4, int32_t ___queryTriggerInteraction5, const MethodInfo* method) IL2CPP_METHOD_ATTR;
