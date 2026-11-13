#pragma once

#include <vector>
#include <utility>
#include <ranges>
#include <algorithm>
#include <algorithm>

template<typename T>
class Collection
{
private:
    std::vector<T> items;
public:


    const std::vector<T>& getAll() const { return items; }

    T* findById(int idTemp)
    {
        auto it = std::ranges::find_if(items, [idTemp](const auto& item){ return item.getId() == idTemp; });

        if (it == items.end()) return nullptr;

        return &(*it);
    }
    const T* findById(int idTemp) const
    {
        auto it = std::ranges::find_if(items, [idTemp](const auto& item){ return item.getId() == idTemp; });

        if (it == items.end()) return nullptr;

        return &(*it);
    }

    bool add(T item)
    {
        if (findById(item.getId()) != nullptr) return false;

        items.push_back(std::move(item));

        return true;
    }
    bool removeById(int idTemp)
    {
        auto it = std::ranges::find_if(items, [idTemp](const auto& item){ return item.getId() == idTemp; });

        if (it == items.end()) return false;

        items.erase(it);
        return true;
    }

    bool empty() const { return items.empty(); }
    std::size_t size() const { return items.size(); }

    template<typename Predicate>
    std::vector<T*> findIf(Predicate predicate)
    {
        std::vector<T*> result;

        for (auto& item : items)
        {
            if (predicate(item))
                result.push_back(&item);
        }

        return result;
    }

    template<typename Compare>
    void sort(Compare compare)
    {
        std::ranges::sort(items, compare);
    }
};