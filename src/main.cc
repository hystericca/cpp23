#include "types.hh"

#include <numeric>
#include <print>
#include <span>
#include <vector>

/*
 * Given an array arr[] and an integer k,
 * we need to calculate the maximum sum of
 * a subarray having size exactly k
 */
auto max_sum(std::span<const i32> values, usize k) -> std::optional<i32> {
    if (k == 0 || values.size() < k) {
        return std::nullopt;
    }

    auto window_sum =
        std::reduce(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(k), i32{0});

    auto best = window_sum;

    for (usize i = k; i < values.size(); ++i) {
        window_sum += values[i] - values[i - k];
        best = std::max(best, window_sum);
    }

    return best;
}

auto main() -> int {
    const std::vector<i32> values{5, 2, -1, 0, 3};

    if (auto result = max_sum(values, 3)) {
        std::println("{}", *result);
    } else {
        std::println("invalid window size");
    }
}
