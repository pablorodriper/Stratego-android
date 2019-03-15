#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


// Pieza
struct Pieza_t77110675;

#include "mscorlib_System_Array1146569071.h"
#include "AssemblyU2DCSharp_Pieza77110675.h"

#pragma once
// Pieza[,]
struct PiezaU5BU2CU5D_t2010370755  : public Il2CppArray
{
public:
	ALIGN_FIELD (8) Pieza_t77110675 * m_Items[1];

public:
	inline Pieza_t77110675 * GetAt(il2cpp_array_size_t index) const { return m_Items[index]; }
	inline Pieza_t77110675 ** GetAddressAt(il2cpp_array_size_t index) { return m_Items + index; }
	inline void SetAt(il2cpp_array_size_t index, Pieza_t77110675 * value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier(m_Items + index, value);
	}
	inline Pieza_t77110675 * GetAt(il2cpp_array_size_t i, il2cpp_array_size_t j) const
	{
		il2cpp_array_size_t index = i * bounds[1].length + j;
		return m_Items[index];
	}
	inline Pieza_t77110675 ** GetAddressAt(il2cpp_array_size_t i, il2cpp_array_size_t j)
	{
		il2cpp_array_size_t index = i * bounds[1].length + j;
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t i, il2cpp_array_size_t j, Pieza_t77110675 * value)
	{
		il2cpp_array_size_t index = i * bounds[1].length + j;
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier(m_Items + index, value);
	}
};
// Pieza[]
struct PiezaU5BU5D_t2010370754  : public Il2CppArray
{
public:
	ALIGN_FIELD (8) Pieza_t77110675 * m_Items[1];

public:
	inline Pieza_t77110675 * GetAt(il2cpp_array_size_t index) const { return m_Items[index]; }
	inline Pieza_t77110675 ** GetAddressAt(il2cpp_array_size_t index) { return m_Items + index; }
	inline void SetAt(il2cpp_array_size_t index, Pieza_t77110675 * value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier(m_Items + index, value);
	}
};
