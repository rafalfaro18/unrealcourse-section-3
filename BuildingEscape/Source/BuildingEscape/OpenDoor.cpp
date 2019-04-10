// Copyright (c) 2019 Rafael Alfaro

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Find the owning object
	// Store it in a variable called Owner
	
	AActor* Owner = GetOwner();

	// Try and access the Owner's rotation

	FString ObjectName = Owner->GetName();
	FString OwnerRotation = Owner->GetTransform().GetRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *OwnerRotation);
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

