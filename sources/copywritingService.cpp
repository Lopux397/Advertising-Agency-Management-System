#include "../headers/copywritingService.h"

#include <stdexcept>
#include <cmath>

CopywritingService::CopywritingService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerThousandWordsTemp, int wordCountTemp)
    : Service(nameTemp, descriptionTemp, specialistIdsTemp), pricePerThousandWords(pricePerThousandWordsTemp), wordCount(wordCountTemp)
{
    if (!std::isfinite(pricePerThousandWordsTemp) || pricePerThousandWordsTemp < 0)
        throw std::invalid_argument("Price per thousand words cannot be negative or invalid");
    if (wordCountTemp < 1)
        throw std::invalid_argument("Word count cannot be negative or equal to zero");
}

double CopywritingService::getPricePerThousandWords() const { return pricePerThousandWords; }
int CopywritingService::getWordCount() const { return wordCount; }

void CopywritingService::setPricePerThousandWords(double pricePerThousandWordsTemp)
{
    if (!std::isfinite(pricePerThousandWordsTemp) || pricePerThousandWordsTemp < 0)
        throw std::invalid_argument("Price per thousand words cannot be negative or invalid");

    pricePerThousandWords = pricePerThousandWordsTemp;
}
void CopywritingService::setWordCount(int wordCountTemp)
{
    if (wordCountTemp < 1)
        throw std::invalid_argument("Word count cannot be negative or equal to zero");

    wordCount = wordCountTemp;
}

double CopywritingService::calculateCost() const
{
    return (pricePerThousandWords * wordCount) / 1000;
}
std::string_view CopywritingService::getType() const { return "CopywritingService"; }
