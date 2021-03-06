#include "duckdb/execution/operator/helper/physical_execute.hpp"

namespace duckdb {

void PhysicalExecute::GetChunkInternal(ExecutionContext &context, DataChunk &chunk, PhysicalOperatorState *state_) {
	D_ASSERT(plan);
	plan->GetChunk(context, chunk, state_);
}

unique_ptr<PhysicalOperatorState> PhysicalExecute::GetOperatorState() {
	return plan->GetOperatorState();
}

} // namespace duckdb
