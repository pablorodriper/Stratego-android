#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.GameObject
struct GameObject_t3674682005;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_t747900261;
// BoardHighlight
struct BoardHighlight_t2578246798;
// System.Predicate`1<UnityEngine.GameObject>
struct Predicate_1_t3285738888;

#include "UnityEngine_UnityEngine_MonoBehaviour667441552.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// BoardHighlight
struct  BoardHighlight_t2578246798  : public MonoBehaviour_t667441552
{
public:
	// UnityEngine.GameObject BoardHighlight::highlightPrefab
	GameObject_t3674682005 * ___highlightPrefab_2;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> BoardHighlight::highlights
	List_1_t747900261 * ___highlights_3;

public:
	inline static int32_t get_offset_of_highlightPrefab_2() { return static_cast<int32_t>(offsetof(BoardHighlight_t2578246798, ___highlightPrefab_2)); }
	inline GameObject_t3674682005 * get_highlightPrefab_2() const { return ___highlightPrefab_2; }
	inline GameObject_t3674682005 ** get_address_of_highlightPrefab_2() { return &___highlightPrefab_2; }
	inline void set_highlightPrefab_2(GameObject_t3674682005 * value)
	{
		___highlightPrefab_2 = value;
		Il2CppCodeGenWriteBarrier(&___highlightPrefab_2, value);
	}

	inline static int32_t get_offset_of_highlights_3() { return static_cast<int32_t>(offsetof(BoardHighlight_t2578246798, ___highlights_3)); }
	inline List_1_t747900261 * get_highlights_3() const { return ___highlights_3; }
	inline List_1_t747900261 ** get_address_of_highlights_3() { return &___highlights_3; }
	inline void set_highlights_3(List_1_t747900261 * value)
	{
		___highlights_3 = value;
		Il2CppCodeGenWriteBarrier(&___highlights_3, value);
	}
};

struct BoardHighlight_t2578246798_StaticFields
{
public:
	// BoardHighlight BoardHighlight::<Instance>k__BackingField
	BoardHighlight_t2578246798 * ___U3CInstanceU3Ek__BackingField_4;
	// System.Predicate`1<UnityEngine.GameObject> BoardHighlight::<>f__am$cache3
	Predicate_1_t3285738888 * ___U3CU3Ef__amU24cache3_5;

public:
	inline static int32_t get_offset_of_U3CInstanceU3Ek__BackingField_4() { return static_cast<int32_t>(offsetof(BoardHighlight_t2578246798_StaticFields, ___U3CInstanceU3Ek__BackingField_4)); }
	inline BoardHighlight_t2578246798 * get_U3CInstanceU3Ek__BackingField_4() const { return ___U3CInstanceU3Ek__BackingField_4; }
	inline BoardHighlight_t2578246798 ** get_address_of_U3CInstanceU3Ek__BackingField_4() { return &___U3CInstanceU3Ek__BackingField_4; }
	inline void set_U3CInstanceU3Ek__BackingField_4(BoardHighlight_t2578246798 * value)
	{
		___U3CInstanceU3Ek__BackingField_4 = value;
		Il2CppCodeGenWriteBarrier(&___U3CInstanceU3Ek__BackingField_4, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__amU24cache3_5() { return static_cast<int32_t>(offsetof(BoardHighlight_t2578246798_StaticFields, ___U3CU3Ef__amU24cache3_5)); }
	inline Predicate_1_t3285738888 * get_U3CU3Ef__amU24cache3_5() const { return ___U3CU3Ef__amU24cache3_5; }
	inline Predicate_1_t3285738888 ** get_address_of_U3CU3Ef__amU24cache3_5() { return &___U3CU3Ef__amU24cache3_5; }
	inline void set_U3CU3Ef__amU24cache3_5(Predicate_1_t3285738888 * value)
	{
		___U3CU3Ef__amU24cache3_5 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__amU24cache3_5, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
