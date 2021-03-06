// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,Category="FX")
	UParticleSystem* PickupFX;
	
	UPROPERTY(VisibleAnywhere,Category="Components")
	UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere,Category="Components")
	USphereComponent* sphere;
	void PlayEffect();

public:	
	virtual void NotifyActorBeginOverlap(AActor* otherActor) override;
};
