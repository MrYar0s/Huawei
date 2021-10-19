#include <../include/stack.hpp>
#include <../include/stack-impl.hpp>
#include <benchmark/benchmark.h>

const size_t size = 100000;

void MultTest(benchmark::State& state)
{
	long double counter = state.range(0);
	stack::MEMORY_MULT = 1.7;
	stack::Stack<size_t> stk;
	for(auto _ : state)
	{
		for(size_t i = 0; i < size; i++)
		{
			stk.push(i);
		}
	}
}

BENCHMARK(MultTest)
	-> Arg(20)
	-> Arg(21)
	-> Arg(22)
	-> Arg(23)
        -> Arg(24)
	-> Arg(25);

BENCHMARK_MAIN();
