#include "../headers/projectReadinessChecker.h"

const std::vector<std::string>& ProjectReadinessChecker::getIssues() const{ return issues; }

bool ProjectReadinessChecker::isReady() const { return issues.empty(); }

void ProjectReadinessChecker::checkProject(const Project& project, const Collection<AdvertisingCampaign>& campaigns, const Collection<Project>& projects, const Collection<Specialist>& specialists)
{
    issues.clear();

    const AdvertisingCampaign* campaign =
        campaigns.findById(project.getCampaignId());
    if (campaign == nullptr)
        issues.emplace_back("The project's advertising campaign was not found");

    if (project.getServices().empty())
        issues.emplace_back("The project contains no services");

    for (const auto& service : project.getServices())
    {
        if (service->getSpecialistIds().empty())
        {
            issues.emplace_back("A service has no assigned specialists");
            continue;
        }
        for (int specialistId : service->getSpecialistIds())
            if (specialists.findById(specialistId) == nullptr)
                issues.emplace_back("A service contains a non-existent specialist");
    }

    if (campaign != nullptr)
    {
        double totalCost{};

        for (const Project& currentProject : projects.getAll())
            if (currentProject.getCampaignId() == project.getCampaignId())
                totalCost += currentProject.calculateTotalCost();
        if (totalCost > campaign->getBudget().getAllocatedAmount())
            issues.emplace_back("The campaign budget has been exceeded");
    }
}

