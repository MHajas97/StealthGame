// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSObjectiveActor.h"
#include "FPSCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include"Kismet/GameplayStatics.h"
// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphere->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	sphere->SetupAttachment(meshComp);

}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor * otherActor)
{
	Super::NotifyActorBeginOverlap(otherActor);
	PlayEffect();
	AFPSCharacter* myCharacter = Cast<AFPSCharacter>(otherActor);
	if (myCharacter)
	{
		myCharacter->isObjectivePickup = true;
		this->Destroy();
	}

}



void AFPSObjectiveActor::PlayEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}
