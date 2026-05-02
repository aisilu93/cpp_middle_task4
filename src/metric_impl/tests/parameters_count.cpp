#include "metric_impl/parameters_count.hpp"
#include "analyse.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

// здесь ваш код
TEST(ParamCount, Comments) {
    std::string filename = "src/metric_impl/tests/files/comments.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 3);
}

TEST(ParamCount, Exceptions) {
    std::string filename = "src/metric_impl/tests/files/exceptions.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 0);
}

TEST(ParamCount, If) {
    std::string filename = "src/metric_impl/tests/files/if.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 1);
}

TEST(ParamCount, Loops) {
    std::string filename = "src/metric_impl/tests/files/loops.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 1);
}

TEST(ParamCount, Many_Lines) {
    std::string filename = "src/metric_impl/tests/files/many_lines.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 0);
}

TEST(ParamCount, Many_Parameters) {
    std::string filename = "src/metric_impl/tests/files/many_parameters.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 5);
}

TEST(ParamCount, Match_Case) {
    std::string filename = "src/metric_impl/tests/files/match_case.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 1);
}

TEST(ParamCount, Nested_If) {
    std::string filename = "src/metric_impl/tests/files/nested_if.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 2);
}

TEST(ParamCount, Simple) {
    std::string filename = "src/metric_impl/tests/files/simple.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 0);
}

TEST(ParamCount, Ternary) {
    std::string filename = "src/metric_impl/tests/files/ternary.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CountParametersMetric>());

    int count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { count += std::get<int>(result.value); });
    });
    EXPECT_EQ(count, 1);
}

}  // namespace analyzer::metric::metric_impl
