#pragma once

#include <unordered_map>
#include <string>

namespace fix {

	using FixMessage = std::unordered_map<int, std::string>;

	struct FixField{
		int tag;
		std::string value;
	};

	std::unordered_map<const int, std::string> fix_field_storage(const std::string &raw_str);
}