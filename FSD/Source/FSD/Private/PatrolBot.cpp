#include "PatrolBot.h"
#include "Net/UnrealNetwork.h"

class UHealthComponentBase;
class UPrimitiveComponent;
class AActor;

void APatrolBot::SetIsPatrolling(bool patroling) {
}

void APatrolBot::SetHacked() {
}

void APatrolBot::SetFiringRockets(bool firing) {
}

void APatrolBot::ReviveDrone() {
}





void APatrolBot::OnRep_State() {
}

void APatrolBot::OnRep_IsLockedOn() {
}

void APatrolBot::OnRep_FiringRockets() {
}

void APatrolBot::OnRep_ControlState(EPatrolBotControlState oldState) {
}


void APatrolBot::OnMovementStateChanged(EDeepMovementState NewState) {
}






void APatrolBot::OnDroneAlerted() {
}


void APatrolBot::OnDeath(UHealthComponentBase* aHealthComponent) {
}


void APatrolBot::OnCollided(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void APatrolBot::Jumped_Implementation() {
}

bool APatrolBot::IsHacked() const {
    return false;
}

void APatrolBot::ImpactSound_Implementation() {
}

void APatrolBot::EndFireRockets() {
}

void APatrolBot::DisableDrone() {
}

void APatrolBot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APatrolBot, IsLockedOn);
    DOREPLIFETIME(APatrolBot, State);
    DOREPLIFETIME(APatrolBot, ControlState);
    DOREPLIFETIME(APatrolBot, FiringRockets);
    DOREPLIFETIME(APatrolBot, Alerted);
    DOREPLIFETIME(APatrolBot, CurrentTarget);
}

APatrolBot::APatrolBot() {
    this->NearTargetSphere = NULL;
    this->MaxMotionSoundVelThresholdFlying = 400.00f;
    this->MaxMotionSoundVelThreshold = 400.00f;
    this->MaxTurningMotionSoundVelThreshold = 400.00f;
    this->DebugAudio = false;
    this->HackedAttackMultiplier = 0.50f;
    this->IsLockedOn = false;
    this->DelayAfterLockOn = 0.50f;
    this->ImpactCue = NULL;
    this->JumpSound = NULL;
    this->StartupAccelerationSound = NULL;
    this->LaunchPower = 0.00f;
    this->SpawnRocketsTime = 5.00f;
    this->State = EPatrolBotState::Rolling;
    this->ControlState = EPatrolBotControlState::Hostile;
    this->HackedAttackSpeedMultiplier = 0.80f;
    this->LaserPenetrationDistance = 10.00f;
    this->MinTurretAngle = -30.00f;
    this->MaxTurretAngle = 50.00f;
    this->SpawnRocketsChance = 0.50f;
    this->GunRange = 0.00f;
    this->RollingAttackCooldown = 0.00f;
    this->FlyingAttackCooldown = 0.00f;
    this->TurretLerpSpeed = 3.00f;
    this->AimDownwardsOffset = 40.00f;
    this->AccelerationThreshold = 0.00f;
    this->LowSpeedThreshold = 50.00f;
    this->RollSettings = NULL;
    this->JumpSettings = NULL;
    this->SpawnRocketsSettings = NULL;
    this->CanJump = false;
    this->JumpForce = 0.00f;
    this->StartFlyingTimer = 0.50f;
    this->MinRollingTime = 0.00f;
    this->MaxRollingTime = 0.00f;
    this->MinFlyingTime = 0.00f;
    this->MaxFlyingTime = 0.00f;
    this->SinSpeed = 0.50f;
    this->SinSize = 50.00f;
    this->FlyingDampOmega = 4.00f;
    this->RollingDampOmega = 20.00f;
    this->FiringRockets = false;
    this->Alerted = false;
    this->CurrentTarget = NULL;
}

