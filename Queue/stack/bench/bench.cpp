#include <benchmark/benchmark.h>

#include <stack-impl.hpp>
#include <stack.hpp>

const size_t kSize = 10000000;

const size_t kMaxMemoryMult = 10;

void MultTest(benchmark::State &state)
{
	for (auto _ : state)
	{
		stack::Stack<size_t> stk;
		stk.change_memory_mult(1.0 + state.range() / 10.0);
		for (size_t i = 0; i < kSize; i++)
		{
			stk.push(i);
		}
	}
}

BENCHMARK(MultTest)
    ->DenseRange(1, kMaxMemoryMult)
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
