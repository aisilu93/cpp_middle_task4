#include "metric_impl/code_lines_count.hpp"
#include "analyse.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

// здесь ваш код
TEST(CodeLines, Comments) {
    std::string filename = "src/metric_impl/tests/files/comments.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 3);
}

TEST(CodeLines, Exceptions) {
    std::string filename = "src/metric_impl/tests/files/exceptions.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 7);
}

TEST(CodeLines, If) {
    std::string filename = "src/metric_impl/tests/files/if.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 3);
}

TEST(CodeLines, Loops) {
    std::string filename = "src/metric_impl/tests/files/loops.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 6);
}

TEST(CodeLines, Many_Lines) {
    std::string filename = "src/metric_impl/tests/files/many_lines.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 11);
}

TEST(CodeLines, Many_Parameters) {
    std::string filename = "src/metric_impl/tests/files/many_parameters.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 1);
}

TEST(CodeLines, Match_Case) {
    std::string filename = "src/metric_impl/tests/files/match_case.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 7);
}

TEST(CodeLines, Nested_If) {
    std::string filename = "src/metric_impl/tests/files/nested_if.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 8);
}

TEST(CodeLines, Simple) {
    std::string filename = "src/metric_impl/tests/files/simple.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 5);
}

TEST(CodeLines, Ternary) {
    std::string filename = "src/metric_impl/tests/files/ternary.py";
    std::vector<std::string> files;
    files.push_back(filename);

    analyzer::metric::MetricExtractor metric_extractor;
    metric_extractor.RegisterMetric(std::make_unique<CodeLinesCountMetric>());

    int lines_count = 0;
    auto analysis = analyzer::AnalyseFunctions(files, metric_extractor);
    std::ranges::for_each(analysis, [&](const auto &elem) {
        const auto &[function, metrics] = elem;
        std::ranges::for_each(metrics, [&](const auto &result) { lines_count += std::get<int>(result.value); });
    });
    EXPECT_EQ(lines_count, 1);
}

}  // namespace analyzer::metric::metric_impl
