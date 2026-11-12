#pragma once

#include "../headers/service.h"

class PromotionService : public Service
{
private:
    double pricePerChannel;
    int channelCount;
    int durationMonths;
public:
    PromotionService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerChannelTemp, int channelCountTemp, int durationMonthsTemp);

    double getPricePerChannel() const;
    int getChannelCount() const;
    int getDurationMonths() const;

    void setPricePerChannel(double pricePerChannelTemp);
    void setChannelCount(int channelCountTemp);
    void setDurationMonths(int durationMonthsTemp);

    double calculateCost() const override;
    std::string_view getType() const override;
};