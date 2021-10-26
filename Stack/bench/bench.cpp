#include <benchmark/benchmark.h>

#include <../include/stack-impl.hpp>
#include <../include/stack.hpp>

const size_t size = 10000000;

const size_t max_memory_mult = 10;

void MultTest(benchmark::State &state) {
  for (auto _ : state) {
    stack::Stack<size_t> stk;
    stk.change_memory_mult(1.0 + state.range() / 10.0);
    for (size_t i = 0; i < size; i++) {
      stk.push(i);
    }
  }
}

BENCHMARK(MultTest)->DenseRange(1, max_memory_mult)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
