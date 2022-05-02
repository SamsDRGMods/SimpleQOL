#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "CoilgunWeaponTrail.generated.h"

class UNiagaraComponent;
class USceneComponent;
class UCapsuleComponent;
class UPrimitiveComponent;
class UStatusEffect;

UCLASS()
class ACoilgunWeaponTrail : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* Collision;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* Trail;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParticleTrailOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_TrailHalfLength, meta=(AllowPrivateAccess=true))
    float TrailHalgLength;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_SpawnFireTrail, meta=(AllowPrivateAccess=true))
    bool SpawnFireTrail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> FireEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> ElectricEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> EffectsToApply;
    
public:
    ACoilgunWeaponTrail();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TrailHalfLength();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SpawnFireTrail();
    
    UFUNCTION(BlueprintCallable)
    void OnInited_Callback();
    
    UFUNCTION(BlueprintCallable)
    void OnActorLeaveTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnActorEnteredTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};
