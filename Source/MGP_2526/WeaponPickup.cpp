#include "WeaponPickup.h"
#include "MGP_2526Character.h"

// Sets up the gun pickup when it spawns
AWeaponPickup::AWeaponPickup()
{
    // Create a zone that detects the player walking in
    PickupZone = CreateDefaultSubobject<USphereComponent>(TEXT("PickupZone"));
    PickupZone->SetSphereRadius(100.f);
    RootComponent = PickupZone;

    // Create the visible gun mesh
    GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
    GunMesh->SetupAttachment(RootComponent);

    // Connect the overlap to our function below
    PickupZone->OnComponentBeginOverlap.AddDynamic(this, &AWeaponPickup::OnPlayerEnter);
}

// This runs when something walks into the pickup zone
void AWeaponPickup::OnPlayerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    // Check if it was the player who walked in
    AMGP_2526Character* Player = Cast<AMGP_2526Character>(OtherActor);

    if (Player)
    {
        // Give the player the weapon
        if (Player)
        {
            // Delete the pickup from the world
            Destroy();
        }
    }
}