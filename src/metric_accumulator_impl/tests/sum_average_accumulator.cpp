#include "metric_accumulator_impl/sum_average_accumulator.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

// здесь ваш код
TEST(SumAverageAccumulator, CalcAverageSum) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    SumAverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Accumulate(metric::MetricResult{"test", 20});
    acc.Accumulate(metric::MetricResult{"test", 30});

    acc.Finalize();

    auto result = acc.Get();

    EXPECT_EQ(result.sum, 60);
    EXPECT_DOUBLE_EQ(result.average, 20.0);
}

TEST(SumAverageAccumulator, SingleValue) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    SumAverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 123});
    acc.Finalize();

    auto result = acc.Get();

    EXPECT_EQ(result.sum, 123);
    EXPECT_DOUBLE_EQ(result.average, 123.0);
}

TEST(SumAverageAccumulator, Reset) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    SumAverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Accumulate(metric::MetricResult{"test", 20});
    acc.Finalize();

    auto r1 = acc.Get();
    EXPECT_EQ(r1.sum, 30);
    EXPECT_DOUBLE_EQ(r1.average, 15.0);

    acc.Reset();

    acc.Accumulate(metric::MetricResult{"test", 100});
    acc.Accumulate(metric::MetricResult{"test", 200});
    acc.Finalize();

    auto r2 = acc.Get();
    EXPECT_EQ(r2.sum, 300);
    EXPECT_DOUBLE_EQ(r2.average, 150.0);
}

TEST(SumAverageAccumulator, GetBeforeFinalizeException) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    SumAverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});

    EXPECT_THROW(acc.Get(), std::runtime_error);
}

TEST(SumAverageAccumulator, StateAfterResetInvalid) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    SumAverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Finalize();

    auto r1 = acc.Get();
    EXPECT_EQ(r1.sum, 10);

    acc.Reset();

    EXPECT_THROW(acc.Get(), std::runtime_error);

    acc.Accumulate(metric::MetricResult{"test", 50});
    acc.Finalize();

    auto r2 = acc.Get();
    EXPECT_EQ(r2.sum, 50);
    EXPECT_DOUBLE_EQ(r2.average, 50.0);
}
}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
