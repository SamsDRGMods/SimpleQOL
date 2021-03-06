#pragma once
#include "CoreMinimal.h"
#include "SessionUpdateRequest.generated.h"

USTRUCT(BlueprintType)
struct FSessionUpdateRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FString SessionKey;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 NumPlayers;
    
    FSD_API FSessionUpdateRequest();
};

