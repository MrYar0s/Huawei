#include <benchmark/benchmark.h>

#include "list_version/queue_impl.hpp"

static const int kStart = 1;
static const int kFinish = 10;
static const int kStep = 1;
static const int kNTest = 1e6;

static void BM_Queue_List(benchmark::State& state)
{
	for (auto _ : state)
	{
		queue_list::Queue<int> q;
		for (int i = 0; i < kNTest; i++)
		{
			q.push(i);
		}
		for (int i = 0; i < kNTest; i++)
		{
			q.pop();
		}
	}
}
BENCHMARK(BM_Queue_List)
    ->DenseRange(kStart, kFinish, kStep)
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
