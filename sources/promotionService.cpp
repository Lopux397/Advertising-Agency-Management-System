#include "../headers/promotionService.h"

#include <stdexcept>
#include <cmath>

PromotionService::PromotionService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerChannelTemp, int channelCountTemp, int durationMonthsTemp)
    : Service(nameTemp, descriptionTemp, specialistIdsTemp), pricePerChannel(pricePerChannelTemp), channelCount(channelCountTemp), durationMonths(durationMonthsTemp)
{
    if (!std::isfinite(pricePerChannelTemp) || pricePerChannelTemp < 0)
        throw std::invalid_argument("Price per channel cannot be negative or invalid");
    if (channelCountTemp < 1)
        throw std::invalid_argument("Channel count cannot be negative or equal to zero");
    if (durationMonthsTemp < 1)
        throw std::invalid_argument("Duration months cannot be negative or equal to zero");
}

double PromotionService::getPricePerChannel() const { return pricePerChannel; }
int PromotionService::getChannelCount() const { return channelCount; }
int PromotionService::getDurationMonths() const { return durationMonths; }

void PromotionService::setPricePerChannel(double pricePerChannelTemp)
{
    if (!std::isfinite(pricePerChannelTemp) || pricePerChannelTemp < 0)
        throw std::invalid_argument("Price per channel cannot be negative or invalid");

    pricePerChannel = pricePerChannelTemp;
}
void PromotionService::setChannelCount(int channelCountTemp)
{
    if (channelCountTemp < 1)
        throw std::invalid_argument("Channel count cannot be negative or equal to zero");

    channelCount = channelCountTemp;
}
void PromotionService::setDurationMonths(int durationMonthsTemp)
{
    if (durationMonthsTemp < 1)
        throw std::invalid_argument("Duration months cannot be negative or equal to zero");

    durationMonths = durationMonthsTemp;
}

double PromotionService::calculateCost() const
{
    return pricePerChannel * channelCount *durationMonths;
}
std::string_view PromotionService::getType() const { return "PromotionService"; }