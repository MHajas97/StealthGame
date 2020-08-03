// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{

	overlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	overlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	overlapComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	overlapComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECR_Overlap);
	overlapComponent->SetBoxExtent(FVector(200.0f));
	RootComponent = overlapComponent;

	overlapComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);


	decalComponent = CreateAbstractDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	decalComponent->DecalSize = FVector(200.0f);
	decalComponent->SetupAttachment(RootComponent);
}

void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{


}

