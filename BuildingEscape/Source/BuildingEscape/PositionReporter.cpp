// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	FTransform Transform = GetOwner()->GetActorTransform();
	FVector Position = Transform.GetTranslation();
	FString ObjectPos = FString::Printf(TEXT("X=%s, Y=%s, Z=%s") , *FString::SanitizeFloat(Position.X), *FString::SanitizeFloat(Position.Y), *FString::SanitizeFloat(Position.Z));

	// * before a FString gets it as a TCHAR needed by UE_LOG
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName , *ObjectPos);
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

