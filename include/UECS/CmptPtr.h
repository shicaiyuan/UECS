#pragma once

#include "CmptType.h"

#include <cassert>

namespace Ubpa {
	class CmptPtr {
	public:
		CmptPtr(CmptType type, void* p) :type{ type }, p{ p }{}
		template<typename Cmpt>
		CmptPtr(Cmpt* p) : type{ CmptType::Of<Cmpt>() }, p{ p }{}

		template<typename Cmpt>
		Cmpt* As() const noexcept {
			assert(type.Is<Cmpt>());
			return reinterpret_cast<Cmpt*>(p);
		}
		CmptType Type() const noexcept { return type; }
		void* Ptr() const noexcept { return p; }
	private:
		CmptType type;
		void* p;
	};

	class CmptCPtr {
	public:
		CmptCPtr(CmptType type, const void* p) :type{ type }, p{ p }{}
		template<typename Cmpt>
		CmptCPtr(const Cmpt* p) : type{ CmptType::Of<Cmpt>() }, p{ p }{}

		template<typename Cmpt>
		const Cmpt* As() const noexcept {
			assert(type.Is<Cmpt>());
			return reinterpret_cast<Cmpt*>(p);
		}
		CmptType Type() const noexcept { return type; }
		const void* Ptr() const noexcept { return p; }
	private:
		CmptType type;
		const void* p;
	};
}
