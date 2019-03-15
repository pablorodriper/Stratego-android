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
// System.Object
struct Il2CppObject;
// UnityEngine.Vector2
struct Vector2_t4282066565;
struct Vector2_t4282066565_marshaled_pinvoke;
struct Vector2_t4282066565_marshaled_com;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector24282066565.h"
#include "mscorlib_System_Object4170816371.h"

// System.String UnityEngine.Vector2::ToString()
extern "C"  String_t* Vector2_ToString_m3859776067 (Vector2_t4282066565 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Vector2::GetHashCode()
extern "C"  int32_t Vector2_GetHashCode_m128434585 (Vector2_t4282066565 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Vector2::Equals(System.Object)
extern "C"  bool Vector2_Equals_m3404198849 (Vector2_t4282066565 * __this, Il2CppObject * ___other0, const MethodInfo* method) IL2CPP_METHOD_ATTR;

// Methods for marshaling
struct Vector2_t4282066565;
struct Vector2_t4282066565_marshaled_pinvoke;

extern "C" void Vector2_t4282066565_marshal_pinvoke(const Vector2_t4282066565& unmarshaled, Vector2_t4282066565_marshaled_pinvoke& marshaled);
extern "C" void Vector2_t4282066565_marshal_pinvoke_back(const Vector2_t4282066565_marshaled_pinvoke& marshaled, Vector2_t4282066565& unmarshaled);
extern "C" void Vector2_t4282066565_marshal_pinvoke_cleanup(Vector2_t4282066565_marshaled_pinvoke& marshaled);

// Methods for marshaling
struct Vector2_t4282066565;
struct Vector2_t4282066565_marshaled_com;

extern "C" void Vector2_t4282066565_marshal_com(const Vector2_t4282066565& unmarshaled, Vector2_t4282066565_marshaled_com& marshaled);
extern "C" void Vector2_t4282066565_marshal_com_back(const Vector2_t4282066565_marshaled_com& marshaled, Vector2_t4282066565& unmarshaled);
extern "C" void Vector2_t4282066565_marshal_com_cleanup(Vector2_t4282066565_marshaled_com& marshaled);
