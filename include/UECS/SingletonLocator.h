#pragma once

#include "CmptTag.h"

#include "CmptType.h"

#include <set>

namespace Ubpa::UECS {
	class SingletonLocator {
	public:
		SingletonLocator(const CmptType* types, size_t num);
		SingletonLocator() = default;

		template<typename Func>
		static SingletonLocator Generate();

		template<typename Func>
		SingletonLocator& Combine();

		const std::set<CmptType>& SingletonTypes() const noexcept { return singletonTypes; }

		bool HasWriteSingletonType() const noexcept;

	private:
		std::set<CmptType> singletonTypes;
	};
}

#include "detail/SingletonLocator.inl"
