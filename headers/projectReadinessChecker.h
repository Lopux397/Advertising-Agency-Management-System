#pragma once

#include "../headers/collection.h"
#include "../headers/project.h"
#include "../headers/advertisingCampaign.h"
#include "../headers/specialist.h"

#include <vector>
#include <string>

class ProjectReadinessChecker
{
private:
    std::vector<std::string> issues;
public:
    const std::vector<std::string>& getIssues() const;

    bool isReady() const;

    void checkProject(const Project& project, const Collection<AdvertisingCampaign>& campaigns, const Collection<Project>& projects, const Collection<Specialist>& specialists);
};