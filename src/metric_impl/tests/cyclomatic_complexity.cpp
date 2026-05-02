#include "metric_impl/cyclomatic_complexity.hpp"
#include "analyse.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

// здесь ваш код
TEST(CycloComplex, Comments) {
    std::string filename = "src/metric_impl/tests/files/comments.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 1);
}

TEST(CycloComplex, Exceptions) {
    std::string filename = "src/metric_impl/tests/files/exceptions.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 4);
}

TEST(CycloComplex, If) {
    std::string filename = "src/metric_impl/tests/files/if.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 2);
}

TEST(CycloComplex, Loops) {
    std::string filename = "src/metric_impl/tests/files/loops.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 4);
}

TEST(CycloComplex, Many_Lines) {
    std::string filename = "src/metric_impl/tests/files/many_lines.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 2);
}

TEST(CycloComplex, Many_Parameters) {
    std::string filename = "src/metric_impl/tests/files/many_parameters.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 2);
}

TEST(CycloComplex, Match_Case) {
    std::string filename = "src/metric_impl/tests/files/match_case.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 4);
}

TEST(CycloComplex, Nested_If) {
    std::string filename = "src/metric_impl/tests/files/nested_if.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 4);
}

TEST(CycloComplex, Simple) {
    std::string filename = "src/metric_impl/tests/files/simple.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 2);
}

TEST(CycloComplex, Ternary) {
    std::string filename = "src/metric_impl/tests/files/ternary.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CyclomaticComplexityMetric>());

    int complexity = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { complexity += std::get<int>(result.value); });
    });
    EXPECT_EQ(complexity, 3);
}

}  // namespace analyzer::metric::metric_impl
