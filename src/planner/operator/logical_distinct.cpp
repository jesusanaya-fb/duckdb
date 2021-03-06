#include "duckdb/planner/operator/logical_distinct.hpp"
#include "duckdb/common/string_util.hpp"

namespace duckdb {

using namespace duckdb;

string LogicalDistinct::ParamsToString() const {
	string result = LogicalOperator::ParamsToString();
	if (distinct_targets.size() > 0) {
		result += StringUtil::Join(distinct_targets, distinct_targets.size(), "\n",
		                           [](const unique_ptr<Expression> &child) { return child->GetName(); });
	}

	return result;
}

} // namespace duckdb
