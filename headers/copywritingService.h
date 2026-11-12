#pragma once

#include "../headers/Service.h"

class CopywritingService : public Service
{
private:
    double pricePerThousandWords;
    int wordCount;
public:
    CopywritingService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerThousandWordsTemp, int wordCountTemp);

    double getPricePerThousandWords() const;
    int getWordCount() const;

    void setPricePerThousandWords(double pricePerThousandWordsTemp);
    void setWordCount(int wordCountTemp);

    double calculateCost() const override;
    std::string_view getType() const override;
};