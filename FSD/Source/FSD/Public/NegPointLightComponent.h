#pragma once
#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "NegPointLightComponent.generated.h"

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UNegPointLightComponent : public UPointLightComponent {
    GENERATED_BODY()
public:
    UNegPointLightComponent();
};

