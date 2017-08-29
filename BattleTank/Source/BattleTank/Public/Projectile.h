// Copyright Francisco Javier Martinez 2017.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	virtual void BeginPlay() override;

	void LaunchProjectile(float Speed);

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URadialForceComponent* ExplosionForce = nullptr;

private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpired();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float DestroyDelay = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ProjectileDamage = 100;
};
