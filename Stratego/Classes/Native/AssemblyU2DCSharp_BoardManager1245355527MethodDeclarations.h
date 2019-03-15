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

// BoardManager
struct BoardManager_t1245355527;
// System.Boolean[,]
struct BooleanU5BU2CU5D_t3456302924;
// Pieza[,]
struct PiezaU5BU2CU5D_t2010370755;
// Pieza
struct Pieza_t77110675;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_BoardManager1245355527.h"
#include "AssemblyU2DCSharp_Pieza77110675.h"
#include "UnityEngine_UnityEngine_Vector34282066566.h"

// System.Void BoardManager::.ctor()
extern "C"  void BoardManager__ctor_m547433588 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::set_Instance(BoardManager)
extern "C"  void BoardManager_set_Instance_m2217333755 (Il2CppObject * __this /* static, unused */, BoardManager_t1245355527 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// BoardManager BoardManager::get_Instance()
extern "C"  BoardManager_t1245355527 * BoardManager_get_Instance_m3227571012 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::set_movimientosPermitidos(System.Boolean[,])
extern "C"  void BoardManager_set_movimientosPermitidos_m3103027618 (BoardManager_t1245355527 * __this, BooleanU5BU2CU5D_t3456302924* ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean[,] BoardManager::get_movimientosPermitidos()
extern "C"  BooleanU5BU2CU5D_t3456302924* BoardManager_get_movimientosPermitidos_m2786346193 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::set_Piezas(Pieza[,])
extern "C"  void BoardManager_set_Piezas_m923239860 (BoardManager_t1245355527 * __this, PiezaU5BU2CU5D_t2010370755* ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Pieza[,] BoardManager::get_Piezas()
extern "C"  PiezaU5BU2CU5D_t2010370755* BoardManager_get_Piezas_m138115325 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::Start()
extern "C"  void BoardManager_Start_m3789538676 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::Update()
extern "C"  void BoardManager_Update_m1517434137 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::SeleccionarPieza(System.Int32,System.Int32)
extern "C"  void BoardManager_SeleccionarPieza_m688834577 (BoardManager_t1245355527 * __this, int32_t ___x0, int32_t ___y1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::MoverPieza(System.Int32,System.Int32)
extern "C"  void BoardManager_MoverPieza_m2911875940 (BoardManager_t1245355527 * __this, int32_t ___x0, int32_t ___y1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 BoardManager::Combate(Pieza,Pieza)
extern "C"  int32_t BoardManager_Combate_m3297731747 (BoardManager_t1245355527 * __this, Pieza_t77110675 * ___piezaSeleccionada0, Pieza_t77110675 * ___piezaDefensa1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::UpdateSelection()
extern "C"  void BoardManager_UpdateSelection_m1655854677 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::SpawnFiguras(System.Int32,System.Int32,System.Int32)
extern "C"  void BoardManager_SpawnFiguras_m815606873 (BoardManager_t1245355527 * __this, int32_t ___index0, int32_t ___x1, int32_t ___y2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::SpawnTodas()
extern "C"  void BoardManager_SpawnTodas_m425081744 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 BoardManager::GetTileCenter(System.Int32,System.Int32)
extern "C"  Vector3_t4282066566  BoardManager_GetTileCenter_m3119775893 (BoardManager_t1245355527 * __this, int32_t ___x0, int32_t ___y1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::DrawBoard()
extern "C"  void BoardManager_DrawBoard_m1170171028 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void BoardManager::FinDelJuego()
extern "C"  void BoardManager_FinDelJuego_m2727213844 (BoardManager_t1245355527 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
