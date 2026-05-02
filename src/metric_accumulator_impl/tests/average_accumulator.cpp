#include "metric_accumulator_impl/average_accumulator.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

// здесь ваш код
TEST(AverageAccumulator, CalcAverage) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    AverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Accumulate(metric::MetricResult{"test", 20});
    acc.Accumulate(metric::MetricResult{"test", 30});

    acc.Finalize();

    EXPECT_DOUBLE_EQ(acc.Get(), 20.0);
}

TEST(AverageAccumulator, SingleValue) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    AverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 123});
    acc.Finalize();

    EXPECT_DOUBLE_EQ(acc.Get(), 123.0);
}

TEST(AverageAccumulator, Reset) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    AverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Accumulate(metric::MetricResult{"test", 20});
    acc.Finalize();

    EXPECT_DOUBLE_EQ(acc.Get(), 15.0);

    acc.Reset();

    acc.Accumulate(metric::MetricResult{"test", 100});
    acc.Accumulate(metric::MetricResult{"test", 200});
    acc.Finalize();

    EXPECT_DOUBLE_EQ(acc.Get(), 150.0);
}

TEST(AverageAccumulator, GetBeforeFinalizeException) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    AverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Accumulate(metric::MetricResult{"test", 20});

    EXPECT_THROW(acc.Get(), std::runtime_error);
}

TEST(AverageAccumulator, FinalizeRequiredAfterReset) {
    using namespace analyzer::metric_accumulator::metric_accumulator_impl;

    AverageAccumulator acc;

    acc.Accumulate(metric::MetricResult{"test", 10});
    acc.Finalize();

    EXPECT_DOUBLE_EQ(acc.Get(), 10.0);

    acc.Reset();

    EXPECT_THROW(acc.Get(), std::runtime_error);

    acc.Accumulate(metric::MetricResult{"test", 50});
    acc.Finalize();

    EXPECT_DOUBLE_EQ(acc.Get(), 50.0);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
