#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// Pieza
struct Pieza_t77110675;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_t747900261;
// BoardManager
struct BoardManager_t1245355527;
// System.Boolean[,]
struct BooleanU5BU2CU5D_t3456302924;
// Pieza[,]
struct PiezaU5BU2CU5D_t2010370755;

#include "UnityEngine_UnityEngine_MonoBehaviour667441552.h"
#include "UnityEngine_UnityEngine_Quaternion1553702882.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// BoardManager
struct  BoardManager_t1245355527  : public MonoBehaviour_t667441552
{
public:
	// Pieza BoardManager::piezaSeleccionada
	Pieza_t77110675 * ___piezaSeleccionada_4;
	// System.Int32 BoardManager::casillasAlto
	int32_t ___casillasAlto_5;
	// System.Int32 BoardManager::casillasLargo
	int32_t ___casillasLargo_6;
	// System.Int32 BoardManager::selectionX
	int32_t ___selectionX_7;
	// System.Int32 BoardManager::selectionY
	int32_t ___selectionY_8;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> BoardManager::figuras
	List_1_t747900261 * ___figuras_9;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> BoardManager::figurasActivas
	List_1_t747900261 * ___figurasActivas_10;
	// System.Boolean BoardManager::turnoRojo
	bool ___turnoRojo_11;
	// UnityEngine.Quaternion BoardManager::orientation
	Quaternion_t1553702882  ___orientation_12;
	// System.Boolean[,] BoardManager::<movimientosPermitidos>k__BackingField
	BooleanU5BU2CU5D_t3456302924* ___U3CmovimientosPermitidosU3Ek__BackingField_14;
	// Pieza[,] BoardManager::<Piezas>k__BackingField
	PiezaU5BU2CU5D_t2010370755* ___U3CPiezasU3Ek__BackingField_15;

public:
	inline static int32_t get_offset_of_piezaSeleccionada_4() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___piezaSeleccionada_4)); }
	inline Pieza_t77110675 * get_piezaSeleccionada_4() const { return ___piezaSeleccionada_4; }
	inline Pieza_t77110675 ** get_address_of_piezaSeleccionada_4() { return &___piezaSeleccionada_4; }
	inline void set_piezaSeleccionada_4(Pieza_t77110675 * value)
	{
		___piezaSeleccionada_4 = value;
		Il2CppCodeGenWriteBarrier(&___piezaSeleccionada_4, value);
	}

	inline static int32_t get_offset_of_casillasAlto_5() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___casillasAlto_5)); }
	inline int32_t get_casillasAlto_5() const { return ___casillasAlto_5; }
	inline int32_t* get_address_of_casillasAlto_5() { return &___casillasAlto_5; }
	inline void set_casillasAlto_5(int32_t value)
	{
		___casillasAlto_5 = value;
	}

	inline static int32_t get_offset_of_casillasLargo_6() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___casillasLargo_6)); }
	inline int32_t get_casillasLargo_6() const { return ___casillasLargo_6; }
	inline int32_t* get_address_of_casillasLargo_6() { return &___casillasLargo_6; }
	inline void set_casillasLargo_6(int32_t value)
	{
		___casillasLargo_6 = value;
	}

	inline static int32_t get_offset_of_selectionX_7() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___selectionX_7)); }
	inline int32_t get_selectionX_7() const { return ___selectionX_7; }
	inline int32_t* get_address_of_selectionX_7() { return &___selectionX_7; }
	inline void set_selectionX_7(int32_t value)
	{
		___selectionX_7 = value;
	}

	inline static int32_t get_offset_of_selectionY_8() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___selectionY_8)); }
	inline int32_t get_selectionY_8() const { return ___selectionY_8; }
	inline int32_t* get_address_of_selectionY_8() { return &___selectionY_8; }
	inline void set_selectionY_8(int32_t value)
	{
		___selectionY_8 = value;
	}

	inline static int32_t get_offset_of_figuras_9() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___figuras_9)); }
	inline List_1_t747900261 * get_figuras_9() const { return ___figuras_9; }
	inline List_1_t747900261 ** get_address_of_figuras_9() { return &___figuras_9; }
	inline void set_figuras_9(List_1_t747900261 * value)
	{
		___figuras_9 = value;
		Il2CppCodeGenWriteBarrier(&___figuras_9, value);
	}

	inline static int32_t get_offset_of_figurasActivas_10() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___figurasActivas_10)); }
	inline List_1_t747900261 * get_figurasActivas_10() const { return ___figurasActivas_10; }
	inline List_1_t747900261 ** get_address_of_figurasActivas_10() { return &___figurasActivas_10; }
	inline void set_figurasActivas_10(List_1_t747900261 * value)
	{
		___figurasActivas_10 = value;
		Il2CppCodeGenWriteBarrier(&___figurasActivas_10, value);
	}

	inline static int32_t get_offset_of_turnoRojo_11() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___turnoRojo_11)); }
	inline bool get_turnoRojo_11() const { return ___turnoRojo_11; }
	inline bool* get_address_of_turnoRojo_11() { return &___turnoRojo_11; }
	inline void set_turnoRojo_11(bool value)
	{
		___turnoRojo_11 = value;
	}

	inline static int32_t get_offset_of_orientation_12() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___orientation_12)); }
	inline Quaternion_t1553702882  get_orientation_12() const { return ___orientation_12; }
	inline Quaternion_t1553702882 * get_address_of_orientation_12() { return &___orientation_12; }
	inline void set_orientation_12(Quaternion_t1553702882  value)
	{
		___orientation_12 = value;
	}

	inline static int32_t get_offset_of_U3CmovimientosPermitidosU3Ek__BackingField_14() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___U3CmovimientosPermitidosU3Ek__BackingField_14)); }
	inline BooleanU5BU2CU5D_t3456302924* get_U3CmovimientosPermitidosU3Ek__BackingField_14() const { return ___U3CmovimientosPermitidosU3Ek__BackingField_14; }
	inline BooleanU5BU2CU5D_t3456302924** get_address_of_U3CmovimientosPermitidosU3Ek__BackingField_14() { return &___U3CmovimientosPermitidosU3Ek__BackingField_14; }
	inline void set_U3CmovimientosPermitidosU3Ek__BackingField_14(BooleanU5BU2CU5D_t3456302924* value)
	{
		___U3CmovimientosPermitidosU3Ek__BackingField_14 = value;
		Il2CppCodeGenWriteBarrier(&___U3CmovimientosPermitidosU3Ek__BackingField_14, value);
	}

	inline static int32_t get_offset_of_U3CPiezasU3Ek__BackingField_15() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527, ___U3CPiezasU3Ek__BackingField_15)); }
	inline PiezaU5BU2CU5D_t2010370755* get_U3CPiezasU3Ek__BackingField_15() const { return ___U3CPiezasU3Ek__BackingField_15; }
	inline PiezaU5BU2CU5D_t2010370755** get_address_of_U3CPiezasU3Ek__BackingField_15() { return &___U3CPiezasU3Ek__BackingField_15; }
	inline void set_U3CPiezasU3Ek__BackingField_15(PiezaU5BU2CU5D_t2010370755* value)
	{
		___U3CPiezasU3Ek__BackingField_15 = value;
		Il2CppCodeGenWriteBarrier(&___U3CPiezasU3Ek__BackingField_15, value);
	}
};

struct BoardManager_t1245355527_StaticFields
{
public:
	// BoardManager BoardManager::<Instance>k__BackingField
	BoardManager_t1245355527 * ___U3CInstanceU3Ek__BackingField_13;

public:
	inline static int32_t get_offset_of_U3CInstanceU3Ek__BackingField_13() { return static_cast<int32_t>(offsetof(BoardManager_t1245355527_StaticFields, ___U3CInstanceU3Ek__BackingField_13)); }
	inline BoardManager_t1245355527 * get_U3CInstanceU3Ek__BackingField_13() const { return ___U3CInstanceU3Ek__BackingField_13; }
	inline BoardManager_t1245355527 ** get_address_of_U3CInstanceU3Ek__BackingField_13() { return &___U3CInstanceU3Ek__BackingField_13; }
	inline void set_U3CInstanceU3Ek__BackingField_13(BoardManager_t1245355527 * value)
	{
		___U3CInstanceU3Ek__BackingField_13 = value;
		Il2CppCodeGenWriteBarrier(&___U3CInstanceU3Ek__BackingField_13, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
