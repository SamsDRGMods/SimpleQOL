#pragma once
#include "CoreMinimal.h"
#include "CommunityGoalStateData.generated.h"

USTRUCT(BlueprintType)
struct FCommunityGoalStateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool isGoal;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool isRecruitment;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float TimeLeftSeconds;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 CurrentGoalPeriodID;
    
    FSD_API FCommunityGoalStateData();
};

