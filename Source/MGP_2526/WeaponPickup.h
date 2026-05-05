#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponPickup.generated.h"

UCLASS()
class MGP_2526_API AWeaponPickup : public AActor
{
    GENERATED_BODY()

public:
    // Constructor - sets up the pickup
    AWeaponPickup();

    // The visible gun mesh in the world
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* GunMesh;

    // Detects when player walks into it
    UPROPERTY(VisibleAnywhere)
    USphereComponent* PickupZone;

    // Runs when player touches the pickup
    UFUNCTION()
    void OnPlayerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);
};