// Copyright (c) 2019 Rafael Alfaro

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Classes/Components/PrimitiveComponent.h"

#define OUT

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
	Owner = GetOwner();

}

void UOpenDoor::OpenDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if ( GetTotalMassOfActorsOnPlate() > 24.f ) { // TODO make into a parameter
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	// Check if it's time to close door

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}
	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {

	float TotalMass = 0.f;

	// Find all overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	
	// Iterate through them adding their masses
	for (auto& actor : OverlappingActors)
	{
		float ActorMass = actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		TotalMass += ActorMass;
		UE_LOG(LogTemp, Warning, TEXT("Overlapping %s %s kg"), *actor->GetName(), *FString::SanitizeFloat(ActorMass));
	}

	UE_LOG(LogTemp, Warning, TEXT("Overlapping total mass %s kg"), *FString::SanitizeFloat(TotalMass));

	return TotalMass;
}