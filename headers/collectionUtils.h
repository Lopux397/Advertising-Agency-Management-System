#pragma once

#include <vector>
#include <algorithm>

template <typename T, typename Predicate>
std::vector<T> filterCollection(
    const std::vector<T>& items,
    Predicate predicate)
{
    std::vector<T> result;

    for (const T& item : items)
    {
        if (predicate(item))
            result.push_back(item);
    }

    return result;
}