#pragma once
#include "CoreMinimal.h"
#include "InstantUsable.h"
#include "ControlEnemyUsable.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UControlEnemyUsable : public UInstantUsable {
    GENERATED_BODY()
public:
    UControlEnemyUsable();
};

